#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <fstream>
#include "modelo.h"
#include <iostream>
#include <QColor>
using namespace std;
class Controlador
{
public:


    Controlador();
    ~Controlador();
    /**
     * @brief model : objeto  tipo modelo
     * el cual utiliza para crearle la matriz
      del escenario
     */
    modelo  model;
    /**
     * @brief leerArchivo : metodo encargado de leer el archivo
     * @param ruta : ruta del archivo
     */
    void leerArchivo(string ruta);

};

#endif // CONTROLADOR_H
