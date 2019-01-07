#include "cpython.h"
#include<iostream>
#include"python.h"
#include "iconhelper.h"
using namespace std;
cpython::cpython(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	init();
}

cpython::~cpython()
{

}
void cpython::init()
{
	ui.toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	ui.toolButton->setIconSize(QSize(ui.toolButton->width(), ui.toolButton->height()));
	ui.toolButton_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	ui.toolButton_2->setIconSize(QSize(ui.toolButton_2->width(), ui.toolButton_2->height()));
	ui.toolButton_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	ui.toolButton_3->setIconSize(QSize(ui.toolButton_3->width(), ui.toolButton_3->height()));
	ui.toolButton_4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	ui.toolButton_4->setIconSize(QSize(ui.toolButton_4->width(), ui.toolButton_4->height()));
	ui.toolButton->setText("文件");
	ui.toolButton_2->setText("代码");
	ui.toolButton_3->setText("函数");
	ui.toolButton_4->setText("对象");
	IconHelper::Instance()->setIcon(ui.toolButton, 0xf2d9, 50);
	IconHelper::Instance()->setIcon(ui.toolButton_2, 0xf0f6, 50);
	IconHelper::Instance()->setIcon(ui.toolButton_3, 0xf00b, 50);
	IconHelper::Instance()->setIcon(ui.toolButton_4, 0xf085, 50);
	 this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
	 connect(ui.toolButton,SIGNAL(clicked()),this,SLOT(slot_file()));
	 connect(ui.toolButton_2,SIGNAL(clicked()),this,SLOT(slot_code()));
	 connect(ui.toolButton_3,SIGNAL(clicked()),this,SLOT(slot_fun()));
	 connect(ui.toolButton_4,SIGNAL(clicked()),this,SLOT(slot_class()));
}
void cpython::slot_class()
{

}
void cpython::slot_code()
{
	execPyCode();
}
void cpython::slot_file()
{
	execPyFile();
}
void cpython::slot_fun()
{
	execPyFun();
}
void cpython::execPyFile()
{
	Py_Initialize();
	if (!Py_IsInitialized())
	{
		printf("init error");
		return;
	}
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("print(len(sys.argv))");
	PyRun_SimpleString("sys.argv.append('image')");
	PyRun_SimpleString("sys.path.append('./')");
	PyObject *obj = Py_BuildValue("s", "image.py");
	FILE *fp = _Py_fopen_obj(obj, "r+");
	if (fp == NULL)
		return ;
	PyRun_SimpleFile(fp, "image.py");
	Py_Finalize();
}
void cpython::execPyCode()
{
	Py_Initialize();
	if (!Py_IsInitialized())
	{
		printf("init error");
		return;
	}
	 PyRun_SimpleString("print('exec python code!')");
	 PyRun_SimpleString("import sys");
	 PyRun_SimpleString("sys.argv.append('image')");
	 PyRun_SimpleString("from pylab import *"
		 "\n"
		 "X = np.linspace(-np.pi, np.pi, 256,endpoint=True)"
		 "\n"
		 "C,S = np.cos(X), np.sin(X)"
		 "\n"
		 "plot(X,C)"
		 "\n"
		 "plot(X,S)"
		 "\n"
		 "show()");
	Py_Finalize();
}
void cpython::execPyFun()
{
	Py_Initialize();
	if (!Py_IsInitialized())
	{
		printf("init error");
		return;
	}
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.argv.append('image')");
	PyRun_SimpleString("sys.path.append('./')");
	PyRun_SimpleString("from pylab import *");
	PyObject *pMoudleFile=NULL;
	PyObject *pMoudleFun=NULL;
	pMoudleFile=PyImport_ImportModule("matplot");//matplot
	if (pMoudleFile == NULL)
	{
		printf("not find py File\n");
		return;
	}
	//有参函数
	pMoudleFun=PyObject_GetAttrString(pMoudleFile,"add");
	if (pMoudleFun == NULL)
	{
		printf("import py addFun error\n");
		return;
	}
	 PyObject* args = Py_BuildValue("(ii)", 100, 111);//给python函数参数赋值
	PyObject* pRet = PyObject_CallObject(pMoudleFun, args);//调用函数
	if (pRet == NULL)
	{
		printf("call addFun error\n ");
		return;
	}
	int res = 0;
	PyArg_Parse(pRet, "i", &res);//转换返回类型
	printf("%d\n",res);
	//无参函数
	pMoudleFun=PyObject_GetAttrString(pMoudleFile,"coutstr");
	if (pMoudleFun == NULL)
	{
		printf("import py coutstrFun error\n");
		return;
	}
	pRet = PyObject_CallObject(pMoudleFun, NULL);//调用函数
	if (pRet == NULL)
	{
		printf("call coutstrFun error\n ");
		return;
	}
	//需要import 的函数->fail
	pMoudleFun=PyObject_GetAttrString(pMoudleFile,"image_fun");
	if (pMoudleFun == NULL)
	{
		printf("import py imageFun error\n");
		return;
	}
	pRet = PyObject_CallObject(pMoudleFun, NULL);//调用函数
	if (pRet == NULL)
	{
		printf("call imageFun error\n ");
		return;
	}
	Py_Finalize();
}