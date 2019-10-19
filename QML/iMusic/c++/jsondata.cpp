#include "jsondata.h"
#include<QFile>
class JsonData::PrivateData
{
public:
    QString strJsonPath;
    QString strJsonData;

};

JsonData::JsonData(QObject *parent)
    :QObject (parent)
{
    d_data =new PrivateData;
}
JsonData::~JsonData()
{
    delete d_data;
}
void JsonData::parseJson(const QString & sPath )
{
    if ( sPath.isEmpty() )
    {
        return ;
    }
    d_data->strJsonPath = sPath;
    QFile file ( d_data->strJsonPath );
    if( !file.open ( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        return;
    }
    d_data->strJsonData = file.readAll();
    emit sig_Json( d_data->strJsonData ) ;
}
