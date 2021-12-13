#ifndef VK_API_H
#define VK_API_H

#include <QNetworkReply>
#include <QUrlQuery>
#include <QEventLoop>
#include <QJsonDocument>
#include <QDebug>
#include <QMovie>


class User {
public:
    quint64 id;
    QString first_name;
    QString last_name;
};


class Message {
public:
    Message(quint64, QString, quint64, QString, QString);
    User from_user;
    QString text;
    quint64 id;
};


class VK : public QObject{
    Q_OBJECT
public:
    VK(QString access_token);
    QJsonDocument getMessages(QString);
    QJsonDocument getUser(quint64);
    QVector<Message> getVectorMessages(QString);


private:
    QByteArray getResponse(QUrl);

    const QString _access_token;
    const QString _api_version = "5.131";
};

#endif // VK_API_H
