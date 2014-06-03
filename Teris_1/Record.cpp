// Record.cpp : implementation file
//

#include "stdafx.h"
#include "teris_1.h"
#include "Record.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Record

IMPLEMENT_DYNAMIC(Record, CRecordset)

Record::Record(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(Record)
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString Record::GetDefaultConnect()
{
	return _T("ODBC;DSN=");
}

CString Record::GetDefaultSQL()
{
	return _T("");
}

void Record::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(Record)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// Record diagnostics

#ifdef _DEBUG
void Record::AssertValid() const
{
	CRecordset::AssertValid();
}

void Record::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
