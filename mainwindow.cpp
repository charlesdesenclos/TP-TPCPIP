#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clienttcp.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    client = new clienttcp;

    if(client->initSuccess())
    {
        ui-> statusLabel->setText("Création socket ok");
    }
    else {
        ui->statusLabel->setText("Création socket faled");
    }
    QObject::connect(ui-> connectButton, SIGNAL(clicked()), this, SLOT(onConnectButtonClicked()));
    QObject::connect(ui->CelsiusCapteur1pushButton, SIGNAL(clicked()), this, SLOT(onCelsiusCapteur1ButtonClicked()));
    QObject::connect(ui->CelsiusCapteur2pushButton, SIGNAL(clicked()), this, SLOT(onCelsiusCapteur2ButtonClicked()));
    QObject::connect(ui->CelsiusCapteur3pushButton, SIGNAL(clicked()), this, SLOT(onCelsiusCapteur3ButtonClicked()));
    QObject::connect(ui->FahrenheitCapteur1pushButton, SIGNAL(clicked()), this, SLOT(onFahrenheitCapteur1ButtonClicked()));
    QObject::connect(ui->FahrenheitCapteur2pushButton, SIGNAL(clicked()), this, SLOT(onFahrenheitCapteur2ButtonClicked()));
    QObject::connect(ui->FahrenheitCapteur3pushButton, SIGNAL(clicked()), this, SLOT(onFahrenheitCapteur3ButtonClicked()));
    QObject::connect(ui->HygrometrieCapteur1pushButton, SIGNAL(clicked()), this, SLOT(onHygrometrieCapteur1ButtonClicked()));
    QObject::connect(ui->HygrometrieCapteur2pushButton, SIGNAL(clicked()), this, SLOT(onHygrometrieCapteur2ButtonClicked()));
    QObject::connect(ui->HygrometrieCapteur3pushButton, SIGNAL(clicked()), this, SLOT(onHygrometrieCapteur3ButtonClicked()));
    QObject::connect(, SIGNAL(read()), this, SLOT(onTemperatureReadyRead()));

}



void MainWindow::onConnectButtonClicked()
{
    QString ip =ui-> ipLineEdit-> text();
    uint port = ui-> portLineEdit->text().toUInt();

    if(client-> connectToHost(ip, port))
    {
        ui->statusLabel->setText("Connexion à" + ip +":"+ QString::number(port) +"a réussi");
    }
    else {
        ui->statusLabel->setText("Connexion à" + ip +":"+ QString::number(port) +"a échoué");
    }
}

void MainWindow::onCelsiusCapteur1ButtonClicked()
{
    if(client->envoieCelsiusCapteur1())
    {
        client->

        w("Td01?\n");
    }
}

void MainWindow::onCelsiusCapteur2ButtonClicked()
{

}

void MainWindow::onCelsiusCapteur3ButtonClicked()
{

}

void MainWindow::onFahrenheitCapteur1ButtonClicked()
{

}

void MainWindow::onFahrenheitCapteur2ButtonClicked()
{

}

void MainWindow::onFahrenheitCapteur3ButtonClicked()
{

}

void MainWindow::onHygrometrieCapteur1ButtonClicked()
{

}

void MainWindow::onHygrometrieCapteur2ButtonClicked()
{

}

void MainWindow::onHygrometrieCapteur3ButtonClicked()
{

}

void MainWindow::onTemperatureReadyRead() // La fonction vérifie les informations envoyés par le serveur pui vérifie si c'est un td , un tf et hr et va afficher le résultat au bonne endroit
{

    QByteArray data = client->read(client->bytesAvailable());
    QString donnees(data);



    if(donnees.data()[0] == 'T' && donnees.data()[1] == 'd' && donnees.data()[3] == '1' ) // vérifie si les données commence par un Td si oui il affiche dans le bon label la données
    {
        ui->CelsiusCapteur1Label->setText(""+donnees+" °C");
    }
    else if(donnees.data()[0] == 'T' && donnees.data()[1] == 'd' && donnees.data()[3] == '2' ) // vérifie si les données commence par un Td si oui il affiche dans le bon label la données
    {
        ui->CelsiusCapteur2Label->setText(""+donnees+" °C");
    }
    else if(donnees.data()[0] == 'T' && donnees.data()[1] == 'd' && donnees.data()[3] == '3' ) // vérifie si les données commence par un Td si oui il affiche dans le bon label la données
    {
        ui->CelsiusCapteur3Label->setText(""+donnees+" °C");
    }
    else if(donnees.data()[0] =='T' && donnees.data()[1] =='f' && donnees.data()[3] == '1') // vérifie si les données commence par un Tf si oui il affiche dans le bon label la données
    {
        ui->FahrenheitCapteur1label->setText(""+donnees+" F");
    }
    else if(donnees.data()[0] =='T' && donnees.data()[1] =='f' && donnees.data()[3] == '2') // vérifie si les données commence par un Tf si oui il affiche dans le bon label la données
    {
        ui->FahrenheitCapteur2label->setText(""+donnees+" F");
    }
    else if(donnees.data()[0] =='T' && donnees.data()[1] =='f' && donnees.data()[3] == '3') // vérifie si les données commence par un Tf si oui il affiche dans le bon label la données
    {
        ui->FahrenheitCapteur3label->setText(""+donnees+" F");
    }
    else if(donnees.data()[0] =='H' && donnees.data()[1] == 'r' && donnees.data()[3] == '1') // vérifie si les données commence par un Hr si oui il affiche dans le bon label la données
    {
        ui->HygrometrieCapteur1label->setText(""+donnees+" %");
    }
    else if(donnees.data()[0] =='H' && donnees.data()[1] == 'r' && donnees.data()[3] == '2') // vérifie si les données commence par un Hr si oui il affiche dans le bon label la données
    {
        ui->HygrometrieCapteur1label->setText(""+donnees+" %");
    }
    else if(donnees.data()[0] =='H' && donnees.data()[1] == 'r' && donnees.data()[3] == '3') // vérifie si les données commence par un Hr si oui il affiche dans le bon label la données
    {
        ui->HygrometrieCapteur1label->setText(""+donnees+" %");
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

