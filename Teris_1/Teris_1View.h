// Teris_1View.h : interface of the CTeris_1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TERIS_1VIEW_H__FC19886B_1E46_434C_AA59_B79451F6AF90__INCLUDED_)
#define AFX_TERIS_1VIEW_H__FC19886B_1E46_434C_AA59_B79451F6AF90__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"Box.h"
#include"PassDlg.h"
#include"GkSelectDlg.h "
#include"AgainDlg.h"
#include"WelDlg.h"
#include <shlwapi.h>
#include <fstream>
#include"RecordDlg.h"
#include"string.h"

#pragma comment(lib,"Shlwapi.lib")
class CTeris_1View : public CView
{
protected: // create from serialization only
	CTeris_1View();
	DECLARE_DYNCREATE(CTeris_1View)

// Attributes
public:
	CTeris_1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTeris_1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	int xmxxscore;
	int GetXXOverScore(int i);
	BOOL XMXXOver();
	void MOVEXX();
	int XIAOXX(int i,int j);
	int setCANXIAO(int i,int j);
	void resetXX(CBox *p);
	void XMXXSHOWXIAO(CPoint point);
	int XMXXSCORE();
	void DrawXX(CDC *pdc);
	void XMXXCheck();
	void StartXmxx();
	BOOL isMeetBlock(CBox *m,CBox *b);
	void setBlock();
	void killTimer();
	CString TopName;
	void readRecord();
	int topNum;
	void SetRecord();
	void StartLife();
	void StartReverse();
	int CXYy;
	int CXYx;
	BOOL isEatFood(CBox *moveBox,CBox *bigBox);
	void setFood();
	void StartCXY();
	BOOL isCXYWin();
	void CXYCheck();
	BOOL isReverseWin();
	void ReverseCheck();
	int QPZSCORE();
	COLORREF makecolor;
	BOOL isQPZWin();
	void QPZCheck();
	void StartQPZ();

	//平方的方块
	void StartNormal();
	

	//关卡
	void StartGk();
	void GkCheck();
	BOOL isGkWin();

	
	//再来一次
	void again();
	
	
	
	
	BOOL isIn(CPoint a,CPoint b,int c);
	BOOL isMake;
	void setTimer();
	BOOL flag;
	int Score(int i);
	void upDateMoveAndNextBox();
	void initialNextBox();
	void initialBigBox2();
	void initialMoveBox();
	void DrawBox(CDC *pDC);
	void initialBigBox();
	virtual ~CTeris_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTeris_1View)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMaketeris();
	afx_msg void OnGkmode();
	afx_msg void OnUpdateGkmode(CCmdUI* pCmdUI);
	afx_msg void OnGkChoose();
	afx_msg void OnNewgame();
	afx_msg void OnQpzmode();
	afx_msg void OnUpdateQpzmode(CCmdUI* pCmdUI);
	afx_msg void OnSetcolorfk1();
	afx_msg void OnSetcolorfk2();
	afx_msg void OnSetcolorfk3();
	afx_msg void OnSetcolorfk4();
	afx_msg void OnUpdateMaketeris(CCmdUI* pCmdUI);
	afx_msg void OnQpzChoose();
	afx_msg void OnNormal();
	afx_msg void OnUpdateNormal(CCmdUI* pCmdUI);
	afx_msg void OnCxyBegin();
	afx_msg void OnUpdateCxyBegin(CCmdUI* pCmdUI);
	afx_msg void OnModeReverse();
	afx_msg void OnUpdateModeReverse(CCmdUI* pCmdUI);
	afx_msg void OnSave();
	afx_msg void OnLastNormal();
	afx_msg void OnLastLife();
	afx_msg void OnLastGk();
	afx_msg void OnLastCxy();
	afx_msg void OnLastQpz();
	afx_msg void OnLastReverse();
	afx_msg void OnMODEREVERSESelect();
	afx_msg void OnUpdateLastNormal(CCmdUI* pCmdUI);
	afx_msg void OnUpdateLastGk(CCmdUI* pCmdUI);
	afx_msg void OnUpdateLastCxy(CCmdUI* pCmdUI);
	afx_msg void OnUpdateLastLife(CCmdUI* pCmdUI);
	afx_msg void OnUpdateLastQpz(CCmdUI* pCmdUI);
	afx_msg void OnUpdateLastReverse(CCmdUI* pCmdUI);
	afx_msg void OnModeXmxx();
	afx_msg void OnUpdateModeXmxx(CCmdUI* pCmdUI);
	afx_msg void OnLastXmxx();
	afx_msg void OnUpdateLastXmxx(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Teris_1View.cpp
inline CTeris_1Doc* CTeris_1View::GetDocument()
   { return (CTeris_1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TERIS_1VIEW_H__FC19886B_1E46_434C_AA59_B79451F6AF90__INCLUDED_)
