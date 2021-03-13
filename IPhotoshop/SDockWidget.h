#ifndef SDOCKWIDGET_H
#define SDOCKWIDGET_H

#include <QDockWidget>
#include <QLabel>
#include <QPushButton>
#include <QToolButton>

class SDockTitleBarWgt;
class SDockWidget : public QDockWidget
{
    Q_OBJECT
public:
    explicit SDockWidget(QWidget *parent = 0);
    void                setTitleBarText(const QString& a_text);
    void                setTitleBarIcon(const QIcon& a_icon);

    void                setEnableFloat(bool a_enable);
    QToolButton*        getToolButton() { return m_floatToolBtn; }

signals:
    void                isAnimation(bool);

private slots:
    void                floatBtnClickedSlot(bool);

private:
    SDockTitleBarWgt*   m_titleBarWgt;
    QToolButton*        m_floatToolBtn;
    bool                m_float;
};

class SDockTitleBarWgt : public QWidget
{
public:
    explicit SDockTitleBarWgt(QWidget *parent = 0);

    QLabel*             m_tieleBarText;
    QPushButton*        m_tieleBarIcon;

protected:
    bool                event(QEvent *event);
};
#endif // SDOCKWIDGET_H
