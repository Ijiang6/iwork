#ifndef WARPAFFINEFORM_H
#define WARPAFFINEFORM_H

#include <QWidget>

namespace Ui {
class WarpAffineForm;
}

class WarpAffineForm : public QWidget
{
    Q_OBJECT

public:
    explicit WarpAffineForm(QWidget *parent = 0);
    ~WarpAffineForm();
    void initConection();
signals:
    void sig_updateImg();
public slots:
    void slot_warrf();
    void slot_delFrame();
private:
    Ui::WarpAffineForm *ui;
};

#endif // WARPAFFINEFORM_H
