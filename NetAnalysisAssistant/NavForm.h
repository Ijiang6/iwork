#ifndef NAVFORM_H
#define NAVFORM_H

#include <QWidget>

namespace Ui {
class NavForm;
}

class NavForm : public QWidget
{
    Q_OBJECT

public:
    explicit NavForm(QWidget *parent = nullptr);
    ~NavForm();
void init();
public slots:
 void btnClicked();
signals:
 void sig_curWgtIndex(int index);
 void sig_capture();
private slots:
 void on_toolButton_capture_clicked();

 void on_toolButton_clicked();

private:
    Ui::NavForm *ui;
};

#endif // NAVFORM_H
