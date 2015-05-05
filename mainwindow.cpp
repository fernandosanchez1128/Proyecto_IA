#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    control = Controlador ();
    ui->setupUi(this);
    QPixmap titulo("WindowIcons/Titulo3.png");
    QPixmap mapalogo("WindowIcons/mapa.png");
    QPixmap search("WindowIcons/search.png");
    QPixmap go("WindowIcons/start.png");
    this->ui->label->setPixmap(titulo);
    this->ui->label_2->setPixmap(mapalogo);
    this->ui->Examinar->setIcon(search);
    this->ui->Empezar->setIcon(go);


}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::accion implemenmtada al presional el boton empezar
 */
void MainWindow::on_Empezar_clicked()
{
    /** llma a contro, para que lea el archivo **/
    QString url = this->ui->lineEdit->text();
    control.leerArchivo(url.toStdString()                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       );
    /** crea la interfaz mapa **/
    mapa *  escenario = new  mapa(control);
    escenario->show();
    escenario->pintaMatriz(control.model.matriz, control.model.tamano);

}

void MainWindow::on_Examinar_clicked()
{
    QFileDialog *filename  = new QFileDialog ();
    QString url = filename->getOpenFileName(this,"hola","/home");
    if (url.toStdString() !="")
    {
       this->ui->lineEdit->setText(url);
    }


}
