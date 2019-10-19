#ifndef JSONDATA_H
#define JSONDATA_H

#include <QObject>
#include<QMap>
#include<QStringList>
#include<QTimer>
class JsonData:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString m_jsonData READ getJsonData WRITE setJsonData NOTIFY sig_JsonChange);
    Q_PROPERTY(QString name WRITE setName);

public:
    JsonData(QObject *parent=nullptr);
    ~JsonData();
    void parseJson(const QString & sPath);
    void setJsonData(const QString &data);
    void setName(const QString & sPath)
    {
      name =sPath;
    }

    QString getJsonData();
    void setmapInfo(const QMap<QString,QString> &data);
    QMap<QString,QString> getmapInfo();

public:
signals:
    void sig_updateitem();
    void sig_JsonChange(const QString &);
    void sig_mapInfoChange(const QMap<QString,QString> &);
 public slots:
    void slot_timeOut();
private :
    class PrivateData;
    PrivateData *d_data=nullptr;
    QString m_jsonData=":/icons/Icons/musicinfo.png";
    QString name="music";
    QMap<QString,QString>m_info;
    QTimer *pTimer =nullptr;

};

#endif // JSONDATA_H
