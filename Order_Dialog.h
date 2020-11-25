#pragma once


// Order_Dialog dialog

class Order_Dialog : public CDialogEx
{
	DECLARE_DYNAMIC(Order_Dialog)

public:
	Order_Dialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Order_Dialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int flag = 1; // initialize dialog
	static int table_number;
	int txt_price;
	int txt_calories;
	int txt_cash_input;
	int txt_money;

	CButton CheckBox_Burger;
	CButton CheckBox_Burger_Salad;
	CButton CheckBox_Burger_Cheese;
	CButton CheckBox_Burger_DoubleBurger;
	CButton CheckBox_Falafel;
	CButton CheckBox_Falafel_Hummus;
	CButton CheckBox_Falafel_Tahini;
	CButton CheckBox_Falafel_Salad;
	CButton CheckBox_Shawarma;
	CButton CheckBox_Shawarma_Lafa;
	CButton CheckBox_Shawarma_Mix;
	CButton CheckBox_Shawarma_Spicy;
	CButton CheckBox_Beer;
	CButton CheckBox_Beer_Dark;
	CButton CheckBox_Beer_Light;
	CButton CheckBox_Cola;
	CButton CheckBox_Cola_Regular;
	CButton CheckBox_Cola_Zero;
	CButton CheckBox_Water;
	CButton CheckBox_Water_Mineral;
	CButton CheckBox_Water_Spark;
	CButton CheckBox_Large;
	CButton CheckBox_Cash;
	CButton CheckBox_Credit;
	CButton btn_sign;
	CButton btn_clear;
	CButton btn_payment;
	CComboBox table_como;
	CString txt_kosher;
	CString txt_Alcoholic;
	CString txt_Bill;
	CEdit txt_cash;

	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck7();
	afx_msg void OnBnClickedCheck8();
	afx_msg void OnBnClickedCheck9();
	afx_msg void OnBnClickedCheck10();
	afx_msg void OnBnClickedCheck11();
	afx_msg void OnBnClickedCheck12();
	afx_msg void OnBnClickedCheck13();
	afx_msg void OnBnClickedCheck14();
	afx_msg void OnBnClickedCheck15();
	afx_msg void OnBnClickedCheck16();
	afx_msg void OnBnClickedCheck17();
	afx_msg void OnBnClickedCheck18();
	afx_msg void OnBnClickedCheck21();
	afx_msg void OnBnClickedCheck23();
	afx_msg void OnBnClickedCheck20();
	afx_msg void OnBnClickedCheck24();
	afx_msg void OnBnClickedCheck25();
	afx_msg void OnBnClickedCheck22();
	afx_msg void OnBnClickedCheck26();
	afx_msg void OnBnClickedCheck27();
	afx_msg void OnBnClickedCheck19();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnCbnSelchangeCombo1();


	void clear_checkbox();
	afx_msg void OnBnClickedCheck6();

	CButton btn_save;

	int txt_Edit;
	CEdit txt_Edit_Show;
	CButton btn_Edit_Meal;
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton11();
	CButton btn_order;
	CButton btn_undo;
};

