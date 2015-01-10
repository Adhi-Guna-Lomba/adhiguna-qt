#ifndef IGNNETWORK_H
#define IGNNETWORK_H

#include <QObject>
#include <QNetworkInterface>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QNetworkProxy>

class adhigunanetwork : public QObject
{
    Q_OBJECT
public:
    explicit adhigunanetwork(QObject *parent = 0);
public slots:
    QString myIP();
    void setProxy(const QVariant &config);
};

#endif // IGNNETWORK_H
