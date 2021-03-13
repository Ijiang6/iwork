#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"OpencvInclude.h"
#include<QToolBar>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum ANIMATION_DIRECTION
    {
        LEFT_TO_RIGHT = 0x1,
        RIGHT_TO_LEFT,
        TOP_TO_BOOTM,
        BOOTM_TO_TOP
    };
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
  void initDocWgt();
  void initConnection();
  void initScene();
  void setEnableDockWgtAnimation(QWidget *a_Wgt, bool a_enable);
  void hideWgtAnimation(QWidget *a_wgt, MainWindow::ANIMATION_DIRECTION a_direction, int a_timeout=200);
 void  showWgtAnimation(QWidget *a_wgt, MainWindow::ANIMATION_DIRECTION a_direction, int a_timeout=200);
  bool isDockWidget(QObject* obj);
 bool eventFilter(QObject *obj, QEvent *event);
 bool isDockButton(QObject *obj);
 void removeDockWgtEventFilter(QList<QWidget*> &wgtList, QWidget *diffWgt);
public slots:
  void floatAnimationSlot(bool a_enable);
  void hideAnimationFinishSlot();
  void hoverEnterSlot(QObject*);
  void hoverLeaveSlot(QObject*);
  void showAnimationFinishSlot();
  void slot_openImg();

  void slot_updateImg();
signals:
  void  hoverEnter(QObject*);
  void  hoverLeave(QObject*);

private:
    Ui::MainWindow *ui;
    class PrivateData;
    PrivateData *pData;
};

#endif // MAINWINDOW_H
