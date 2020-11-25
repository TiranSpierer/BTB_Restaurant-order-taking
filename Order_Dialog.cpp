// Order_Dialog.cpp : implementation file
//

#include "pch.h"
#include "BTB_Restaurant.h"
#include "Order_Dialog.h"
#include "Signature_Dialog.h"
#include "afxdialogex.h"

#include <typeinfo>
#include <vector>
#include "Burger.h"
#include "Falafel.h"
#include "Shawarma.h"
#include "Water.h"
#include "Cola.h"
#include "Beer.h"

vector<Table*> table[5];
int Order_Dialog::table_number = -1;
// Order_Dialog dialog

IMPLEMENT_DYNAMIC(Order_Dialog, CDialogEx)

Order_Dialog::Order_Dialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, txt_price(0)
	, txt_calories(0)
	, txt_kosher(_T(""))
	, txt_Alcoholic(_T(""))
	, txt_Bill(_T(""))
	, txt_cash_input(0)
	, txt_money(0)
	, txt_Edit(1)
{

}

Order_Dialog::~Order_Dialog()
{
}

void Order_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, CheckBox_Cash);
	DDX_Control(pDX, IDC_CHECK2, CheckBox_Credit);
	DDX_Control(pDX, IDC_CHECK6, CheckBox_Burger);
	DDX_Control(pDX, IDC_CHECK7, CheckBox_Burger_Salad);
	DDX_Control(pDX, IDC_CHECK8, CheckBox_Burger_Cheese);
	DDX_Control(pDX, IDC_CHECK9, CheckBox_Burger_DoubleBurger);
	DDX_Control(pDX, IDC_CHECK10, CheckBox_Falafel);
	DDX_Control(pDX, IDC_CHECK11, CheckBox_Falafel_Hummus);
	DDX_Control(pDX, IDC_CHECK12, CheckBox_Falafel_Tahini);
	DDX_Control(pDX, IDC_CHECK13, CheckBox_Falafel_Salad);
	DDX_Control(pDX, IDC_CHECK14, CheckBox_Shawarma);
	DDX_Control(pDX, IDC_CHECK15, CheckBox_Shawarma_Lafa);
	DDX_Control(pDX, IDC_CHECK16, CheckBox_Shawarma_Mix);
	DDX_Control(pDX, IDC_CHECK17, CheckBox_Shawarma_Spicy);
	DDX_Control(pDX, IDC_CHECK18, CheckBox_Beer);
	DDX_Control(pDX, IDC_CHECK20, CheckBox_Cola);
	DDX_Control(pDX, IDC_CHECK22, CheckBox_Water);
	DDX_Control(pDX, IDC_CHECK19, CheckBox_Large);
	DDX_Control(pDX, IDC_CHECK21, CheckBox_Beer_Dark);
	DDX_Control(pDX, IDC_CHECK23, CheckBox_Beer_Light);
	DDX_Control(pDX, IDC_CHECK24, CheckBox_Cola_Regular);
	DDX_Control(pDX, IDC_CHECK25, CheckBox_Cola_Zero);
	DDX_Control(pDX, IDC_CHECK26, CheckBox_Water_Mineral);
	DDX_Control(pDX, IDC_CHECK27, CheckBox_Water_Spark);
	DDX_Text(pDX, IDC_EDIT1, txt_price);
	DDX_Text(pDX, IDC_EDIT2, txt_calories);
	DDX_Text(pDX, IDC_EDIT3, txt_kosher);
	DDX_Text(pDX, IDC_EDIT4, txt_Alcoholic);
	DDX_Text(pDX, IDC_EDIT5, txt_Bill);
	DDX_Control(pDX, IDC_EDIT6, txt_cash);
	DDX_Control(pDX, IDC_BUTTON3, btn_clear);
	DDX_Control(pDX, IDC_BUTTON4, btn_sign);
	DDX_Control(pDX, IDC_COMBO1, table_como);
	DDX_Control(pDX, IDC_BUTTON8, btn_payment);
	DDX_Text(pDX, IDC_EDIT6, txt_money);
	//DDX_Control(pDX, IDC_BUTTON2, btn_Edit);
	DDX_Control(pDX, IDC_BUTTON6, btn_save);
	DDX_Control(pDX, IDC_EDIT7, txt_Edit_Show);
	DDX_Text(pDX, IDC_EDIT7, txt_Edit);
	DDX_Control(pDX, IDC_BUTTON9, btn_Edit_Meal);
	DDX_Control(pDX, IDC_BUTTON1, btn_order);
	DDX_Control(pDX, IDC_BUTTON5, btn_undo);

	CImage img;
	if (S_OK == img.Load(L"Button/BANNER.jpg")) {
		CStatic* control = (CStatic*)GetDlgItem(IDC_MAINPIC);
		control->ModifyStyle(0, SS_BITMAP);
		auto oldbmp = control->SetBitmap(img.Detach());
		if (oldbmp)
			DeleteObject(oldbmp);
	}
	if (flag)
	{
		table_como.AddString(L"1");
		table_como.AddString(L"2");
		table_como.AddString(L"3");
		table_como.AddString(L"4");
		table_como.AddString(L"5");
		CheckBox_Credit.EnableWindow(FALSE);
		CheckBox_Cash.EnableWindow(FALSE);
		txt_cash.EnableWindow(FALSE);
		btn_payment.EnableWindow(FALSE);
		btn_Edit_Meal.EnableWindow(FALSE);
		btn_save.EnableWindow(FALSE);
		txt_Edit_Show.EnableWindow(FALSE);
		btn_order.EnableWindow(FALSE);
		btn_undo.EnableWindow(FALSE);

		clear_checkbox();
		flag = 0;
	}


}

BEGIN_MESSAGE_MAP(Order_Dialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON4, &Order_Dialog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_CHECK6, &Order_Dialog::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_CHECK7, &Order_Dialog::OnBnClickedCheck7)
	ON_BN_CLICKED(IDC_CHECK8, &Order_Dialog::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_CHECK9, &Order_Dialog::OnBnClickedCheck9)
	ON_BN_CLICKED(IDC_CHECK10, &Order_Dialog::OnBnClickedCheck10)
	ON_BN_CLICKED(IDC_CHECK11, &Order_Dialog::OnBnClickedCheck11)
	ON_BN_CLICKED(IDC_CHECK12, &Order_Dialog::OnBnClickedCheck12)
	ON_BN_CLICKED(IDC_CHECK13, &Order_Dialog::OnBnClickedCheck13)
	ON_BN_CLICKED(IDC_CHECK14, &Order_Dialog::OnBnClickedCheck14)
	ON_BN_CLICKED(IDC_CHECK15, &Order_Dialog::OnBnClickedCheck15)
	ON_BN_CLICKED(IDC_CHECK16, &Order_Dialog::OnBnClickedCheck16)
	ON_BN_CLICKED(IDC_CHECK17, &Order_Dialog::OnBnClickedCheck17)
	ON_BN_CLICKED(IDC_CHECK18, &Order_Dialog::OnBnClickedCheck18)
	ON_BN_CLICKED(IDC_CHECK21, &Order_Dialog::OnBnClickedCheck21)
	ON_BN_CLICKED(IDC_CHECK23, &Order_Dialog::OnBnClickedCheck23)
	ON_BN_CLICKED(IDC_CHECK20, &Order_Dialog::OnBnClickedCheck20)
	ON_BN_CLICKED(IDC_CHECK24, &Order_Dialog::OnBnClickedCheck24)
	ON_BN_CLICKED(IDC_CHECK25, &Order_Dialog::OnBnClickedCheck25)
	ON_BN_CLICKED(IDC_CHECK22, &Order_Dialog::OnBnClickedCheck22)
	ON_BN_CLICKED(IDC_CHECK26, &Order_Dialog::OnBnClickedCheck26)
	ON_BN_CLICKED(IDC_CHECK27, &Order_Dialog::OnBnClickedCheck27)
	ON_BN_CLICKED(IDC_CHECK19, &Order_Dialog::OnBnClickedCheck19)
	ON_BN_CLICKED(IDC_BUTTON1, &Order_Dialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &Order_Dialog::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &Order_Dialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &Order_Dialog::OnBnClickedButton5)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Order_Dialog::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON8, &Order_Dialog::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_CHECK1, &Order_Dialog::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &Order_Dialog::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_BUTTON9, &Order_Dialog::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON6, &Order_Dialog::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON11, &Order_Dialog::OnBnClickedButton11)
END_MESSAGE_MAP()

//Burger CheckBox control
void Order_Dialog::OnBnClickedCheck6()
{
	if (!CheckBox_Burger.GetCheck())
	{
		txt_price = 0;
		txt_calories = 0;
		txt_kosher = "";
		txt_Alcoholic = "";
		UpdateData(FALSE);

		CheckBox_Burger_Salad.SetCheck(0);
		CheckBox_Burger_Cheese.SetCheck(0);
		CheckBox_Burger_DoubleBurger.SetCheck(0);

		CheckBox_Burger_Salad.EnableWindow(FALSE);
		CheckBox_Burger_Cheese.EnableWindow(FALSE);
		CheckBox_Burger_DoubleBurger.EnableWindow(FALSE);
	}
	else
	{
		txt_price = 56;
		txt_calories = 300;
		txt_kosher = "Yes";
		txt_Alcoholic = "No";
		UpdateData(FALSE);

		Order_Dialog::clear_checkbox();
		CheckBox_Burger.SetCheck(1);
		CheckBox_Burger.EnableWindow(TRUE);
		CheckBox_Falafel.EnableWindow(TRUE);
		CheckBox_Shawarma.EnableWindow(TRUE);
		CheckBox_Beer.EnableWindow(TRUE);
		CheckBox_Cola.EnableWindow(TRUE);
		CheckBox_Water.EnableWindow(TRUE);
		CheckBox_Burger_Salad.EnableWindow(TRUE);
		CheckBox_Burger_Cheese.EnableWindow(TRUE);
		CheckBox_Burger_DoubleBurger.EnableWindow(TRUE);
		btn_order.EnableWindow(TRUE);
		btn_undo.EnableWindow(TRUE);
	}
}
void Order_Dialog::OnBnClickedCheck7()
{
	if (CheckBox_Burger_Salad.GetCheck())
	{
		txt_price += 3;
		UpdateData(FALSE);
	}
	else
	{
		txt_price -= 3;
		UpdateData(FALSE);
	}
}
void Order_Dialog::OnBnClickedCheck8()
{
	if (CheckBox_Burger_Cheese.GetCheck())
	{
		txt_price += 5;
		txt_calories += 50;
		txt_kosher = "No";
		UpdateData(FALSE);
		AfxMessageBox(L"WARNING!!!!, Not Kosher!!");
	}
	else
	{
		txt_price -= 5;
		txt_calories -= 50;
		txt_kosher = "Yes";
		UpdateData(FALSE);
	}
}
void Order_Dialog::OnBnClickedCheck9()
{
	if (CheckBox_Burger_DoubleBurger.GetCheck())
	{
		txt_price += 15;
		txt_calories += 150;
		UpdateData(FALSE);
	}
	else
	{
		txt_price -= 15;
		txt_calories -= 150;
		UpdateData(FALSE);
	}
}

//Falafel CheckBox control
void Order_Dialog::OnBnClickedCheck10()
{
	if (!CheckBox_Falafel.GetCheck())
	{
		txt_price = 0;
		txt_calories = 0;
		txt_kosher = "";
		txt_Alcoholic = "";
		UpdateData(FALSE);

		CheckBox_Falafel_Hummus.SetCheck(0);
		CheckBox_Falafel_Tahini.SetCheck(0);
		CheckBox_Falafel_Salad.SetCheck(0);

		CheckBox_Falafel_Hummus.EnableWindow(FALSE);
		CheckBox_Falafel_Tahini.EnableWindow(FALSE);
		CheckBox_Falafel_Salad.EnableWindow(FALSE);
	}
	else
	{
		txt_price = 18;
		txt_calories = 100;
		txt_kosher = "Yes";
		txt_Alcoholic = "No";
		UpdateData(FALSE);

		Order_Dialog::clear_checkbox();
		CheckBox_Falafel_Hummus.EnableWindow(TRUE);
		CheckBox_Falafel_Tahini.EnableWindow(TRUE);
		CheckBox_Falafel_Salad.EnableWindow(TRUE);
		CheckBox_Burger.EnableWindow(TRUE);
		CheckBox_Falafel.EnableWindow(TRUE);
		CheckBox_Falafel.SetCheck(1);
		CheckBox_Shawarma.EnableWindow(TRUE);
		CheckBox_Beer.EnableWindow(TRUE);
		CheckBox_Cola.EnableWindow(TRUE);
		CheckBox_Water.EnableWindow(TRUE);
		btn_order.EnableWindow(TRUE);
		btn_undo.EnableWindow(TRUE);
	}
}
void Order_Dialog::OnBnClickedCheck11()
{
	if (CheckBox_Falafel_Hummus.GetCheck())
	{
		txt_price += 1;
		UpdateData(FALSE);
	}
	else
	{
		txt_price -= 1;
		UpdateData(FALSE);
	}
}
void Order_Dialog::OnBnClickedCheck12()
{
	if (CheckBox_Falafel_Tahini.GetCheck())
	{
		txt_price += 1;
		UpdateData(FALSE);
	}
	else
	{
		txt_price -= 1;
		UpdateData(FALSE);
	}
}
void Order_Dialog::OnBnClickedCheck13()
{
	if (CheckBox_Falafel_Salad.GetCheck())
	{
		txt_price += 3;
		UpdateData(FALSE);
	}
	else
	{
		txt_price -= 3;
		UpdateData(FALSE);
	}
}

//Shawarma CheckBox control
void Order_Dialog::OnBnClickedCheck14()
{
	if (!CheckBox_Shawarma.GetCheck())
	{
		txt_price = 0;
		txt_calories = 0;
		txt_kosher = "";
		txt_Alcoholic = "";
		UpdateData(FALSE);

		CheckBox_Shawarma_Lafa.SetCheck(0);
		CheckBox_Shawarma_Mix.SetCheck(0);
		CheckBox_Shawarma_Spicy.SetCheck(0);

		CheckBox_Shawarma_Lafa.EnableWindow(FALSE);
		CheckBox_Shawarma_Mix.EnableWindow(FALSE);
		CheckBox_Shawarma_Spicy.EnableWindow(FALSE);


	}
	else
	{
		txt_price = 40;
		txt_calories = 200;
		txt_kosher = "Yes";
		txt_Alcoholic = "No";
		UpdateData(FALSE);

		Order_Dialog::clear_checkbox();
		CheckBox_Shawarma_Lafa.EnableWindow(TRUE);
		CheckBox_Shawarma_Mix.EnableWindow(TRUE);
		CheckBox_Shawarma_Spicy.EnableWindow(TRUE);
		CheckBox_Burger.EnableWindow(TRUE);
		CheckBox_Falafel.EnableWindow(TRUE);
		CheckBox_Shawarma.EnableWindow(TRUE);
		CheckBox_Shawarma.SetCheck(1);
		CheckBox_Beer.EnableWindow(TRUE);
		CheckBox_Cola.EnableWindow(TRUE);
		CheckBox_Water.EnableWindow(TRUE);
		btn_order.EnableWindow(TRUE);
		btn_undo.EnableWindow(TRUE);
	}
}
void Order_Dialog::OnBnClickedCheck15()
{
	if (CheckBox_Shawarma_Lafa.GetCheck())
	{
		txt_price += 13;
		txt_calories += 50;

		UpdateData(FALSE);
	}
	else
	{
		txt_price -= 13;
		txt_calories -= 50;

		UpdateData(FALSE);
	}
}
void Order_Dialog::OnBnClickedCheck16()
{
	if (CheckBox_Shawarma_Mix.GetCheck())
	{
		txt_price += 5;

		UpdateData(FALSE);
	}
	else
	{
		txt_price -= 5;

		UpdateData(FALSE);
	}
}
void Order_Dialog::OnBnClickedCheck17()
{
	if (CheckBox_Shawarma_Spicy.GetCheck())
	{
		txt_price += 1;

		UpdateData(FALSE);
	}
	else
	{
		txt_price -= 1;

		UpdateData(FALSE);
	}

}

//Beer CheckBox control
void Order_Dialog::OnBnClickedCheck18()
{
	if (!CheckBox_Beer.GetCheck())
	{
		txt_price = 0;
		txt_calories = 0;
		txt_Alcoholic = "";
		txt_kosher = "";
		UpdateData(FALSE);

		CheckBox_Beer_Dark.SetCheck(0);
		CheckBox_Beer_Light.SetCheck(0);
		CheckBox_Large.SetCheck(0);

		CheckBox_Beer_Dark.EnableWindow(FALSE);
		CheckBox_Beer_Light.EnableWindow(FALSE);
		CheckBox_Large.EnableWindow(FALSE);
	}
	else
	{
		txt_price = 22;
		txt_calories = 0;
		txt_kosher = "Yes";
		txt_Alcoholic = "Yes";
		AfxMessageBox(L"WARNING!!!!, Alcoholic Drinks!!");
		UpdateData(FALSE);

		Order_Dialog::clear_checkbox();
		CheckBox_Beer_Dark.EnableWindow(TRUE);
		CheckBox_Beer_Light.EnableWindow(TRUE);
		CheckBox_Large.EnableWindow(TRUE);
		CheckBox_Beer_Dark.SetCheck(1);
		CheckBox_Burger.EnableWindow(TRUE);
		CheckBox_Falafel.EnableWindow(TRUE);
		CheckBox_Shawarma.EnableWindow(TRUE);
		CheckBox_Beer.EnableWindow(TRUE);
		CheckBox_Beer.SetCheck(1);
		CheckBox_Cola.EnableWindow(TRUE);
		CheckBox_Water.EnableWindow(TRUE);
		btn_order.EnableWindow(TRUE);
		btn_undo.EnableWindow(TRUE);
	}
}
void Order_Dialog::OnBnClickedCheck21()
{
	if (CheckBox_Beer_Dark.GetCheck())
	{
		CheckBox_Beer_Light.SetCheck(0);
	}
	else
	{
		CheckBox_Beer_Light.SetCheck(1);
	}
}
void Order_Dialog::OnBnClickedCheck23()
{
	if (CheckBox_Beer_Light.GetCheck())
	{
		CheckBox_Beer_Dark.SetCheck(0);

	}
	else
	{
		CheckBox_Beer_Dark.SetCheck(1);

	}
}

//Cola CheckBox control
void Order_Dialog::OnBnClickedCheck20()
{
	if (!CheckBox_Cola.GetCheck())
	{
		txt_price = 0;
		txt_calories = 0;
		txt_kosher = "";
		txt_Alcoholic = "";
		UpdateData(FALSE);
		CheckBox_Cola_Regular.SetCheck(0);
		CheckBox_Cola_Zero.SetCheck(0);
		CheckBox_Large.SetCheck(0);
		CheckBox_Cola_Regular.EnableWindow(FALSE);
		CheckBox_Cola_Zero.EnableWindow(FALSE);
		CheckBox_Large.EnableWindow(FALSE);
	}
	else
	{
		txt_price = 10;
		txt_calories = 0;
		txt_Alcoholic = "No";
		txt_kosher = "Yes";
		UpdateData(FALSE);

		Order_Dialog::clear_checkbox();
		CheckBox_Cola_Regular.EnableWindow(TRUE);
		CheckBox_Cola_Zero.EnableWindow(TRUE);
		CheckBox_Large.EnableWindow(TRUE);
		CheckBox_Cola_Regular.SetCheck(1);
		CheckBox_Burger.EnableWindow(TRUE);
		CheckBox_Falafel.EnableWindow(TRUE);
		CheckBox_Shawarma.EnableWindow(TRUE);
		CheckBox_Beer.EnableWindow(TRUE);
		CheckBox_Cola.EnableWindow(TRUE);
		CheckBox_Cola.SetCheck(1);
		CheckBox_Water.EnableWindow(TRUE);
		btn_order.EnableWindow(TRUE);
		btn_undo.EnableWindow(TRUE);
	}
}
void Order_Dialog::OnBnClickedCheck24()
{
	if (CheckBox_Cola_Regular.GetCheck())
	{
		CheckBox_Cola_Zero.SetCheck(0);
		txt_price -= 2;
		UpdateData(FALSE);
	}
	else
	{
		CheckBox_Cola_Zero.SetCheck(1);
		txt_price += 2;
		UpdateData(FALSE);
	}
}
void Order_Dialog::OnBnClickedCheck25()
{
	if (CheckBox_Cola_Zero.GetCheck())
	{
		CheckBox_Cola_Regular.SetCheck(0);
		txt_price += 2;
		UpdateData(FALSE);
	}
	else
	{
		CheckBox_Cola_Regular.SetCheck(1);
		txt_price -= 2;
		UpdateData(FALSE);
	}
}

//Water CheckBox control
void Order_Dialog::OnBnClickedCheck22()
{
	if (!CheckBox_Water.GetCheck())
	{
		txt_price = 0;
		txt_calories = 0;
		txt_Alcoholic = "";
		txt_kosher = "";
		UpdateData(FALSE);
		CheckBox_Water_Mineral.SetCheck(0);
		CheckBox_Water_Spark.SetCheck(0);
		CheckBox_Large.SetCheck(0);
		CheckBox_Water_Mineral.EnableWindow(FALSE);
		CheckBox_Water_Spark.EnableWindow(FALSE);
		CheckBox_Large.EnableWindow(FALSE);
	}
	else
	{
		txt_price = 7;
		txt_calories = 0;
		txt_Alcoholic = "No";
		txt_kosher = "Yes";
		UpdateData(FALSE);

		Order_Dialog::clear_checkbox();
		CheckBox_Water_Mineral.EnableWindow(TRUE);
		CheckBox_Water_Spark.EnableWindow(TRUE);
		CheckBox_Large.EnableWindow(TRUE);
		CheckBox_Water_Mineral.SetCheck(1);
		CheckBox_Burger.EnableWindow(TRUE);
		CheckBox_Falafel.EnableWindow(TRUE);
		CheckBox_Shawarma.EnableWindow(TRUE);
		CheckBox_Beer.EnableWindow(TRUE);
		CheckBox_Cola.EnableWindow(TRUE);
		CheckBox_Water.EnableWindow(TRUE);
		CheckBox_Water.SetCheck(1);
		btn_order.EnableWindow(TRUE);
		btn_undo.EnableWindow(TRUE);
	}
}
void Order_Dialog::OnBnClickedCheck26()
{
	if (CheckBox_Water_Mineral.GetCheck())
	{
		CheckBox_Water_Spark.SetCheck(0);
		txt_price = 7;
		UpdateData(FALSE);
	}
	else
	{
		CheckBox_Water_Spark.SetCheck(1);
		txt_price = 9;
		UpdateData(FALSE);
	}
}
void Order_Dialog::OnBnClickedCheck27()
{
	if (CheckBox_Water_Spark.GetCheck())
	{
		CheckBox_Water_Mineral.SetCheck(0);
		txt_price = 9;
		UpdateData(FALSE);
	}
	else
	{
		CheckBox_Water_Mineral.SetCheck(1);
		txt_price = 7;
		UpdateData(FALSE);

		Order_Dialog::clear_checkbox();
		CheckBox_Burger.SetCheck(0);
		CheckBox_Falafel.SetCheck(0);
		CheckBox_Shawarma.SetCheck(0);
		CheckBox_Beer.SetCheck(0);
		CheckBox_Cola.SetCheck(0);
	}
}

//Large Drinks CheckBox control
void Order_Dialog::OnBnClickedCheck19()
{
	if (CheckBox_Large.GetCheck())
	{
		txt_price += 2;
		UpdateData(FALSE);
	}
	else
	{
		txt_price -= 2;

		UpdateData(FALSE);
	}
}

// Goto Signature Dialog
void Order_Dialog::OnBnClickedButton4()
{
	CDialogEx::OnOK();
	Signature_Dialog go;
	go.DoModal();
}

//Order control
void Order_Dialog::OnBnClickedButton1()
{
	if (CheckBox_Burger.GetCheck())//if Burger
	{
		BOOL x1 = CheckBox_Burger_Salad.GetCheck();
		BOOL y1 = CheckBox_Burger_Cheese.GetCheck();
		BOOL z1 = CheckBox_Burger_DoubleBurger.GetCheck();
		table[table_number].push_back(new Burger(x1, y1, z1));
	}
	else if (CheckBox_Falafel.GetCheck())//if Falafel
	{
		BOOL x1 = CheckBox_Falafel_Hummus.GetCheck();
		BOOL y1 = CheckBox_Falafel_Tahini.GetCheck();
		BOOL z1 = CheckBox_Falafel_Salad.GetCheck();
		table[table_number].push_back(new Falafel(x1, y1, z1));
	}
	else if (CheckBox_Shawarma.GetCheck())//if Shawarma
	{
		BOOL x1 = CheckBox_Shawarma_Lafa.GetCheck();
		BOOL y1 = CheckBox_Shawarma_Mix.GetCheck();
		BOOL z1 = CheckBox_Shawarma_Spicy.GetCheck();
		table[table_number].push_back(new Shawarma(x1, y1, z1));
	}
	else if (CheckBox_Beer.GetCheck())//if Beer
	{
		BOOL x1 = CheckBox_Beer_Dark.GetCheck();
		BOOL y1 = CheckBox_Large.GetCheck();
		table[table_number].push_back(new Beer(x1, y1));
	}
	else if (CheckBox_Cola.GetCheck())//if Cola
	{
		BOOL x1 = CheckBox_Large.GetCheck();
		BOOL y1 = CheckBox_Cola_Zero.GetCheck();
		table[table_number].push_back(new Cola(x1, y1));
	}
	else if (CheckBox_Water.GetCheck())//if Water
	{
		BOOL x1 = CheckBox_Large.GetCheck();
		BOOL y1 = CheckBox_Water_Spark.GetCheck();
		table[table_number].push_back(new Water(x1, y1));
	}
	Order_Dialog::OnBnClickedButton2();
	if (table[table_number].size() > 0)
	{
		btn_Edit_Meal.EnableWindow(TRUE);
		txt_Edit_Show.EnableWindow(TRUE);
	}
}

//clear table
void Order_Dialog::OnBnClickedButton3()
{
	int flag_change = 0;

	if (CheckBox_Cash.GetCheck()) {
		int temp_price = 0;
		UpdateData(TRUE);

		for (unsigned int i = 0; i < table[table_number].size(); i++)
			temp_price += table[table_number][i]->priceOfBill();
		int change = txt_money - temp_price;
		string str;
		CString str2;
		str = to_string(change);
		str2 = str.c_str();
		if (change > 0) {
			MessageBox(str2, L"Your change is: ");
		}
		else if(change==0)
			MessageBox(L"Payment succesful");
		else {
			str2.Delete(0);
			MessageBox(str2, L" Left to pay");
			if (change < 0)
				flag_change = 1;
		}
	}
	else
		btn_sign.EnableWindow(TRUE);


	if (!flag_change) {
		for (unsigned int i = 0; i < table[table_number].size(); i++)
			delete table[table_number][i];

		table[table_number].clear();
		
		SetDlgItemText(IDC_EDIT6, L"");
		txt_cash.EnableWindow(FALSE);
		CheckBox_Cash.SetCheck(0);
		CheckBox_Cash.EnableWindow(FALSE);

		Order_Dialog::OnBnClickedButton2();
	}
	txt_cash_input = 0;
	UpdateData(TRUE);
	btn_Edit_Meal.EnableWindow(FALSE);
	btn_save.EnableWindow(FALSE);
	CheckBox_Credit.EnableWindow(FALSE);
	txt_money = 0;
	UpdateData(FALSE);
	btn_order.EnableWindow(FALSE);
	btn_undo.EnableWindow(FALSE);
	clear_checkbox();

}

//print bill
void Order_Dialog::OnBnClickedButton2()
{
	string temp_str;
	int temp_price = 0;

	for (unsigned int i = 0; i < table[table_number].size(); i++) {
		temp_str += table[table_number][i]->printBill();
		temp_price += table[table_number][i]->priceOfBill();
	}
	temp_str += "Total: $" + to_string(temp_price) + "\r\n";
	txt_Bill = temp_str.c_str();
	UpdateData(FALSE);
}

//Clear Checkbox
void Order_Dialog::clear_checkbox()
{

	CheckBox_Burger.SetCheck(0);
	CheckBox_Burger_Salad.SetCheck(0);
	CheckBox_Burger_Cheese.SetCheck(0);
	CheckBox_Burger_DoubleBurger.SetCheck(0);

	CheckBox_Falafel.SetCheck(0);
	CheckBox_Falafel_Hummus.SetCheck(0);
	CheckBox_Falafel_Tahini.SetCheck(0);
	CheckBox_Falafel_Salad.SetCheck(0);

	CheckBox_Shawarma.SetCheck(0);
	CheckBox_Shawarma_Lafa.SetCheck(0);
	CheckBox_Shawarma_Mix.SetCheck(0);
	CheckBox_Shawarma_Spicy.SetCheck(0);

	CheckBox_Beer.SetCheck(0);
	CheckBox_Beer_Dark.SetCheck(0);
	CheckBox_Beer_Light.SetCheck(0);
	CheckBox_Large.SetCheck(0);

	CheckBox_Cola.SetCheck(0);
	CheckBox_Cola_Regular.SetCheck(0);
	CheckBox_Cola_Zero.SetCheck(0);
	CheckBox_Large.SetCheck(0);

	CheckBox_Water.SetCheck(0);
	CheckBox_Water_Mineral.SetCheck(0);
	CheckBox_Water_Spark.SetCheck(0);
	CheckBox_Large.SetCheck(0);

	CheckBox_Burger.EnableWindow(FALSE);
	CheckBox_Burger_Salad.EnableWindow(FALSE);
	CheckBox_Burger_Cheese.EnableWindow(FALSE);
	CheckBox_Burger_DoubleBurger.EnableWindow(FALSE);

	CheckBox_Falafel.EnableWindow(FALSE);
	CheckBox_Falafel_Hummus.EnableWindow(FALSE);
	CheckBox_Falafel_Tahini.EnableWindow(FALSE);
	CheckBox_Falafel_Salad.EnableWindow(FALSE);

	CheckBox_Shawarma.EnableWindow(FALSE);
	CheckBox_Shawarma_Lafa.EnableWindow(FALSE);
	CheckBox_Shawarma_Mix.EnableWindow(FALSE);
	CheckBox_Shawarma_Spicy.EnableWindow(FALSE);

	CheckBox_Beer.EnableWindow(FALSE);
	CheckBox_Beer_Dark.EnableWindow(FALSE);
	CheckBox_Beer_Light.EnableWindow(FALSE);
	CheckBox_Large.EnableWindow(FALSE);

	CheckBox_Cola.EnableWindow(FALSE);
	CheckBox_Cola_Regular.EnableWindow(FALSE);
	CheckBox_Cola_Zero.EnableWindow(FALSE);
	CheckBox_Large.EnableWindow(FALSE);

	CheckBox_Water.EnableWindow(FALSE);
	CheckBox_Water_Mineral.EnableWindow(FALSE);
	CheckBox_Water_Spark.EnableWindow(FALSE);
	CheckBox_Large.EnableWindow(FALSE);

	if(!CheckBox_Credit.GetCheck())btn_sign.EnableWindow(FALSE);
	btn_clear.EnableWindow(FALSE);
}

//Undo
void Order_Dialog::OnBnClickedButton5()
{
	if (table[table_number].size()) {
		vector<Table*>::iterator it;
		it = table[table_number].end() - 1;
		delete table[table_number][table[table_number].size() - 1];

		table[table_number].erase(it);

		Order_Dialog::OnBnClickedButton2();
	}	
	if (table[table_number].size() == 0)
	{
		btn_Edit_Meal.EnableWindow(FALSE);
		btn_save.EnableWindow(FALSE);
		txt_Edit_Show.EnableWindow(FALSE);
		txt_price = 0;
		txt_calories = 0;
		txt_kosher = "";
		txt_Alcoholic = "";
		UpdateData(FALSE);
	}

}

//table control
void Order_Dialog::OnCbnSelchangeCombo1()
{
	table_number = table_como.GetCurSel();
	Order_Dialog::clear_checkbox();
	CheckBox_Burger.EnableWindow(TRUE);
	CheckBox_Falafel.EnableWindow(TRUE);
	CheckBox_Shawarma.EnableWindow(TRUE);
	CheckBox_Beer.EnableWindow(TRUE);
	CheckBox_Cola.EnableWindow(TRUE);
	CheckBox_Water.EnableWindow(TRUE);
	btn_payment.EnableWindow(TRUE);
	txt_price = 0;
	txt_calories = 0;
	txt_kosher = "";
	txt_Alcoholic = "";
	UpdateData(FALSE);
	if (table[table_number].size() > 0)
	{
		btn_Edit_Meal.EnableWindow(TRUE);
		txt_Edit_Show.EnableWindow(TRUE);
	}
	else 
	{
		btn_Edit_Meal.EnableWindow(FALSE);
		txt_Edit_Show.EnableWindow(FALSE);
	}
	Order_Dialog::OnBnClickedButton2();
}

//Payment
void Order_Dialog::OnBnClickedButton8()
{

	int total = 0;
	for (unsigned int i = 0; i < table[table_number].size(); i++)
		total += table[table_number][i]->priceOfBill();
	if (total != 0) {
		CheckBox_Cash.EnableWindow(TRUE);
		CheckBox_Credit.EnableWindow(TRUE);
	}
	else {
		CheckBox_Cash.EnableWindow(FALSE);
		CheckBox_Credit.EnableWindow(FALSE);
	}
}
void Order_Dialog::OnBnClickedCheck1()
{
	if (CheckBox_Cash.GetCheck())
	{
		CheckBox_Credit.SetCheck(0);
		txt_cash.EnableWindow(TRUE);
		btn_clear.EnableWindow(TRUE);
	}
	else
	{
		CheckBox_Credit.SetCheck(1);
		txt_money = 0;
		UpdateData(FALSE);
		txt_cash.EnableWindow(FALSE);
	}
}
void Order_Dialog::OnBnClickedCheck2()
{
	if (CheckBox_Credit.GetCheck())
	{
		CheckBox_Cash.SetCheck(0);
		btn_clear.EnableWindow(TRUE);
		txt_cash.EnableWindow(FALSE);
		txt_money = 0;
		UpdateData(FALSE);
	}
	
	else
	{
		CheckBox_Cash.SetCheck(1);
		txt_cash.EnableWindow(TRUE);

	}
}

//edit meal control
void Order_Dialog::OnBnClickedButton9()
{
	UpdateData(TRUE);
	clear_checkbox();
	btn_save.EnableWindow(TRUE);
	if (txt_Edit > table[table_number].size()) {
		txt_Edit = table[table_number].size();
		UpdateData(FALSE);
	}
	string meal_name = typeid(*table[table_number][txt_Edit - 1]).name();

	if ((unsigned int) txt_Edit - 1 <= table[table_number].size()) {
		if (meal_name == "class Burger")
		{
			CheckBox_Burger.SetCheck(1);
			(static_cast <Burger*> (table[table_number][txt_Edit - 1])->getSalad()) ? CheckBox_Burger_Salad.SetCheck(1) : CheckBox_Burger_Salad.SetCheck(0);
			(static_cast <Burger*> (table[table_number][txt_Edit - 1])->getCheese()) ? CheckBox_Burger_Cheese.SetCheck(1) : CheckBox_Burger_Cheese.SetCheck(0);
			(static_cast <Burger*> (table[table_number][txt_Edit - 1])->getDoubleBurger()) ? CheckBox_Burger_DoubleBurger.SetCheck(1) : CheckBox_Burger_DoubleBurger.SetCheck(0);
			CheckBox_Burger_Salad.EnableWindow(TRUE);
			CheckBox_Burger_Cheese.EnableWindow(TRUE);
			CheckBox_Burger_DoubleBurger.EnableWindow(TRUE);
			txt_price = static_cast <Burger*> (table[table_number][txt_Edit - 1])->getPrice();
			txt_calories = static_cast <Burger*> (table[table_number][txt_Edit - 1])->getCalories();
			txt_kosher = (static_cast <Burger*> (table[table_number][txt_Edit - 1])->getKosher()) ? "True" : "False";
			txt_Alcoholic = "No";
			UpdateData(FALSE);

		}
		else if (meal_name == "class Falafel")
		{
			CheckBox_Falafel.SetCheck(1);
			(static_cast <Falafel*> (table[table_number][txt_Edit - 1])->getHumus()) ? CheckBox_Falafel_Hummus.SetCheck(1) : CheckBox_Falafel_Hummus.SetCheck(0);
			(static_cast <Falafel*> (table[table_number][txt_Edit - 1])->getTahini()) ? CheckBox_Falafel_Tahini.SetCheck(1) : CheckBox_Falafel_Tahini.SetCheck(0);
			(static_cast <Falafel*> (table[table_number][txt_Edit - 1])->getSalad()) ? CheckBox_Falafel_Salad.SetCheck(1) : CheckBox_Falafel_Salad.SetCheck(0);
			CheckBox_Falafel_Hummus.EnableWindow(TRUE);
			CheckBox_Falafel_Tahini.EnableWindow(TRUE);
			CheckBox_Falafel_Salad.EnableWindow(TRUE);
			txt_price = static_cast <Falafel*> (table[table_number][txt_Edit - 1])->getPrice();
			txt_calories = static_cast <Falafel*> (table[table_number][txt_Edit - 1])->getCalories();
			txt_kosher = (static_cast <Falafel*> (table[table_number][txt_Edit - 1])->getKosher()) ? "True" : "False";
			txt_Alcoholic = "No";
			UpdateData(FALSE);
		}
		else if (meal_name == "class Shawarma")
		{
			CheckBox_Shawarma.SetCheck(1);
			(static_cast <Shawarma*> (table[table_number][txt_Edit - 1])->getLafa()) ? CheckBox_Shawarma_Lafa.SetCheck(1) : CheckBox_Shawarma_Lafa.SetCheck(0);
			(static_cast <Shawarma*> (table[table_number][txt_Edit - 1])->getMix()) ? CheckBox_Shawarma_Mix.SetCheck(1) : CheckBox_Shawarma_Mix.SetCheck(0);
			(static_cast <Shawarma*> (table[table_number][txt_Edit - 1])->getSpicy()) ? CheckBox_Shawarma_Spicy.SetCheck(1) : CheckBox_Shawarma_Spicy.SetCheck(0);
			CheckBox_Shawarma_Lafa.EnableWindow(TRUE);
			CheckBox_Shawarma_Mix.EnableWindow(TRUE);
			CheckBox_Shawarma_Spicy.EnableWindow(TRUE);
			txt_price = static_cast <Shawarma*> (table[table_number][txt_Edit - 1])->getPrice();
			txt_calories = static_cast <Shawarma*> (table[table_number][txt_Edit - 1])->getCalories();
			txt_kosher = (static_cast <Shawarma*> (table[table_number][txt_Edit - 1])->getKosher()) ? "True" : "False";
			txt_Alcoholic = "No";
			UpdateData(FALSE);
		}
		else if (meal_name == "class Beer")
		{
			CheckBox_Beer.SetCheck(1);
			(static_cast <Beer*> (table[table_number][txt_Edit - 1])->getKind()) ? CheckBox_Beer_Dark.SetCheck(1) : CheckBox_Beer_Light.SetCheck(1);
			(static_cast <Beer*> (table[table_number][txt_Edit - 1])->getBig()) ? CheckBox_Large.SetCheck(1) : CheckBox_Large.SetCheck(0);
			CheckBox_Beer_Dark.EnableWindow(TRUE);
			CheckBox_Beer_Light.EnableWindow(TRUE);
			CheckBox_Large.EnableWindow(TRUE);
			txt_price = static_cast <Beer*> (table[table_number][txt_Edit - 1])->getPrice();
			txt_calories = 0;
			txt_kosher = "Yes";
			txt_Alcoholic = "Yes";
			UpdateData(FALSE);
		}
		else if (meal_name == "class Cola")
		{
			CheckBox_Cola.SetCheck(1);
			(static_cast <Cola*> (table[table_number][txt_Edit - 1])->getZero()) ? CheckBox_Cola_Regular.SetCheck(1) : CheckBox_Cola_Zero.SetCheck(1);
			(static_cast <Cola*> (table[table_number][txt_Edit - 1])->getBig()) ? CheckBox_Large.SetCheck(1) : CheckBox_Large.SetCheck(0);
			CheckBox_Cola_Regular.EnableWindow(TRUE);
			CheckBox_Cola_Zero.EnableWindow(TRUE);
			CheckBox_Large.EnableWindow(TRUE);
			txt_price = static_cast <Cola*> (table[table_number][txt_Edit - 1])->getPrice();
			txt_calories = 0;
			txt_kosher = "Yes";
			txt_Alcoholic = "No";
			UpdateData(FALSE);
		}
		else if (meal_name == "class Water")
		{
			CheckBox_Water.SetCheck(1);
			(static_cast <Water*> (table[table_number][txt_Edit - 1])->getSpark()) ? CheckBox_Water_Mineral.SetCheck(1) : CheckBox_Water_Mineral.SetCheck(1);
			(static_cast <Water*> (table[table_number][txt_Edit - 1])->getBig()) ? CheckBox_Large.SetCheck(1) : CheckBox_Large.SetCheck(0);
			CheckBox_Water_Mineral.EnableWindow(TRUE);
			CheckBox_Water_Spark.EnableWindow(TRUE);
			CheckBox_Large.EnableWindow(TRUE);
			txt_price = static_cast <Water*> (table[table_number][txt_Edit - 1])->getPrice();
			txt_kosher = "Yes";
			txt_Alcoholic = "No";
			UpdateData(FALSE);
		}
		btn_order.EnableWindow(FALSE);
		btn_undo.EnableWindow(FALSE);
		btn_Edit_Meal.EnableWindow(FALSE);
	}
	else
	{
		AfxMessageBox(L"Product not found");
	}

}

//save meal control
void Order_Dialog::OnBnClickedButton6()
{
	string meal_name = typeid(*table[table_number][txt_Edit - 1]).name();

	if ((unsigned int)txt_Edit - 1 <= table[table_number].size()) 
	{
		if (meal_name == "class Burger")
		{
			static_cast <Burger*> (table[table_number][txt_Edit - 1])->setSalad(CheckBox_Burger_Salad.GetCheck());
			static_cast <Burger*> (table[table_number][txt_Edit - 1])->setCheese(CheckBox_Burger_Cheese.GetCheck());
			static_cast <Burger*> (table[table_number][txt_Edit - 1])->setDoubleBurger(CheckBox_Burger_DoubleBurger.GetCheck());
		}
		else if (meal_name == "class Falafel")
		{
			static_cast <Falafel*> (table[table_number][txt_Edit - 1])->setHumus(CheckBox_Falafel_Hummus.GetCheck());
			static_cast <Falafel*> (table[table_number][txt_Edit - 1])->setTahini(CheckBox_Falafel_Tahini.GetCheck());
			static_cast <Falafel*> (table[table_number][txt_Edit - 1])->setSalad(CheckBox_Falafel_Salad.GetCheck());
		}
		else if (meal_name == "class Shawarma")
		{
			static_cast <Shawarma*> (table[table_number][txt_Edit - 1])->setLafa(CheckBox_Shawarma_Lafa.GetCheck());
			static_cast <Shawarma*> (table[table_number][txt_Edit - 1])->setMix(CheckBox_Shawarma_Mix.GetCheck());
			static_cast <Shawarma*> (table[table_number][txt_Edit - 1])->setSpicy(CheckBox_Shawarma_Spicy.GetCheck());
		}
		else if (meal_name == "class Beer")
		{
			static_cast <Beer*> (table[table_number][txt_Edit - 1])->setKind(CheckBox_Beer_Dark.GetCheck());
			static_cast <Beer*> (table[table_number][txt_Edit - 1])->setBig(CheckBox_Large.GetCheck());
		}
		else if (meal_name == "class Cola")
		{
			static_cast <Cola*> (table[table_number][txt_Edit - 1])->setZero(CheckBox_Cola_Zero.GetCheck());
			static_cast <Cola*> (table[table_number][txt_Edit - 1])->setBig(CheckBox_Large.GetCheck());
		}
		else if (meal_name == "class Water")
		{
			static_cast <Water*> (table[table_number][txt_Edit - 1])->setSpark(CheckBox_Water_Spark.GetCheck());
			static_cast <Water*> (table[table_number][txt_Edit - 1])->setBig(CheckBox_Large.GetCheck());
		}
		btn_order.EnableWindow(TRUE);
		btn_undo.EnableWindow(TRUE);
	}
	
	Order_Dialog::OnBnClickedButton2();
	btn_save.EnableWindow(FALSE);
	Order_Dialog::clear_checkbox();
	CheckBox_Burger.EnableWindow(TRUE);
	CheckBox_Falafel.EnableWindow(TRUE);
	CheckBox_Shawarma.EnableWindow(TRUE);
	CheckBox_Beer.EnableWindow(TRUE);
	CheckBox_Cola.EnableWindow(TRUE);
	CheckBox_Water.EnableWindow(TRUE);
}

//total income today control
void Order_Dialog::OnBnClickedButton11()
{
	string temp = "Total: $" + to_string(Table::getBill());
	txt_Bill = temp.c_str();
	UpdateData(FALSE);
}
