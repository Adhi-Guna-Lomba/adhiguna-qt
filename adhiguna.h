#ifndef ADHIGUNA_H
#define ADHIGUNA_H
#include "fs.h"
#include "adhigunadownload.h"
#include "adhigunasql.h"
#include "adhigunasystem.h"
#include "adhigunanetwork.h"
#include "traynotificationmanager.h"
#include <QObject>
#include <QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMessageBox>
#include <QtWebKitWidgets/QtWebKitWidgets>
#include <QtNetwork/QNetworkInterface>
#include <QSize>
#include <QVariant>
#include <QPixmap>
#include <QtWidgets/QSplashScreen>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QNetworkProxy>
#include <QFileSystemWatcher>
#include <QThread>
#include <QtGui>

class adhiguna: public QObject
{
    Q_OBJECT
private:
    QWebView web;
    QWebFrame *frame;
    bool fullscreen;
    fs *m_filesystem;
    QtDownload *dl;
    adhigunasql *m_sqldrv;
    adhigunasystem *m_adhigunasystem;
    adhigunanetwork *m_adhigunanetwork;

    QPoint offset;
    bool mMoving;

public:
    adhiguna(QObject *parent = 0);
    TrayNotificationManager *m_notify;
    void render(QString w);
    void show();
    void widgetNoFrame();
    void widgetTransparent();
    void liveCode();
    QString pathLive;
    QString pathApp;
    QString version;
    bool debugging;
    QFileSystemWatcher live;

    void closeEvent(QCloseEvent *);

signals:
    void downloadProgress(qint64 recieved, qint64 total);

private slots:
    void fileChanged(const QString& path) {
        qDebug() << "directory changed: " << path;
        QThread::msleep(50);
        this->web.page()->triggerAction(QWebPage::Reload,true);
    }

public slots:
    //main slot
    void adhigunaJS();
    void setUrl(const QString& url);
    //adhiguna message
    void showMessage(const QString& msg);
    //adhiguna developer mode
    void setDev(bool v);
    void setDevRemote(int port);
    //adhiguna action
    void quit();
    void back();
    void forward();
    void reload();
    void stop();
    void cut();
    void copy();
    void paste();
    void undo();
    void redo();

    void widgetSizeMax(int w,int h);
    void widgetSizeMin(int w,int h);
    void widgetSize(int w,int h);
    void widgetNoTaskbar();
    void getToggleFullScreen();
    void getFullScreen(bool screen);
    void showMaximized();
    void showMinimized();

    QString loadBin(const QString &script);
    //adhiguna manifest
    void config(QString path);
    //adhiguna settings
    void websecurity(bool c);
    //adhiguna network
    void saveFile(const QByteArray &data, QString filename, QString path);
    void download(QString data, QString path);
    void download_signal(qint64 recieved, qint64 total);
    //adhiguna filesystem
    QObject *filesystem();
    //adhiguna sql
    QObject *sql();
    //adhiguna system
    QObject *sys();
    //adhiguna network
    QObject *net();
    //adhigunasdk version
    QString sdkVersion();
    //notify
    void notificationWarning(QString v);
    void notificationInfo(QString v);
};

#endif // ADHIGUNA_H
