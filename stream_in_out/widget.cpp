#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnCalculate_clicked()
{
    QString str = ui->editNum->text();//读取数量
    int num = str.toInt();
    str = ui->editPrice->text();// 读取单价
    float price = str.toFloat();
    float total = num * price;
    //str = str.sprintf("%.2f", total);
    //str = QString::number(total, 'f', 2);
    //str = QString::asprintf("%.2f", total);
    str = str.setNum(total, 'f', 2);
    ui->editTotal->setText(str);
}

void Widget::on_btnDecimal_clicked()
{
    // 读取十进制数，转换为其他进制
    QString str = ui->editDecimal->text();
    int val = str.toInt(); // 缺省为十进制
    str = str.setNum(val, 16); // 十六进制
    str = str.toUpper();
    ui->editHex->setText(str);

    str = str.setNum(val, 2);//二进制
    ui->editBinary->setText(str);
}

void Widget::on_btnBinary_clicked()
{
    // 读取二进制数，转换为其他进制
    bool ok;
    QString str = ui->editBinary->text();
    int val = str.toInt(&ok, 2); // 以二进制读取
    str = str.setNum(val, 10); // 数字显示为十进制字符串
    ui->editDecimal->setText(str);

    str = str.setNum(val, 16);// 显示为十六进制
    str = str.toUpper();
    ui->editHex->setText(str);
}

void Widget::on_btnHex_clicked()
{
    // 读取十六进制数，转换为其他进制
    bool ok;
    QString str = ui->editHex->text();
    int val = str.toInt(&ok, 16); // 以十六进制读取
    str = str.setNum(val, 10); // 数字显示为十进制字符串
    ui->editDecimal->setText(str);

    str = str.setNum(val, 2);// 显示为二进制
    str = str.toUpper();
    ui->editBinary->setText(str);
}

void Widget::on_btnAppend_clicked()
{
    QString str1 = ui->comboBox->currentText();
    QString str2 = ui->comboBox_2->currentText();
    auto str3 = str1.append(str2);
    ui->editResult->setText(str3);
}

void Widget::on_btnPrepend_clicked()
{
    QString str1 = ui->comboBox->currentText();
    QString str2 = ui->comboBox_2->currentText();
    auto str3 = str1.prepend(str2);
    ui->editResult->setText(str3);
}

void Widget::on_btnToUpper_clicked()
{
    auto str = ui->editResult->text();
    str = str.toUpper();
    ui->editResult->setText(str);
}

void Widget::on_btnToLower_clicked()
{
    auto str = ui->editResult->text();
    str = str.toLower();
    ui->editResult->setText(str);
}

void Widget::on_btnLeft_clicked()
{
    QString str1,str2;
    str1 = ui->comboBox->currentText();
    int cnt = str1.size();
    int v = ui->spinBox->value();
    // str从左取v个字节
    str2 = str1.left(v);
    ui->editResult->setText(str2);
}

void Widget::on_btnRight_clicked()
{
    QString str1,str2;
    str1 = ui->comboBox->currentText();
    int cnt = str1.size();
    int v = ui->spinBox->value();
    // str从右取cnt-v-1个字节
    str2 = str1.right(cnt - v -1);
    ui->editResult->setText(str2);
}

void Widget::on_btnSection_clicked()
{
    //section()函数
    int i;
    QString str1,str2,str3;
    str1=ui->comboBox->currentText();
    i=ui->spinBox->value();
    //    str2=str1.section('\\',2,2);
    str3=ui->comboBox_2->currentText();
    if (QString::compare(str3,"\\",Qt::CaseInsensitive)==0)
        str2=str1.section('\\',i,i+1); //
    else
        str2=str1.section(str3,i,i+1); //

    ui->editResult->setText(str2);
}

void Widget::on_btnSimplified_clicked()
{
    //simplified()函数
    QString str1 = " Are     you     OK ?", str2;
    str2=str1.simplified();
    ui->editResult->setText(str2);
}

void Widget::on_btnTrimm_clicked()
{
    //simplified()函数
    QString str1 = " Are     you     OK ?    ", str2;
    str2=str1.trimmed();
    ui->editResult->setText(str2);
}

void Widget::on_btnCount_clicked()
{
    QString str1=ui->comboBox->currentText();
    int i=str1.count();
//    int i=str1.length();
    ui->spinBox->setValue(i);
    ui->label_10->setText("count()");
}

void Widget::on_btnSize_clicked()
{
    QString str1=ui->comboBox->currentText();
    int i=str1.size();
//    int i=str1.length();
    ui->spinBox->setValue(i);
    ui->label_10->setText("size()");
}

void Widget::on_btnIndexOf_clicked()
{
    QString str1 = ui->comboBox->currentText();
    QString str2 = ui->comboBox_2->currentText();
    // 查找str2最先出现的位置
    int N = str1.indexOf(str2);
    ui->spinBox->setValue(N);
    ui->label_10->setText("indexof()");
}

void Widget::on_btnLastIndexOf_clicked()
{
    QString str1 = ui->comboBox->currentText();
    QString str2 = ui->comboBox_2->currentText();
    // 查找str2最后出现的位置
    int N = str1.lastIndexOf(str2);
    ui->spinBox->setValue(N);
    ui->label_10->setText("lastIndexOf()");
}

void Widget::on_btnEndsWith_clicked()
{
    // endsWith 判断是否以某个字符串结束
    QString str1 = ui->comboBox->currentText();
    QString str2 = ui->comboBox_2->currentText();
    int N = str1.endsWith(str2);
    ui->spinBox->setValue(N);
    ui->label_10->setText("endsWith()");
}

void Widget::on_btnStartsWith_clicked()
{
    // startsWith 判断是否以某个字符串开头
    QString str1 = ui->comboBox->currentText();
    QString str2 = ui->comboBox_2->currentText();
    int N = str1.startsWith(str2);
    ui->spinBox->setValue(N);
    ui->label_10->setText("startsWith()");
}

void Widget::on_btnContains_clicked()
{
    // 判断字符串内是否包含某个字符串
    QString str1 = ui->comboBox->currentText();
    QString str2 = ui->comboBox_2->currentText();
    int N = str1.contains(str2);
    ui->spinBox->setValue(N);
    ui->label_10->setText("contains()");
}

void Widget::on_btnIsNull_clicked()
{
    QString str1,str2 = "";
    int N = str1.isNull();
    ui->spinBox->setValue(N);
    ui->label_10->setText("isNull()");
}

void Widget::on_btnIsEmpty_clicked()
{
    QString str1,str2 = "";
    int N = str2.isEmpty();
    ui->spinBox->setValue(N);
    ui->label_10->setText("isEmpty()");
}
