#include "adhigunasystem.h"
#include <QDebug>

adhigunasystem::adhigunasystem(QObject *parent)
    : QObject(parent)
{

}

QString adhigunasystem::cliOut(const QString& cli){
    QProcess os;
    os.setProcessChannelMode(QProcess::MergedChannels);
    os.start(cli);
#ifdef Q_WS_X11
    int pid = os.pid();
    qDebug() << pid;
#endif
    os.waitForFinished(-1);
    return os.readAllStandardOutput();
}

QString adhigunasystem::hash(const QString &data,QString hash_func){
    QByteArray hash;
    QByteArray byteArray = data.toLatin1();
    if(hash_func == "md4"){
        hash=QCryptographicHash::hash(byteArray,QCryptographicHash::Md4);
    }
    else if(hash_func == "md5"){
        hash=QCryptographicHash::hash(byteArray,QCryptographicHash::Md5);
    }
    else if(hash_func == "sha1"){
        hash=QCryptographicHash::hash(byteArray,QCryptographicHash::Sha1);
    }
    else if(hash_func == "sha224"){
        hash=QCryptographicHash::hash(byteArray,QCryptographicHash::Sha224);
    }
    else if(hash_func == "sha256"){
        hash=QCryptographicHash::hash(byteArray,QCryptographicHash::Sha256);
    }
    else if(hash_func == "sha384"){
        hash=QCryptographicHash::hash(byteArray,QCryptographicHash::Sha384);
    }
    else if(hash_func == "sha512"){
        hash=QCryptographicHash::hash(byteArray,QCryptographicHash::Sha512);
    }

    return hash.toHex();
}

void adhigunasystem::desktopService(const QString &link){
    QDesktopServices ::openUrl(QUrl(link));
}

void adhigunasystem::exec(const QString& cli){
    proc = new QProcess( this );
    proc->setReadChannelMode(QProcess::MergedChannels);
    connect( proc, SIGNAL(readyReadStandardOutput()), this, SLOT( _out()) );
    proc->start(cli);
    qDebug()<<cli;
}

void adhigunasystem::_out(){
    emit out(proc->readAllStandardOutput());
}

void adhigunasystem::kill(){
    proc->kill();
}
