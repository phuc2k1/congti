#include <QCoreApplication>
#include "QDebug"
#include"lockdataclass.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"Start!";
    lockdataclass lockdata;

    return a.exec();
}
