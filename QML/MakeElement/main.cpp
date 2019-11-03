#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include"qqml.h"
#include<QQmlContext>
#include"filereader.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<FileReader>("Files",0,1,"ReadFile");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
