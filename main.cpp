#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "./h/PriceMachine.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    PriceMachine priceMachine;
    engine.rootContext()->setContextProperty("priceMachine", &priceMachine);

    const QUrl url(QStringLiteral("qrc:/main.qml"));    
    engine.load(url);

    return app.exec();
}
