#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
private:
    QTimer *fTime; // 定时器
    QTime fTimeCounter; // 计时器
private slots:
    void on_timer_timeout();// 定时器溢出处理函数
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnGetDateTime_clicked();

    void on_btnSetTimeDate_clicked();

    void on_btnDate_clicked();

    void on_btnSetTime_clicked();

    void on_calendarWidget_selectionChanged();

    void on_btnStart_clicked();

    void on_btnStop_clicked();

    void on_btnSetIntv_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
