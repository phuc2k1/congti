#ifndef LOCKDATACLASS_H
#define LOCKDATACLASS_H

#define DATA_LOCK_LINK "/home/selexdev/Desktop/phuc/lockdata/data"
#define NAME_FILE_MASTER "master.txt"
#define NAME_FILE_HTTP "http.txt"
#define NAME_FILE_MQTT "mqtt.txt"

#include "qprocess.h"
#include"qdebug.h"
#include <QDir>
#include<QDateTime>
#include"QString"
#include "qobject.h"
#include "QFile"
typedef enum LOCK_DATA_STATE{
    LOCK_DATA_STATE_INIT =1,
    LOCK_DATA_STATE_CREATEFILE=2,
    LOCK_DATA_STAE_READING=3,
    LOCK_DATA_STATE_WRITING=4,
    LOCK_DATA_STATE_READY=5,
}LOCK_DATA_STATE;
typedef enum LOCK_DATA_ERROR{
    LOCK_DATA_ERROR_WRITING =1,
    LOCK_DATA_ERROR_READING=2,
    LOCK_DATA_ERROR_INIT=3,
}LOCK_DATA_ERROR;
class lockdataclass: public QObject
{
    Q_OBJECT
public:
    lockdataclass();
private:
    //QProcess process;
    QString folderPath;
    QString timenow;
    QString namefolder;
    LOCK_DATA_ERROR error_state;
    LOCK_DATA_STATE lock_state;
private:
    void start();
    void readlistfolder(QStringList &list);
    void readtimenow(QString &time);
    void createfolder(QString namefolder);
    bool createfile(QString namefile,QString namefolder);
    bool checkfolder();
    bool checkfolderagain();
    bool checkfile(QString namefolder,QString namefile);
    bool checkfileagain(QString namefolder,QString namefile);
private:
    void readfile(int code,int namefile);
signals:
    void  WriteLockdata();

public slots:
};

#endif // LOCKDATACLASS_H
