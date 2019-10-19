#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include"jsondata.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    //QObject *pJsonobj=new JsonData;
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<JsonData>("com.i.JsonCpp",1,0,"JsonCpp");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
