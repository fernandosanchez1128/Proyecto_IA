#include "mapa.h"
#include "ui_mapa.h"

mapa::mapa(Controlador control, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mapa)
{
    ui->setupUi(this);
    this->control = control;
    QPixmap aplicar("WindowIcons/apply.png");
    QPixmap step("WindowIcons/step.png");
    this->ui->Amplitud->setIcon(aplicar);
    this->ui->A_Asterisco->setIcon(aplicar);
    this->ui->paso_amplitud->setIcon(step);
    this->ui->paso_A_Asterisco->setIcon(step);
}

mapa::~mapa()
{
    delete ui;
}

void mapa :: pintaMatriz(int **mapa,int tamano)
{
    /** crea el tamaño de la tabla **/
    this->ui->tableWidget->setColumnCount(tamano);
    this->ui->tableWidget->setRowCount(tamano);
    this->ui->tableWidget->setIconSize(QSize(42,42));       //ICONSIZE

    this->ui->tableWidget->setLineWidth(90);
    this->ui->tableWidget->setGeometry(QRect((647/2)-((55*tamano)/2),190,501,461));
    if(tamano<9){
    this->setFixedHeight(tamano*110);
    this->ui->tableWidget->setFixedSize(QSize(tamano*58,tamano*58));
        //this->setAutoFillBackground(true);
    }
    else{
        this->setFixedSize(QSize(674,661));
    }


    /** pone el numero a las filas y  a las columnas**/
    for (int i =0; i< tamano;i++)
    {

        QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(i));
        QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(i));
        this->ui->tableWidget->setVerticalHeaderItem(i,item1);
        this->ui->tableWidget->setHorizontalHeaderItem(i, item2);
    }
    /** crea item a a las celdas para que se puedan modificar sus colores **/
    for (int i =0; i< tamano;i++)
    {
        for (int a =0; a< tamano;a++)
        {
            QTableWidgetItem *item = new QTableWidgetItem();
            this->ui->tableWidget->setItem(i,a,item);
            this->ui->tableWidget->setColumnWidth(a,48);
            this->ui->tableWidget->setRowHeight(i,48);

        }
    }
    /** pinta la matriz deacuerdo a los datos dados en el archivo **/
    for (int i =0; i< tamano;i++)
    {
        for (int a =0; a< tamano;a++)
        {
           QTableWidgetItem * item = this->ui->tableWidget->item(i,a);
           int numero = mapa [i][a];
           QIcon iconocelda  = switchIcono(numero);
           item->setIcon(iconocelda);
           if(numero==0){
               anteriorX=i;
               anteriorY=a;
               this->iconoceldaAnterior=QIcon();
           }
        }
    }

    int ini_x = control.model.ini_x;
    int ini_y = control.model.ini_y;
    control.model.insertarRaiz(ini_x,ini_y);

}


QIcon mapa::switchIcono(int numero)
{
    QIcon icono;
    switch (numero)
    {

        case  0:
            icono = QIcon (QString("MatrizImages/robot.png"));    //inicio -> robot
            break;
        case  1:
            icono = QIcon (QString("MatrizImages/wall.png")); //pared -> gris
            break;
        case  2:
            icono = QIcon ();   //espacio -> blanco
            break;
        case  3:
            icono = QIcon (QString("MatrizImages/water.png"));   //resbaloso -> naranja
            break;
        case  4:
            icono = QIcon (QString("MatrizImages/people.png"));   //alto flujo -> verde
            break;
        case 5:
            icono = QIcon (QString("MatrizImages/forbidden.png")); //restringido -> negro
            break;
        case  6 :
            icono = QIcon (QString("MatrizImages/battery.png"));  //recarga -> amarilla
            break;
        default:
            icono = QIcon (QString("MatrizImages/flag.png"));    //meta -> roja
            break;
    }

    return icono ;

}


void mapa::on_Amplitud_clicked()
{
    int meta_x = control.model.meta_x;
    int meta_y = control.model.meta_y;
    string camino_solucion = control.model.amplitud(meta_x,meta_y);
    if (camino_solucion == "no hay solucion")
    {
        QMessageBox msgBox;
        msgBox.setText("no hay solucion");
        msgBox.exec();
    }
    else
    {
        int nodos_creados = control.model.nodos_creados_amplitud;
        int nodos_expandidos = control.model.nodos_expandidos;
        int costos =control.model.costo;
        int profundidad = control.model.profundidad;
        QMessageBox msgBox;
        QString msg1 = QString ("Nodos Creados: \n");
        QString nd_creados = QString::number(nodos_creados)+ QString ("\n");
        QString msg2 =QString ("Nodos Expandidos: \n");
        QString nd_expandidos =QString::number(nodos_expandidos)+QString ("\n");
        QString costo_solucion =QString("el costo de la solucion es \n");
        QString costo =QString::number(costos)+QString ("\n");
        QString camino = QString ("camino solucion: \n");
        QString camino_sol = QString::fromStdString(camino_solucion);
        QString rami = QString ("factor de ramificacion : ");
        int factor_ramificacion = ramificacion(profundidad,nodos_creados);
        QString ramificacion = QString ("[") +QString::number(factor_ramificacion - 1) + QString (", ") +   QString::number(factor_ramificacion)+ QString ("] ")  + QString ("\n");
        msgBox.setText(msg1+nd_creados+msg2+nd_expandidos+costo_solucion+costo+rami+ ramificacion + camino +camino_sol);
        msgBox.exec();
        crear_archivo(nodos_creados,nodos_expandidos,costos,factor_ramificacion);
    }
    this->ui->paso_amplitud->setEnabled(true);
}

void mapa::on_A_Asterisco_clicked()
{
    int meta_x = control.model.meta_x;
    int meta_y = control.model.meta_y;
    cout<<"item"<<this->ui->ComboHeuristica->currentIndex()<<endl;
    int combo=this->ui->ComboHeuristica->currentIndex();
    string camino_solucion;
    if(combo==0){
        camino_solucion = control.model.A_asterisco(meta_x,meta_y,1);
    }
    if(combo==1){
        camino_solucion = control.model.A_asterisco(meta_x,meta_y,2);
    }

    if (camino_solucion == "no hay solucion")
    {
        QMessageBox msgBox;
        msgBox.setText("no hay solucion");
        msgBox.exec();
    }
    else
    {
        int nodos_creados = control.model.nodos_creados_a_asterisco;
        int nodos_expandidos = control.model.nodos_expandidos;
        int costos = control.model.costo;
        int profundidad = control.model.profundidad;
        QMessageBox msgBox;
        QString msg1 = QString ("Nodos Creados: \n");
        QString nd_creados = QString::number(nodos_creados)+ QString ("\n");
        QString msg2 =QString ("Nodos Expandidos: \n");
        QString nd_expandidos =QString::number(nodos_expandidos)+QString ("\n");
        QString costo_solucion =QString("el costo de la solucion es \n");
        QString costo =QString::number(costos)+QString ("\n");
        QString camino = QString ("camino solucion: \n");
        QString camino_sol = QString::fromStdString(camino_solucion);
        QString rami = QString ("factor de ramificacion: ");
        int factor_ramificacion = ramificacion(profundidad,nodos_creados);
        QString ramificacion = QString ("[") +QString::number(factor_ramificacion -1) + QString (", ") +   QString::number(factor_ramificacion)+ QString ("] ")  + QString ("\n");
        msgBox.setText(msg1+nd_creados+msg2+nd_expandidos+costo_solucion+costo+rami + ramificacion +camino +camino_sol);
        msgBox.exec();

        crear_archivo(nodos_creados,nodos_expandidos,costos,factor_ramificacion);
    }
        this->ui->paso_A_Asterisco->setEnabled(true);
}

void mapa::on_btSalir_clicked()
{
    this->close();
}

void mapa::on_paso_amplitud_clicked()
{
    //QTableWidgetItem * item = this->ui->tableWidget->item(anteriorX,anteriorY);
    //item->setIcon(this->iconoceldaAnterior);
    this->ui->tableWidget->item(anteriorX,anteriorY)->setIcon(iconoceldaAnterior);

    if(control.model.listaSolucion.empty()){
        cout<<"ENTRO lista Vacia:"<<endl;
        this->ui->paso_amplitud->setEnabled(false);
    }
    else{
        int celdaY=control.model.listaSolucion.front();
        control.model.listaSolucion.pop_front();
        int celdaX=control.model.listaSolucion.front();
        control.model.listaSolucion.pop_front();
        this->iconoceldaAnterior  = this->ui->tableWidget->item(celdaX,celdaY)->icon();
        QTableWidgetItem * item = this->ui->tableWidget->item(celdaX,celdaY);
        anteriorX=celdaX; anteriorY=celdaY;
        item->setIcon(QIcon (QString("MatrizImages/robot2.png")));
    }
}

void mapa::on_paso_A_Asterisco_clicked()
{
    //QTableWidgetItem * item = this->ui->tableWidget->item(anteriorX,anteriorY);
    //item->setIcon(this->iconoceldaAnterior);
    this->ui->tableWidget->item(anteriorX,anteriorY)->setIcon(iconoceldaAnterior);

    if(control.model.listaSolucion.empty()){
        cout<<"ENTRO lista Vacia:"<<endl;
        this->ui->paso_A_Asterisco->setEnabled(false);
    }
    else{
        int celdaY=control.model.listaSolucion.front();
        control.model.listaSolucion.pop_front();
        int celdaX=control.model.listaSolucion.front();
        control.model.listaSolucion.pop_front();
        this->iconoceldaAnterior  = this->ui->tableWidget->item(celdaX,celdaY)->icon();
        QTableWidgetItem * item = this->ui->tableWidget->item(celdaX,celdaY);
        anteriorX=celdaX; anteriorY=celdaY;
        item->setIcon(QIcon (QString("MatrizImages/robot2.png")));
    }
}


void mapa::crear_archivo (int nodos_creados, int nodos_expandidos, int costo, int ramificacion )
{

    cout <<"creacion del archivo"<<endl;
    FILE * fichero ;
    fichero = fopen ("salida.txt","w+");
    char msg1 [] = "nodos creados : ";
    char msg2 [] = "nodos expandidos :";
    char msg3 [] = "costo solucion :";
    char msg4 [] = "factor de ramificacion : [";
    char msg5 [] = ", ";
    char msg6 [] = "]";
    char creados [10];
    sprintf(creados, "%d", nodos_creados);
    char expandidos [10];
    sprintf(expandidos, "%d", nodos_expandidos);
    char cadena_costo [10];
    sprintf(cadena_costo, "%d", costo);
    char ramif_inf [10];
    sprintf(ramif_inf, "%d", (ramificacion - 1));
    char ramif_sup [10];
    sprintf(ramif_sup, "%d", ramificacion);

    fputs (msg1,fichero);
    fprintf(fichero, creados);
    fprintf(fichero, "\n");
    fputs (msg2,fichero);
    fprintf(fichero, expandidos);
    fprintf(fichero, "\n");
    fputs (msg3,fichero);
    fprintf(fichero, cadena_costo);
    fprintf(fichero, "\n");
    fputs (msg4,fichero);
    fprintf(fichero, ramif_inf);
    fprintf(fichero, msg5);
    fprintf(fichero, ramif_sup);
    fprintf(fichero, msg6);
    fprintf(fichero, "\n");
    fclose (fichero);
}

int  mapa:: ramificacion (int profundidad, int nodos_creados)
{

    int ramificacion;
    bool aceptacion  = false;
    for (int i = 0; i<100; i++)
    {
        int val = 0;
        for (int j = 0; j<profundidad ; j++)
        {
          val += pow(i,j);
        }
        if (val >= nodos_creados  && (!aceptacion))
        {
            cout <<"paso por la condicion " + i <<endl;
            ramificacion = i;
            aceptacion = true;
            i = 100;
        }
    }

    return ramificacion;
}
