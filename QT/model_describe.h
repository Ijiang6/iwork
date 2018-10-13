#ifndef MODEL_DESCRIBE_H
#define MODEL_DESCRIBE_H
#include<QAbstractTableModel>
#include<QStringList>
#include<QVector>
#include <QMap>
 #include <QColor>
class Model_Describe : public QAbstractTableModel
{
public:
    Model_Describe();
    int  rowCount(const QModelIndex &parent)const;
    int columnCount(const QModelIndex &parent) const;
    QVariant    data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,int role) const;
	void setUserHeader(const QStringList &strList);
	bool upDateData(const QString &strID,const QStringList & listMsg);//数据更新
	QMap<QString,QStringList> getData();
	void deleteOneData(const QString &strID);
	/*bool insertRows ( int row, int count, const QModelIndex & parent );

	void refrushModel();
	void clearData();*/
private:
    QStringList  m_data;
    QStringList  m_headData;
    QMap<QString,QStringList>m_mData;
	QVariant nowData;
};

#endif // MODEL_DESCRIBE_H
