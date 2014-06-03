// Welcome.cpp : implementation file
//

#include "stdafx.h"
#include "Teris_1.h"
#include "Welcome.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Welcome dialog


Welcome::Welcome(CWnd* pParent /*=NULL*/)
	: CDialog(Welcome::IDD, pParent)
{
	//{{AFX_DATA_INIT(Welcome)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Welcome::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Welcome)

	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Welcome, CDialog)
	//{{AFX_MSG_MAP(Welcome)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Welcome message handlers









//DEL int Welcome::DoModal() 
//DEL {
//DEL 	// TODO: Add your specialized code here and/or call the base cla
//DEL 	return CDialog::DoModal();
//DEL }
