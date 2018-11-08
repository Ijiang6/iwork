// Comm.h: interface for the CComm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(ICOMM_H__)
#define ICOMM_H__

class IComm
{
public:
	bool OpenComm(int portno, const char* pBaudRate="9600", int nParity=0, int nByteSize=8, int nStopBits=0);
	void WriteComm(const char * pData, int nLength);
	int ReadComm(char * pData, int nLength);
	//清除串口缓冲区的内容
	void CleanComBuff();
	bool CloseComm();
private:
	void * hComm;
};
#endif // !defined(COMM_H__)
