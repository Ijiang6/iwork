#include "filereader.h"
#include<QTextStream>
FileReader::FileReader(QObject *parent) : QObject(parent)
{
    connect(this,&FileReader::gotError,this,&FileReader::handleError);
    connect(this,&FileReader::outPutChanged,this,&FileReader::handleOut);
}

QString FileReader::fileName()
{
    return m_fileName;
}

QString FileReader::outPut()
{
    return m_outPut;
}

QString FileReader::errorString()
{
    return m_errorString;
}

void FileReader::setFileName(const QString &fileName)
{
    if(m_fileName == fileName)
    {
        return;
    }
    m_fileName = fileName;
    m_fileName =fileName;
}

FileReader::Type FileReader::type()
{
    return m_type;
}

void FileReader::setType(const FileReader::Type &type)
{
    if(m_type == type)
    {
        return;
    }
    m_type =type;
    emit typeChanged();
}

QString FileReader::inComing()
{
    return  m_inComing;
}

void FileReader::setInComing(const QString &incoming)
{
    if(m_inComing == incoming)
        return;
    m_inComing = incoming;
    emit inComingChanged();
}

void FileReader::readFile()
{
    QFile file(m_fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    { gotError("open file error");
        return;
    }
    while (!file.atEnd()) {
        QString line = file.readAll();
        outPutChanged(line);
        file.close();
        file.flush();
    }
}

void FileReader::exec()
{
    if(m_type == Read)
    {
        QFile file(m_fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {  gotError("open file error");
            return;
        }
        while (!file.atEnd()) {
            QString line = file.readAll();
            outPutChanged(line);
            file.close();
            file.flush();
        }
    }
    else if(m_type == Write)
    {
        QFile file(m_fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {  gotError("open file error");
            return;
        }

        QTextStream out(&file);
        out<<m_inComing;
        file.close();
        file.flush();
    }
}

void FileReader::handleOut(QString outPut)
{
    if(m_outPut == outPut)
        return;
    m_outPut = outPut;
    emit textChange();
}

void FileReader::handleError(QString err)
{
    m_errorString = err;
    emit error();
}
