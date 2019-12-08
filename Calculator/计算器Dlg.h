// ¼ÆËãÆ÷Dlg.h : header file
//

#if !defined(AFX_DLG_H__EC85E1CF_6345_4B11_8B5C_69D6C3B71487__INCLUDED_)
#define AFX_DLG_H__EC85E1CF_6345_4B11_8B5C_69D6C3B71487__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

class CMyDlg : public CDialog
{
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
	CEdit	m_CResult;
	CButton	m_equal;
	CButton	m_divide;
	CButton	m_times;
	CButton	m_minus;
	CButton	m_plus;
	CButton	m_0;
	CButton	m_9;
	CButton	m_8;
	CButton	m_7;
	CButton	m_6;
	CButton	m_5;
	CButton	m_4;
	CButton	m_2;
	CButton	m_1;
	CButton	m_3;
	int		m_value1;
	int		m_value2;
	int		m_result;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton11();
	afx_msg void OnButton12();
	afx_msg void OnButton13();
	afx_msg void OnButton14();
	afx_msg void OnChangeEdit1();
	afx_msg void OnChangeEdit3();
	afx_msg void OnSetfocusEdit1();
	afx_msg void OnSetfocusEdit2();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__EC85E1CF_6345_4B11_8B5C_69D6C3B71487__INCLUDED_)
