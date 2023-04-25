
#include "readdata.h"

readdata::readdata()
{


}

bool readdata::getdata(int vitri)
{
    QFile file(LINK);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QString _data= file.readAll();
        QList<QString> list=_data.split("");
        if(list[vitri]!="1"){return false;}else{return true;}
    }
    else{qDebug()<<"Error read data";}
}
void readdata::setdata(QString datainput,int vitri){
    QFile file(LINK);
    QTextStream in(&file);
    if (file.open(QIODevice::ReadWrite | QIODevice::Text|QIODevice::Truncate)){
        QString _data= file.readAll();
        QList<QString> list=_data.split("");
        list[vitri]=datainput;
        QString _datasave=list.join("");
        in<<_datasave;
    }
    else{qDebug()<<"Error read data";}
    file.close();
}

uint32_t readdata::getvitri()
{
    if(!getdata(0)){return 1;}
    if(!getdata(1)){return 2;}
    if(!getdata(2)){return 3;}
    return 4;
}

