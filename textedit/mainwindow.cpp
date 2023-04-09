#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUI();
    initSignalSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI()
{
    // 状态栏上添加组件
    fLabCurFile = new QLabel;
    fLabCurFile->setMinimumWidth(150);
    fLabCurFile->setText("当前文件：");
    ui->statusBar->addWidget(fLabCurFile); //添加到状态栏

    progressBar1 = new QProgressBar;
    progressBar1->setMaximumWidth(200);
    progressBar1->setMinimum(5);
    progressBar1->setMaximum(50);
    progressBar1->setValue(ui->txtEdit->font().pointSize());
    ui->statusBar->addWidget(progressBar1); //添加到状态栏
    // 工具栏上添加组件
    spinFontSize = new QSpinBox; // 文字大小 SpinBox
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
    spinFontSize->setValue(ui->txtEdit->font().pointSize());
    spinFontSize->setMinimumWidth(50);

    ui->mainToolBar->addWidget(new QLabel("字体大小 "));
    ui->mainToolBar->addWidget(spinFontSize); //spinBox添加到工具栏

    ui->mainToolBar->addSeparator();//分隔符
    ui->mainToolBar->addWidget(new QLabel(" 字体 "));

    comboxFont = new QFontComboBox;
    comboxFont->setMinimumWidth(150);
    ui->mainToolBar->addWidget(comboxFont); // 添加到工具栏
    setCentralWidget(ui->txtEdit);
}
void MainWindow::initSignalSlots()
{
    //信号与槽的关联，当函数带有参数时，必须写明参数的类型
    connect(spinFontSize, SIGNAL(valueChanged(int)),
            this, SLOT(on_spinBoxFontSize_valueChanged(int)));
    connect(comboxFont, SIGNAL(currentIndexChanged(const QString &)),
            this, SLOT(comboFont_currentIndexChanged(const QString &)));
}

void MainWindow::on_actFontItalic_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt=ui->txtEdit->currentCharFormat();
    fmt.setFontItalic(checked);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_actFontBold_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->txtEdit->currentCharFormat();
    if(checked)
        fmt.setFontWeight(QFont::Bold);
    else
       fmt.setFontWeight(QFont::Normal);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_actFontUnder_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt=ui->txtEdit->currentCharFormat();
    fmt.setFontUnderline(checked);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_txtEdit_copyAvailable(bool b)
{
    // 更新cut、copy、paste的enabled属性
    ui->actCut->setEnabled(b);
    ui->actCopy->setEnabled(b);
    ui->actPaste->setEnabled(ui->txtEdit->canPaste());
}

void MainWindow::on_txtEdit_selectionChanged()
{
    // 更新粗体、斜体和下划线3种action的checked属性
    QTextCharFormat fmt;
    fmt = ui->txtEdit->currentCharFormat();// 获取文字的格式
    ui->actFontItalic->setChecked(fmt.font().italic());// 是否斜体
    ui->actFontBold->setChecked(fmt.font().bold());//是否加粗
    ui->actFontUnder->setChecked(fmt.font().underline());//是否有下划线
}

void MainWindow::on_spinBoxFontSize_valueChanged(int aFontSize)
{
    // 改变字体大小的SpinBox
    using namespace  std;
    cout << "aFontSize:" << aFontSize << endl;
    QTextCharFormat fmt;
    fmt.setFontPointSize(aFontSize); // 设置字体大小
    ui->txtEdit->mergeCurrentCharFormat(fmt);
    progressBar1->setValue(aFontSize);
}
void MainWindow::comboFont_currentIndexChanged(const QString &arg1)
{
    // FontCombobox的响应，选择字体名称
    QTextCharFormat fmt;
    fmt.setFontFamily(arg1); // 设置字体名称
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}
