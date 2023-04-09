#ifndef QMYWIDGET_H
#define QMYWIDGET_H

#include <QWidget>
#include "qperson.h"
namespace Ui {
class QmyWidget;
}

class QmyWidget : public QWidget
{
    Q_OBJECT
private:
    QPerson *boy;
    QPerson *girl;

public:
    explicit QmyWidget(QWidget *parent = nullptr);
    ~QmyWidget();
private slots:
    void on_ageChanged(int value);
    void on_spin_valueChanged(int value);

    void on_btnBoyInc_clicked();

    void on_btnGirlInc_clicked();

    void on_btnClassInfo_clicked();

    void on_btnClear_clicked();
    void initPerson();

private:
    Ui::QmyWidget *ui;
};

#endif // QMYWIDGET_H
