#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QVBoxLayout>
#include <QComboBox>
//#include "paintingwidget.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    inline DWORD getBit(DWORD a, int k)
//    {
//        return (a>>k) & 1;
//    }
private:
    QVBoxLayout *m_layout;
  //  PaintingWidget *m_painting;
};

#endif // MAINWINDOW_H
