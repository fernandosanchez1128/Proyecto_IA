#ifndef MAPA_H
#define MAPA_H
#include <iostream>
#include <string>
#include <QWidget>
#include <controlador.h>
#include <QMessageBox>
#include <QIcon>
#include <math.h>
using namespace  std;
namespace Ui {
class mapa;
}

class mapa : public QWidget
{
    Q_OBJECT

public:
    explicit mapa(Controlador control, QWidget *parent = 0);
    /**
     * @brief pintaMatriz : metodo encargado de pintar la matriz deacuerod la
     *  a los valores dados en el archivo
     * @param mapa : matriz con los datos
     * @param tamano : tamano de la matriz
     */
    void pintaMatriz (int ** mapa, int tamano );
    ~mapa();
    /**
     * @brief switchColor : metodo encargado de devolver un color
     * deacuerdo a un numero dado
     * @param numero : numero que representa el estado de la celda
     * @return color correspondiente al numero
     */
    QIcon switchIcono(int numero);
    Controlador control;

    /**Parametros que guarda la celda del paso anterior**/
    int anteriorX, anteriorY;
    QIcon iconoceldaAnterior;


private slots:

    void on_Amplitud_clicked();

    void on_A_Asterisco_clicked();

    void on_btSalir_clicked();

    void on_paso_amplitud_clicked();

    void on_paso_A_Asterisco_clicked();
    void crear_archivo (int nodos_creados, int nodos_expandidos, int costo, int factor_ramificacion);
    int ramificacion (int profundidad, int nodos_creados);

private:
    Ui::mapa *ui;
};

#endif // MAPA_H
