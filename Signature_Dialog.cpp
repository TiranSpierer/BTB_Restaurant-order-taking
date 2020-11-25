// LineDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Signature_Dialog.h"
#include "BTB_Restaurant.h"
#include "Order_Dialog.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


int Signature_Dialog::vector_number = 0;



// CLineDlg dialog



Signature_Dialog::Signature_Dialog(CWnd* pParent /*= nullptr */)
	: CDialogEx(IDD_DIALOG2, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Signature_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Signature_Dialog, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_STATIC, &Signature_Dialog::OnBnClickedSing)

END_MESSAGE_MAP()


// CLineDlg message handlers

BOOL Signature_Dialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	//HICON m_hIcon = LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI___)
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	m_brush.CreateSolidBrush(RGB(100, 100, 100)); //Dialog color

	// TODO: Add extra initialization here
	// Set Images
	CImage img;
	if (S_OK == img.Load(L"Button/Sign.png")) {
		CStatic* control = (CStatic*)GetDlgItem(IDC_STATIC);
		control->ModifyStyle(0, SS_BITMAP);
		auto oldbmp = control->SetBitmap(img.Detach());
		if (oldbmp)
			DeleteObject(oldbmp);
	}
	CImage img2;
	if (S_OK == img2.Load(L"Button/Sign_Here.png")) {
		CStatic* control = (CStatic*)GetDlgItem(IDC_STATIC2);
		control->ModifyStyle(0, SS_BITMAP);
		auto oldbmp = control->SetBitmap(img2.Detach());
		if (oldbmp)
			DeleteObject(oldbmp);
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Signature_Dialog::OnPaint()
{
	CPaintDC dc(this);

	int j = 0;

	for (j = 0; j <= vector_number; j++)
	{
		const std::vector<CPoint>& linePoints = m_linePoints[j];
		int sizeLinePoints = linePoints.size();
		if (sizeLinePoints > 0)
		{
			CPen myPen1(PS_SOLID, 2, RGB(255, 255, 255));
			CPen* oldPen = dc.SelectObject(&myPen1);
			dc.MoveTo(linePoints[0]);
			for (int i = 1; i < sizeLinePoints; i++)
			{
				dc.LineTo(linePoints[i]);
			}
			dc.SelectObject(oldPen);
		}
	}
}

HCURSOR Signature_Dialog::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Signature_Dialog::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);

	m_mouseDragging = true;

	this->AddLinePoint(point);

	Invalidate();
	UpdateWindow();
	CDialog::OnLButtonDown(nFlags, point);

}

void Signature_Dialog::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_mouseDragging = false;
	vector_number++;
	CDialog::OnLButtonUp(nFlags, point);
}
void Signature_Dialog::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_mouseDragging)
	{
		CClientDC dc(this);
		this->AddLinePoint(point);

		Invalidate();
		UpdateWindow();
	}

}


void Signature_Dialog::OnBnClickedButton1()
{
	CDialogEx::OnOK();
	Order_Dialog go;
	go.DoModal();
}

BOOL Signature_Dialog::OnEraseBkgnd(CDC* pDC)
{
	CRect r;
	pDC->GetClipBox(&r);

	pDC->FillSolidRect(r, RGB(0, 0, 0)); //ugly magenta background
	return TRUE;
}

HBRUSH Signature_Dialog::OnCtlcolor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	return m_brush;
}

void Signature_Dialog::OnBnClickedSing() {
	//CDialogEx::OnOK();
	Order_Dialog go;
	go.DoModal();
}

