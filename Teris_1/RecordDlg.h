#if !defined(AFX_RECORDDLG_H__0B2E1929_606F_4FDB_BE42_A948290EC838__INCLUDED_)
#define AFX_RECORDDLG_H__0B2E1929_606F_4FDB_BE42_A948290EC838__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RecordDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RecordDlg dialog

class RecordDlg : public CDialog
{
// Construction
public:
	CString m_Name;
	
	RecordDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(RecordDlg)
	enum { IDD = IDD_DIALOG6 };

	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RecordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(RecordDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECORDDLG_H__0B2E1929_606F_4FDB_BE42_A948290EC838__INCLUDED_)
