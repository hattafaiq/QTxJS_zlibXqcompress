#include <QCoreApplication>
#include "QString"
#include <QDebug>
#include "QtNetwork/QNetworkInterface"
#include "QtNetwork/QtNetwork"

QString getMacAddress()
{
    foreach(QNetworkInterface netInterface, QNetworkInterface::allInterfaces())
    {
        // Return only the first non-loopback MAC Address
        if (!(netInterface.flags() & QNetworkInterface::IsLoopBack))
            return netInterface.hardwareAddress();
    }
    return QString();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<getMacAddress();
    return a.exec();
}
