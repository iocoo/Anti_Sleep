; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CShutdownDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Anti_Sleep.h"

ClassCount=4
Class1=CAnti_SleepApp
Class2=CAnti_SleepDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_ANTI_SLEEP_DIALOG
Class4=CShutdownDlg
Resource4=IDD_SHUTDOWNDIALOG

[CLS:CAnti_SleepApp]
Type=0
HeaderFile=Anti_Sleep.h
ImplementationFile=Anti_Sleep.cpp
Filter=W

[CLS:CAnti_SleepDlg]
Type=0
HeaderFile=Anti_SleepDlg.h
ImplementationFile=Anti_SleepDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CAnti_SleepDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=Anti_SleepDlg.h
ImplementationFile=Anti_SleepDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_ANTI_SLEEP_DIALOG]
Type=1
Class=CAnti_SleepDlg
ControlCount=5
Control1=IDCANCEL,button,1342242827
Control2=IDC_TIMESTATIC,static,1342312448
Control3=IDC_WORKSTATIC,static,1342308352
Control4=ID_TIMESHUTDOWN,button,1342242827
Control5=ID_TOTRAY,button,1342242827

[DLG:IDD_SHUTDOWNDIALOG]
Type=1
Class=CShutdownDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TIMEPICKER,SysDateTimePick32,1342242857
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATICTIME,static,1073872896

[CLS:CShutdownDlg]
Type=0
HeaderFile=ShutdownDlg.h
ImplementationFile=ShutdownDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_TIMEPICKER

