# QT

qt新增界面可以手动新增.h .cpp文件，然后空间一个个的布局上去，参考finddialog

也可以先添加.ui文件 （.ui文件是页面设计，可以直接拖控件），然后根据uic.exe来生成.h跟.cpp文件

生成.ui文件:

右键项目->qt->选择对应的项目

创建完成后，双击xxx.ui文件可以进入设计界面，可以随意拖动空间布局

根据uic.exe来生成.h、cpp文件 需要把uic.exe假如到环境变量。uic.exe的路径根据vs版本不同可能不同，本机的路径是 D:\Qt\Qt5.9.2\5.9.2\msvc2017_64\bin



然后cmd 进去xx.ui文件的路径

```
C:\Users\hc>e:

E:\>cd E:\练习Demo\c++Demo\FirstQt

E:\练习Demo\c++Demo\FirstQt>uic Test.ui -o Test.h

E:\练习Demo\c++Demo\FirstQt>uic Test.ui -o Test.cpp
```

默认生成的.h 、.cpp文件  的class名字为 UI_Dialog,把它改成自己想要的名字，并且类要继承QDialog

```
class TestDialog: public QDialog
{
    ...
}
```

在TestDialog show出窗体之前，需要调用一下 setupUi 方法


