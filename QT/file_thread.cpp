#include "file_thread.h"
#include <QMutexLocker>
#include <QThread>

CFileBaseThread::CFileBaseThread(QObject * parent /* = 0 */)
	: QObject(parent)
{
	m_bLoading = false;
	m_bStopLoad = false;
	connect(this, SIGNAL(sig_beginLoad()), this, SLOT(slot_loadFile()));
	m_pThread = new QThread;
	moveToThread(m_pThread);
	m_pThread->start();
}

CFileBaseThread::~CFileBaseThread()
{
	m_pThread->quit();
	m_pThread->deleteLater();
}

void CFileBaseThread::setFilePath(const QString & strFilePath)
{
	m_strFilePath = strFilePath;
}

void CFileBaseThread::startLoadFile()
{
	QMutexLocker locker(&m_mutex);
	if (m_bLoading)
	{
		printf(tr("文件正在加载").toStdString().data());
	}
	else
	{
		m_bLoading = true;
		m_bStopLoad = false;
		emit sig_beginLoad();
	}
}

void CFileBaseThread::stopLoadFile()
{
	QMutexLocker locker(&m_mutex);
	if (m_bLoading)
	{
		m_bStopLoad = true;
	}
}

void CFileBaseThread::slot_loadFile()
{
	emit sig_loadFinished(readFile());
	QMutexLocker locker(&m_mutex);
	m_bLoading = false;
	m_bStopLoad = false;
}
bool CFileBaseThread::readFile()
{
	printf("filereadThread=%x\n", this->thread());
	m_mutex.lock();
	QFile rfile(m_strFilePath);
	m_mutex.unlock();
	if (!rfile.open(QFile::ReadOnly))
	{
		return false;
	}
	int iTotal = rfile.size();
	QTextStream in(&rfile);
	for(int iTrun = 0;iTrun < getHeadLineCount(); iTrun++)
	{
		in.readLine();
	}
	//获取所有数据
	bool bHPC=false;
	while (!in.atEnd()) 
	{
		m_mutex.lock();
		if (m_bStopLoad)
		{
			m_mutex.unlock();
			return false;
		}
		m_mutex.unlock();
		QString line = in.readLine();
		if ((line.contains("#"))&& (m_emDataType == EM_DATA_HPC))
		{
			in.readLine();
			in.readLine();
			bHPC=true;
			continue;
		}
		QStringList strLst = line.split(",");
		if (strLst.size() < 6)
		{
			continue;
		}
		QDateTime dateTime;
		int iYear=("20"+strLst.at(0)).toInt();
		int iMonth=strLst.at(1).toInt();
		int iDay=strLst.at(2).toInt();
		int iHour=strLst.at(3).toInt();
		int iMinute=strLst.at(4).toInt();
		int iSconed=strLst.at(5).toInt();
		dateTime.setDate(QDate(iYear,iMonth,iDay));
		dateTime.setTime(QTime(iHour,iMinute,iSconed));
		strLst = strLst.mid(6);
		m_mutex.lock();
		if (bHPC)
		{
			m_hDtData_Rh[dateTime.toTime_t()]=strLst;
		}
		else
		{
			m_hDtData[dateTime.toTime_t()] = strLst;
		}
		m_mutex.unlock();
		emit sig_loadProgress(rfile.pos(), iTotal);
	}
	rfile.close();
	return true;
}