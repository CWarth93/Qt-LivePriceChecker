#pragma once

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>

class WebScraper : public QObject
{

    Q_OBJECT

public:
    explicit WebScraper(QObject* parent = nullptr);
    void loadHtml(QString url);
    QString readHtml();

private:
    QNetworkAccessManager manager;
    QNetworkReply* response;

private slots:
    void receiveReply();

signals:
    void replyReceived();

};
