#include "comminfo/comm_thread.h"
#include "comminfo/qtcominf.h"
#include <QTimer>

CComProcThread::CComProcThread(QObject * parent /* = 0 */)
	:QThread(parent)
{
	m_pComm = new QtComInf;
	m_bOpen = false;
	m_iPort = 0;
	m_strBaud = "";

	m_pTimerOpen = new QTimer(this);
	connect(m_pTimerOpen, SIGNAL(timeout()), this, SLOT(slot_openComm()));
// 	QTimer * timer = new QTimer(this);
// 	connect(timer, SIGNAL(timeout()), this, SLOT(slot_sendRevData()));
// 	timer->start(100);
} 

CComProcThread::~CComProcThread()
{
	terminate();
	wait();
	m_pComm->close();
	delete m_pComm;
}

void CComProcThread::closeComm()
{
	if (isRunning())
	{
		terminate();
		wait();
		mutexSendData.lock();
		m_qSendData.clear();
		mutexSendData.unlock();
	}
	if(m_bOpen)
	{
		m_pComm->close();
		m_bOpen = false;
	}
}

void CComProcThread::initComm(int iPort, const QString & strBaud)//打开串口，波特率
{
	if ((m_iPort != iPort || m_strBaud != strBaud)
		|| !m_bOpen)
	{
		closeComm();
		m_iPort = iPort;
		m_strBaud = strBaud;
		m_pTimerOpen->start(2000);
		slot_openComm();
	}
}

void CComProcThread::run()
{
	while (true)
	{
		QByteArray dataSend;
		if(getSendData(dataSend))
		{
			m_pComm->write(dataSend);
		}
		QByteArray dataOne = m_pComm->read(512);
		if (!dataOne.isEmpty())
		{
			//dataOne.append(m_pComm->read(4096));
			emit sig_revData(dataOne);
		}
		else
		{
			msleep(20);
		}
	}
}

bool CComProcThread::getSendData(QByteArray & dataSend)
{
	mutexSendData.lock();
	if(m_qSendData.isEmpty())
	{
		mutexSendData.unlock();
		return false;
	}
	else
	{
		dataSend = m_qSendData.dequeue();
		mutexSendData.unlock();
		return true;
	}
}

void CComProcThread::sendData(const QByteArray & dataSend)
{
	mutexSendData.lock();
	m_qSendData.push_back(dataSend);
	mutexSendData.unlock();
}

void CComProcThread::slot_openComm()
{
	if (!m_bOpen)
	{
		m_bOpen = m_pComm->Open(m_iPort,m_strBaud);
		if (m_bOpen)
		{
			m_pTimerOpen->stop();
			start();
		}
		emit sig_bindResult(m_bOpen);
	}
}

//void CComProcThread::slot_sendRevData()
//{
//	QByteArray byte;
//	mutexSendData.lock();
//	byte = m_revData;
//	m_revData.clear();
//	mutexSendData.unlock();
//	if (!byte.isEmpty())
//	{
//		emit sig_revData(byte);
//	}
//}