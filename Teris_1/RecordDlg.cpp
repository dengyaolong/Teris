// RecordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Teris_1.h"
#include "RecordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RecordDlg dialog


RecordDlg::RecordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(RecordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(RecordDlg)
	m_Name = _T("");
	//}}AFX_DATA_INIT
}


void RecordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(RecordDlg)
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(RecordDlg, CDialog)
	//{{AFX_MSG_MAP(RecordDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// RecordDlg message handlers

void RecordDlg::OnOK() 
{
	// TODO: Add extra validation here


	CDialog::OnOK();
}
