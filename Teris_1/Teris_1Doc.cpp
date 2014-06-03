// Teris_1Doc.cpp : implementation of the CTeris_1Doc class
//

#include "stdafx.h"
#include "Teris_1.h"

#include "Teris_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTeris_1Doc

IMPLEMENT_DYNCREATE(CTeris_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CTeris_1Doc, CDocument)
	//{{AFX_MSG_MAP(CTeris_1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTeris_1Doc construction/destruction

CTeris_1Doc::CTeris_1Doc()
{

	// TODO: add one-time construction code here
    score=0;
	mode=NORMAL;
	Num=1;
	tick=0;
	

	
	
}

CTeris_1Doc::~CTeris_1Doc()
{
}

BOOL CTeris_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTeris_1Doc serialization

void CTeris_1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar<<score<<Num;
	}
	else
	{
		// TODO: add loading code here
		ar>>score>>Num;
	}
	box.Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CTeris_1Doc diagnostics

#ifdef _DEBUG
void CTeris_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTeris_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTeris_1Doc commands



void CTeris_1Doc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	int size=box.GetSize();
	for(int i=0;i<size;i++)
		delete box.GetAt(i);
		box.RemoveAll();
		score=0;
		
	CDocument::DeleteContents();
	
}


