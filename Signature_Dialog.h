// LineDlg.h : header file
//

#pragma once
#include <vector>



// CLineDlg dialog
class Signature_Dialog : public CDialogEx
{
	// Construction
public:
	Signature_Dialog(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	std::vector<CPoint> m_linePoints[100]; //amount of customers
	static int vector_number;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
	CBrush m_brush;
	HICON m_hIcon;
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	private: const std::vector<CPoint>& GetLinePoints() { return m_linePoints[vector_number]; }


public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1();
	BOOL OnEraseBkgnd(CDC* pDC);
	HBRUSH OnCtlcolor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	void OnBnClickedSing();
private:
	void AddLinePoint(const CPoint& point) { m_linePoints[vector_number].push_back(point); }
	bool m_mouseDragging{ false };
};