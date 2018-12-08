#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QFileDialog>
#include<QMessageBox>
#include"tcp_server.h"
#include<QStringList>
#include<QTimer>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
 void init();
 void updateProcess();
private slots:
    void slot_tbfile();
    void slot_tbok();
    void slot_timerAlarm();
private:
    Ui::Dialog *ui;
    tcp_server m_server;
    QTimer *pTimer;
};

#endif // DIALOG_H
