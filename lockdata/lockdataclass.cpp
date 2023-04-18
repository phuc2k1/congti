#include "lockdataclass.h"


lockdataclass::lockdataclass()
{
    folderPath = DATA_LOCK_LINK;
    this->lock_state=LOCK_DATA_STATE_INIT;



}

void lockdataclass::readlistfolder(QStringList &list)
{
    QDir folder(folderPath);
    QStringList fileList = folder.entryList();
    QProcess process;
    process.start("ls", QStringList() << folderPath);
    process.waitForFinished();
    QString output = process.readAll();
    list = output.split("\n",QString::SkipEmptyParts);



}

void lockdataclass::readtimenow(QString &time)
{QDateTime now = QDateTime::currentDateTime();

    // Lấy ngày, tháng, năm hiện tại
    QDate currentDate = now.date();
    QString year =QString::number( currentDate.year());
    QString month = QString::number(currentDate.month());
    QString day =QString::number( currentDate.day());
    time=day+"_"+month+"_"+year;

}

void lockdataclass::createfolder(QString namefolder)
{
    QString folderPath = DATA_LOCK_LINK+namefolder;
    QProcess process;
    QStringList args;
    args << "-p" << folderPath;
    process.start("mkdir", args);
    process.waitForFinished();

}

void lockdataclass::start()
{
    if(checkfolder()){
        if(checkfile(namefolder,NAME_FILE_MASTER)&&checkfile(namefolder,NAME_FILE_HTTP)&&checkfile(namefolder,NAME_FILE_MQTT)){
                qDebug()<<"INIT Success";
                this->lock_state=LOCK_DATA_STATE_READY;
    }
        else{
            qDebug()<<"ERROR INIT";
            this->error_state=LOCK_DATA_ERROR_INIT;
        }

    }
}

bool lockdataclass::checkfolder()
{
    QStringList listfoder;
    readtimenow(timenow);
    readlistfolder(listfoder);
    if(listfoder.contains(timenow)){
        namefolder=timenow;
        return true;
    }else
    {
        createfolder(timenow);
        if(checkfolderagain()){
            namefolder=timenow;
            return true;
        }
        else{
            return false;
        }


    }
}
bool lockdataclass::checkfolderagain()
{
    QStringList listfoder;
    readtimenow(timenow);
    readlistfolder(listfoder);
    if(listfoder.contains(timenow)){
        return true;
    }else
    {
        return false;

    }
}
bool lockdataclass::createfile(QString namefolder,QString namefile){
    QString filePath =DATA_LOCK_LINK+namefolder+namefile;
    QFile file(filePath);
    if(checkfile(namefolder,namefile)){
        return true;
    }
    else{
        return false;
    }

}
bool lockdataclass::checkfile(QString namefolder,QString namefile){
    QString folderPath =DATA_LOCK_LINK+namefolder;
    QDir folder(folderPath);
    if(folder.exists(namefile)){
        return true;
    }
    else{
        createfile(namefolder,namefile);
        if(checkfileagain(namefolder,namefile)){
            return true;
        }
        else{
            return false;
        }

    }
}
bool lockdataclass::checkfileagain(QString namefolder,QString namefile){
    QString folderPath =DATA_LOCK_LINK+namefolder;
    QDir folder(folderPath);
    if(folder.exists(namefile)){
        return true;
    }
    else{
        return false;
    }
}
