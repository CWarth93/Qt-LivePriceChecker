#pragma once

#include <memory>

#include <QObject>

#include "WebScraper.h"

class PriceMachine : public QObject
{
    Q_OBJECT

    public:
        explicit PriceMachine(QObject *parent = nullptr);

    public slots:
        void update();
        bool isInitialized();
        QString getPrice(QString currency);

    signals:
        void updated();

    private slots:
        void newHtmlFetched();

    private:
        std::unique_ptr<WebScraper> scraper;
        QString currentHtml;
        bool initialized;

};
