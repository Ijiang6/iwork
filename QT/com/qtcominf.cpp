#include "comminfo/qtcominf.h"
#include "comminfo/comm.h"

QtComInf::QtComInf(QObject * parent /* = 0 */)
{
	m_bOpen = false;
	m_pComm = new IComm;
	//lstComBaud 
	//	<< "50" 
	//	<< "75" 
	//	<< "110" 
	//	<< "134" 
	//	<< "150" 
	//	<< "200" 
	//	<< "300" 
	//	<< "600" 
	//	<< "1200" 
	//	<< "1800"              //POSIX ONLY
	//	<< "2400"
	//	<< "4800"
	//	<< "9600"
	//	<< "14400"             //WINDOWS ONLY
	//	<< "19200"
	//	<< "38400"
	//	<< "56000"             //WINDOWS ONLY
	//	<< "57600"
	//	<< "76800"             //POSIX ONLY
	//	<< "115200"
	//	<< "128000"            //WINDOWS ONLY
	//	<< "256000";             //WINDOWS ONLY
}

QtComInf::~QtComInf()
{
	close();
	delete m_pComm;
}

void QtComInf::CleanComBuff()
{
	if (m_bOpen)
	{
		m_pComm->CleanComBuff();
	}
}

bool QtComInf::Open(int iPort, const QString & strBaud)
{
	m_bOpen = m_pComm->OpenComm(iPort,strBaud.toStdString().c_str());
	if (!m_bOpen)
	{
		m_pComm->CloseComm();
	}
	return m_bOpen;
}
void QtComInf::close()
{
	if (m_bOpen)
	{
		m_pComm->CleanComBuff();
		m_pComm->CloseComm();
		m_bOpen = false;
	}
}

int QtComInf::write(const QByteArray & dataWrite)
{
	if (m_bOpen)
	{
		m_pComm->WriteComm(dataWrite.data(),dataWrite.size());
		return dataWrite.size();
	}
	return -1;
}
QByteArray QtComInf::readAll()
{
	QByteArray dataRead;
	if (m_bOpen)
	{
		int iReadLen = m_pComm->ReadComm(chBuf,512);
		while(iReadLen > 0)
		{
			dataRead.append(chBuf, iReadLen);
			iReadLen = m_pComm->ReadComm(chBuf,512);
		}
	}
	return dataRead;
}

QByteArray QtComInf::read(int iMaxLen /* = 512 */)
{
	QByteArray dataRead;
	if (m_bOpen)
	{
		int iReadLen = m_pComm->ReadComm(chBuf,iMaxLen);
		if(iReadLen > 0)
		{
			dataRead.append(chBuf, iReadLen);
		}
	}
	return dataRead;
}
