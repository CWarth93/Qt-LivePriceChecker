#include "../h/WebScraper.h"

#include <QEventLoop>
#include <QNetworkReply>

WebScraper::WebScraper(QObject *parent) : QObject(parent)
{}

void WebScraper::loadHtml(QString url)
{
    QNetworkRequest *request = new QNetworkRequest(QUrl(url));
    request->setRawHeader( "User-Agent", "Mozilla/5.0 (X11; U; Linux i686 (x86_64); "
                               "en-US; rv:1.9.0.1) Gecko/2008070206 Firefox/3.0.1" );
    request->setRawHeader( "charset", "utf-8" );
    request->setRawHeader( "Connection", "keep-alive" );

    this->response =  manager.get(*request);
    QObject::connect(response, SIGNAL(finished()), this, SLOT(receiveReply()));
}

QString WebScraper::readHtml()
{
    QString html = this->response->readAll();
    return html;
}

void WebScraper::receiveReply()
{
    emit replyReceived();               // es kommt nichts..
}
