// Redlg.cpp : implementation file
//

#include "stdafx.h"
#include "teris_1.h"
#include "Redlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Redlg dialog


Redlg::Redlg(CWnd* pParent /*=NULL*/)
	: CDialog(Redlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(Redlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Redlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Redlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Redlg, CDialog)
	//{{AFX_MSG_MAP(Redlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Redlg message handlers

BOOL Redlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
		// TODO: Add extra initialization here

	m_list.InsertColumn("ģʽ");
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
