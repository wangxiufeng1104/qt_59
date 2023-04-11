#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnCalculate_clicked();

    void on_btnDecimal_clicked();

    void on_btnBinary_clicked();

    void on_btnHex_clicked();

    void on_btnAppend_clicked();

    void on_btnPrepend_clicked();

    void on_btnToUpper_clicked();

    void on_btnToLower_clicked();

    void on_btnLeft_clicked();

    void on_btnRight_clicked();

    void on_btnSection_clicked();

    void on_btnSimplified_clicked();

    void on_btnTrimm_clicked();

    void on_btnCount_clicked();

    void on_btnSize_clicked();

    void on_btnIndexOf_clicked();

    void on_btnLastIndexOf_clicked();

    void on_btnEndsWith_clicked();

    void on_btnStartsWith_clicked();

    void on_btnContains_clicked();

    void on_btnIsNull_clicked();

    void on_btnIsEmpty_clicked();

    void on_btnCalculate_2_clicked();

    void on_btnDecimal_2_clicked();

    void on_btnBinary_2_clicked();

    void on_btnHex_2_clicked();

    void slider_color_valueCHanged(int value);

    void on_sliderRed_2_valueChanged(int value);

    void on_horizontalScrollBar_valueChanged(int value);

    void on_progressBar_valueChanged(int value);

    void on_dial_valueChanged(int value);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_3_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
