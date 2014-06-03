// WelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Teris_1.h"
#include "WelDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// WelDlg dialog


WelDlg::WelDlg(CWnd* pParent /*=NULL*/)
: CDialog(WelDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(WelDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	
	
}


void WelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(WelDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(WelDlg, CDialog)
//{{AFX_MSG_MAP(WelDlg)
ON_BN_CLICKED(ID_WEL_QPZ, OnWelQpz)
ON_BN_CLICKED(ID_WEL_REVERSE, OnWelReverse)
ON_BN_CLICKED(ID_WEL_NORMAL, OnWelNormal)
ON_BN_CLICKED(ID_WEL_LIFE, OnWelLife)
ON_BN_CLICKED(ID_WEL_GK, OnWelGk)
ON_BN_CLICKED(ID_WEL_CXY, OnWelCxy)
	ON_BN_CLICKED(IDC_MODE_XMXX, OnModeXmxx)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// WelDlg message handlers

void WelDlg::OnWelQpz() 
{
	// TODO: Add your control notification handler code here
	mode=QPZ;
	this->OnOK();
}

void WelDlg::OnWelReverse() 
{
	// TODO: Add your control notification handler code here
	mode=REVERSE;
	this->OnOK();
}

void WelDlg::OnWelNormal() 
{
	// TODO: Add your control notification handler code here
	mode=NORMAL;
	this->OnOK();
}

void WelDlg::OnWelLife() 
{
	// TODO: Add your control notification handler code here
	mode=LIFE;
	this->OnOK();
}

void WelDlg::OnWelGk() 
{
	// TODO: Add your control notification handler code here
	mode=GK;
	this->OnOK();
}

void WelDlg::OnWelCxy() 
{
	// TODO: Add your control notification handler code here
	mode=CXY;
	this->OnOK();
}

void WelDlg::OnModeXmxx() 
{
	// TODO: Add your control notification handler code here
	mode=XMXX;
	this->OnOK();
}
