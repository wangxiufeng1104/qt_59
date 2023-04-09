#include <iostream>
#include <QtCore>
#include <QList>
using namespace std;

int main()
{
    // >>>>>>>>>>>>>>>>>>顺序容器类 <<<<<<<<<<<<<<<<<
    /* QList
     * QList 是一个数组形式实现的list
     */
    do
    {
        cout << "+++++++++++++++QList++++++++++++++" << endl;
        QList<QString> aList;
        aList.append("Monday");
        aList.append("Tuesday");
        aList.append("Wednesday");
        aList << "one" << "two" << "three";
        QString str = aList[0];
        qDebug("first: %s", qUtf8Printable(str));
        QString str1 = aList.at(aList.size() - 1);
        qDebug("last :%s", qUtf8Printable(str1));
        qDebug("aList size:%d", aList.size());
        foreach(const QString &s, aList)
        {
            qDebug("%s", qUtf8Printable(s));
        }
        // JAVA 类型迭代器
        cout << "----------java Iterator---------" << endl;
        cout << "==========begin to end==========" << endl;
        QListIterator<QString> i(aList);
        while (i.hasNext()) {
            cout << i.next().toStdString() << endl;
        }
        cout << "==========back to front==========" << endl;
        i.toBack();
        while (i.hasPrevious()) {
            qDebug() << i.previous();
        }
        cout << "-----------writeable list--------" << endl;
        QList<int> list;
        list << 1 << 2 << 3 << 4 << 5 << 6;
        QMutableListIterator<int> j(list); // 使用可修改的迭代器删除奇数项
        while (j.hasNext()) {
            if(j.next() % 2 != 0)
               j.remove();
        }
        j.toFront();
        while (j.hasNext()) {
            cout << j.next() << endl;
        }
        //exit(EXIT_SUCCESS);
    }while(0);

    // QLinkedList
    // QLinkedList 是一个链表容器
    do
    {
        cout << "+++++++++++++++QLinkedList++++++++++++++" << endl;
        QLinkedList<QString> list;
        list.append("one");
        list.append("two");
        list.append("three");
        // list: ["one", "two", "three"]
    }while(0);
    // QVector
    do
    {
        cout << "+++++++++++++++QVector++++++++++++++" << endl;
        // 创建一个大小为10 的动态数组，默认填充为"pass"
        QVector<QString> vector(10, "Pass");
        vector[7] = "Alfonso";
        for (int i = 0; i < vector.size(); ++i) {
              if (vector.at(i) == "Alfonso")
                  cout << "Found Alfonso at position " << i << endl;
              else
                  cout << vector.at(i).toStdString() << endl;
          }
    }while(0);
    // QStack
    do
    {
        cout << "+++++++++++++++QStack++++++++++++++" << endl;
        QStack<int> stack;
        stack.push(10);
        stack.push(20);
        stack.push(30);
        while(!stack.isEmpty())
            cout << stack.pop() << endl;
    }while(0);

    // QQueue
    do
    {
        cout << "+++++++++++++++QQueue++++++++++++++" << endl;
        QQueue<int> queue;
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        while(!queue.isEmpty())
            cout << queue.dequeue() << endl;
    }while(0);

    // >>>>>>>>>>>>>>>>>>>>>>>>>关联容器类<<<<<<<<<<<<<<<<<<<<<<<<<
    // QSet
    do
    {
        cout << "+++++++++++++++QQset++++++++++++++" << endl;
        QSet<QString> set;
        set << "dog" << "cat" << "tiger";
        // 测试一个值是否在这个集合中
        if(set.contains("cat"))
            cout << "contains" << endl;
        if(!set.contains("cat1"))
            cout << "not contains" << endl;
    }while(0);

    // QMap
    /*
     *QMap<key, T> 提供一个字典，一个键映射到一个值。
     * QMap存储数据是按照键的顺序，如果不在乎存储循序，使用QHash会更快
     */
    do
    {
        cout << "+++++++++++++++QMap++++++++++++++" << endl;
        QMap<QString, int> map;
        map["one"] = 1;
        map["two"] = 2;
        map["three"] = 3;
        map.insert("four", 4);
        map.remove("two");
        int num1 = map["four"];
        qDebug("num1:%d", num1);
        int num2 = map.value("three");
        qDebug("num2:%d", num2);
        QMapIterator<QString, int> i(map);
        while (i.hasNext()) {
            i.next();
            cout << i.key().toStdString() << ": " << i.value() << endl;
        }
        QMap<QString, QString> map1;
        map1.insert("Moscow", "Russia");
        map1.insert("Paris", "France");
        map1.insert("New York", "USA");
        map1.insert("Mexico City", "USA");

        QMutableMapIterator<QString, QString> j(map1);
        while (j.hasNext()) {
            if(j.next().key().endsWith("City"))
                j.remove();
        }
        j.toFront();
        while (j.hasNext()) {
            //cout << j.next().key().toStdString() << ": " << j.next().value().toStdString() << endl;
            auto jj = j.next();
            cout  << jj.key().toStdString() << ":" << jj.value().toStdString() << endl;
        }
    }while(0);

    // QMultiMap
    /*
     * QMultiMap 是QMap的子类，用于处理多值映射的便利类
     * 多值映射就是一个键可以对应多个值。QMap正常情况下不允许多值映射，除非使用QMap::insertMulti添加键值对
     */
    do
    {
        cout << "+++++++++++++++QMultiMap++++++++++++++" << endl;
        QMultiMap<QString, int> map1,map2,map3;
        map1.insert("plenty", 100);
        map1.insert("plenty", 2000);  // map1.size() = 2
        map2.insert("plenty", 5000);  // map2.size() = 1
        map3 = map1 + map2;           // map3.size() = 3
        QList<int> values = map3.values("plenty");
        cout << values.size() << endl;
        for(int i = 0; i < values.size(); i++)
            cout << i <<":" << values.at(i) << endl;
        // 存在多值映射可以使用双重foreach循环
        foreach(const QString &str, map3.uniqueKeys())
        {
            foreach(int i , map3.values(str))
                cout << str.toStdString() << ":" << i << endl;
        }
    }while(0);

    /* QHash
     * QHash 是基于散列表来实现字典功能的的模板类，QHash<key,T>存储的键值对具有非常快的查找速度
     */
    do
    {
        cout << "+++++++++++++++QHash++++++++++++++" << endl;
        QHash<QString, int> hash;
        hash["one"] = 1;
        hash["three"] = 3;
        hash["seven"] = 7;
        hash.insert("twelve", 12);
        int num1 = hash["thirteen"];
        int num2 = hash.value("thirteen");
        int timeout = hash.value("TIMEOUT", 30);
        //qInfo("num1:%d,num2:%d,timeout:%d\n", num1, num2, timeout);
        cout << "num1:" << num1 << " num2:" << num2 << " timeout:" << timeout << endl;
        QHash<QString, int>::const_iterator i = hash.constBegin();
        while (i != hash.constEnd()) {
            cout << i.key().toStdString() << ": " << i.value() << endl;
            ++i;
        }
        QHashIterator<QString, int> j(hash);
        while (j.hasNext()) {
            j.next();
            cout << j.key().toStdString() << ": " << j.value() << endl;
        }

    }while(0);

    /* QMultiHash
     * QMultiHash 是QHash的子类，用于处理多值映射的便利类，用法与QMultiMap类似
     */
    do
    {
        cout << "+++++++++++++++QMultiHash++++++++++++++" << endl;
        QMultiHash<QString, int> hash1, hash2, hash3;
        hash1.insert("plenty", 100);
        hash1.insert("plenty", 2000);
        // hash1.size() == 2

        hash2.insert("plenty", 5000);
        // hash2.size() == 1

        hash3 = hash1 + hash2;
        // hash3.size() == 3
        QMultiHash<QString, int>::iterator i = hash3.find("plenty");
        while (i != hash3.end() && i.key() == "plenty") {
            cout << i.value() << endl;
            ++i;
        }
    }while(0);
    return 0;
}
