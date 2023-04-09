#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QSpinBox>
#include <QFontComboBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actFontItalic_triggered(bool checked);

    void on_actFontBold_triggered(bool checked);

    void on_actFontUnder_triggered(bool checked);

    void on_txtEdit_copyAvailable(bool b);

    void on_txtEdit_selectionChanged();

    void on_spinBoxFontSize_valueChanged(int aFontSize); //改变字体大小
    void comboFont_currentIndexChanged(const QString &arg1); //选择字体

private:
    QLabel *fLabCurFile; //状态栏显示当前文件的Label
    QProgressBar *progressBar1;//状态栏上的进度条
    QSpinBox *spinFontSize;//  字体大小 spinBox
    QFontComboBox *comboxFont; // 字体名称comboBox
    void initUI();// 代码实现的UI初始化
    Ui::MainWindow *ui;
    void initSignalSlots(); // 关联信号与槽

};

#endif // MAINWINDOW_H
