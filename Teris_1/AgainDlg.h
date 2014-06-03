#if !defined(AFX_AGAINDLG_H__C31CC22C_C5D3_4000_B194_CA40066D006D__INCLUDED_)
#define AFX_AGAINDLG_H__C31CC22C_C5D3_4000_B194_CA40066D006D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AgainDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// AgainDlg dialog

class AgainDlg : public CDialog
{
// Construction
public:
	AgainDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(AgainDlg)
	enum { IDD = IDD_DIALOG3 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AgainDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(AgainDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AGAINDLG_H__C31CC22C_C5D3_4000_B194_CA40066D006D__INCLUDED_)
