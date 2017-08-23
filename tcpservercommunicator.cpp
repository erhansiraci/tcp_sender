#include "tcpservercommunicator.h"

TCPServerCommunicator::TCPServerCommunicator(QObject *parent) :
    QObject(parent)
{
}

void TCPServerCommunicator::openTcpSession()
{
    tcpSocket = new QTcpSocket(this);

    tcpSocket->connectToHost(tcpHost,tcpPort.toInt());

    if(tcpSocket->waitForConnected(1000))
    {
        qDebug() << "Connected";
    }
    else
    {
        openTcpSession();
    }

    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(handle_error(QAbstractSocket::SocketError)));
}

void TCPServerCommunicator::handle_error(QAbstractSocket::SocketError e)
{
    qDebug() << e << "  : tcpSocket error : "  <<  tcpSocket->errorString();
}


void TCPServerCommunicator::send_data()
{
    if (tcpSocket->isOpen())
    {
        QByteArray data = tcpData.toLatin1();
        qDebug() << tcpData;
        tcpSocket->write(data);
        tcpSocket->waitForBytesWritten();
    }
}
