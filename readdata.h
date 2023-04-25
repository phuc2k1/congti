
#ifndef READDATA_H
#define READDATA_H
#define LINK "/home/pi/Downloads/CodeDieuKhuyen/listview/data.txt"

#include <QFile>
#include <QTextStream>
#include <QString>
#include "qdebug.h"
#include"qlist.h"
class readdata
{
public:
    readdata();
    bool getdata(int vitri);
    void setdata(QString datainput,int vitri);
    uint32_t getvitri();



private:
    QString data;

};

#endif // READDATA_H
