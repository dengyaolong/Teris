#if !defined(AFX_REDLG_H__E165A263_9913_4186_B223_3AE6CFEDF89B__INCLUDED_)
#define AFX_REDLG_H__E165A263_9913_4186_B223_3AE6CFEDF89B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Redlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Redlg dialog

class Redlg : public CDialog
{
// Construction
public:
	Redlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Redlg)
	enum { IDD = IDD_DIALOG7 };
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Redlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Redlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REDLG_H__E165A263_9913_4186_B223_3AE6CFEDF89B__INCLUDED_)
