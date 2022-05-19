#include "clienttcp.h"
#include <QDebug>

clienttcp::clienttcp()
{
    initDone = false;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == INVALID_SOCKET)
    {
        qDebug() <<"socket() failed";
    }
    else
    {
        initDone = true;
    }

}

bool clienttcp::connectToHost(QString ip , uint port)
{
    struct hostent *hostinfo = NULL;
    SOCKADDR_IN sin = { 0 }; /* initialise la structure avec des 0 */
    const char *hostname = ip.toStdString().c_str();

    hostinfo = gethostbyname(hostname); /* on récupère les informations de l'hôte auquel on veut se connecter */
    if (hostinfo == NULL) /* l'hôte n'existe pas */
    {
        qDebug() << "Unknow host " << hostname;
        return false;
    }

    sin.sin_addr = *(IN_ADDR *) hostinfo->h_addr; /* l'adresse se trouve dans le champ h_addr de la structure hostinfo */
    sin.sin_port = htons(port); /* on utilise htons pour le port */
    sin.sin_family = AF_INET;

    if(connect(sock,(SOCKADDR *) &sin, sizeof(SOCKADDR)) == SOCKET_ERROR)
    {
        qDebug() <<"connect() failed";
        return false;
    }
    return true;
}

char clienttcp::envoieCelsiusCapteur1()
{

    QString message ="Td01?";
    QByteArray mes = message.toLocal8Bit();
    const char *buffer =mes.data();


    if(send(sock, buffer, strlen(buffer), 0) < 0)
    {

        perror("send()");
        exit(errno);
    }
}

char clienttcp::envoieCelsiusCapteur2()
{
    QString message ="Td02?";
    QByteArray mes = message.toLocal8Bit();
    const char *buffer =mes.data();




    if(send(sock, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        exit(errno);
    }
}

char clienttcp::envoieCelsiusCapteur3()
{

    QString message ="Td03?";
    QByteArray mes = message.toLocal8Bit();
    const char *buffer =mes.data();

    if(send(sock, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        exit(errno);
    }
}

char clienttcp::envoieFahrenheitCapteur1()
{

    QString message ="Tf01?";
    QByteArray mes = message.toLocal8Bit();
    const char *buffer =mes.data();

    if(send(sock, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        exit(errno);
    }
}

char clienttcp::envoieFahrenheitCapteur2()
{

    QString message ="Tf02?";
    QByteArray mes = message.toLocal8Bit();
    const char *buffer =mes.data();

    if(send(sock, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        exit(errno);
    }
}

char clienttcp::envoieFahrenheitCapteur3()
{

    QString message ="Tf03?";
    QByteArray mes = message.toLocal8Bit();
    const char *buffer =mes.data();

    if(send(sock, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        exit(errno);
    }
}

char clienttcp::envoieHygrometrieCapteur1()
{

    QString message ="Hr01?";
    QByteArray mes = message.toLocal8Bit();
    const char *buffer =mes.data();

    if(send(sock, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        exit(errno);
    }
}

char clienttcp::envoieHygrometrieCapteur2()
{

    QString message ="Hr02?";
    QByteArray mes = message.toLocal8Bit();
    const char *buffer =mes.data();

    if(send(sock, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        exit(errno);
    }
}

char clienttcp::envoieHygrometrieCapteur3()
{

    QString message ="Hr03?";
    QByteArray mes = message.toLocal8Bit();
    const char *buffer =mes.data();

    if(send(sock, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        exit(errno);
    }
}

char clienttcp::receptiondonnees()
{
    if(sock != INVALID_SOCKET)
    {
        int nbRecv = ::recv(sock, buf, 1024, 0);

        for(int i = 0; i< nbRecv; i++)
        {
            buffer.push_back(buf[i]);
        }
        return  nbRecv;
    }

    return -1;


}


