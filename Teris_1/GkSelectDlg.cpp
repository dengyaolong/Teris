// GkSelectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Teris_1.h"
#include "GkSelectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// GkSelectDlg dialog


GkSelectDlg::GkSelectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(GkSelectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(GkSelectDlg)
	m_Num = 1;
	//}}AFX_DATA_INIT
}


void GkSelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GkSelectDlg)
	DDX_Text(pDX, IDC_EDIT1, m_Num);
	DDV_MinMaxInt(pDX, m_Num, 1, 10);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(GkSelectDlg, CDialog)
	//{{AFX_MSG_MAP(GkSelectDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// GkSelectDlg message handlers


