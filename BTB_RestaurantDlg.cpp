
// BTB_RestaurantDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "BTB_Restaurant.h"
#include "BTB_RestaurantDlg.h"
#include "afxdialogex.h"
#include "Order_Dialog.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBTBRestaurantDlg dialog



CBTBRestaurantDlg::CBTBRestaurantDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BTB_RESTAURANT_DIALOG, pParent)
	, txt_password(_T(""))
	, txt_create(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBTBRestaurantDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, txt_password);
	DDX_Control(pDX, IDC_BUTTON1, btn_create);
	DDX_Text(pDX, IDC_EDIT2, txt_create);
}

BEGIN_MESSAGE_MAP(CBTBRestaurantDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CBTBRestaurantDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_STATIC3, &CBTBRestaurantDlg::OnBnClickedLog)
END_MESSAGE_MAP()


// CBTBRestaurantDlg message handlers

BOOL CBTBRestaurantDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	CImage img;
	if (S_OK == img.Load(L"Button/Login.png")) {
		CStatic* control = (CStatic*)GetDlgItem(IDC_STATIC3);
		control->ModifyStyle(0, SS_BITMAP);
		auto oldbmp = control->SetBitmap(img.Detach());
		if (oldbmp)
			DeleteObject(oldbmp);
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBTBRestaurantDlg::OnPaint()
{
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	CFont font;
	font.CreatePointFont(450, _T("Arial"));
	CFont* oldFont = dc.SelectObject(&font);
	dc.SetBkMode(TRANSPARENT);
	CString string = _T("BTB");
	dc.SetTextColor(RGB(255, 0, 0));
	dc.DrawText(string, &rect, DT_CENTER);
	CDialogEx::OnPaint();
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBTBRestaurantDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

bool CBTBRestaurantDlg::check_password(CString password)
{
	string user_ID;
	ifstream myfile;
	myfile.open("supervisor.txt");

	if (myfile.is_open())
		while (!myfile.eof())
		{
			getline(myfile, user_ID);

			if (user_ID[user_ID.size() - 1] == '\n')
				user_ID[user_ID.size() - 1] = '\0';
			if (user_ID.c_str() == password) {
				myfile.close();
				return true;
			}
		}

	return false;
}
void CBTBRestaurantDlg::add_password(CString password)
{
	wofstream myfile;
	myfile.open("supervisor.txt", ios::app);

	if (myfile.is_open())
	{
		myfile << '\n';
		myfile << (LPCTSTR)password;
	}
	myfile.close();
}

//log in
void CBTBRestaurantDlg::OnBnClickedLog()
{
	UpdateData(TRUE);
	
	//if (check_password(txt_password) == true) { // log in with password
	if(true){ // log in without password
		CDialogEx::OnOK();
		Order_Dialog go;
		go.DoModal();
	}
	else
		MessageBox(__T("Wrong password"), __T("Error"));
}

////create
void CBTBRestaurantDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);

	if (check_password(txt_password)) {
		add_password(txt_create);
		MessageBox(__T("New password updated"), __T("Success"));
	}
	else
		MessageBox(__T("Wrong password"), __T("Error"));
}