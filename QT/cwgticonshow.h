#ifndef CWGTICONSHOW_H
#define CWGTICONSHOW_H

#include <QSystemTrayIcon>
//功能说明：实现窗体最小化托盘区图标显示，右键快捷菜单显示
class CWgtIconShow : public QSystemTrayIcon
{
	Q_OBJECT

public:
	CWgtIconShow(QSystemTrayIcon *parent = 0);
	~CWgtIconShow();
	void setInit();//初始化
private:
	
};

#endif // CWGTICONSHOW_H
