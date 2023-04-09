#ifndef QPERSON_H
#define QPERSON_H

#include <QObject>

class QPerson : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("author", "xiufeng")
    Q_CLASSINFO("company", "UPC")
    Q_CLASSINFO("version", "1.0.0")
    Q_PROPERTY(int age READ getAge WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(int score MEMBER m_score)
private:
    int m_age = 0;
    QString m_name;
    int m_score = 79;
public:
    explicit QPerson(QString fName, QObject *parent = nullptr);
    int getAge();
    void setAge(int value);
    void incAge();
signals:
    void ageChanged(int value);
public slots:
};

#endif // QPERSON_H
