#include "nodos.h"

Nodos::Nodos(int id, int posx, int posy, int carga, int id_padre ,int val_pasos, double valor)
{
    this->id = id;
    this->posx = posx;
    this->posy = posy;
    this->carga = carga;
    this->val_pasos = val_pasos;
    this->id_padre = id_padre;
    this->valor = valor;
}

Nodos::~Nodos()
{
}

bool Nodos::estaAfuera(int tamano)
{
    if ((posx >= tamano) || (posy >= tamano) ||(posx < 0) || (posy < 0) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Nodos::agregarValor(double valor_paso, int heuristica, int metax, int metay)
{
    if (valor_paso ==5)
    {
        carga = 6;
    }

    if(heuristica==1){
        this->val_pasos += valor_paso;
        this->valor = this->val_pasos + distancia_manhattan (this->posx,this->posy,metax,metay);
    }
    if(heuristica==2){
        this->val_pasos += valor_paso;
        this->valor = this->val_pasos + distancia_linea_recta(this->posx,this->posy,metax,metay);
    }

}


bool Nodos::esAccesible()
{
    if (valor != 1)
    {
        return true ;
    }
    else
    {
        return false;
    }
}

bool Nodos::esAccesible(int val_paso)
{
    if (val_paso != 1)
    {
        return true ;
    }
    else
    {
        return false;
    }
}

bool Nodos::esMeta(int metax, int metay)
{
    if ((posx == metax) && (posy == metay))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Nodos:: setValor (double valor)
{
    this->valor = valor;
    if (valor ==6)
    {
        carga = 6;
    }
}


double Nodos::distancia_manhattan(int inix, int iniy, int metax, int metay)
{
    double distancia = abs(metax - inix) + abs(metay-iniy);
    return distancia;
}

double Nodos::distancia_linea_recta(int inix, int iniy, int metax, int metay)
{

    double adx=abs(metax - inix);
    double ady=abs(metay - iniy);
    double distancia = qSqrt((qPow(adx,2)+(qPow(ady,2))));
    return distancia;
    cout<<"Entro en distancia_linea"<<endl;
}



int Nodos::getId()
{
    return id;
}

int Nodos::getPosx()
{
    return posx;
}

int Nodos::getPosy()
{
    return posy;
}

int Nodos::getIdpadre()
{
    return id_padre;
}

int Nodos::getCarga()
{
    return carga;
}

int Nodos::getValPasos()
{
    return val_pasos;
}

bool Nodos::bateriaAgotada()
{
    if (carga <= 0)
    {
       return true;
    }

    else
    {
        return false;
    }
}

double Nodos::getValor()
{
    return valor;
}

void Nodos::setValores(int val_paso)
{
    //cout<< val_paso<<endl;
    this->val_pasos += val_paso;
}

