#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
  void init();
public slots:
    void  slot_dispalyMsg(const QString & msg);
    void   slot_curWgtIndex(int index);
    void slot_capture();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
