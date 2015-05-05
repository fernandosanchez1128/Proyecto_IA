#ifndef MODELO_H
#define MODELO_H
#include "nodos.h"
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
//#include <crtdbg.h>
#include <exception>
#include <stdexcept>
#include <stdlib.h>
#include <deque>
#include <list>
#include"mycomparison.h"
using namespace std;
class modelo
{
public:
    int id;
    /**
     * @brief cola : cola usada para la implementacion de algoritmo de
     * busqueda por amplitud
     */
    queue <Nodos> * cola;

    /**
     * @brief expandidos : pila usada para almacenar los nodos expandidos y
     * encontrrar el camino hacia la solucion
     */
    stack <Nodos> *expandidos;

    /**
     * @brief cola_prioridad : cola usada para implementar el algoritmo de
     * busqueda A*
     */
    typedef std::priority_queue<Nodos,std::vector<Nodos>,mycomparison> queue_priority;
    queue_priority cola_prioridad;


    /**
     * @brief matriz:  matriz donde se guarda la informacion del sistema
    **/
    int ** matriz;

    /**
     * @brief tamano : tamano de la matriz
     */
    int tamano;
    /** se almacena la profundidad en la que se encuentra la solucion**/
    int profundidad ;

    modelo();
    ~modelo();

    /**
     * @brief amplitud: implementacion algoritmo busqueda por amplitud.
     * @return string que contiene el camino a la solucion
     */
    string amplitud (int metax,int metay) ;

    /**
     * @brief A_asterisco : implementacion algoritmo busqueda A*.
     * @return string que contiene el camino a la solucion
     */
    string A_asterisco (int metax, int metay, int heuristica) ;
    int costo;

    /** posicion inicial **/
    int ini_x;
    int ini_y;

    /** posicion meta**/
    int meta_x;
    int meta_y;

    /** variable para guardar el numero nodos creados **/
    int nodos_creados_amplitud;
    int nodos_creados_a_asterisco;

    /** variable para guardar el numero nodos expandidos **/
    int nodos_expandidos;

    /**
     * @brief insertarRaiz : metodo usado para insertar a la cola el primer
     * nodo o el nodo inicio
     * @param inix : posicion en x del nodo inicial
     * @param iniy : posicion en y del nodo inicio
     */
    void insertarRaiz (int inix,int iniy);

    /**
     * @brief caminoSolucion: metodo usado para obtener el camino a la solucion
     * @return string con el camino a la solucion
     */
    string caminoSolucion ();


    /** listaSolucion: Lista que contiene los enteros correspondiente a la
     *  posicion de las celdas solucion
     **/
    list <int> listaSolucion;

    int valPaso (int val_matriz);


};

#endif // MODELO_H
