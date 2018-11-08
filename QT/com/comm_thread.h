#ifndef _COM_THREAD_H
#define _COM_THREAD_H

#include <QThread>
#include <QQueue>
#include <QMutex>

class QtComInf;
class QTimer;

class CComProcThread: public QThread
{
	Q_OBJECT
public:
	CComProcThread(QObject * parent = 0);
	virtual ~CComProcThread();
public:
	void closeComm();//关闭串口
	void initComm(int iPort, const QString & strBaud);

	void sendData(const QByteArray & byte);//发送数据
protected:
	void run();
	bool getSendData(QByteArray & dataSend);//获取一条发送数据
signals:
	void sig_bindResult(bool bSuccess);
protected slots:
	void slot_openComm();
private:
	QMutex mutexSendData;//数据锁
	QtComInf * m_pComm;//串口
	QQueue<QByteArray> m_qSendData;//发送数据队列
	int m_iPort;///端口,如1
	QString m_strBaud;///波特率,如"9600"
	bool m_bOpen;///设备打开否

	QTimer * m_pTimerOpen;	//定时打开串口
signals:
	void sig_revData(QByteArray byte);
};

#endif //_RY_COM_PROC_THREAD_H