#ifndef CWGTICONSHOW_H
#define CWGTICONSHOW_H

#include <QSystemTrayIcon>
//����˵����ʵ�ִ�����С��������ͼ����ʾ���Ҽ���ݲ˵���ʾ
class CWgtIconShow : public QSystemTrayIcon
{
	Q_OBJECT

public:
	CWgtIconShow(QSystemTrayIcon *parent = 0);
	~CWgtIconShow();
	void setInit();//��ʼ��
private:
	
};

#endif // CWGTICONSHOW_H
