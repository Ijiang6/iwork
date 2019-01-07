#include "cpython.h"
#include <QtGui/QApplication>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	cpython w;
	w.show();
	return a.exec();
}
