#include <fstream>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Cola
{
public:

    Cola();
    FILE *fp;
    void crear_archivo();
    void eliminar_linea ();
    void agregar (int dato);
    long indice;
    void espacio();
    void continuar_archivo();
    void abrir_lectura ();

};

Cola :: Cola ()
{
	indice = 0;
}

void Cola :: crear_archivo()
{
	fp = fopen ( "mapa.txt", "w+" ); 
}
void Cola :: abrir_lectura()
{
	fp = fopen ( "mapa.txt", "r" ); 
}

void Cola :: continuar_archivo()
{
	fp = fopen ( "mapa.txt", "a" ); 
}


void Cola :: agregar (int numero)
{
	
				char c [10];
				sprintf(c, "%d", numero);
				fprintf(fp, c);
				fprintf(fp, " ");		
				
}

void Cola :: espacio () 
{
	fprintf(fp, "\n");
}
int main ()
{
	/**int * a = new int ();
	*a = 5;
	int b = 2;
	a= &b; 
	b = 4;
	cout <<*a<<endl;
	**/
	Cola cola = Cola ();
	cola.crear_archivo();
	srand(time(NULL));
	for (int i=0; i<10;i++)
    {
		for (int a=0; a<10;a++)
    {
		int num = rand()%6+1; 
        cola.agregar (num);
	}
	cola.espacio();
    }
	
}



