#ifndef CLIENTTCP_H
#define CLIENTTCP_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

#include <QString>

class clienttcp
{
    SOCKET sock;
    SOCKET * buf;
    char buffer;
    bool initDone;
public:
    clienttcp();
    bool initSuccess(){
        return initDone;
    }

    bool connectToHost(QString ip, uint port);

    char envoieCelsiusCapteur1();
    char envoieCelsiusCapteur2();
    char envoieCelsiusCapteur3();
    char envoieFahrenheitCapteur1();
    char envoieFahrenheitCapteur2();
    char envoieFahrenheitCapteur3();
    char envoieHygrometrieCapteur1();
    char envoieHygrometrieCapteur2();
    char envoieHygrometrieCapteur3();

    char receptiondonnees();
};

#endif // CLIENTTCP_H
