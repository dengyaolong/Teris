// Teris_1Doc.h : interface of the CTeris_1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TERIS_1DOC_H__D03E239D_9D97_4402_AC72_367177F7C4BD__INCLUDED_)
#define AFX_TERIS_1DOC_H__D03E239D_9D97_4402_AC72_367177F7C4BD__INCLUDED_

#include "Box.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once

#endif // _MSC_VER > 1000
#ifndef MODE_YL
#define GK 1
#define QPZ 2
#define NORMAL 3
#define LIFE 4
#define REVERSE 5
#define CXY   6
#define XMXX  7
#define MODE_YL
#endif

class CTeris_1Doc : public CDocument
{
protected: // create from serialization only
    CTeris_1Doc();
	DECLARE_DYNCREATE(CTeris_1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTeris_1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	int tick;


	int score;
	CObArray box;
	int Num;
	int mode;
	virtual ~CTeris_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTeris_1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TERIS_1DOC_H__D03E239D_9D97_4402_AC72_367177F7C4BD__INCLUDED_)
