
// BTB_RestaurantDlg.h : header file
//

#pragma once


// CBTBRestaurantDlg dialog
class CBTBRestaurantDlg : public CDialogEx
{
// Construction
public:
	CBTBRestaurantDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BTB_RESTAURANT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString txt_password;
	afx_msg void OnBnClickedButton1();
	void OnBnClickedLog();
	void add_password(CString);
	bool check_password(CString);
	CButton btn_create;
	CString txt_create;
};
