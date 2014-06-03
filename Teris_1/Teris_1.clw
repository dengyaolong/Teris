; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTeris_1View
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "teris_1.h"
LastPage=0

ClassCount=14
Class1=AgainDlg
Class2=GkSelectDlg
Class3=CMainFrame
Class4=CPassDlg
Class5=RecordDlg
Class6=CTeris_1App
Class7=CAboutDlg
Class8=CTeris_1Doc
Class9=CTeris_1View
Class10=Welcome
Class11=WelDlg

ResourceCount=9
Resource1=IDD_DIALOG1
Resource2=IDD_DIALOG5
Resource3=IDD_ABOUTBOX
Resource4=IDD_DIALOG4
Resource5=IDD_DIALOG3
Resource6=IDR_MAINFRAME
Resource7=IDD_DIALOG2
Class12=Record
Class13=Records
Resource8=IDD_DIALOG6
Class14=Redlg
Resource9=IDD_DIALOG7

[CLS:AgainDlg]
Type=0
BaseClass=CDialog
HeaderFile=AgainDlg.h
ImplementationFile=AgainDlg.cpp

[CLS:GkSelectDlg]
Type=0
BaseClass=CDialog
HeaderFile=GkSelectDlg.h
ImplementationFile=GkSelectDlg.cpp

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[CLS:CPassDlg]
Type=0
BaseClass=CDialog
HeaderFile=PassDlg.h
ImplementationFile=PassDlg.cpp

[CLS:RecordDlg]
Type=0
BaseClass=CDialog
HeaderFile=RecordDlg.h
ImplementationFile=RecordDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[CLS:CTeris_1App]
Type=0
BaseClass=CWinApp
HeaderFile=Teris_1.h
ImplementationFile=Teris_1.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=Teris_1.cpp
ImplementationFile=Teris_1.cpp

[CLS:CTeris_1Doc]
Type=0
BaseClass=CDocument
HeaderFile=Teris_1Doc.h
ImplementationFile=Teris_1Doc.cpp

[CLS:CTeris_1View]
Type=0
BaseClass=CView
HeaderFile=Teris_1View.h
ImplementationFile=Teris_1View.cpp
LastObject=ID_LAST_XMXX
Filter=C
VirtualFilter=VWC

[CLS:Welcome]
Type=0
BaseClass=CDialog
HeaderFile=Welcome.h
ImplementationFile=Welcome.cpp

[CLS:WelDlg]
Type=0
BaseClass=CDialog
HeaderFile=WelDlg.h
ImplementationFile=WelDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=ID_MODE_XMXX

[DLG:IDD_DIALOG3]
Type=1
Class=AgainDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG2]
Type=1
Class=GkSelectDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG1]
Type=1
Class=CPassDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG6]
Type=1
Class=RecordDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=3
Control1=IDC_STATIC,static,1342308480
Control2=IDC_STATIC,static,1342308352
Control3=IDOK,button,1342373889

[DLG:IDD_DIALOG4]
Type=1
Class=Welcome
ControlCount=2
Control1=IDCANCEL,button,1342275585
Control2=IDOK,button,1342275585

[DLG:IDD_DIALOG5]
Type=1
Class=WelDlg
ControlCount=7
Control1=ID_WEL_NORMAL,button,1342242816
Control2=ID_WEL_CXY,button,1342242816
Control3=ID_WEL_REVERSE,button,1342242816
Control4=ID_WEL_LIFE,button,1476460544
Control5=ID_WEL_GK,button,1342242816
Control6=ID_WEL_QPZ,button,1342242816
Control7=IDC_MODE_XMXX,button,1342242816

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_NEWGAME
Command2=ID_SAVE
Command3=ID_LAST_NORMAL
Command4=ID_LAST_GK
Command5=ID_LAST_QPZ
Command6=ID_LAST_CXY
Command7=ID_LAST_REVERSE
Command8=ID_LAST_LIFE
Command9=ID_LAST_XMXX
Command10=ID_APP_EXIT
Command11=ID_APP_ABOUT
Command12=ID_MAKETERIS
Command13=ID_SETCOLORFK1
Command14=ID_SETCOLORFK2
Command15=ID_SETCOLORFK3
Command16=ID_SETCOLORFK4
Command17=ID_NORMAL
Command18=ID_GKMODE
Command19=ID_GK_CHOOSE
Command20=ID_GK_ADD
Command21=ID_QPZMODE
Command22=ID_QPZ_CHOOSE
Command23=ID_CXY_BEGIN
Command24=ID_MODE_REVERSE
Command25=ID_MODE_REVERSE_Select
Command26=ID_MODE_XMXX
Command27=ID_LIVEMODE
CommandCount=27

[ACL:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_EDIT_COPY
Command2=ID_FILE_SAVE
Command3=ID_FILE_NEW
Command4=ID_FILE_PRINT
Command5=ID_SAVE
Command6=ID_EDIT_PASTE
Command7=ID_EDIT_UNDO
CommandCount=7

[CLS:Record]
Type=0
HeaderFile=Record.h
ImplementationFile=Record.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:Record]
DB=1
DBType=ODBC
ColumnCount=0

[CLS:Records]
Type=0
HeaderFile=Records.h
ImplementationFile=Records.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=Records

[DB:Records]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[MyName], 12, 60
Column2=[Score], 5, 2
Column3=[Mode], 12, 60
Column4=[Timer], 5, 2

[DLG:IDD_DIALOG7]
Type=1
Class=Redlg
ControlCount=1
Control1=IDC_LIST1,SysListView32,1350631427

[CLS:Redlg]
Type=0
HeaderFile=Redlg.h
ImplementationFile=Redlg.cpp
BaseClass=CDialog
Filter=D
LastObject=Redlg
VirtualFilter=dWC

