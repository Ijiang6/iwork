#ifndef CPYTHON_H
#define CPYTHON_H

#include <QtGui/QMainWindow>
#include "ui_cpython.h"

class cpython : public QMainWindow
{
	Q_OBJECT

public:
	cpython(QWidget *parent = 0, Qt::WFlags flags = 0);
	~cpython();
	void init();
	void execPyFile();
	void execPyCode();
	void execPyFun();
private slots:
	void slot_file();
	void slot_code();
	void slot_fun();
	void slot_class();

private:
	Ui::cpythonClass ui;

};

#endif // CPYTHON_H
