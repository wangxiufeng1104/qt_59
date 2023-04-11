#include "widget.h"
#include "ui_widget.h"
#include <QDateTime>

void Widget::on_timer_timeout()
{
    // 定时器中断响应
    QTime curTime = QTime::currentTime();// 获取当前时间
    ui->LCDHour->display(curTime.hour());// 显示  小时
    ui->LCDMin->display(curTime.minute()); // 显示 分钟
    ui->LCDSec->display(curTime.second()); // 显示 秒
    int va = ui->progressBar->value();
    va ++;
    if(va > 100)
        va = 0;
    ui->progressBar->setValue(va);
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    fTime = new QTimer(this);
    fTime->stop();
    fTime->setInterval(1000); // 设置定时周期，单位毫秒
    connect(fTime, SIGNAL(timeout()), this, SLOT(on_timer_timeout()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnGetDateTime_clicked()
{
    QDateTime curDateTime = QDateTime::currentDateTime();// 读取当前日期时间

    ui->timeEdit->setTime(curDateTime.time()); // 设置时间
    ui->leTime->setText(curDateTime.toString("hh:mm:ss")); // 转换为字符串显示

    ui->dateEdit->setDate(curDateTime.date()); // 设置时间
    ui->leDate->setText(curDateTime.toString("yyyy-MM-dd")); // 转换为字符串显示

    ui->dateTimeEdit->setDateTime(curDateTime);
    ui->leTimeDate->setText(curDateTime.toString("yyyy-MM-dd hh:mm:ss"));// 转换为字符串显示
}

void Widget::on_btnSetTimeDate_clicked()
{
    // 字符串转换为 QDateTime
    QString str=ui->leTimeDate->text();
    str = str.trimmed();
    if(!str.isEmpty())
    {
        QDateTime dateTime = QDateTime::fromString(str, "yyyy-MM-dd hh:mm:ss");
        ui->dateTimeEdit->setDateTime(dateTime);
    }
}

void Widget::on_btnDate_clicked()
{
    // 字符串转换为 QDate
    QString str = ui->leDate->text();
    str = str.trimmed();
    if(!str.isEmpty())
    {
        QDate date = QDate::fromString(str, "yyyy-MM-dd");
        ui->dateEdit->setDate(date);
    }
}

void Widget::on_btnSetTime_clicked()
{
    // 字符串转换为 QTime
    QString str = ui->leTime->text();
    str = str.trimmed();
    if(!str.isEmpty())
    {
        QTime time = QTime::fromString(str, "hh:mm:ss");
        ui->timeEdit->setTime(time);
    }
}

void Widget::on_calendarWidget_selectionChanged()
{
    // 在日历上选择日期
    QDate dt = ui->calendarWidget->selectedDate();
    QString str = dt.toString("yyyy年MM月dd日");
    ui->editCalendar->setText(str);
}

void Widget::on_btnStart_clicked()
{
    fTime->start(); // 定时器开始工作
    fTimeCounter.start();// 计时器开始工作
    ui->btnStart->setEnabled(false);
    ui->btnStop->setEnabled(true);
    ui->btnSetIntv->setEnabled(false);
}

void Widget::on_btnStop_clicked()
{
    fTime->stop(); // 定时器停止
    int tmMsec = fTimeCounter.elapsed();// 毫秒数
    int ms = tmMsec % 1000;
    int sec = tmMsec / 1000;
    QString str = QString::asprintf("流逝时间：%d 秒，%d 毫秒", sec, ms);
    ui->label_6->setText(str);
    ui->btnStart->setEnabled(true);
    ui->btnStop->setEnabled(false);
    ui->btnSetIntv->setEnabled(true);
}

void Widget::on_btnSetIntv_clicked()
{
    int intv = ui->spinBox->value();
    fTime->setInterval(intv);
}
