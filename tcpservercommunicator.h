#ifndef TCPSERVERCOMMUNICATOR_H
#define TCPSERVERCOMMUNICATOR_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>

class TCPServerCommunicator : public QObject
{
    Q_OBJECT
public:
    explicit TCPServerCommunicator(QObject *parent = 0);
    QTcpSocket *tcpSocket;
    QString tcpPort;
    QString tcpHost;
    QString tcpData;
signals:

public slots:
    void openTcpSession();
    void handle_error(QAbstractSocket::SocketError e);
    void send_data();
};

#endif // TCPSERVERCOMMUNICATOR_H
