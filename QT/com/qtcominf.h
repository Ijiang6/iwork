#ifndef _QTCOMInf_H_
#define _QTCOMInf_H_

//#include <QStringList>
#include <QObject>
class WSComm;

class QtComInf : public QObject
{
	Q_OBJECT
public:
	QtComInf(QObject * parent = 0);
	virtual ~QtComInf();
public:
	/*! \brief 
	*   \打开串口*/
	bool Open(int iPort,const QString & strBaud);

	/*! \brief 
	*   \发送数据*/
	int write(const QByteArray & dataWrite);

	/*! \brief 
	*   \读取串口数据*/
	QByteArray read(int iMaxLen = 512);

	/*! \brief 
	*   \读取串口中的所有数据*/
	QByteArray readAll();

	/*! \brief 
	*   \关闭串口*/
	void close();

	/*! \brief 
	*   \清理串口缓存*/
	void CleanComBuff();
private:
	IComm * m_pComm;
	char chBuf[8192];
	bool m_bOpen;
	//QStringList lstComBaud;
};

#endif
