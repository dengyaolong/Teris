// Box.cpp: implementation of the CBox class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Teris_1.h"
#include "Box.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CBox,CObject,1) //5
CBox::CBox()
{
	

}
CBox::CBox(CBox *box){
    int k=box->LOCAL.size();
	for(int i=0;i<k;i++){
	
		vector<FK> tmp;
		for(int j=0;j<k;j++)
			tmp.push_back(box->LOCAL[i][j]);
		LOCAL.push_back(tmp);
			
	
	}
     
	 this->type=box->type;
	 this->FKtype=box->FKtype;


}
CBox::CBox(int type,COLORREF brushColor,COLORREF penColor){

	this->penColor=penColor;
	this->brushColor=brushColor;
	otherInitial();
	
	switch(type){
	
	case BIGBOX:
		this->type=type;
	   initialBigBox();
	   
		break;
	case MOVEBOX:
		this->type=type;
		initialMoveBox();
		
		break;
	case NEXTBOX:
		this->type=type;


		initialNextBox();	
		break;
	default:
		;
	
	}
	
	
	
	


}
CBox::~CBox()
{

}
void CBox::Serialize(CArchive &ar){

	int i,j;
	if(ar.IsStoring()){
	  //ar<<;
		ar<<type;
		for(i=0;i<LOCAL.size();i++)
				for( j=0;j<LOCAL[0].size();j++)
					ar<<LOCAL[i][j].canSee<<LOCAL[i][j].halfSize<<LOCAL[i][j].local<<LOCAL[i][j].penColor<<LOCAL[i][j].brushColor;
				
				ar<<brushColor<<FKtype<<rotatetype<<penColor<<speed;
		
	
	}else{
	  //ar>>;
		   int tmptype,i,j;
		   FK tmp[25][25];
			ar>>tmptype;
			this->type =tmptype;
		
			if(tmptype!=BIGBOX){
			   for(i=0;i<5;i++)
				   for(j=0;j<5;j++)
					   ar>>tmp[i][j].canSee>>tmp[i][j].halfSize
					   >>tmp[i][j].local>>tmp[i][j].penColor>>tmp[i][j].brushColor;

			for(i=0;i<5;i++){
					   vector<FK> t;
					   for(j=0;j<5;j++)
					   t.push_back(tmp[i][j]);  
					   this->LOCAL.push_back(t);
				   
				   }
			
			}else{
				for(i=0;i<15;i++)
				for( j=0;j<19;j++)
					ar>>tmp[i][j].canSee>>tmp[i][j].halfSize
					   >>tmp[i][j].local>>tmp[i][j].penColor>>tmp[i][j].brushColor;
			
				for(i=0;i<15;i++)
				   {
					   vector<FK> t;
					   for(j=0;j<19;j++)
					   t.push_back(tmp[i][j]);
					   
					   this->LOCAL.push_back(t);
				   
				   }
			
			}
			
			
		
			
		ar>>brushColor>>FKtype>>rotatetype>>penColor>>speed;
	
	}

}

//初始化//initial=======================
void CBox::otherInitial()
{
	
	speed=SLOW;
	rotatetype=ROTATERIGHT;

	

}

void CBox::initialBigBox()
{
	
	for(int i=0;i<WNUMBER;i++ ){
		vector<FK> tmp;
		for(int j=0;j<HNUMBER;j++ ){
			
			tmp.push_back(
				FK( CPoint(BOARD_LEFT+i*TERISSIZE+TERISHALFSIZE,BOARD_UP+j*TERISSIZE+TERISHALFSIZE),this->brushColor,this->penColor,TERISHALFSIZE,SEE)
				);
		}
		LOCAL.push_back(tmp);
	}
	

}

void CBox::initialMoveBox()
{

	initialMoveBoxBeforeSet();
//	randChange();
	
	


}

void CBox::initialNextBox()
{
	initialNextBoxBeforeSet();
//	randChange();

	
}
void CBox::initialNextBoxBeforeSet()
{
	for(int i=0;i<NEXTWNUMBER;i++ ){
		vector<FK> tmp;
		for(int j=0;j<NEXTHNUMBER;j++ ){
			
			tmp.push_back(
				FK( 	CPoint(NEXT_LOCAL_X+i*TERISSIZE+TERISHALFSIZE,	NEXT_LOCAL_Y+j*TERISSIZE+TERISHALFSIZE),
				this->brushColor,	this->penColor,	TERISHALFSIZE,	UNSEE)
				);
		}
		LOCAL.push_back(tmp);
	}


}

void CBox::initialMoveBoxBeforeSet(){

	for(int i=0;i<MOVEWNUMBER;i++ ){
		vector<FK> tmp;
		for(int j=0;j<MOVEHNUMBER;j++ ){
			
			tmp.push_back(
				FK( CPoint(MOVE_BEGIN_X+i*TERISSIZE+TERISHALFSIZE,MOVE_BEGIN_Y+j*TERISSIZE+TERISHALFSIZE),
				this->brushColor,this->penColor,TERISHALFSIZE,UNSEE)
				);
		}
		LOCAL.push_back(tmp);
	}

}

//初始化//initial=======================

//set FK========================
//o
void CBox::setO()
{
     LOCAL[1][2].setCanSee(SEE); LOCAL[1][3].setCanSee(SEE);LOCAL[2][2].setCanSee(SEE);LOCAL[2][3].setCanSee(SEE);
}
//z
void CBox::setZ()
{
    LOCAL[1][1].setCanSee(SEE); LOCAL[1][2].setCanSee(SEE);LOCAL[2][2].setCanSee(SEE);LOCAL[2][3].setCanSee(SEE);
}
//L
void CBox::setL()
{
	LOCAL[0][2].setCanSee(SEE);LOCAL[1][2].setCanSee(SEE);LOCAL[2][2].setCanSee(SEE);LOCAL[2][3].setCanSee(SEE);

}
//J
void CBox::setJ()
{
		LOCAL[0][2].setCanSee(SEE);LOCAL[1][2].setCanSee(SEE);LOCAL[2][2].setCanSee(SEE);LOCAL[2][1].setCanSee(SEE);

}
//I
void CBox::setI()
{
	LOCAL[0][2].setCanSee(SEE);LOCAL[1][2].setCanSee(SEE);LOCAL[2][2].setCanSee(SEE);LOCAL[3][2].setCanSee(SEE);
}
//T
void CBox::setT()
{

	LOCAL[2][1].setCanSee(SEE);LOCAL[2][2].setCanSee(SEE);LOCAL[2][3].setCanSee(SEE);LOCAL[1][2].setCanSee(SEE);
}
//S
void CBox::setS()
{

	LOCAL[1][2].setCanSee(SEE);LOCAL[1][3].setCanSee(SEE);LOCAL[2][2].setCanSee(SEE);LOCAL[2][1].setCanSee(SEE);
}
//set FK========================

void CBox::Draw(CDC *pDC)
{



	if(this->type==BIGBOX){
	CPen pen1;
	
	CBrush brush1;
     for(int i=0;i<LOCAL.size();i++)
		 for(int j=0;j<LOCAL[i].size();j++){
			 	
	            
             	brush1.CreateSolidBrush(LOCAL[i][j].brushColor);
             	pen1.CreatePen(PS_SOLID,2,LOCAL[i][j].brushColor);
             	CBrush *oldBrush=pDC->SelectObject(&brush1);
				CPen *oldPen=pDC->SelectObject(&pen1);
			 if(LOCAL[i][j].canSee==SEE||LOCAL[i][j].canSee==FOODSEE){
			 pDC->Rectangle(LOCAL[i][j].local.x-LOCAL[i][j].halfSize,LOCAL[i][j].local.y-LOCAL[i][j].halfSize,
			 LOCAL[i][j].local.x+LOCAL[i][j].halfSize,LOCAL[i][j].local.y+LOCAL[i][j].halfSize);

			 }else if(LOCAL[i][j].canSee==BACKSEE){
				 pen1.DeleteObject();
				 pen1.CreatePen(PS_SOLID,2,TRISPENCOLOR);
				 pDC->SelectObject(&pen1);
			 
              pDC->Rectangle(LOCAL[i][j].local.x-LOCAL[i][j].halfSize,LOCAL[i][j].local.y-LOCAL[i][j].halfSize,
			 LOCAL[i][j].local.x+LOCAL[i][j].halfSize,LOCAL[i][j].local.y+LOCAL[i][j].halfSize);
			 
			 } else if(LOCAL[i][j].canSee==BLOCKSEE){
			 
				  pen1.DeleteObject();
				 pen1.CreatePen(PS_NULL,2,TRISPENCOLOR);
				 pDC->SelectObject(&pen1);
			    brush1.DeleteObject();
				brush1.CreateSolidBrush(BLOCKCOLOR);
				pDC->SelectObject(&brush1);
				 pDC->Rectangle(LOCAL[i][j].local.x-LOCAL[i][j].halfSize,LOCAL[i][j].local.y-LOCAL[i][j].halfSize,
			 LOCAL[i][j].local.x+LOCAL[i][j].halfSize,LOCAL[i][j].local.y+LOCAL[i][j].halfSize);

			 
			 }else if(LOCAL[i][j].canSee==XXSEE){
			     pen1.DeleteObject();
				 pen1.CreatePen(PS_SOLID,2,RGB(0,0,50));
				 pDC->SelectObject(&pen1);
			 
                pDC->Rectangle(LOCAL[i][j].local.x-LOCAL[i][j].halfSize,LOCAL[i][j].local.y-LOCAL[i][j].halfSize,
			    LOCAL[i][j].local.x+LOCAL[i][j].halfSize,LOCAL[i][j].local.y+LOCAL[i][j].halfSize);

			 
			 }else if(LOCAL[i][j].canSee==XXCANXIAO){
			     pen1.DeleteObject();
				 pen1.CreatePen(PS_SOLID,2,RGB(250,250,210));
				 pDC->SelectObject(&pen1);
			 
                pDC->Rectangle(LOCAL[i][j].local.x-LOCAL[i][j].halfSize,LOCAL[i][j].local.y-LOCAL[i][j].halfSize,
			    LOCAL[i][j].local.x+LOCAL[i][j].halfSize,LOCAL[i][j].local.y+LOCAL[i][j].halfSize);

			 
			 }else if(LOCAL[i][j].canSee==XXBKSEE){
				 pen1.DeleteObject();
				 pen1.CreatePen(PS_SOLID,1,XXBK);
				 pDC->SelectObject(&pen1);
			 
                pDC->Rectangle(LOCAL[i][j].local.x-LOCAL[i][j].halfSize,LOCAL[i][j].local.y-LOCAL[i][j].halfSize,
			    LOCAL[i][j].local.x+LOCAL[i][j].halfSize,LOCAL[i][j].local.y+LOCAL[i][j].halfSize);
			 
			 
			 
			 }
			 
			   if(LOCAL[i][j].canSee==FOODSEE){
				 pen1.DeleteObject();
				 pen1.CreatePen(PS_NULL,2,TRISPENCOLOR);
				 pDC->SelectObject(&pen1);
			    brush1.DeleteObject();
				brush1.CreateSolidBrush(FOODCOLOR);
				pDC->SelectObject(&brush1);
				 pDC->Ellipse(LOCAL[i][j].local.x-LOCAL[i][j].halfSize,LOCAL[i][j].local.y-LOCAL[i][j].halfSize,
			 LOCAL[i][j].local.x+LOCAL[i][j].halfSize,LOCAL[i][j].local.y+LOCAL[i][j].halfSize);

			 

			 
			 }
			 brush1.DeleteObject();
			 pen1.DeleteObject();
		     pDC->SelectObject(oldBrush);
			 pDC->SelectObject(oldPen);

			 
		 }
		 
		 
		 


	}
	else{
		CPen pen1(PS_SOLID,2,TRISPENCOLOR);
	CPen *oldPen=pDC->SelectObject(&pen1);
	CBrush brush1;
     for(int i=0;i<LOCAL.size();i++)
		 for(int j=0;j<LOCAL[i].size();j++){
			 	
	            
             	brush1.CreateSolidBrush(LOCAL[i][j].brushColor);
             	
             	CBrush *oldBrush=pDC->SelectObject(&brush1);
			 if(LOCAL[i][j].canSee==SEE||LOCAL[i][j].canSee==BACKSEE){
			 pDC->Rectangle(LOCAL[i][j].local.x-LOCAL[i][j].halfSize,LOCAL[i][j].local.y-LOCAL[i][j].halfSize,
			 LOCAL[i][j].local.x+LOCAL[i][j].halfSize,LOCAL[i][j].local.y+LOCAL[i][j].halfSize);

			 }
			 brush1.DeleteObject();
		     pDC->SelectObject(oldBrush);

			 
		 }
		 
		 
		 

	pDC->SelectObject(oldPen);
	
	

	
	
	
	
	}

}





BOOL CBox::JIAO(CBox *box,int direct)
{

		int k=this->LOCAL.size();
		int i,j;
	if(box->type==BIGBOX){
		switch(direct){
		
		case LEFT:
		for( i=0;i<k;i++)
			for(j=0;j<k;j++)
				if(LOCAL[i][j].canSee==SEE&&LOCAL[i][j].local.x<BACK_TRIS_LEFT)
					return TRUE;
			break;
		case RIGHT:
			for( i=0;i<k;i++)
			for(j=0;j<k;j++)
				if(LOCAL[i][j].canSee==SEE&&LOCAL[i][j].local.x>BACK_TRIS_RIGHT)
					return TRUE;
			break;
		case UP:
			for( i=0;i<k;i++)
			for(j=0;j<k;j++)
				if(LOCAL[i][j].canSee==SEE&&
					(LOCAL[i][j].local.x>BACK_TRIS_RIGHT||LOCAL[i][j].local.x<BACK_TRIS_LEFT||LOCAL[i][j].local.y>BACK_TRIS_DOWN))
					return TRUE;

		
			break;
		case DOWN:
			for( i=0;i<k;i++)
			for(j=0;j<k;j++)
				if(LOCAL[i][j].canSee==SEE&&LOCAL[i][j].local.y>BACK_TRIS_DOWN)
					return TRUE;
			break;
		
		
		}
	
	
		for( i=0;i<k;i++)
			for(j=0;j<k;j++)
				if(LOCAL[i][j].canSee==SEE)
			{
			

				int a=(LOCAL[i][j].local.x-TERISHALFSIZE-BOARD_LEFT)/TERISSIZE;
				int b=(LOCAL[i][j].local.y-TERISHALFSIZE-BOARD_UP)/TERISSIZE;
				if(	box->LOCAL[a][b].canSee==BACKSEE)
					return TRUE;
			
			}
	
	}
	return  FALSE;

}



void CBox::upDate()
{

}



 void CBox::add(CBox *box)
{

    for(int i=0;i<box->LOCAL.size();i++)
		for(int j=0;j<box->LOCAL.size();j++)
			if(box->LOCAL[i][j].canSee==SEE){
			

			
				int a=(box->LOCAL[i][j].local.x-TERISHALFSIZE-BOARD_LEFT)/TERISSIZE;
				int b=(box->LOCAL[i][j].local.y-TERISHALFSIZE-BOARD_UP)/TERISSIZE;
				if(a>=0&&b>=0){
				this->LOCAL[a][b].brushColor=box->brushColor;
				this->LOCAL[a][b].canSee=BACKSEE;
				}
			}
		

			



}
void CBox::GameMove()
{

	for(int i=0;i<LOCAL.size();i++)
		for(int j=0;j<LOCAL.size();j++)
			LOCAL[i][j].local.y+=2*speed*LOCAL[i][j].halfSize;
}
void CBox::moveDown()
{
	

	//每一个单元往下跑
		
	for(int i=0;i<LOCAL.size();i++)
		for(int j=0;j<LOCAL.size();j++)
			LOCAL[i][j].local.y+=2*LOCAL[i][j].halfSize;

}
void CBox::moveLeft()
{
	

	  int i,j;
		for(i=0;i<LOCAL.size();i++)
		for( j=0;j<LOCAL.size();j++)
			if(LOCAL[i][j].local.x<BACK_TRIS_LEFT&&LOCAL[i][j].canSee==SEE)
				return;
        for( i=0;i<LOCAL.size();i++)
		for( j=0;j<LOCAL.size();j++)
			LOCAL[i][j].local.x-=2*LOCAL[i][j].halfSize;
      
}
void CBox::moveRight()
{
	
		for(int i=0;i<LOCAL.size();i++)
		for(int j=0;j<LOCAL.size();j++)
			LOCAL[i][j].local.x+=2*LOCAL[i][j].halfSize;

}

void CBox::randChange()
{

	int randT=1+rand()%7;
	int randR=rand()%4;
	this->FKtype=randT;
	switch(FKtype){
	
	
	case BOX_O:
		setO();
		break;
	case BOX_S:
		setS();
		break;
	case BOX_T:
		setT();
		break;
	case BOX_Z:
		setT();
		break;
	case BOX_L:
		setL();
		break;
	case BOX_J:
		setJ();
		break;
	case BOX_I:
		setI();
		break;
	default:
		;
	
	
	}
	while(randR--){
	
		this->rotateLeft();
	}
}





//旋转========================

void CBox::rotate()
{
	
	if(FKtype!=BOX_O)
		switch(type){
		case MOVEBOX:
			this->rotateRight();
		//	this->rotateLeft();
			break;
			
	}
			

	
}

void CBox::rotate1()   //   关于对角线  \翻转
{

	
	for(int i=0;i<LOCAL.size();i++)
		for(int j=0;j<i;j++)
			LOCAL[i][j].swap(LOCAL[j][i]);
}
void CBox::rotate2()  //   关于对角线  /翻转
{

	int k=LOCAL.size()-1;
	for(int i=0;i<=k;i++)
		for(int j=0;j+i<=k;j++)
			LOCAL[i][j].swap(LOCAL[k-j][k-i]);

			
		
	
}
void CBox::rotateLeft()
{

	

    
	int j,i;
	int k=LOCAL.size()-1;
	
	   int S[MOVEWNUMBER][MOVEHNUMBER];
	   COLORREF C[MOVEWNUMBER][MOVEHNUMBER];
	   COLORREF P[MOVEWNUMBER][MOVEHNUMBER];
	//	CPoint tmp[MOVEWNUMBER][MOVEHNUMBER];
		for(j=0;j<=k;j++)
			for( i=k;i>=0;i--){
			S[j][k-i]=LOCAL[i][j].canSee;
			C[j][k-i]=LOCAL[i][j].brushColor;
			P[j][k-i]=LOCAL[i][j].penColor;
			}
		
			for( i=0;i<=k;i++)
				for(j=0;j<=k;j++){
		//	LOCAL[i][j].local=tmp[i][j];
            LOCAL[i][j].canSee=S[i][j];
			LOCAL[i][j].brushColor=C[i][j];
            LOCAL[i][j].penColor=P[i][j];
			
				}

	
}

void CBox::rotateRight()
{
//	CBox tmp(MOVEBOX,brushColor,penColor);
	
	int j,i;
	int k=LOCAL.size()-1;
	//CPoint tmp[MOVEWNUMBER][MOVEHNUMBER];
	  int S[MOVEWNUMBER][MOVEHNUMBER];
	 COLORREF C[MOVEWNUMBER][MOVEHNUMBER];
	 COLORREF P[MOVEWNUMBER][MOVEHNUMBER];
		for( j=k;j>=0;j--)
			for(i=0;i<=k;i++){
		//	tmp[k-j][i]=LOCAL[i][j].local;
			S[k-j][i]=LOCAL[i][j].canSee;
			C[k-j][i]=LOCAL[i][j].brushColor;
			P[k-j][i]=LOCAL[i][j].penColor;


			}

			
	   for( i=0;i<=k;i++)
		   for(j=0;j<=k;j++){
			//LOCAL[i][j].local=tmp[i][j];
			   LOCAL[i][j].canSee=S[i][j];
			LOCAL[i][j].brushColor=C[i][j];
            LOCAL[i][j].penColor=P[i][j];

		   }

}
//旋转========================




void CBox::setSpeed(int speed)
{
	

	switch(speed){
	case SLOW         : 
	case SOSO         :
	case FAST         :
	case VERYFAST     :
	case MOSTFAST     :
		this->speed=speed;
		break;
	
	}
}





BOOL CBox::isDownTouch(CBox *box)
{

	
	CBox nextBox(this);
	nextBox.moveDown();
	return nextBox.JIAO(box,DOWN);
	


}

BOOL CBox::isLeftTouch(CBox *box)
{
	/*
	if(box->type==BIGBOX){
	   	for(int i=0;i<LOCAL.size();i++)
			for(int j=0;j<LOCAL.size();j++)
		     if(LOCAL[i][j].canSee==SEE &&LOCAL[i][j].local.x<=BACK_TRIS_LEFT)
			   return true;
	
			 
	}*/

	
	CBox nextBox(this);
	nextBox.moveLeft();
	return nextBox.JIAO(box,LEFT);
}
BOOL CBox::isRightTouch(CBox *box)
{
	/*
	if(box->type==BIGBOX){
	   	for(int i=0;i<LOCAL.size();i++)
			for(int j=0;j<LOCAL.size();j++)
		     if(LOCAL[i][j].canSee==SEE &&LOCAL[i][j].local.x>=BACK_TRIS_RIGHT)
			   return true;
	
			 
	}*/
	CBox nextBox(this);
	nextBox.moveRight();
	return nextBox.JIAO(box,RIGHT);

}
BOOL CBox::isRotateTouch(CBox *box)
{
	CBox nextBox(this);
	switch(rotatetype){
	
	case ROTATELEFT:
		nextBox.rotateLeft();
		break;
	case ROTATERIGHT:
		nextBox.rotateRight();
		break;

	}
	return nextBox.JIAO(box,UP);

}

void CBox::NextResetMove()
{
	if(this->type==NEXTBOX){
	
		this->type=MOVEBOX;
		for(int i=0;i<this->LOCAL.size();i++)
			for(int j=0;j<this->LOCAL.size();j++)
				LOCAL[i][j].local=CPoint(MOVE_BEGIN_X+i*TERISSIZE+TERISHALFSIZE,MOVE_BEGIN_Y+j*TERISSIZE+TERISHALFSIZE);
	
	}

}


void CBox::xiao(int j)
{
	
	int p;
	if(j==0){
	
		for(p=0;p<WNUMBER;j++){
			LOCAL[p][j].canSee=SEE;
		    LOCAL[p][j].brushColor=BACKGROUAND_BRUSHCOLOR;
		}
	
	}
		for( p=0;p<WNUMBER;p++)
			if(LOCAL[p][j].canSee==BACKSEE)
				break;
			if(p==WNUMBER){
				for(int k=0;k<WNUMBER;k++){
	            LOCAL[k][j-1].give(LOCAL[k][j]);
				
				}

				return;
			}
	for(int i=0;i<WNUMBER;i++)
	LOCAL[i][j-1].give(LOCAL[i][j]);
	xiao(j-1);

}
int CBox::xiaoqu() //暴力
{
	int count=0;
	switch(type){
	
	case BIGBOX:

		
		 
		for(int j=0;j<HNUMBER;j++){
			    for(int i=0;i<WNUMBER;i++)
				  if(LOCAL[i][j].canSee==SEE)
					break;
				
				  if(i==WNUMBER){
				    count++;
				    xiao(j);
				  }
			
		}
		break;
	}
	return count;
}

BOOL CBox::isLive()
{
	for(int i=0;i<this->LOCAL.size();i++)
		if(LOCAL[i][0].canSee==BACKSEE)
			return FALSE;
		return TRUE;


}

int CBox::xiaoquByColor()
{

	int count=0;
	switch(type){
	
	case BIGBOX:

		
		 
		for(int j=0;j<HNUMBER;j++){
			    for(int i=0;i<WNUMBER;i++)
				  if(LOCAL[i][j].canSee==SEE||LOCAL[i][j].brushColor!=LOCAL[0][j].brushColor)
					break;
				
				  if(i==WNUMBER){
				    count++;
				    xiao(j);
				  }
			
		}
		break;
	}
	return count;
}



int CBox::xiaoquByAllColor()
{
	int count=0;
	switch(type){
	
	case BIGBOX:

		
		 int i;
		for(int j=0;j<HNUMBER;j++){
			COLORREF tmp[4];
			int now=0;
			for(i=0;i<WNUMBER;i++){
				
				  if(LOCAL[i][j].canSee==SEE)
					break;
				  else{
					  if(now==0){
					  tmp[now]=LOCAL[i][j].brushColor;
					  now++;
					  }else{
					  
						  int z;
						  for( z=0;z<now;z++)
							 if( tmp[z]==LOCAL[i][j].brushColor)
								 break;
							 if(z==now){
							 
								 tmp[now]=LOCAL[i][j].brushColor;
								 now++;
							 
							 }
					  
					  
					  }
				  
				  }
			}
				
				  if(i==WNUMBER&&now==4){
				    count++;
				    xiao(j);
				  }
			
		}
		break;
	}
	return count;

}

void CBox::reverse()

{
	int tallj=19,i,j;
	if(this->type==BIGBOX){
		for( i=0;i<LOCAL.size();i++)
			for(j=0;j<LOCAL[0].size();j++){
	            if(LOCAL[i][j].canSee!=BACKSEE)
					continue;
				else{
					if(tallj>j)
					tallj=j;
					break;

				}
			
			}
			

			
			for( i=0;i<LOCAL.size();i++){
				
				COLORREF tmpC[19];
			    int      tmpS[19];
				int o=0;
				//int len=LOCAL[0].size()-tallj-1;
				for(j=tallj;j<LOCAL[0].size();j++){

					
					tmpS[o]=LOCAL[i][j].canSee;
					tmpC[o]=LOCAL[i][j].brushColor;
					o++;
				
				}
				o=0;
				for(j=LOCAL[0].size()-1;j>=tallj;j--){
				
					LOCAL[i][j].canSee=tmpS[o];
					LOCAL[i][j].brushColor=tmpC[o];
					o++;
				
				}

			}


				




	
	
	}

}

int CBox::xiaoquExceptRed()
{
	int count=0;
	switch(type){
	
	case BIGBOX:

		
		 
		for(int j=0;j<HNUMBER;j++){
			    for(int i=0;i<WNUMBER;i++)
				  if(LOCAL[i][j].canSee==SEE||LOCAL[i][j].brushColor==FKC3)
					break;
				
				  if(i==WNUMBER){
				    count++;
				    xiao(j);
				  }
			
		}
		break;
	}
	return count;

}
