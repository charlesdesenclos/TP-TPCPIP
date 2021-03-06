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



}



void MainWindow::onConnectButtonClicked()
{
    QString ip =ui-> ipLineEdit-> text();
    uint port = ui-> portLineEdit->text().toUInt();

    if(client-> connectToHost(ip, port))
    {
        ui->statusLabel->setText("Connexion à " + ip + " : "+ QString::number(port) +" a réussi ");
    }
    else {
        ui->statusLabel->setText("Connexion à " + ip + " : "+ QString::number(port) +" a échoué ");
    }
}

void MainWindow::onCelsiusCapteur1ButtonClicked()
{
    client->envoieCelsiusCapteur1();
}

void MainWindow::onCelsiusCapteur2ButtonClicked()
{
    client->envoieCelsiusCapteur2();
}

void MainWindow::onCelsiusCapteur3ButtonClicked()
{
    client->envoieCelsiusCapteur3();
}

void MainWindow::onFahrenheitCapteur1ButtonClicked()
{
    client->envoieFahrenheitCapteur1();
}

void MainWindow::onFahrenheitCapteur2ButtonClicked()
{
    client->envoieFahrenheitCapteur2();
}

void MainWindow::onFahrenheitCapteur3ButtonClicked()
{
    client->envoieFahrenheitCapteur3();
}

void MainWindow::onHygrometrieCapteur1ButtonClicked()
{
    client->envoieHygrometrieCapteur1();
}

void MainWindow::onHygrometrieCapteur2ButtonClicked()
{
    client->envoieHygrometrieCapteur2();
}

void MainWindow::onHygrometrieCapteur3ButtonClicked()
{
    client->envoieHygrometrieCapteur3();
}

void MainWindow::onTemperatureReadyRead()
// La fonction vérifie les informations envoyés par le serveur pui vérifie si c'est un td , un tf et hr et va afficher le résultat au bonne endroit
{
    char message = client->receptiondonnees();
    QByteArray data;
    data = QByteArray((char*)message);
    QString donnees(data);



    if(donnees.data()[0] == 'T' && donnees.data()[1] == 'd' && donnees.data()[3] == '1' )
        // vérifie si les données commence par un Td et vérifie le numéro du capteur si oui il affiche dans le bon label la données
    {
        ui->CelsiusCapteur1Label->setText(""+donnees+" °C");
    }
    else if(donnees.data()[0] == 'T' && donnees.data()[1] == 'd' && donnees.data()[3] == '2' )
        // vérifie si les données commence par un Td et vérifie le numéro du capteur si oui il affiche dans le bon label la données
    {
        ui->CelsiusCapteur2Label->setText(""+donnees+" °C");
    }
    else if(donnees.data()[0] == 'T' && donnees.data()[1] == 'd' && donnees.data()[3] == '3' )
        // vérifie si les données commence par un Td et vérifie le numéro du capteur si oui il affiche dans le bon label la données
    {
        ui->CelsiusCapteur3Label->setText(""+donnees+" °C");
    }
    else if(donnees.data()[0] =='T' && donnees.data()[1] =='f' && donnees.data()[3] == '1')
        // vérifie si les données commence par un Tf et vérifie le numéro du capteur si oui il affiche dans le bon label la données
    {
        ui->FahrenheitCapteur1label->setText(""+donnees+" F");
    }
    else if(donnees.data()[0] =='T' && donnees.data()[1] =='f' && donnees.data()[3] == '2')
        // vérifie si les données commence par un Tf et vérifie le numéro du capteur si oui il affiche dans le bon label la données
    {
        ui->FahrenheitCapteur2label->setText(""+donnees+" F");
    }
    else if(donnees.data()[0] =='T' && donnees.data()[1] =='f' && donnees.data()[3] == '3')
        // vérifie si les données commence par un Tf et vérifie le numéro du capteur si oui il affiche dans le bon label la données
    {
        ui->FahrenheitCapteur3label->setText(""+donnees+" F");
    }
    else if(donnees.data()[0] =='H' && donnees.data()[1] == 'r' && donnees.data()[3] == '1')
        // vérifie si les données commence par un Hr et vérifie le numéro du capteur si oui il affiche dans le bon label la données
    {
        ui->HygrometrieCapteur1label->setText(""+donnees+" %");
    }
    else if(donnees.data()[0] =='H' && donnees.data()[1] == 'r' && donnees.data()[3] == '2')
        // vérifie si les données commence par un Hr et vérifie le numéro du capteur si oui il affiche dans le bon label la données
    {
        ui->HygrometrieCapteur1label->setText(""+donnees+" %");
    }
    else if(donnees.data()[0] =='H' && donnees.data()[1] == 'r' && donnees.data()[3] == '3')
        // vérifie si les données commence par un Hr et vérifie le numéro du capteur si oui il affiche dans le bon label la données
    {
        ui->HygrometrieCapteur1label->setText(""+donnees+" %");
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

