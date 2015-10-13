; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=m_AddSight
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ParkPathProblem.h"

ClassCount=5
Class1=CParkPathProblemApp
Class2=CParkPathProblemDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_PARKPATHPROBLEM_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=m_AddSight
Resource4=IDD_DIALOG1
Class5=AddPath
Resource5=IDD_DIALOG2

[CLS:CParkPathProblemApp]
Type=0
HeaderFile=ParkPathProblem.h
ImplementationFile=ParkPathProblem.cpp
Filter=N

[CLS:CParkPathProblemDlg]
Type=0
HeaderFile=ParkPathProblemDlg.h
ImplementationFile=ParkPathProblemDlg.cpp
Filter=D
LastObject=CParkPathProblemDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ParkPathProblemDlg.h
ImplementationFile=ParkPathProblemDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PARKPATHPROBLEM_DIALOG]
Type=1
Class=CParkPathProblemDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_SUMSIGHT,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_SUMPATH,edit,1350631552
Control7=IDC_ADDSIGHT,button,1342242816
Control8=IDC_ADDPATH,button,1342242816
Control9=IDC_DRAW,button,1342242816
Control10=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG1]
Type=1
Class=m_AddSight
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308608
Control6=IDC_EDIT1,edit,1350631552
Control7=IDC_CONFIRM,button,1342242816
Control8=IDC_STATIC,static,1342308352

[CLS:m_AddSight]
Type=0
HeaderFile=m_AddSight.h
ImplementationFile=m_AddSight.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_CONFIRM
VirtualFilter=dWC

[DLG:IDD_DIALOG2]
Type=1
Class=AddPath
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COMBO1,combobox,1344340226
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_COMBO2,combobox,1344340226
Control7=IDC_EDIT1,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_CONFRIM,button,1342242816

[CLS:AddPath]
Type=0
HeaderFile=AddPath.h
ImplementationFile=AddPath.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_COMBO1
VirtualFilter=dWC

