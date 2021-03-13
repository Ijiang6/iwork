#ifndef UDPFORM_H
#define UDPFORM_H

#include <QWidget>
#include"SGlobal.h"
#include"pcap.h"
#include"tchar.h"
#include"DataFormat.h"
namespace Ui {
class RealForm;
}

class RealForm : public QWidget
{
    Q_OBJECT

public:
    explicit RealForm(QWidget *parent = nullptr);
    ~RealForm();
  void  startCapture();

public slots:
  void  slot_realPackage();
private:
    Ui::RealForm *ui;
};

#endif // UDPFORM_H
