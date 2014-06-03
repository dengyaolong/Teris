#if !defined(AFX_GKSELECTDLG_H__D24EE161_7C96_46BD_97CC_F96C710234FD__INCLUDED_)
#define AFX_GKSELECTDLG_H__D24EE161_7C96_46BD_97CC_F96C710234FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GkSelectDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// GkSelectDlg dialog

class GkSelectDlg : public CDialog
{
// Construction
public:
	GkSelectDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(GkSelectDlg)
	enum { IDD = IDD_DIALOG2 };
	int		m_Num;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(GkSelectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(GkSelectDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GKSELECTDLG_H__D24EE161_7C96_46BD_97CC_F96C710234FD__INCLUDED_)
