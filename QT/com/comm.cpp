#include "comminfo/comm.h"
#include <WindoI.h>
#include <iostream>
//#include <afxwin.h>

// 串口设备句柄
//HANDLE hComm;

// 打开串口
// pPort: 串口名称或设备路径，可用"COM1"或"\\.\COM1"两种方式，建议用后者
// nBaudRate: 波特率
// nParity: 奇偶校验
// nByteSize: 数据字节宽度
// nStopBits: 停止位
bool IComm::OpenComm(int PortNo, const char* pBaudRate, int nParity, int nByteSize, int nStopBits)
{
	char pPort[64];
	sprintf(pPort,"COM%d",PortNo);
	int nBaudRate=atoi(pBaudRate);
	//控制块和超时变量
//	void * hComm;
	DCB dcb;		// 串口控制块
	//COMMTIMEOUTS timeouts = {	// 串口超时控制参数
	//	100,				// 读字符间隔超时时间: 100 ms
	//	1,					// 读操作时每字符的时间: 1 ms (n个字符总共为n ms)
	//	500,				// 基本的(额外的)读超时时间: 500 ms
	//	1,					// 写操作时每字符的时间: 1 ms (n个字符总共为n ms)
	//	100
	//	};				// 基本的(额外的)写超时时间: 100 ms
	COMMTIMEOUTS timeouts = {	// 串口超时控制参数
		100,				// 读字符间隔超时时间: 100 ms
		1,					// 读操作时每字符的时间: 1 ms (n个字符总共为n ms)
		200,				// 基本的(额外的)读超时时间: 500 ms
		1,					// 写操作时每字符的时间: 1 ms (n个字符总共为n ms)
		100
	};				// 基本的(额外的)写超时时间: 100 ms
	char tport[128];
	memset(tport,0,128);
	if(!strstr(pPort,"\\\\.\\"))
	{
		sprintf(tport,"\\\\.\\%s",pPort);
	}
	//打开串口
	hComm = CreateFile(tport,	// 串口名称或设备路径
			GENERIC_READ | GENERIC_WRITE,	// 读写方式
			0,				// 共享方式：独占
			NULL,			// 默认的安全描述符
			OPEN_EXISTING,	// 创建方式
			0,				// 不需设置文件属性
			NULL);			// 不需参照模板文件
	
	if(hComm == INVALID_HANDLE_VALUE) return FALSE;		// 打开串口失败
	
	// 设置输入输出缓冲区大小
	SetupComm(hComm, 4096, 1024);	
	if (hComm)		// 检查串口是否打开
	{
		PurgeComm(hComm, PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT);
	}

	// 设置DCB
	GetCommState(hComm, &dcb);		// 取DCB

	dcb.BaudRate = nBaudRate;
	dcb.ByteSize = nByteSize;
	dcb.Parity = nParity;
	dcb.StopBits = nStopBits;
	dcb.fBinary = TRUE ;			//龙克锋新增
	dcb.fParity = FALSE;			//龙克锋新增

	SetCommState(hComm, &dcb);		

	// 设置超时
	::SetCommTimeouts(hComm, &timeouts);	
//	g_com[PortNo]=hComm;
	return TRUE;
}
//清除串口缓冲区的内容
void IComm::CleanComBuff()
{
	if (hComm)		// 检查串口是否打开
	{
		PurgeComm(hComm, PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT);
	}
}
// 关闭串口
bool IComm::CloseComm()
{
	return CloseHandle(hComm);
}

// 写串口
// pData: 待写的数据缓冲区指针
// nLength: 待写的数据长度
void IComm::WriteComm(const char * pData, int nLength)
{
	DWORD dwNumWrite;	// 串口发出的数据长度
/*	if (hComm)		// 检查串口是否打开
	{
		PurgeComm(hComm, PURGE_TXCLEAR);
	}
*/
	WriteFile(hComm, pData, (DWORD)nLength, &dwNumWrite, NULL);
//	memset(m_DeviceMonitor[portno].Wdata,0,sizeof(m_DeviceMonitor[portno].Wdata));
//	sprintf(m_DeviceMonitor[portno].Wdata,"%d",dwNumWrite);
}

// 读串口
// pData: 待读的数据缓冲区指针
// nLength: 待读的最大数据长度
// 返回: 实际读入的数据长度
int IComm::ReadComm(char * pData, int nLength)
{
	DWORD dwNumRead;	// 串口收到的数据长度
	ReadFile(hComm, pData, (DWORD)nLength, &dwNumRead, NULL);
//	memset(m_DeviceMonitor[portno].Rdata,0,sizeof(m_DeviceMonitor[portno].Rdata));
//	sprintf(m_DeviceMonitor[portno].Rdata,"%d",dwNumRead);
	return (int)dwNumRead;
}
