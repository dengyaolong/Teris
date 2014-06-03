// AgainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Teris_1.h"
#include "AgainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AgainDlg dialog


AgainDlg::AgainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(AgainDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(AgainDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void AgainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AgainDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AgainDlg, CDialog)
	//{{AFX_MSG_MAP(AgainDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AgainDlg message handlers
