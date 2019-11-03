#ifndef FILEREADER_H
#define FILEREADER_H

#include <QObject>
#include<QFile>
#include<QStringList>
#include<QTextStream>
class FileReader : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName NOTIFY fileNameChanged)
    Q_PROPERTY(QString outPut READ outPut )
    Q_PROPERTY(QString  errorString READ errorString )
    Q_PROPERTY(QString inComing READ inComing WRITE setInComing NOTIFY inComingChanged)
    Q_PROPERTY(FileReader::Type type READ type WRITE setType NOTIFY typeChanged)
    Q_ENUMS(Type)
public:
    explicit FileReader(QObject *parent = nullptr);
    enum Type
    {
        Read,
        Write
    };
  QString fileName();
  QString outPut();
  QString errorString();
  void setFileName(const QString &fileName);
  FileReader::Type type();
  void setType(const FileReader::Type &type);
  QString inComing();
  void setInComing(const QString &incoming);
Q_INVOKABLE void readFile();
  Q_INVOKABLE void exec();


signals:
 void fileNameChanged();
 void outPutChanged(QString str);
 void error();
 void gotError(QString);
 void textChange();
 void typeChanged();
 void inComingChanged();
public slots:
 void handleOut(QString outPut);

 void handleError(QString err);
 private:
  QString m_fileName;
  QString m_outPut;
  QString m_errorString;
 Type m_type;
  QString m_inComing;
};

#endif // FILEREADER_H
