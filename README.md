Anti-PC-Sleep[阻止计算机休眠]
==========

Keep your PC awake for those who have no administrator password in Enterprise domain Network.

Anti_Sleep.dsp
    This file (the project file) contains information at the project level and
    is used to build a single project or subproject. Other users can share the
    project (.dsp) file, but they should export the makefiles locally.

Anti_Sleep.h
    This is the main header file for the application.  It includes other
    project specific headers (including Resource.h) and declares the
    CAnti_SleepApp application class.

Anti_Sleep.cpp
    This is the main application source file that contains the application
    class CAnti_SleepApp.

Anti_Sleep.rc
    This is a listing of all of the Microsoft Windows resources that the
    program uses.  It includes the icons, bitmaps, and cursors that are stored
    in the RES subdirectory.  This file can be directly edited in Microsoft
	Visual C++.

Anti_Sleep.clw
    This file contains information used by ClassWizard to edit existing
    classes or add new classes.  ClassWizard also uses this file to store
    information needed to create and edit message maps and dialog data
    maps and to create prototype member functions.

res\Anti_Sleep.ico
    This is an icon file, which is used as the application's icon.  This
    icon is included by the main resource file Anti_Sleep.rc.

res\Anti_Sleep.rc2
    This file contains resources that are not edited by Microsoft 
	Visual C++.  You should place all resources not editable by
	the resource editor in this file.

==========
Name:      Anti-ScrSaver/Anti_Sleep
Function：     阻止计算机屏幕保护开启，计算机休眠,为无计算机管理员权限的用户提供
Env:  Windows XP/Vista/7


ChangeLog版本更新
==========
   v1.0         完成基本功能，UI;
   v1.1         利用时钟出发，实现在非激活状态下运行
   v1.2         修复按回车程序即退出的Bug
   v1.3beta版   增加最小化到托盘功能(alpha版),如果选择隐藏此功能暂时无法达到防止屏保开启功能
   v1.3正式版   修复隐藏到托盘无法正常工作的bug
   v1.5         更新UI，增加定时关机功能,自动关机时间17:32:00
   
   

