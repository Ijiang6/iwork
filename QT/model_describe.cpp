#include "model_describe.h"
#include<QDebug>
Model_Describe::Model_Describe()
{
	 QStringList listName;
	 listName<<tr("设备编号")<<tr("站点名称")<<tr("管理单位ID")<<tr("数据状态");
	 m_headData=listName;
}
void Model_Describe::setUserHeader(const QStringList &strList)
{
	m_headData=strList;
}
int Model_Describe::rowCount(const QModelIndex &parent) const
{
    return  m_mData.size();
}
int Model_Describe::columnCount(const QModelIndex &parent) const
{
    return  m_headData.size();
}
QVariant Model_Describe::data(const QModelIndex &index, int role) const
{
	
	QVector<QStringList> vecData;
	QMap<QString,QStringList>::Iterator it=m_mData.begin();
	while(it != m_mData.end())
	{
		vecData.append(it.value());
		it++;
	}
    if(!index.isValid())
    {
        return QVariant();
    }
    if(role==Qt::TextAlignmentRole)
    {
        return QVariant(Qt::AlignLeft|Qt::AlignCenter);
    }
     if(role==Qt::DisplayRole)
    {
		
        return vecData.at(index.row()).at(index.column());
    }
	 ////Qt::TextColorRole
	 //if (role==Qt::TextColorRole)//Qt::BackgroundRole)
	 //{
		// if (vecData.at(index.row()).at(3)==tr("正常"))
		// {

		//	 return QColor("#34bcb1");
		// }
		// else if(vecData.at(index.row()).at(3)==tr("异常"))
		// {
		//	 return QColor("#28958c");
		// }
		// else
		//	 return Qt::black;
	 //}
	
	 
	return QVariant();
}
QVariant Model_Describe::headerData(int section, Qt::Orientation orientation,int role) const//
{
	if(role==Qt::DisplayRole && orientation==Qt::Horizontal)

		return  m_headData[section];

	return QAbstractTableModel::headerData(section,orientation,role);
}

bool  Model_Describe::upDateData(const QString &strID,const QStringList & listMsg)
{
	bool bOk=false;
	QMap<QString,QStringList>::Iterator it=m_mData.find(strID);
	if (it != m_mData.end())
	{
		it.value()=listMsg;
		bOk=true;
	}
	else
	{
		m_mData.insert(strID,listMsg);
		bOk=true;
	}
	reset();
	return bOk;
}
void Model_Describe::deleteOneData(const QString &strID)
{
	QMap<QString,QStringList>::Iterator it=m_mData.find(strID);
	if (it != m_mData.end())
	{
		m_mData.remove(it.key());
	}
}
QMap<QString,QStringList>  Model_Describe::getData()
{
	return m_mData;
}

