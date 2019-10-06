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
    pTimer = new QTimer;
    connect(pTimer ,&QTimer::timeout ,this, &JsonData::slot_timeOut);
//    pTimer->start(5000);
}
JsonData::~JsonData()
{
    delete d_data;
}

void JsonData::slot_timeOut()
{
    emit sig_updateitem();
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
    emit sig_JsonChange( d_data->strJsonData ) ;
}
QString JsonData::getJsonData()
{
    return m_jsonData;
}
void JsonData::setJsonData(const QString &data)
{
    if( !data.isEmpty() )
    {
        m_jsonData = data ;
    }
}
void JsonData::setmapInfo(const QMap<QString,QString> &data)
{
    m_info["活力补给站 | 从这些歌里听见年轻的心跳"]=":/icons/Icons/musicinfo.png";
    m_info["<秋日微醺>想来点舒适度100%的微风吗"]=":/icons/Icons/musicinfo.png";
    m_info["滚石杂志:历年五星专辑全收录"]=":/icons/Icons/musicinfo.png";
    m_info["情绪河豚 | 不要温和地走进那个墨绿的夜"]=":/icons/Icons/musicinfo.png";
}
QMap<QString,QString> JsonData::getmapInfo()
{
    return m_info;
}
