#if !defined(AFX_RECORD_H__DD9FE591_5AFD_40D4_A487_D8158AEB31D0__INCLUDED_)
#define AFX_RECORD_H__DD9FE591_5AFD_40D4_A487_D8158AEB31D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Record.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Record recordset

class Record : public CRecordset
{
public:
	Record(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Record)

// Field/Param Data
	//{{AFX_FIELD(Record, CRecordset)
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Record)
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

#endif // !defined(AFX_RECORD_H__DD9FE591_5AFD_40D4_A487_D8158AEB31D0__INCLUDED_)
