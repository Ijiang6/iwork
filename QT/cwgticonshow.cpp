#include "cwgticonshow.h"

CWgtIconShow::CWgtIconShow(QSystemTrayIcon *parent)
	: QSystemTrayIcon(parent)
{
setInit();
}

CWgtIconShow::~CWgtIconShow()
{

}
void CWgtIconShow::setInit()
{
	this->setToolTip(tr("������ʾ"));
	this->setIcon(QIcon("./icon/logo.ico"));

}