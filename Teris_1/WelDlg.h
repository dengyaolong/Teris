#if !defined(AFX_WELDLG_H__C981E6FF_786C_4B02_B04E_E9D83B0D52C6__INCLUDED_)
#define AFX_WELDLG_H__C981E6FF_786C_4B02_B04E_E9D83B0D52C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WelDlg.h : header file
//
#include"Teris_1Doc.h"
/////////////////////////////////////////////////////////////////////////////
// WelDlg dialog

class WelDlg : public CDialog
{
// Construction
public:
	int mode;
	WelDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(WelDlg)
	enum { IDD = IDD_DIALOG5 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(WelDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(WelDlg)
	afx_msg void OnWelQpz();
	afx_msg void OnWelReverse();
	afx_msg void OnWelNormal();
	afx_msg void OnWelLife();
	afx_msg void OnWelGk();
	afx_msg void OnWelCxy();
	afx_msg void OnModeXmxx();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WELDLG_H__C981E6FF_786C_4B02_B04E_E9D83B0D52C6__INCLUDED_)
