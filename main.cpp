#include <QCoreApplication>
#include "tcpservercommunicator.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString hostname = "";
    QString port = "";
    QString data = "";

    if(argc>3)
    {
        if(argv[1] != NULL)
        {
            hostname = argv[1];
        }

        if(argv[2] != NULL)
        {
            port = argv[2];
        }

        if(argv[3] != NULL)
        {
            data = argv[3];
        }

        TCPServerCommunicator sender;
        sender.tcpHost = hostname;
        sender.tcpPort = port;
        sender.tcpData = data;
        sender.openTcpSession();
        sender.send_data();
    }
    else
        qDebug() << "Please set parameters correctly tcp_sender.exe <ip_address> <port> <data>";
    return 0;
}
