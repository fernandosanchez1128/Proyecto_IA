#include "modelo.h"

modelo::modelo()
{
    id = 0;
    costo = 0;
    profundidad = 0;
}

modelo::~modelo()
{

}

string modelo :: amplitud  (int metax, int metay)
{

    if (cola->empty())
    {
        return "no hay solucion";
    }
        else
        {
            //cout <<"else"<<endl;
            Nodos nodo = Nodos (0,0,0,0);
           // cout <<"valor" + nodo.getValPasos()<<endl;
            nodo =  cola->front();
            //cout << "bateria " << nodo.getCarga()<<endl;
            int bateria =nodo.getCarga();
            expandidos->push(nodo);
            int padre = nodo.getId();
            int inix = nodo.getPosx();
            int iniy = nodo.getPosy();
            int valor_acum = nodo.getValPasos();
            if (nodo.esMeta(metax,metay))
            {
                return caminoSolucion();
            }
            else if (nodo.bateriaAgotada())
            {
                cola->pop();
                id++;
                return amplitud( metax,metay);
            }
            else
            {

                cola->pop();
                id++;
                Nodos nodo_der =Nodos (id,inix+1,iniy,(bateria-1),padre,valor_acum);  //derecha
                id++;
                Nodos nodo_abajo =  Nodos (id,inix,iniy+1,(bateria-1),padre,valor_acum);  //abajo
                id++;
                Nodos nodo_izq = Nodos (id,(inix-1),iniy,(bateria-1),padre,valor_acum);  //izquierda
                id++;
                Nodos nodo_arriba = Nodos (id,inix,iniy-1,(bateria-1),padre, valor_acum);  //arriba
                id++;
                if (!nodo_der.estaAfuera(tamano))
                {
                    nodo_der.setValor(matriz[inix+1][iniy]);
                    int valor = valPaso(matriz[inix+1][iniy]);
                    nodo_der.setValores(valor);
                    if (nodo_der.esAccesible())
                    {
                        cola->push(nodo_der);
                    }
                }



                if (!nodo_abajo.estaAfuera(tamano))
                {
                    nodo_abajo.setValor(matriz[inix][iniy+1]);
                    int valor = valPaso(matriz[inix][iniy + 1]);
                    nodo_abajo.setValores(valor);

                    if (nodo_abajo.esAccesible())
                    {
                        cola->push(nodo_abajo);
                    }
                }


                if (!nodo_izq.estaAfuera(tamano))
                {
                    nodo_izq.setValor(matriz[inix-1][iniy]);
                    int valor = valPaso(matriz[inix-1][iniy]);
                    nodo_izq.setValores(valor);

                    if (nodo_izq.esAccesible())
                    {
                        cola->push(nodo_izq);
                    }
                }


                if (!nodo_arriba.estaAfuera(tamano))
                {
                    nodo_arriba.setValor(matriz[inix][iniy-1]);
                    int valor = valPaso(matriz[inix][iniy -1]);
                    nodo_arriba.setValores(valor);

                    if (nodo_arriba.esAccesible())
                    {
                        cola->push(nodo_arriba);

                    }
                }
                return amplitud(metax,metay);
            }
        }
}


void modelo::insertarRaiz(int inix, int iniy)
{

    cola = new queue  <Nodos> () ;

    expandidos = new stack <Nodos> ();
    int carga =6;
    Nodos nodo = Nodos(id,inix,iniy,carga) ;
    cola->push(nodo);
    cola_prioridad = queue_priority(mycomparison(true));
    cola_prioridad.push (nodo);
    id++;

}

string modelo::caminoSolucion()
{
    nodos_creados_amplitud = cola->size() + expandidos->size();
    nodos_creados_a_asterisco = cola_prioridad.size() + expandidos->size();
    nodos_expandidos = expandidos->size();
    string solucion = "[(";
    stringstream stream;
    string palabra;
    Nodos nodo =  expandidos->top();
    expandidos->pop();
    costo = nodo.getValPasos();
    int id_padre = nodo.getIdpadre();
    listaSolucion.push_front(nodo.getPosx());
    stream << nodo.getPosx();
    palabra = stream.str();
    solucion = solucion + palabra;
    listaSolucion.push_front(nodo.getPosy());
    stringstream stream2;
    stream2 << nodo.getPosy();
    palabra = stream2.str();
    solucion = solucion + "," + palabra + ") Carga:";
    stringstream stream3;
    stream3 << nodo.getCarga();
    palabra = stream3.str();
    solucion = solucion + palabra + "]; [(";

    while (!expandidos->empty())
    {
        solucion = solucion;
        Nodos nodo =  expandidos->top();
        expandidos->pop();
        int id = nodo.getId();
        if (id == id_padre)
        {
            profundidad++;
            id_padre = nodo.getIdpadre();
            stringstream stream;
            listaSolucion.push_front(nodo.getPosx());
            stream << nodo.getPosx();            
            palabra = stream.str();
            solucion = solucion + palabra;
            stringstream stream2;
            listaSolucion.push_front(nodo.getPosy());
            stream2 << nodo.getPosy();            
            palabra = stream2.str();
            solucion = solucion + "," + palabra + ") Carga:";
            stringstream stream3;
            stream3 << nodo.getCarga();
            palabra = stream3.str();
            solucion = solucion + palabra +  "], ";
        }

    }

    /**while(!listaSolucion.empty()) {

        cout<<"ListaSolucion:"<<listaSolucion.front()<<endl;
        listaSolucion.pop_front();
    }**/
    cout<<"SOLUCION: "<<solucion<<"listaSOl: "<<listaSolucion.size()<<endl;
    return solucion;

}

int modelo::valPaso(int val_matriz)
{
    switch (val_matriz)
    {
        case 2:
            return 1;

        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 6;

        case 6:
            return 5;
        default:
            return 1;
    }
}


string modelo::A_asterisco(int metax, int metay,int heuristica)
{

    if (cola_prioridad.empty())
    {
        return "no hay solucion";
    }
        else
        {
            //cout <<"else"<<endl;
            Nodos nodo = Nodos (0,0,0,0);
            nodo =  cola_prioridad.top();
            cout<< nodo.getValor()<<endl;
            //cout << "bateria " << nodo.getCarga()<<endl;
            int bateria =nodo.getCarga();
            expandidos->push(nodo);
            int padre = nodo.getId();
            int inix = nodo.getPosx();
            int iniy = nodo.getPosy();
            int valor = nodo.getValor();
            if (nodo.esMeta(metax,metay))
            {
                return caminoSolucion();
            }
            else if (nodo.bateriaAgotada())
            {
                cola_prioridad.pop();
                id++;
                return A_asterisco( metax,metay,heuristica);
            }
            else
            {

                cola_prioridad.pop();
                int valPasosPadre = nodo.getValPasos();
                id++;
                Nodos nodo_der =Nodos (id,inix+1,iniy,(bateria-1),padre,valPasosPadre);  //derecha
                id++;
                Nodos nodo_abajo =  Nodos (id,inix,iniy+1,(bateria-1),padre,valPasosPadre);  //abajo
                id++;
                Nodos nodo_izq = Nodos (id,(inix-1),iniy,(bateria-1),padre,valPasosPadre);  //izquierda
                id++;
                Nodos nodo_arriba = Nodos (id,inix,iniy-1,(bateria-1),padre,valPasosPadre);  //arriba
                id++;

                if (!nodo_der.estaAfuera(tamano))
                {
                    nodo_der.agregarValor(valPaso(matriz[inix+1][iniy]),heuristica,metax,metay);
                    if (nodo_der.esAccesible(matriz[inix+1][iniy]))
                    {
                        cola_prioridad.push(nodo_der);
                    }
                }



                if (!nodo_abajo.estaAfuera(tamano))
                {
                    nodo_abajo.agregarValor(valPaso(matriz[inix][iniy+1]),heuristica,metax,metay);
                    if (nodo_abajo.esAccesible(matriz[inix][iniy+1]))
                    {
                        cola_prioridad.push(nodo_abajo);
                    }
                }


                if (!nodo_izq.estaAfuera(tamano))
                {
                    nodo_izq.agregarValor(valPaso(matriz[inix-1][iniy]),heuristica,metax,metay);
                    if (nodo_izq.esAccesible(matriz[inix-1][iniy]))
                    {
                        cola_prioridad.push(nodo_izq);
                    }
                }


                if (!nodo_arriba.estaAfuera(tamano))
                {
                    nodo_arriba.agregarValor(valPaso(matriz[inix][iniy-1]),heuristica,metax,metay);
                    if (nodo_arriba.esAccesible(matriz[inix][iniy-1]))
                    {
                        cola_prioridad.push(nodo_arriba);
                    }
                }
                return A_asterisco(metax,metay,heuristica);
            }
        }
}
