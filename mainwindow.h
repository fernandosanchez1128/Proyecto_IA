#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controlador.h"
#include "mapa.h"
#include "modelo.h"
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief control : objeto controlador que utiliza para
     *  comunicarse con el modelo
     */
    Controlador control;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_Empezar_clicked();

    void on_Examinar_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
