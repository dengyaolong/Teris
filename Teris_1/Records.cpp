// Records.cpp : implementation file
//

#include "stdafx.h"
#include "teris_1.h"
#include "Records.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Records

IMPLEMENT_DYNAMIC(Records, CRecordset)

Records::Records(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(Records)
	m_MyName = _T("");
	m_Score = 0;
	m_Mode = _T("");
	m_Timer = 0;
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString Records::GetDefaultConnect()
{
	return _T("ODBC;DSN=GameInfo");
}

CString Records::GetDefaultSQL()
{
	return _T("[record]");
}

void Records::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(Records)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[MyName]"), m_MyName);
	RFX_Int(pFX, _T("[Score]"), m_Score);
	RFX_Text(pFX, _T("[Mode]"), m_Mode);
	RFX_Int(pFX, _T("[Timer]"), m_Timer);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// Records diagnostics

#ifdef _DEBUG
void Records::AssertValid() const
{
	CRecordset::AssertValid();
}

void Records::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
