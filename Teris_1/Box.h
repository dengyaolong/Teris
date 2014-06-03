// Box.h: interface for the CBox class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOX_H__59B077F0_0CB3_4FDE_98D7_124CBBEC90CE__INCLUDED_)
#define AFX_BOX_H__59B077F0_0CB3_4FDE_98D7_124CBBEC90CE__INCLUDED_



#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//类型
#ifndef _DENGYAOLONG_TYPE_
#define BIGBOX   1
#define MOVEBOX  2
#define NEXTBOX  3
#define BOX_O    1
#define BOX_S    2
#define BOX_T    3
#define BOX_Z    4
#define BOX_L    5
#define BOX_J    6
#define BOX_I    7
        
#define _DENGYAOLONG_TYPE_
#endif
//大小

#ifndef _DENGYAOLONG_SIZE
#define WLNUMBER         5                           //左宽多少个
#define WRNUMBER         5                           //右宽多少个
#define WMNUMBER         5                           //中宽多少个
#define WNUMBER         (WLNUMBER+WMNUMBER+WRNUMBER)  //总款
#define HNUMBER         19                           //高多少个
#define MOVEWNUMBER     WMNUMBER                      //移动的box的数目
#define MOVEHNUMBER     WMNUMBER
#define NEXTWNUMBER     MOVEWNUMBER                  //预示的box的数目
#define NEXTHNUMBER     MOVEHNUMBER
#define TERISHALFSIZE   15                 //半长
#define TERISSIZE       (2*TERISHALFSIZE)    //方块SIZE
#define _DENGYAOLONG_SIZE
#endif  

//旋转类型
#ifndef _DENGYAOLONG_ROTATE
#define _DENGYAOLONG_ROTATE

#define ROTATELEFT 1
#define ROTATERIGHT 2
#endif

//边界
#ifndef _DENGYAOLONG_BOARD_
#define MOVE_BEGIN_X     WLNUMBER*TERISSIZE
#define MOVE_BEGIN_Y     (-2*TERISSIZE)
#define BACK_TRIS_UP     0
#define BACK_TRIS_DOWN   (HNUMBER*TERISSIZE-TERISHALFSIZE)
#define BACK_TRIS_LEFT    TERISHALFSIZE
#define BACK_TRIS_RIGHT   (WNUMBER*TERISSIZE-TERISHALFSIZE)
#define BOARD_UP         0
#define BOARD_DOWN       (HNUMBER*TERISSIZE)
#define BOARD_LEFT       0
#define BOARD_RIGHT      (WNUMBER*TERISSIZE)
#define NEXT_LOCAL_X     (BOARD_RIGHT)
#define NEXT_LOCAL_Y     (BOARD_UP+TERISSIZE)
#define SCORE_LOCAL_X      (MOVE_BEGIN_X+TERISSIZE)
#define SCORE_LOCAL_Y      (BOARD_DOWN+5*TERISSIZE)
#define _DENGYAOLONG_BOARD_
#endif
//方向
#ifndef _DENGYAOLONG_DIRECT_
#define UP     1
#define DOWN   2
#define LEFT   3
#define RIGHT  4
#define RANDDIRECTION   5
#define _DENGYAOLONG_DIRECT_
#endif
//速度
#ifndef _DENGYAOLONG_SPEED
#define SLOW         1
#define SOSO         2   
#define FAST         3
#define VERYFAST     4
#define MOSTFAST     5
#define _DENGYAOLONG_SPEED
#endif
//属性改变
#ifndef  _DENGYAOLONG_CHANGE_
#define   UNMOVE     0
#define   MOVE       1
#define   DEAD       0
#define   LIVE       1
#define   UNSEE      0
#define   SEE        1
#define   BACKSEE    2
#define   FOODSEE    3
#define   BLOCKSEE   4
#define   XXCANXIAO  5
#define   XXSEE      6
#define   XXBKSEE    7
#define   UNROTATE   0
#define   ROTATE     1
#define  _DENGYAOLONG_CHANGE_
#endif
//颜色
#ifndef _DENGYAOLONG_COLOR_
#define NULLCOLOR    -2
#define RANDCOLOR    -1
//#define BACKGROUAND_BRUSHCOLOR   RGB(3,137,161)
#define BACKGROUAND_BRUSHCOLOR   RGB(204 ,255 ,153)
#define BACKGROUAND_PENCOLOR     NULLCOLOR
#define BLUE          0x00FF0000
#define GREEN         0x0000FF00
#define RED           0x000000FF
#define CYAN          0x00FFFF00
#define MAGENTA       0x00FF00FF
#define YELLOW        0x0000FFFF
#define LIGHTBLUE     0x00FF8080
#define LIGHTGREEN    0x0080FF80
#define LIGHTRED      0x008080FF
#define LIGHTCYAN     0x00FFFF80
#define LIGHTMAGENTA  0x00FF80FF
#define LIGHTYELLOW   0x0080FFFF
#define DARKBLUE      0x00800000
#define DARKGREEN     0x00008000
#define DARKRED       0x00000080
#define DARKCYAN      0x00808000
#define DARKMAGENTA   0x00800080
#define DARKYELLOW    0x00008080
#define WHITE         0x00FFFFFF
#define LIGHTGRAY     0x00D3D3D3
#define GRAY          0x00808080
#define DARKGRAY      0x00404040
#define BLACK         0x00000000
#define BACK1         0x00008081

#define FKC1          0x00FFD803 //天蓝
#define FKC2          0x00FF03CD //紫色
#define FKC3          0x005C03FF //玫瑰红
#define FKC4          RGB(174, 221, 129) //浅绿

#define FKC5          0x0080FFFF
#define FKC6          0x00FF0303
#define MAKETERISCOLOR     0x00FF7403

#define XX1           RGB(0,162,233)
#define XX2           RGB(240,133,25)
#define XX3           RGB(172,206,34)
#define XX4           RGB(228,0,130)
#define XX5           RGB(120,30,243)


#define XXBK          RGB(251,215,163)
/*
#define XX1           RGB(10,162,233)
#define XX2           RGB(240,133,10)
#define XX4           RGB(228,10,130)
#define XX3           RGB(192,106,30)
#define XX5           RGB(140,10,180)
                        // RGB(176,75,135)
#define FKC5          0x000380FF
#define FKC6          0x00FF0303
#define FKC1          0x00FF7403
#define FKC2          0x00FF7403
#define FKC3          0x00FF7403
#define FKC4          0x00FF7403
#define FKC5          0x00FF7403
#define FKC6          0x00FF7403
*/

#define TRISPENCOLOR  RGB(0,0,0)
#define FOODCOLOR     LIGHTRED
#define BLOCKCOLOR    RGB(0,0,0)

const COLORREF COLOR[]={FKC1,FKC2,FKC3,FKC4,FKC4,FKC2};
const COLORREF COLORXX[]={XX1,XX2,XX3,XX4,XX5};
#define _DENGYAOLONG_COLOR_
#endif
#include<vector>
using namespace std;
class CBox : public CObject     //1
{
	DECLARE_SERIAL(CBox)     //3
public:
	CBox();                  //4
	CBox(CBox *box);
	CBox(int type,COLORREF brushColor,COLORREF penColor=RED);
	virtual ~CBox();
	virtual void Serialize(CArchive &ar); //2
	int type;
	int rotatetype;                  //旋转次数
	int FKtype;
	int speed;                      //游戏速度
 	
private:
	//方块
	class  FK{
	public:
		COLORREF brushColor;
		COLORREF penColor;
		int       halfSize;
		CPoint    local;
        int      canSee;
		//拓展
		FK(CPoint l,COLORREF b=RED,COLORREF p=RED,int h=TERISHALFSIZE,int c=SEE):
		                 local(l),brushColor(b),penColor(p)	,halfSize(h),canSee(c){ 
		
		}
						 FK(){}
		void give(FK &a){
		
			a.halfSize=halfSize;
			a.penColor=penColor;
			a.brushColor=brushColor;
			if(canSee!=FOODSEE){
			a.canSee=canSee;
			}else{
			a.canSee=SEE;
			}
		}
		void setCanSee(int s){
			switch(s){
			
			case SEE:
			case UNSEE:
				canSee=s;
				break;
			}
		
		
		}
		void swap(FK &a){
		
		
			FK tmp;
			give(tmp);
			a.give(*this);
			tmp.give(a);
			
		
		}
		
		
		
	
        
	};

public:
	int xiaoquExceptRed();
	void reverse();
	int xiaoquByAllColor();
	int xiaoquByColor();
	BOOL isGk;
	BOOL isLive();
	void xiao(int p);
	int xiaoqu();
	void NextResetMove();
	BOOL isDownTouch(CBox *box);
	BOOL isRotateTouch(CBox *box);
	BOOL isLeftTouch(CBox *box);
	BOOL isRightTouch(CBox *box);
	BOOL JIAO(CBox *box,int direct);
	void GameMove();
	void setSpeed(int Speed);
	void rotateLeft();
	void rotateRight();
	void otherInitial();
	void initialNextBoxBeforeSet();
	void randChange();
	void moveLeft();
	void moveRight();
	void moveDown();
	void add(CBox *box);
	void upDate();
	vector<vector<FK> >  LOCAL;
	void rotate();
	void rotate1();
	void rotate2();
	void setZ();
	void setT();
	void setJ();
	void setL();
	void setS();
	void setO();
	void setI();
	void initialMoveBoxBeforeSet();
	void Draw(CDC *pDC);
	COLORREF penColor;
	COLORREF brushColor;
	void initialNextBox();
	void initialMoveBox();
	void initialBigBox();
	
	

};

#endif // !defined(AFX_BOX_H__59B077F0_0CB3_4FDE_98D7_124CBBEC90CE__INCLUDED_)
