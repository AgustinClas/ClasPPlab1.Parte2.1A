#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"
#include "UTNnotebook.h"
#include "UTNtrabajoyservicio.h"

// cuando se termine el testeo del programa TAMNOT Y TAMTRB pasan a tener como valor 1000
#define TAMNOT 7
#define TAMTRB 7
#define TAMTIP 4
#define TAMMAR 4
#define TAMSER 4
#define TAMCLI 6


int mostrarMenu();

int main()
{
    //Inicializamos ambas en 1 ya que hay datos hardcodeados, de otra manera estarian inicializados en 0
    int flagCase1=1;
    int flagCase8=1;
    int proximoIdTrabajo = 1000;
    int proximoIdNotebook = 1000;
    eMarca marcas[TAMMAR]={ {1, "Compaq"},{2, "Asus"},{3, "Acer"},{4,"HP"}};
    eTipo tipos[TAMTIP]={ {1, "Gamer"},{2, "Disenio"},{3, "Ultrabook"},{4, "Normalita"}};
    eServicio servicios[TAMSER]= {{20000, "Bateria", 250 },{20001, "Antivirus", 300},{20002, "Actualizacion", 400},{20003, "Fuente", 600}};
    eCliente clientes[TAMCLI]={{2000, "Pablo Fernandez", 'm'},{2001, "Gonzalo Gonzales", 'm'},{2002, "Ana Gimenez", 'f'},
                                {2003, "Clara Ortega", 'f'}, {2004, "Carlos Gallo", 'm'}, {2005, "Claudia Estevez", 'f'}};

    eTrabajo trabajos[TAMTRB] = {{1000, 1000, 20000, {14,10,2020},0},
                            {1001, 1001, 20001, {12, 11, 2021},0},
                            {1002, 1004, 20001, {11, 9, 2020},0},
                            {1003, 1000, 20003, {9, 8, 2021},0},
                            {1004, 1002, 20003, {8, 4, 2020},0},
                            {1005, 1003, 20000,{26, 2, 2022}, 0}};

    //inicializarTrabajos(trabajos, TAMTRB);


    eNotebook notebooks[TAMNOT]={{1000, 2000, "Modelo", 1, 4, 20000, 0},
                            {1001,2001, "SuperPro", 1, 1, 14000,0},
                            {1002, 2004,  "nETBokGOb", 1, 4, 12000,0},
                            {1003, 2002, "NOTEBOK", 2, 3, 14000, 0},
                            {1004, 2004, "Netbook",4, 1, 21000, 0},
                            {1005, 2005,"GoGoGo", 2, 1, 12000, 0},
                            {1006, 2004, "PcYear", 1, 3, 24000, 0}};

    //inicializarNotebooks(notebooks, TAMNOT);

    int opcionMenu;

    do
    {
        //No uso system("cls") aqui ya que en mi consola no hace pausa automatioca entonces al listar algo no podria llegar a leerlo
        opcionMenu = mostrarMenu();

        switch(opcionMenu){
        case 1:
            if(altaNotebook(notebooks, TAMNOT, clientes, TAMCLI, tipos, TAMTIP, marcas, TAMMAR, proximoIdNotebook)==0){
                flagCase1=1;
                proximoIdNotebook++;
            }
            break;
        case 2:
            if(!flagCase1){
                printf("\nPrimero debe ingresar una notebook\n");
            }else{
                modificarNotebook(notebooks, TAMNOT, tipos, TAMTIP, marcas, TAMMAR, clientes, TAMCLI);
            }
            break;
        case 3:
            if(!flagCase1){
                printf("\nNo hay notebooks cargadas en el sistema\n\n");
            }else{
                int flag=0;
                bajaNotebook(notebooks, TAMNOT, marcas, TAMMAR, tipos, TAMTIP, clientes, TAMCLI);
                for(int i=0;i<TAMNOT;i++){
                    if(notebooks[i].isEmpty==0){
                        flag=1;
                    }
                }
                if(!flag){
                        flagCase1=0;
                }
            }
            break;
        case 4:
            if(!flagCase1){
                printf("\nNo hay notebooks cargadas en el sistema\n\n");
            }else{
                system("cls");
                listarNotebooks(notebooks, TAMNOT, marcas, TAMMAR, tipos, TAMTIP, clientes, TAMCLI);
            }
            break;
        case 5:
            system("cls");
            listarMarcas(marcas, 4);
            break;
        case 6:
            system("cls");
            listarTipos(tipos, 4);
            break;
        case 7:
            system("cls");
            listarServicios(servicios, 4);
            break;
        case 8:
            if(!flagCase1){
                printf("Primero debe ingresar una notebook\n");
            }else{
                if(altaTrabajo(trabajos, TAMTRB, notebooks, TAMNOT, servicios, 4, proximoIdTrabajo, marcas, TAMMAR, tipos, TAMTIP, clientes, TAMCLI)== 1){
                        proximoIdTrabajo++;
                        flagCase8=1;
                }else{
                    printf("\nOcurrio un error en el sistema\n");
                }
            }
            break;
        case 9:
            if(!flagCase8){
                printf("No hay ningun trabajo cargado en el sistema\n");
            }else{
                listarTrabajos(trabajos, TAMTRB, servicios, TAMSER, notebooks, TAMNOT);
            }
            break;
        case 10:
            informar(notebooks, TAMNOT, marcas, TAMMAR, tipos, TAMTIP, trabajos, TAMTRB, servicios, TAMSER, clientes, TAMCLI);
            break;
        }

    }
    while(opcionMenu!=11);



}


int mostrarMenu()
{
    int opcion;

    printf("\n****Menu****:\n\n1.Alta notebook\n");
    printf("2.Modificar notebook\n3.Baja notebook\n");
    printf("4.Listar notebooks\n5.Listar marcas\n");
    printf("6.Listar tipos\n7.Listar servicios\n8.Alta trabajo\n9.Listar trabajos\n10.Informar\n11.Salir\n");


    utn_getNumeroEntero(&opcion, "Ingrese opcion: ", "\nEsa opcion no es valida. ", 1, 11, 10);


    return opcion;

}

