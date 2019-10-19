#ifndef JSONDATA_H
#define JSONDATA_H

#include <QObject>

class JsonData:public QObject
{
    Q_OBJECT
public:
    JsonData(QObject *parent=nullptr);
    ~JsonData();
    void parseJson(const QString & sPath);
public:
signals:
    void sig_Json(const QString &);
private :
    class PrivateData;
    PrivateData *d_data=nullptr;
};

#endif // JSONDATA_H
