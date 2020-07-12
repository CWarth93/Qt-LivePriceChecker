#include "../h/PriceMachine.h"

#include <QDebug>


PriceMachine::PriceMachine(QObject *parent) : QObject(parent)
{
    this->initialized = false;
    this->scraper = std::unique_ptr<WebScraper>(new WebScraper());
    connect(this->scraper.get(), SIGNAL(replyReceived()), this, SLOT(newHtmlFetched()));
    this->update();
}

void PriceMachine::update()
{
    this->scraper->loadHtml("https://www.finanzen.net/devisen/kryptowaehrungen");
}

bool PriceMachine::isInitialized()
{
    return this->initialized;
}

QString PriceMachine::getPrice(QString currency)
{
    QString html = this->currentHtml;
    qDebug() << html;
    QString firstSplit = "";
    if(html == "")
    {
        return "";
    }
    else if(currency == "bitcoin")
    {
        firstSplit =  html.split("Bitcoin</a></td>")[1];
    }
    else if(currency == "ethereum")
    {
        firstSplit =  html.split("Ethereum</a></td>")[1];
    }
    else if(currency == "ripple")
    {
        firstSplit =  html.split("Ripple</a></td>")[1];
    }
    else if(currency == "stellar")
    {
        firstSplit =  html.split("Stellar</a></td>")[1];
    }
    QString secondSplit = firstSplit.split("</span> </div></td>")[0];
    QString thirdSplit = secondSplit.split(">")[secondSplit.split(">").length() - 1];
    return thirdSplit;
}

void PriceMachine::newHtmlFetched()
{
    this->currentHtml = this->scraper->readHtml();
    if(!this->initialized)
    {
        this->initialized = true;
    }
    emit this->updated();
}

