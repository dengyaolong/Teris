#if !defined(AFX_RECORDS_H__122CB216_7A2A_46B0_BEE8_A0E13AB8BE2F__INCLUDED_)
#define AFX_RECORDS_H__122CB216_7A2A_46B0_BEE8_A0E13AB8BE2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Records.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Records recordset

class Records : public CRecordset
{
public:
	Records(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Records)

// Field/Param Data
	//{{AFX_FIELD(Records, CRecordset)
	CString	m_MyName;
	int		m_Score;
	CString	m_Mode;
	int		m_Timer;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Records)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECORDS_H__122CB216_7A2A_46B0_BEE8_A0E13AB8BE2F__INCLUDED_)
