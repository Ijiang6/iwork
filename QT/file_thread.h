#ifndef _CFILE_THREAD_H_
#define _CFILE_THREAD_H_

#include <QFile>
#include <QMutex>

class QThread;

class CFileBaseThread : public QObject
{
	Q_OBJECT
public:
	CFileBaseThread(QObject * parent = 0);
	virtual ~CFileBaseThread();
public:
	virtual void setFilePath(const QString & strFilePath);
public:
	virtual void startLoadFile();	//开始加载数据
	virtual void stopLoadFile();	//停止加载数据
	 bool readFile();	//读取文件
	 //virtual bool readFile() = 0;	//纯虚函数 子类必须实现该函数才可以创建对象
protected slots:
	/*! \brief 加载数据
	*/
	virtual void slot_loadFile();
signals:
	void sig_beginLoad();	//开始加载
	void sig_loadProgress(int done, int total);	//加载进度
	void sig_loadFinished(bool bSuccess);	//加载完成
protected:
	QThread * m_pThread;	//线程
	QMutex m_mutex;		//互斥，只用来锁是否停止加载
	bool m_bLoading;	//是否正在加载中
	bool m_bStopLoad;	//是否停止加载数据
	QString m_strFilePath;	//文件名
};


#endif