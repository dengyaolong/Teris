#if !defined(AFX_WELCOME_H__7605056B_97CE_47C3_A2A4_84921F6B7E4A__INCLUDED_)
#define AFX_WELCOME_H__7605056B_97CE_47C3_A2A4_84921F6B7E4A__INCLUDED_

#include"Teris_1Doc.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Welcome.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Welcome dialog

class Welcome : public CDialog
{
// Construction
public:
	Welcome(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Welcome)
	enum { IDD = IDD_DIALOG4 };

	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Welcome)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Welcome)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WELCOME_H__7605056B_97CE_47C3_A2A4_84921F6B7E4A__INCLUDED_)
