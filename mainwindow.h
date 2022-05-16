#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "clienttcp.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    clienttcp * client;

private slots:
    void onConnectButtonClicked();
    void onCelsiusCapteur1ButtonClicked();
    void onCelsiusCapteur2ButtonClicked();
    void onCelsiusCapteur3ButtonClicked();
    void onFahrenheitCapteur1ButtonClicked();
    void onFahrenheitCapteur2ButtonClicked();
    void onFahrenheitCapteur3ButtonClicked();
    void onHygrometrieCapteur1ButtonClicked();
    void onHygrometrieCapteur2ButtonClicked();
    void onHygrometrieCapteur3ButtonClicked();
    void onTemperatureReadyRead();
};

#endif // MAINWINDOW_H
