// Teris_1View.cpp : implementation of the CTeris_1View class
//

#include "stdafx.h"
#include "Teris_1.h"

#include "Teris_1Doc.h"
#include "Teris_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTeris_1View

IMPLEMENT_DYNCREATE(CTeris_1View, CView)

BEGIN_MESSAGE_MAP(CTeris_1View, CView)
//{{AFX_MSG_MAP(CTeris_1View)
ON_WM_TIMER()
ON_WM_KEYDOWN()
ON_WM_ERASEBKGND()
ON_WM_LBUTTONDOWN()
ON_COMMAND(ID_MAKETERIS, OnMaketeris)
ON_COMMAND(ID_GKMODE, OnGkmode)
ON_UPDATE_COMMAND_UI(ID_GKMODE, OnUpdateGkmode)
ON_COMMAND(ID_GK_CHOOSE, OnGkChoose)
ON_COMMAND(ID_NEWGAME, OnNewgame)
ON_COMMAND(ID_QPZMODE, OnQpzmode)
ON_UPDATE_COMMAND_UI(ID_QPZMODE, OnUpdateQpzmode)
ON_COMMAND(ID_SETCOLORFK1, OnSetcolorfk1)
ON_COMMAND(ID_SETCOLORFK2, OnSetcolorfk2)
ON_COMMAND(ID_SETCOLORFK3, OnSetcolorfk3)
ON_COMMAND(ID_SETCOLORFK4, OnSetcolorfk4)
ON_UPDATE_COMMAND_UI(ID_MAKETERIS, OnUpdateMaketeris)
ON_COMMAND(ID_QPZ_CHOOSE, OnQpzChoose)
ON_COMMAND(ID_NORMAL, OnNormal)
ON_UPDATE_COMMAND_UI(ID_NORMAL, OnUpdateNormal)
ON_COMMAND(ID_CXY_BEGIN, OnCxyBegin)
ON_UPDATE_COMMAND_UI(ID_CXY_BEGIN, OnUpdateCxyBegin)
ON_COMMAND(ID_MODE_REVERSE, OnModeReverse)
ON_UPDATE_COMMAND_UI(ID_MODE_REVERSE, OnUpdateModeReverse)
ON_COMMAND(ID_SAVE, OnSave)
ON_COMMAND(ID_LAST_NORMAL, OnLastNormal)
ON_COMMAND(ID_LAST_LIFE, OnLastLife)
ON_COMMAND(ID_LAST_GK, OnLastGk)
ON_COMMAND(ID_LAST_CXY, OnLastCxy)
ON_COMMAND(ID_LAST_QPZ, OnLastQpz)
ON_COMMAND(ID_LAST_REVERSE, OnLastReverse)
ON_COMMAND(ID_MODE_REVERSE_Select, OnMODEREVERSESelect)
ON_UPDATE_COMMAND_UI(ID_LAST_NORMAL, OnUpdateLastNormal)
ON_UPDATE_COMMAND_UI(ID_LAST_GK, OnUpdateLastGk)
ON_UPDATE_COMMAND_UI(ID_LAST_CXY, OnUpdateLastCxy)
ON_UPDATE_COMMAND_UI(ID_LAST_LIFE, OnUpdateLastLife)
ON_UPDATE_COMMAND_UI(ID_LAST_QPZ, OnUpdateLastQpz)
ON_UPDATE_COMMAND_UI(ID_LAST_REVERSE, OnUpdateLastReverse)
	ON_COMMAND(ID_MODE_XMXX, OnModeXmxx)
	ON_UPDATE_COMMAND_UI(ID_MODE_XMXX, OnUpdateModeXmxx)
	ON_COMMAND(ID_LAST_XMXX, OnLastXmxx)
	ON_UPDATE_COMMAND_UI(ID_LAST_XMXX, OnUpdateLastXmxx)
	//}}AFX_MSG_MAP
// Standard printing commands
ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTeris_1View construction/destruction

CTeris_1View::CTeris_1View()
{
	// TODO: add construction code here
    flag=TRUE;
    isMake=FALSE;
	makecolor=FKC1;
	xmxxscore=0;
}

CTeris_1View::~CTeris_1View()
{
}

BOOL CTeris_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTeris_1View drawing

void CTeris_1View::OnDraw(CDC* pDC)
{
	CTeris_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	
	
	if( (  (CBox *)pDoc->box.GetAt(0)  )->isLive()){
		
		/*
		if((CBox *)pDoc->box.GetSize()!=0)
			DrawBox(pDC);
		else{
			
			DrawXX(pDC);
			
		}*/
		if(pDoc->mode!=XMXX)
			DrawBox(pDC);
		else{
		//	MessageBox("s");
			DrawXX(pDC);
			
		}

		
	}
	
	else{
		if(GetDocument()->score > this->topNum){
			SetRecord();
		}
		else{
			this->again();
		}
		
	}
	
	switch(GetDocument()->mode){
	case GK:
		GkCheck();
		break;
	case NORMAL:
		
		break;
	case QPZ:
		QPZCheck();
		break;
	case LIFE:
		break;
	case REVERSE:
		ReverseCheck();
		break;
	case CXY:
		
		CXYCheck();
		break;
	case XMXX:
		XMXXCheck();
		break;
		
	}
	
	
	
	
}

/////////////////////////////////////////////////////////////////////////////
// CTeris_1View printing

BOOL CTeris_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTeris_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTeris_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTeris_1View diagnostics

#ifdef _DEBUG
void CTeris_1View::AssertValid() const
{
	CView::AssertValid();
}

void CTeris_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTeris_1Doc* CTeris_1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTeris_1Doc)));
	return (CTeris_1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTeris_1View message handlers



//yaolong================================

//initial
void CTeris_1View::initialBigBox()
{
	
	CTeris_1Doc* pDoc = GetDocument();
	CBox *c=new CBox(BIGBOX,BACKGROUAND_BRUSHCOLOR,BACKGROUAND_PENCOLOR);
	pDoc->box.Add(c);
	
	
}
void CTeris_1View::initialBigBox2()
{
	
	CTeris_1Doc* pDoc = GetDocument();
	CBox *c=new CBox(BIGBOX,XXBK,XXBK);
	pDoc->box.InsertAt(0,c);
	
	
}
void CTeris_1View::initialMoveBox()
{
    CTeris_1Doc* pDoc = GetDocument();
	
	int i=rand()%6;
	CBox *c=new CBox(MOVEBOX,COLOR[i],COLOR[i]);
	if(GetDocument()->mode==QPZ){
		switch(GetDocument()->Num){
			
		case 1:
		case 7:
			c->setO();
			break;
			
		case 2:
			c->setS();
			break;
		case 3:
		case 4:
		case 5:
		case 6:
			
			c->setI();
			break;
			
			
			
		}
		
		
		
	}else{
		c->randChange();
		
	}
	pDoc->box.Add(c);
	
}
void CTeris_1View::initialNextBox()
{
	CTeris_1Doc* pDoc = GetDocument();
	int i=rand()%6;
	CBox *c=new CBox(NEXTBOX,COLOR[i],COLOR[i]);
	if(GetDocument()->mode==QPZ){
		switch(GetDocument()->Num){
			
		case 1:
		case 7:
			c->setO();
			break;
			
		case 2:
			c->setS();
			break;
		case 3:
		case 4:
		case 5:
		case 6:
			
			c->setI();
			break;
			
			
		}
		
		
	}else{
		c->randChange();
		
	}
	pDoc->box.Add(c);
	
}

void CTeris_1View::DrawBox(CDC *pDC)
{
	CRect   rect; 
	GetClientRect(&rect); 
	CDC dcMem;      //用于缓冲作图的内存DC 
	dcMem.CreateCompatibleDC(pDC);      //依附窗口DC创建兼容内存DC
	CBitmap     bmp; //内存中承载临时图象的位图
	bmp.CreateCompatibleBitmap(pDC, rect.Width() , rect.Height() ); //创建兼容位图 
	dcMem.SelectObject(&bmp); //将位图选择进内存DC 
	dcMem.FillSolidRect(rect, pDC->GetBkColor()); //
	
	CTeris_1Doc* pDoc = GetDocument();
	CBox *tmp=NULL;
	for(int i=0;i<pDoc->box.GetSize();i++){
		tmp=(CBox *)pDoc->box.GetAt(i);
		tmp->Draw(&dcMem);
	}
	CString score;
	score.Format("得分：%d",pDoc->score);
	dcMem.SelectStockObject(NULL_BRUSH);
	CPen pen2(PS_SOLID,2,DARKGREEN);
	dcMem.SelectObject(&pen2);
	CString s;
	s.Format("最高记录：%s %d分",TopName,topNum);
	dcMem.TextOut(465,280,s);
	//	dcMem.TextOut(500,290,topNum);
	dcMem.TextOut(500,300,score);
	dcMem.TextOut(500,500,"By yaolong.");
	dcMem.TextOut(500,520,"2013/12/21.");
	dcMem.TextOut(465,400,"开始、暂停请按ENTER");
    s.Format("     用时：%d",(GetDocument()->tick));
	dcMem.TextOut(465,250,s);
	dcMem.Rectangle(450,0,620,200);
	dcMem.Rectangle(450,0,620,569);
	if(GetDocument()->mode==CXY)
		dcMem.Rectangle(0,12*(  (CBox *)pDoc->box.GetAt(0)  )->LOCAL[0][0].halfSize,WNUMBER*2*(  (CBox *)pDoc->box.GetAt(0)  )->LOCAL[0][0].halfSize,12*(  (CBox *)pDoc->box.GetAt(0)  )->LOCAL[0][0].halfSize+1)
		;
	
	pDC->BitBlt(0,0,rect.Width(),rect.Height(), &dcMem ,0,0,SRCCOPY); 
	dcMem.DeleteDC(); //删除DC 
	bmp.DeleteObject(); //删除位图 
	
	
}


void CTeris_1View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	if(nIDEvent==1){
		
		
		CTeris_1Doc* pDoc = GetDocument();
		CBox *BigBox=NULL;
		CBox *MoveBox=NULL;
		CBox *NextBox=NULL;
		
		if(pDoc->box.GetSize()==3){
			
			BigBox=(CBox *)pDoc->box.GetAt(0);
			MoveBox=(CBox *)pDoc->box.GetAt(1);
			NextBox=(CBox *)pDoc->box.GetAt(2);
			if(MoveBox->isDownTouch(BigBox)){
				
				
				BigBox->add(MoveBox);
				
				int s;
				if(GetDocument()->mode==QPZ){
					
					
					if(GetDocument()->Num>=3)
						s=BigBox->xiaoquByAllColor();
					else{
						
						s=BigBox->xiaoquByColor();
						
					}
				}else if(GetDocument()->mode==REVERSE){
					
					s=BigBox->xiaoquExceptRed();
					
				}
				else{
					s=2*BigBox->xiaoquByColor();
					s+=BigBox->xiaoqu();
				}
				if(s!=0){
					pDoc->score+=Score(s);
					if(pDoc->score%100>0){
						
						killTimer();
						setTimer();
					}
					
				}
				
				this->upDateMoveAndNextBox();
			}else{
				
				
				MoveBox->moveDown();
				switch(GetDocument()->mode){
				case CXY:
					
					if(GetDocument()->Num==1&&isEatFood(MoveBox,BigBox)){
						
					}else if(GetDocument()->Num==2){
						
						isMeetBlock(MoveBox,BigBox);
					}
					break;
				}
			}
			
			
		}
		
		
		
		
		
		
		
	}
	
	else if(nIDEvent==2){
		GetDocument()->tick++;
		
		
	}else if(nIDEvent==3){
		
		
		
	}
	this->Invalidate();
	CView::OnTimer(nIDEvent);
}





void CTeris_1View::upDateMoveAndNextBox()
{
	CTeris_1Doc* pDoc = GetDocument();
	pDoc->box.RemoveAt(1);
	CBox *tmp=(CBox *)pDoc->box.GetAt(1);
	tmp->NextResetMove();
	//delete tmp;
	if(GetDocument()->mode==CXY){
		
		CBox *b=(CBox *)pDoc->box.GetAt(0);
		b->LOCAL[CXYx][CXYy].canSee=SEE;
		switch(GetDocument()->Num){
			
		case 1:
			
			
			setFood();
			break;
		case 2:
			setBlock();
			break;
			
			
		}
		
	}
	initialNextBox();
}



void CTeris_1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(GetDocument()->mode==XMXX)
		return;
	
	CTeris_1Doc* pDoc = GetDocument();
	if(GetDocument()->box.GetSize()!=3)
		return ;
	
	if(nChar==VK_SPACE&&GetDocument()->mode==REVERSE){
		(	(CBox *)GetDocument()->box.GetAt(0))->reverse();
		this->Invalidate();
		return ;
	}
	if(nChar==VK_RETURN){
		if(flag){
			setTimer();
		}else{
			killTimer();
			
			
		}
		flag=!flag;
		
		
	}
	if(!flag)
		if(pDoc->box.GetSize()==3){
			CBox *moveBox=(CBox *)pDoc->box.GetAt(1);
			CBox *BigBox=(CBox *)pDoc->box.GetAt(0);
			switch(nChar){
			case VK_UP:
				if(!moveBox->isRotateTouch(BigBox))
					moveBox->rotate();
				break;
			case VK_LEFT:
				if(!moveBox->isLeftTouch(BigBox))
					moveBox->moveLeft();
				
				break;
			case VK_RIGHT:
				if(!moveBox->isRightTouch(BigBox))
					moveBox->moveRight();
				break;
			case VK_DOWN:
				if(!moveBox->isDownTouch(BigBox))
					moveBox->moveDown();
				break;
				
				
				
				
			}
			this->Invalidate();
		}
		
		CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL CTeris_1View::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return true;
	return CView::OnEraseBkgnd(pDC);
}

int CTeris_1View::Score(int i)
{
	
	if(i==1)
		return 10*i;
	else if(i>1&&i<4)
		return 20*i;
	else if(i==4)
		return 30*i;
	else {
		
		return 40*i;
	}
}





void CTeris_1View::setTimer()
{
	CTeris_1Doc* pDoc = GetDocument();
	SetTimer(2,1000,NULL);
	
	if(GetDocument()->mode==XMXX){
		
		return ;
		
		
	}else{
		if(pDoc->score<1500)
			SetTimer(1,500-(pDoc->score/5),NULL);
	}
}

void CTeris_1View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(isMake==TRUE){
		
		if(GetDocument()->box.GetSize()==3){
			
			CBox *BigBox=(CBox *)GetDocument()->box.GetAt(0);
			for(int i=0;i<BigBox->LOCAL.size();i++)
				for(int j=0;j<BigBox->LOCAL[0].size();j++)
					if(
						isIn(BigBox->LOCAL[i][j].local,point,BigBox->LOCAL[i][j].halfSize)
						){
						
						BigBox->LOCAL[i][j].brushColor=makecolor;
						
						BigBox->LOCAL[i][j].canSee=BACKSEE;
						return ;
						
						
						
					}
					
		}
		this->Invalidate();
		
		
	}
	if(GetDocument()->mode==XMXX){
	
		XMXXSHOWXIAO(point);
		this->Invalidate();
	
	}
	CView::OnLButtonDown(nFlags, point);
}

void CTeris_1View::OnMaketeris() 
{
	// TODO: Add your command handler code here
	
	isMake=TRUE;
	killTimer();
	
	
}

BOOL CTeris_1View::isIn(CPoint a, CPoint b, int c)
{
	int MaxX= a.x>b.x ? a.x:b.x ;
	
	int MinX= a.x+b.x-MaxX;
	
	int MaxY= a.y>b.y ? a.y:b.y;
	
	int MinY= a.y+b.y-MaxY;
	
	if(MaxX-MinX<c)
		if(MaxY-MinY<c)
			return TRUE;
		
		return FALSE;
		
}



BOOL CTeris_1View::isGkWin()
{
	
	CBox *box=(CBox *)GetDocument()->box.GetAt(0);
	for(int i=0;i<box->LOCAL.size();i++)
		for(int j=0;j<box->LOCAL[0].size();j++)
			if(box->LOCAL[i][j].brushColor==MAKETERISCOLOR)
				return FALSE;
			
			return TRUE;
			
}

void CTeris_1View::OnGkmode() 
{
	// TODO: Add your command handler code here
	GetDocument()->mode=GK;
	GetDocument()->Num=1;
	this->OnNewgame();
	
	
	
	
	
	
}

void CTeris_1View::OnUpdateGkmode(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(GetDocument()->mode==GK)
		pCmdUI->Enable(false);
	
}
void CTeris_1View::StartNormal(){
	
	
	//	CString s;
	//	AfxGetMainWnd()->PostMessage(ID_FILE_NEW,0,0);
	//	int i=rand()%2;
	//	s.Format("N1.dat");
	//	GetDocument()->OnOpenDocument(s);
	GetDocument()->mode=NORMAL;
	GetDocument()->DeleteContents();
	this->initialBigBox();
	this->initialMoveBox();
	this->initialNextBox();
	//	GetDocument()->score=0;
	this->Invalidate();
	MessageBox("平凡的方块，为了纪念最经典的模式");
	flag=TRUE;
	
	
	
}


void CTeris_1View::StartGk()
{
	
	CString s;
	s.Format("G%d.dat",GetDocument()->Num);
	GetDocument()->OnOpenDocument(s);
	GetDocument()->mode=GK;
    GetDocument()->score=0;
	this->Invalidate();
	MessageBox("通关的方式，就是把蓝色的方块消去。");
	flag=TRUE;
	
	
}

void CTeris_1View::OnGkChoose() 
{
	// TODO: Add your command handler code here
	
	GetDocument()->mode=GK;
	GkSelectDlg g;
	killTimer();
	MessageBox("输入1-10");
	if(g.DoModal()==IDOK){
		
		//	g.UpdateData(true);
		//		CString s;
		//	s.Format("%d",g.m_Num);
		//	MessageBox(s);
		
		GetDocument()->Num=(g.m_Num)%11;
		this->OnNewgame();
		
		
	}
	
}

void CTeris_1View::again()
{
    killTimer();
	AgainDlg a;
	CString s;
	switch(GetDocument()->mode){
	case GK:
		break;
	case NORMAL:
		
		s.Format("你的得分是：%d!",GetDocument()->score);
		MessageBox(s);
		
		break;
	case QPZ:
		break;
	case LIFE:
		break;
		
	}
	if(a.DoModal()==IDOK){
		GetDocument()->score=0;
		this->OnNewgame();
		
			 }else{
		AfxGetMainWnd()->PostMessage(WM_CLOSE, 0, 0); 
			 }
			 
			 
}

void CTeris_1View::GkCheck()
{
	if(this->isGkWin()==TRUE){
		
		killTimer();
		CPassDlg dlg;
		MessageBox("恭喜过关!");
		
		if(dlg.DoModal()==IDOK){
			
			GetDocument()->Num+=1;
			if(GetDocument()->Num==11){
				
				MessageBox("NB!恭喜你通过第十关，试试强迫症？");
				OnQpzmode();
				
			}else{
				
				this->OnNewgame();
				return ;
			}
			
		}else{
			
			AfxGetMainWnd()->PostMessage(WM_CLOSE, 0, 0); 
			
		}
	}
	
	
	
}





void CTeris_1View::OnNewgame() 
{
	// TODO: Add your command handler code here
	killTimer();

	
	GetDocument()->tick=0;
	this->readRecord();

    switch(GetDocument()->mode){
		
	case NORMAL:
		this->StartNormal();
		break;
	case GK:
		this->StartGk();
		break;
	case QPZ:
		this->StartQPZ();
		
		break;
	case CXY:
		//
		//GetDocument()->Num=2;
		this->StartCXY();
		break;
	case REVERSE:
		this->StartReverse();
		break;
	case LIFE:
		this->StartLife();
		break;
	case XMXX:
		this->StartXmxx();
		break;
		
		
		
		
	}
	
	
}

void CTeris_1View::OnQpzmode() 
{
	// TODO: Add your command handler code here
    GetDocument()->mode=QPZ;
	GetDocument()->Num=1;
	this->OnNewgame();
	
	
}

void CTeris_1View::OnUpdateQpzmode(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(GetDocument()->mode==QPZ){
		
		pCmdUI->Enable(FALSE);
	}
}

void CTeris_1View::StartQPZ()
{
	int i=GetDocument()->Num;
	flag=TRUE;  
	CString s;
	s.Format("QPZ%d.dat",i);
	GetDocument()->OnOpenDocument(s);
    GetDocument()->score=0;
	GetDocument()->mode=QPZ;
	this->Invalidate();
	flag=TRUE;
	
	if(i==2){
		MessageBox("Z字方块，消不掉的痛\r更痛的是，同色才会被消去。\r欢迎你来到强迫症的世界。\r本关目标只是10分，\r看起来蛮简单的,试试吧!") ;
	}else if(i==1){
		MessageBox("强迫症患者都喜爱整整齐齐,同行颜色一样\r，于是作者很想一直掉下来的都是O字方块,\r很不幸，作者设计的是15宽的。\r本关目标是100分.") ;
		
	}else if(i==3){
		MessageBox("每一个玩俄罗斯方块的人都喜欢长条消去四行，\r作者也这么认为.\r在别的俄罗斯方块都似乎没有只出长条这个选项。\r但是在这里，你可以.\r可惜，你玩的模式是强迫症，摸索一下吧。\r目标100分");
		
	}else if(i==4){
		
		MessageBox("相信你已经摸索到规律了。\r目标100分");
		
	}else if(i==5){
		MessageBox("我相信，在这关你会觉得强迫症真的很懊恼。\r目标100分");
		
	}else if(i==6){
		
		MessageBox("废话不多，目标100分");
		
	}else if(i==7){
		
		MessageBox("相信你玩了好几关，你好像没以前那么爱长条了。\r没关系，这是长条的最后一关。\r目标100分");
	}
	
}



void CTeris_1View::QPZCheck()
{
	if(isQPZWin()){
		
		killTimer();
		MessageBox("很不错！强迫症的烦恼又解决了一个。\r但是作者是强迫症患者，来看看下一个强迫症的烦恼？");
		
		GetDocument()->Num+=1;
		GetDocument()->score=0;
		
		if(GetDocument()->Num==8){
			
			MessageBox("能走到这关，真不错。");
		}else{
			this->OnNewgame();
			
			
		}
		
	}
	
}

BOOL CTeris_1View::isQPZWin()
{
	
	if(GetDocument()->score==0)
		return FALSE;
	if(GetDocument()->score>=QPZSCORE())
		return TRUE;
	CBox *b=(CBox *)GetDocument()->box.GetAt(0);
	for(int i=0;i<b->LOCAL.size();i++)
		for(int j=0;j<b->LOCAL[0].size();j++)
			if(b->LOCAL[i][j].canSee==BACKSEE)
				return FALSE;
			return TRUE;
}

void CTeris_1View::OnSetcolorfk1() 
{
	// TODO: Add your command handler code here
	this->makecolor=FKC1;
}

void CTeris_1View::OnSetcolorfk2() 
{
	// TODO: Add your command handler code here
	this->makecolor=FKC2;
}

void CTeris_1View::OnSetcolorfk3() 
{
	// TODO: Add your command handler code here
	this->makecolor=FKC3;
}

void CTeris_1View::OnSetcolorfk4() 
{
	// TODO: Add your command handler code here
	this->makecolor=FKC4;
	
}

int CTeris_1View::QPZSCORE()
{
	
	int n=	GetDocument()->Num;
	int score=0;
	switch(n){
		
	case 1:
		score=100;
		break;
	case 2:
		score=10;
		break;
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
		score=100;
		break;
		
		
	}
	return score;
}

void CTeris_1View::OnUpdateMaketeris(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CTeris_1View::OnQpzChoose() 
{
	// TODO: Add your command handler code here
	GkSelectDlg s; 
	MessageBox("输入1-6");
	if(s.DoModal()==IDOK){
		
		GetDocument()->Num=s.m_Num%7;
		GetDocument()->mode=QPZ;
	}
	this->OnNewgame();
	
}

void CTeris_1View::ReverseCheck()
{
	if(isReverseWin()){
		
		killTimer();
		if(GetDocument()->Num<=2){
			
			MessageBox("恭喜通关，so easy!");
			GetDocument()->Num+=1;
			
			this->OnNewgame();
		}
		else{
			
			MessageBox("暂时这样子！");
		}
		
	}
	
}

BOOL CTeris_1View::isReverseWin()
{
	CBox *p=(CBox *)GetDocument()->box.GetAt(0);
	for(int j=0;j<p->LOCAL[0].size();j++){
		for(int i=0;i<p->LOCAL.size();i++)
			if(p->LOCAL[i][j].brushColor!=FKC3)
				break;
			
			if(i==p->LOCAL.size())
				return TRUE;
			
	}
	
	
	return FALSE;
	
}

void CTeris_1View::CXYCheck()
{
	
	if(isCXYWin()){
		
		killTimer();
		MessageBox("程先生的游戏。是不是很有趣？下一关更有爱");
		
		GetDocument()->Num+=1;
		GetDocument()->score=0;
		
		if(GetDocument()->Num==4){
			
			MessageBox("暂时就这样子");
		}else{
			StartCXY();
		}
		
	}else{
		CBox *p=(CBox *)GetDocument()->box.GetAt(0);
		for(int i=0;i<p->LOCAL.size();i++)
			for(int j=0;j<6;j++){
				if(p->LOCAL[i][j].canSee==BACKSEE)
					p->LOCAL[i][0].canSee=BACKSEE;
			}
			
			
			
			
	}
	
	
}

BOOL CTeris_1View::isCXYWin()
{
	if(GetDocument()->score%1024==0&&GetDocument()->score>0)
		return TRUE;
	return FALSE;
}

void CTeris_1View::StartCXY()
{
	
	GetDocument()->DeleteContents();
	this->initialBigBox();
	this->initialMoveBox();
	this->initialNextBox();
	GetDocument()->mode=CXY;
	GetDocument()->score=0;
	this->Invalidate();
	flag=TRUE;
	switch(GetDocument()->Num){
	case 1://贪吃蛇
		
		MessageBox("我相信，贪吃蛇，你一定玩过.\r但是，贪吃的俄罗斯方块你玩过吗？\r程先生是一个很奇怪的人.\r所以他设计的方块很奇怪\rtips:通关当且仅当获得1024分.");
		setFood();		
		break;
	case 2://黑洞模式
		MessageBox("有一天，程先生想到一个奇怪的游戏。");
		setBlock();
		break;
	case 4://坦克大战
		MessageBox("小时候，程先生有一台小霸王。\r里面有一个游戏叫做，坦克大战。\rtips:通关当且仅当获得1024分");
		break;
	case 3://华容道
		MessageBox("相信你已经觉得程先生是一个想象力丰富的人.\r所以，你应该知道，这一关，应该不同");
		break;
	}
	
}

void CTeris_1View::OnNormal() 
{
	// TODO: Add your command handler code here
	GetDocument()->mode=NORMAL;
	this->OnNewgame();
	
}

void CTeris_1View::OnUpdateNormal(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if(GetDocument()->mode==NORMAL){
		
		pCmdUI->Enable(false);
	}
}

void CTeris_1View::OnCxyBegin() 
{
	// TODO: Add your command handler code here
	GetDocument()->mode=CXY;
	GetDocument()->Num=1;
	this->OnNewgame();
	
}

void CTeris_1View::OnUpdateCxyBegin(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(GetDocument()->mode==CXY){
		
		pCmdUI->Enable(FALSE);
	}
	
}

void CTeris_1View::setFood()
{
	//设置食物
	
	CBox * b=(CBox *)GetDocument()->box.GetAt(0);
	CXYx=rand()%(b->LOCAL.size());
	CXYy=3+rand()%3;
	int x=CXYx;
	int y=CXYy;
	
	//CBox * b=(CBox *)GetDocument()->box.GetAt(0);
	if(b->LOCAL[x][y].canSee==SEE)
		b->LOCAL[x][y].canSee=FOODSEE;
	
}

BOOL CTeris_1View::isEatFood(CBox *moveBox, CBox *bigBox)
{
				
				for(int k=0;k<moveBox->LOCAL.size();k++)
					for(int m=0;m<moveBox->LOCAL[0].size();m++)
						if(bigBox->LOCAL[CXYx][CXYy].canSee==FOODSEE&&bigBox->LOCAL[CXYx][CXYy].local==moveBox->LOCAL[k][m].local&&moveBox->LOCAL[k][m].canSee==SEE){
							bigBox->LOCAL[CXYx][CXYy].canSee=SEE;
							GetDocument()->score+=2;
							int c=m;
							while(moveBox->LOCAL[k][m].canSee==SEE){
								
								
								m--;
								if(m==-1){
									break;
								}
								if(	moveBox->LOCAL[k][m].canSee!=SEE)
								{
									moveBox->LOCAL[k][m].canSee=SEE;
									
									return TRUE;
								}
								
								
								
                                
								
								
							}
							
							
							while(moveBox->LOCAL[k][c].canSee==SEE){
								
								c++;
							}
							if(c<5){
								moveBox->LOCAL[k][c].canSee=SEE;
								return TRUE;
								
							}else{
								
								return FALSE;
								
							}
							
							
							
						}
						return FALSE;
						
						
}



void CTeris_1View::StartReverse()
{
	
	
	CString s;
	s.Format("SL%d.dat",GetDocument()->Num);
	GetDocument()->OnOpenDocument(s);
	GetDocument()->mode=REVERSE;
	GetDocument()->score=0;
	this->Invalidate();
	
	if(GetDocument()->Num==1){
		
		
		MessageBox("喜爱红色\r作者是一个热血的少年\r本模式的通关要求仅仅是集齐一行的红色方块。\r tips:作者为了这关特意写了一个神奇的功能\r试试(空格键)吧！");
	}else{
		
		MessageBox("一身热血");
		
	}
	flag=TRUE;
}

void CTeris_1View::StartLife()
{
	
}

void CTeris_1View::OnModeReverse() 
{
	// TODO: Add your command handler code here
	GetDocument()->mode=REVERSE;
	GetDocument()->Num=1;
	this->OnNewgame();
}

void CTeris_1View::OnUpdateModeReverse(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(GetDocument()->mode==REVERSE)
		pCmdUI->Enable(FALSE);
	
}

void CTeris_1View::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	WelDlg w;
	w.DoModal();
	
	GetDocument()->mode=w.mode;
	GetDocument()->score=0;
	GetDocument()->Num=1;
	//读记录
	
	this->OnNewgame();
}



void CTeris_1View::OnSave() 
{
	// TODO: Add your command handler code here
	killTimer();
	flag=TRUE;
	CString s;
	switch(GetDocument()->mode){
		
	case NORMAL:
		s.Format("NRL.dat");
		break;
	case QPZ:
		s.Format("QPL.dat");
		break;
	case LIFE:
		s.Format("LFL.dat");
		break;
	case CXY:
		s.Format("CXYL.dat");
		break;
	case REVERSE:
		s.Format("RL.dat");
		break;
	case GK:
		s.Format("GKL.dat");
		break;
	case XMXX:
		s.Format("XMXXL.dat");
		break;
		
		
	}
	GetDocument()->OnSaveDocument(s);
	MessageBox("保存成功！");
	
}



void CTeris_1View::OnLastNormal() 
{
	// TODO: Add your command handler code here
	killTimer();
	GetDocument()->OnOpenDocument("NRL.dat");
	GetDocument()->mode=NORMAL;
	flag=TRUE;
	
	this->Invalidate();
	MessageBox("读取成功！");
	
}

void CTeris_1View::OnLastLife() 
{
	// TODO: Add your command handler code here
	killTimer();
	GetDocument()->OnOpenDocument("LFL.dat");
	GetDocument()->mode=LIFE;
	flag=TRUE;
	
	this->Invalidate();
	MessageBox("读取成功！");
	
}

void CTeris_1View::OnLastGk() 
{
	// TODO: Add your command handler code here
	killTimer();
	GetDocument()->OnOpenDocument("GKL.dat");
	GetDocument()->mode=GK;
	flag=TRUE;
	
	this->Invalidate();
	MessageBox("读取成功！");
	
}

void CTeris_1View::OnLastCxy() 
{
	// TODO: Add your command handler code here
	killTimer();
	GetDocument()->OnOpenDocument("CXYL.dat");
	GetDocument()->mode=CXY;
	flag=TRUE;
	
	this->Invalidate();
	MessageBox("读取成功！");
	
}

void CTeris_1View::OnLastQpz() 
{
	// TODO: Add your command handler code here
	
	killTimer();
	GetDocument()->OnOpenDocument("QPL.dat");
	GetDocument()->mode=QPZ;
	flag=TRUE;
	
	this->Invalidate();
	MessageBox("读取成功！");
	
}

void CTeris_1View::OnLastReverse() 
{
	// TODO: Add your command handler code here
	
	killTimer();
	GetDocument()->OnOpenDocument("RL.dat");
	GetDocument()->mode=REVERSE;
	flag=TRUE;
	
	this->Invalidate();
	MessageBox("读取成功！");
	
}

void CTeris_1View::OnMODEREVERSESelect() 
{
	// TODO: Add your command handler code here
	GkSelectDlg s;
	MessageBox("输入1-3");
	if(s.DoModal()==IDOK){
		
		GetDocument()->Num=s.m_Num%4;
		GetDocument()->mode=REVERSE;
	}
	this->OnNewgame();
}

void CTeris_1View::OnUpdateLastNormal(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (PathFileExists("NRL.dat"))
	{
		//存在
		pCmdUI->Enable(TRUE);
		
	}
	
    else {
		
		pCmdUI->Enable(FALSE);
		
	}
}

void CTeris_1View::OnUpdateLastGk(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (PathFileExists("GKL.dat"))
	{
		//存在
		pCmdUI->Enable(TRUE);
		
	}
	
    else {
		
		pCmdUI->Enable(FALSE);
		
	}
	
}

void CTeris_1View::OnUpdateLastCxy(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (PathFileExists("CXYL.dat"))
	{
		//存在
		pCmdUI->Enable(TRUE);
		
	}
	
    else {
		
		pCmdUI->Enable(FALSE);
		
	}
	
}

void CTeris_1View::OnUpdateLastLife(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (PathFileExists("LFL.dat"))
	{
		//存在
		pCmdUI->Enable(TRUE);
		
	}
	
    else {
		
		pCmdUI->Enable(FALSE);
		
	}
}

void CTeris_1View::OnUpdateLastQpz(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (PathFileExists("QPL.dat"))
	{
		//存在
		pCmdUI->Enable(TRUE);
		
	}
	
    else {
		
		pCmdUI->Enable(FALSE);
		
	}
}

void CTeris_1View::OnUpdateLastReverse(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (PathFileExists("RL.dat"))
	{
		//存在
		pCmdUI->Enable(TRUE);
		
	}
	
    else {
		
		pCmdUI->Enable(FALSE);
		
	}
}

void CTeris_1View::SetRecord()
{
	killTimer();
	
	if(GetDocument()->score>topNum){
			RecordDlg r;
		switch(GetDocument()->mode){
			
			
			
		case XMXX:
		
			if(r.DoModal()==IDOK){
				
				topNum=GetDocument()->score;
				CString m;
				
				m.Format("%s %d ",r.m_Name,topNum);
				std::ofstream ofs("r2.txt");
				ofs.write(m,strlen(m));
				ofs.close();
				
			}
			this->again();
			
			
			
			break;
			
			
		default:
			
			
			if(r.DoModal()==IDOK){
				topNum=GetDocument()->score;
				CString m;
				
				m.Format("%s %d ",r.m_Name,topNum);
				std::ofstream ofs("r1.txt");
				ofs.write(m,strlen(m));
				ofs.close();
				
			}
			this->again();
			break;
			
		}
		
	}
}



void CTeris_1View::readRecord()
{
	CString rrr;
	if(GetDocument()->mode!=XMXX){

		rrr=_T("r1.txt");
		
	}else{
		
		rrr=_T("r2.txt");
	
	}
	std::ifstream ifs(rrr);
	char ch[100];
	memset(ch,0,100);
	ifs.read(ch,100);
	int i=0;
	TopName="";
	//TopName.Format("%s",ch);
	while(ch[i]!=' '){
		
		TopName.Insert(i,ch[i]);
		i++;
	}
	i++;
	topNum=0;
	while(ch[i]!=' '){
		topNum=10*topNum+(ch[i]-'0');
		i++;
	}
	
	ifs.close();
	
	
}

void CTeris_1View::killTimer()
{
	KillTimer(1);
	KillTimer(2);
	KillTimer(3);
	
}

void CTeris_1View::setBlock()
{
	
	
	CBox * b=(CBox *)GetDocument()->box.GetAt(0);
	CXYx=rand()%(b->LOCAL.size());
	CXYy=3+rand()%3;
	int x=CXYx;
	int y=CXYy;
	
	//CBox * b=(CBox *)GetDocument()->box.GetAt(0);
	if(b->LOCAL[x][y].canSee==SEE)
		b->LOCAL[x][y].canSee=BLOCKSEE;
	
}

BOOL CTeris_1View::isMeetBlock(CBox *m, CBox *b)
{
	
	return FALSE;
}


void CTeris_1View::StartXmxx()
{
	xmxxscore=0;
	if(GetDocument()->box.GetSize()>=1){
	delete (CBox *)GetDocument()->box.GetAt(0);
     GetDocument()->box.RemoveAt(0);
	}
	
	this->initialBigBox2();
	if(GetDocument()->Num==1){
	
		MessageBox("我不相信你没有玩过这个游戏，\r其实和俄罗斯方块扯不上太大的关系。");
	
	}
	CBox *b=(CBox *)GetDocument()->box.GetAt(0);
	int i,j;
	int p;
	for(i=1;i<11;i++)
		for(j=b->LOCAL[0].size()-2;j+10>b->LOCAL[0].size()-2;j--){
			
			b->LOCAL[i][j].canSee=XXSEE;

			//srand( (unsigned)time( NULL ) );
			p=rand()%5;
			b->LOCAL[i][j].brushColor=COLORXX[p];
		}
		
		this->Invalidate();
		
		
}

void CTeris_1View::XMXXCheck()
{
	if(XMXXOver()==TRUE){
		killTimer();
		CBox *b=(CBox *)GetDocument()->box.GetAt(0);
		int i,j;
			int count=0;
			for(i=1;i<11;i++)
				for(j=8;j<=17;j++){
			     if(b->LOCAL[i][j].canSee==XXSEE){
				  count++;
				 }
				}
				
				xmxxscore=-count;
				GetDocument()->score+=GetXXOverScore(count);
				DrawXX(GetDC());
				//this->Invalidate();
		if(GetDocument()->score>=XMXXSCORE()){
	

		
		GetDocument()->Num++;
		MessageBox("Congratulation!");
		this->OnNewgame();
	
	
		}else{
			if(GetDocument()->score>topNum)
 
			{
			
				SetRecord();
				
			}

		
		
		}
	

	}
}

void CTeris_1View::DrawXX(CDC *pDC)
{
	CRect   rect; 
	GetClientRect(&rect); 
	CDC dcMem;      //用于缓冲作图的内存DC 
	dcMem.CreateCompatibleDC(pDC);      //依附窗口DC创建兼容内存DC
	CBitmap     bmp; //内存中承载临时图象的位图
	bmp.CreateCompatibleBitmap(pDC, rect.Width() , rect.Height() ); //创建兼容位图 
	dcMem.SelectObject(&bmp); //将位图选择进内存DC 
	dcMem.FillSolidRect(rect, pDC->GetBkColor()); //
	
	CTeris_1Doc* pDoc = GetDocument();
	CBox *tmp=NULL;
	
	tmp=(CBox *)pDoc->box.GetAt(0);
	tmp->Draw(&dcMem);
	CString score;
	score.Format("得分：%d",pDoc->score);
	dcMem.SelectStockObject(NULL_BRUSH);
	CPen pen2(PS_SOLID,2,DARKGREEN);
	dcMem.SelectObject(&pen2);
	CString s;
	s.Format("最高记录：%s %d分",TopName,topNum);
	dcMem.TextOut(465,280,s);
	dcMem.TextOut(500,300,score);
	if(xmxxscore>0){
		
	s.Format("%d个 %d分",xmxxscore,xmxxscore*xmxxscore*5);
	dcMem.TextOut(150,100,s);
	}else if(xmxxscore<0){
		xmxxscore=-xmxxscore;
		s.Format("剩余%d个 ,额外奖励%d分",xmxxscore,GetXXOverScore(xmxxscore) );
	dcMem.TextOut(150,100,s);
	
	
	}
	dcMem.TextOut(500,500,"By yaolong.");
	dcMem.TextOut(500,520,"2013/12/28.");
	//dcMem.TextOut(465,400,"开始、暂停请按ENTER");
    s.Format("     本关要求：%d",(this->XMXXSCORE()));
	dcMem.TextOut(465,250,s);
	dcMem.Rectangle(450,0,620,200);
	dcMem.Rectangle(450,0,620,569);
	
	pDC->BitBlt(0,0,rect.Width(),rect.Height(), &dcMem ,0,0,SRCCOPY); 
	dcMem.DeleteDC(); //删除DC 
	bmp.DeleteObject(); //删除位图 
	
}

int CTeris_1View::XMXXSCORE()
{

	return 1000+(GetDocument()->Num-1)*3000;

}

void CTeris_1View::XMXXSHOWXIAO(CPoint point)
{

	CBox *BigBox=(CBox *)GetDocument()->box.GetAt(0);
		for(int i=0;i<BigBox->LOCAL.size();i++)
				for(int j=0;j<BigBox->LOCAL[0].size();j++)
					if(isIn(BigBox->LOCAL[i][j].local,point,BigBox->LOCAL[i][j].halfSize)){
						
					//	BigBox->LOCAL[i][j].brushColor=makecolor;
						
						if(BigBox->LOCAL[i][j].canSee==XXSEE){
						
							resetXX(BigBox);
							if(BigBox->LOCAL[i][j].brushColor==BigBox->LOCAL[i-1][j].brushColor||BigBox->LOCAL[i][j].brushColor==BigBox->LOCAL[i+1][j].brushColor
								||BigBox->LOCAL[i][j].brushColor==BigBox->LOCAL[i][j-1].brushColor||BigBox->LOCAL[i][j].brushColor==BigBox->LOCAL[i][j+1].brushColor)
							{
								xmxxscore=setCANXIAO(i,j);
								/*
								CString sss;
								sss.Format("%d",zz);
								this->GetDC()->TextOut(100,100,sss);
								*/
								
							    
							}
						
						}
						else if(BigBox->LOCAL[i][j].canSee==XXCANXIAO){
							int sb=XIAOXX(i,j);
							GetDocument()->score+=sb*sb*5;
							MOVEXX();


						
						}
						this->Invalidate();
						return ;

						
						
						
					}

}

void CTeris_1View::resetXX(CBox *p)
{
	xmxxscore=0;
	for(int i=0;i<p->LOCAL.size();i++)
		for(int j=0;j<p->LOCAL[0].size();j++)
			if(p->LOCAL[i][j].canSee==XXCANXIAO)
				p->LOCAL[i][j].canSee=XXSEE;


}

int CTeris_1View::setCANXIAO(int i, int j)
{

	int count;
	CBox *p=(CBox *)GetDocument()->box.GetAt(0);
	if(p->LOCAL[i][j].canSee==XXSEE){
	    count=1;
		p->LOCAL[i][j].canSee=XXCANXIAO;
		if(p->LOCAL[i][j].brushColor==p->LOCAL[i-1][j].brushColor)
			count+=setCANXIAO(i-1,j);
		if(p->LOCAL[i][j].brushColor==p->LOCAL[i+1][j].brushColor)
			count+=setCANXIAO(i+1,j);
		if(p->LOCAL[i][j].brushColor==p->LOCAL[i][j-1].brushColor)
			count+=setCANXIAO(i,j-1);
		if(p->LOCAL[i][j].brushColor==p->LOCAL[i][j+1].brushColor)
			count+=setCANXIAO(i,j+1);
		return count;

	}
	else return 0;

}

int CTeris_1View::XIAOXX(int i,int j)
{
	int count=0;
	CBox *p=(CBox *)GetDocument()->box.GetAt(0);
	if(p->LOCAL[i][j].canSee==XXCANXIAO){
	  
		count=1;
	
		p->LOCAL[i][j].canSee=XXBKSEE;
		
		if(p->LOCAL[i][j].brushColor==p->LOCAL[i-1][j].brushColor)
			count+=XIAOXX(i-1,j);
		if(p->LOCAL[i][j].brushColor==p->LOCAL[i+1][j].brushColor)
			count+=XIAOXX(i+1,j);
		if(p->LOCAL[i][j].brushColor==p->LOCAL[i][j-1].brushColor)
			count+=XIAOXX(i,j-1);
		if(p->LOCAL[i][j].brushColor==p->LOCAL[i][j+1].brushColor)
			count+=XIAOXX(i,j+1);
		
		p->LOCAL[i][j].brushColor=XXBK;
		p->LOCAL[i][j].penColor=XXBK;
		this->Invalidate();
		return count;

	}
	else return 0;


}

void CTeris_1View::MOVEXX()
{
	CBox *b=(CBox *)GetDocument()->box.GetAt(0);
	int i,j;
	for(i=1;i<11;i++)
		for(j=8;j<=17;j++){
			
			if(b->LOCAL[i][j].canSee==XXBKSEE){

			
				int k=j;
				while(k!=8){
				b->LOCAL[i][k-1].swap(b->LOCAL[i][k]);
				k--;
				}
				
				
				
			
			}
			
		}
		for(i=1;i<=10;i++){
		
			if(b->LOCAL[i][17].canSee==XXBKSEE){
			
				for(j=8;j<=17;j++){
					int k=i+1;
					while(b->LOCAL[k][17].canSee==XXBKSEE&&k<=10){
					k++;
					}
					if(k<=10)
					b->LOCAL[i][j].swap(b->LOCAL[k][j]);
				
				}
			
			}
		
		}
		xmxxscore=0;
	this->Invalidate();

}

BOOL CTeris_1View::XMXXOver()
{
	CBox *BigBox=(CBox *)GetDocument()->box.GetAt(0);
	for(int i=1;i<=10;i++)
		for(int j=8;j<=17;j++)
		{
		if(BigBox->LOCAL[i][j].canSee!=XXBKSEE)
		if(	(BigBox->LOCAL[i][j].brushColor==BigBox->LOCAL[i-1][j].brushColor&&BigBox->LOCAL[i-1][j].canSee!=XXBKSEE)
			||(BigBox->LOCAL[i][j].brushColor==BigBox->LOCAL[i+1][j].brushColor&&BigBox->LOCAL[i+1][j].canSee!=XXBKSEE)					
			||(BigBox->LOCAL[i][j].brushColor==BigBox->LOCAL[i][j-1].brushColor&&BigBox->LOCAL[i][j-1].canSee!=XXBKSEE)
			||(BigBox->LOCAL[i][j].brushColor==BigBox->LOCAL[i][j+1].brushColor&&BigBox->LOCAL[i][j+1].canSee!=XXBKSEE) )
			return FALSE;
							
		}
		return TRUE;



}

int CTeris_1View::GetXXOverScore(int i)
{
	switch(i){
	case 0:
		return 2000;break;
	case 1:return 1980;break;
	case 2:return 1920;break;
	case 3:return 1820;break;
	case 4:return 1680;break;
	case 5:return 1500;break;
	case 6:return 1280;break;
	case 7:return 1020;break;
	case 8:return 720;break;
	case 9:return 380;break;
	default:
		return 0;
	
	}
//	return 0;
	


}

void CTeris_1View::OnModeXmxx() 
{
	// TODO: Add your command handler code here
	GetDocument()->mode=XMXX;
	GetDocument()->Num=1;
	this->OnNewgame();
}

void CTeris_1View::OnUpdateModeXmxx(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(	GetDocument()->mode==XMXX){
	
		pCmdUI->Enable(FALSE);
	}else{
	
		pCmdUI->Enable(TRUE);
	
	}
	
}

void CTeris_1View::OnLastXmxx() 
{
	// TODO: Add your command handler code here
	
	killTimer();
	GetDocument()->OnOpenDocument("XMXXL.dat");
	GetDocument()->mode=XMXX;
	flag=TRUE;
	
	this->Invalidate();
	MessageBox("读取成功！");
	
}

void CTeris_1View::OnUpdateLastXmxx(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here9
	if (PathFileExists("XMXXL.dat"))
	{
		//存在
		pCmdUI->Enable(TRUE);
		
	}
	
    else {
		
		pCmdUI->Enable(FALSE);
		
	}
}
