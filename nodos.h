#ifndef NODOS_H
#define NODOS_H
#include <iostream>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <qmath.h>
/**
 * @brief The Nodos class: clase nodos donde se  crea un nodo
 * que tiene un id unico, una posicion en x y una posicion en y
 */
using namespace std;
class Nodos
{
private:
    /**
     * @brief id : id del nodo
     */
    long int id;
    /**
     * @brief posx : posicon x del nodo
     */
    int posx;
    /**
     * @brief posy : posiion y del nodo
     */
    int posy;
    /**
     * @brief id_padre : id del nodo padre.
     */
    long int id_padre;
    /**
     * @brief carga : del robot en ese nodo
     */
    int carga;

    int val_pasos;

public:
    int tamano;
    int valor;

    Nodos(int id, int posx, int posy, int carga, int val_pasos=0, int id_padre = 0 , double valor =0);
    ~Nodos();
    /**
     * @brief estaAfuera : verifica que el nuevo nodo a crear
     * no este por fuera de la matriz
     * @param tamano : tamano de la matriz
     * @return
     */
    bool estaAfuera (int tamano);
    /**
     * @brief esAccesible : verifica si el nodo a crear si puede
     * ser accedido es decir no es una pared
     * @return
     */
    /**
     * @brief agregarValor : agrega el valor del paso al nodo
     * @param valor_paso : valor del paso actual
     * @param heuristica : 1 -> distancia manhattan. 2-> distancia linea recta.
     */
    void agregarValor (double valor_paso, int heuristica,int metax,int metay);

    double distancia_manhattan (int ini,int iniy,int metax,int metay);

    double distancia_linea_recta(int ini, int iniy, int metax, int metay);

    bool esAccesible ();
    bool esAccesible(int val_paso);
    bool esMeta (int metax, int metay);
    void setValor (double valor);
    int getId ();
    int getPosx ();
    int getPosy ();
    int getIdpadre ();
    int getCarga ();
    int getValPasos ();
    bool bateriaAgotada();
    double getValor();
    void setValores(int val_paso);



};

#endif // NODOS_H
