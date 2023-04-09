#include "qperson.h"

QPerson::QPerson(QString fName, QObject *parent) : QObject(parent),m_name(fName)
{

}

int QPerson::getAge()
{
    return m_age;
}

void QPerson::setAge(int value)
{
    m_age = value;
    emit ageChanged(m_age); // 发射信号
}

void QPerson::incAge()
{
    m_age ++;
    emit ageChanged(m_age); // 发射信号
}
