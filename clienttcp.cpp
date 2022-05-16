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
    const char *hostname = "www.developpez.com";

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
    sock;
    char buffer[1024];

    if(send(sock, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        exit(errno);
    }
}

char clienttcp::envoieCelsiusCapteur2()
{
    sock;
    char buffer[1024];

    if(send(sock, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        exit(errno);
    }
}

char clienttcp::envoieCelsiusCapteur3()
{
    sock;
    char buffer[1024];

    if(send(sock, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        exit(errno);
    }
}

char clienttcp::envoieFahrenheitCapteur1()
{
    sock;
    char buffer[1024];

    if(send(sock, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        exit(errno);
    }
}

char clienttcp::envoieFahrenheitCapteur2()
{
    sock;
    char buffer[1024];

    if(send(sock, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        exit(errno);
    }
}

char clienttcp::envoieFahrenheitCapteur3()
{
    sock;
    char buffer[1024];

    if(send(sock, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        exit(errno);
    }
}

char clienttcp::envoieHygrometrieCapteur1()
{
    SOCKET sock;
    char buffer[1024];

    if(send(sock, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        exit(errno);
    }
}

char clienttcp::envoieHygrometrieCapteur2()
{
    sock;
    char buffer[1024];

    if(send(sock, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        exit(errno);
    }
}

char clienttcp::envoieHygrometrieCapteur3()
{
    sock;
    char buffer[1024];

    if(send(sock, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        exit(errno);
    }
}

char clienttcp::receptiondonnees()
{
    char buffer[1024];
    int n = 0;

    if((n = recv(sock, buffer, sizeof buffer - 1, 0)) < 0)
    {
        perror("recv()");
        exit(errno);
    }

    buffer[n] = '\0';
}


