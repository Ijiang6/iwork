#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QQmlContext>
#include<QUrl>
#include<QStandardPaths>
#include<QStringList>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QUrl addPath(QString("%1").arg(app.applicationDirPath()));
    engine.rootContext()->setContextProperty("addPath",addPath);
    QUrl moviewPath;
    const QStringList movies = QStandardPaths::standardLocations(QStandardPaths::MoviesLocation);
    if(movies.isEmpty())
    {
        moviewPath = addPath.resolved(QUrl("/"));
    }
    else
    {
        moviewPath = movies.join(";");
    }
    engine.rootContext()->setContextProperty("moviewPath",moviewPath);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
