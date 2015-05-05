#include "controlador.h"

Controlador::Controlador()
{

}

Controlador::~Controlador()
{
    model =  modelo ();
}

void Controlador :: leerArchivo(string ruta)
{
    int tamano;
    int dato = 0;
    ifstream myfile (ruta.c_str());
    //ifstream myfile ("/home/fernando/Escritorio/IA_project/mapa.txt");
    /** lee la primera linea del archio que es el tamaño de la matriz**/
    myfile >> tamano;
    model.tamano = tamano;

    /** inicializa la matriz del modelo **/    
    model.matriz = new int * [tamano];
    for (int i=0 ; i<tamano; i++)
    {
        model.matriz [i] = new int [tamano];
    }    

    /** agrega los valores a la matriz del modelo **/
    for (int i=0 ; i<tamano; i++)
    {
        for (int a= 0 ; a< tamano; a++)
        {
           myfile >> dato;
           if (dato == 0)
           {
               model.ini_x = i;
               model.ini_y = a;

           }
           if (dato == 7)
           {
               model.meta_x = i;
               model.meta_y = a;
           }

           model.matriz [i] [a] = dato;
        }
    }
    myfile.close();


}
