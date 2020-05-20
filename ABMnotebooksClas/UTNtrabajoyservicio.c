#include "UTN.h"
#include "UTNtrabajoyservicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void listarServicios(eServicio servicios[], int tam)
{
    printf("****Servicios****\n");
    printf("Id              Servicio          Precio\n\n");

    for(int i=0; i<tam; i++)
    {
        printf("%d     %15s       %.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
    }

    printf("\n\n");
}

int altaTrabajo(eTrabajo trabajos[], int tam, eNotebook notebooks[], int tamNot, eServicio servicios[], int tamSer, int proximoId, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip, eCliente clientes[], int tamCli)
{
    int todoOk=0;
    int contadorOk=0;
    int indiceLibre;
    eTrabajo auxTrabajo;

    system("cls");
    printf("***Alta Trabajo***\n\n");

    indiceLibre=buscarLibreTrabajo(trabajos, tam);

    if(indiceLibre==-1)
    {
        printf("\nSistema completo\n");
    }
    else{

        auxTrabajo.id = proximoId;
        listarNotebooks(notebooks, tamNot, marcas, tamMar, tipos, tamTip, clientes, tamCli);
        if(utn_getNumeroEntero(&auxTrabajo.idNotebook, "Ingrese el id de la notebook: ", "Error. ", 999, 9999, 10)==0){
            if(buscarNotebook(auxTrabajo.idNotebook, notebooks, tamNot)>-1){
                contadorOk++;
            }else{
                printf("Este id de notebook no existe\n");
            }
        }

        if(contadorOk==1){
            listarServicios(servicios, tamSer);
            if(utn_getNumeroEntero(&auxTrabajo.idServicio, "Ingrese id del servicio: ", "\nError. ", 20000, 20003, 10)==0){
                contadorOk++;
            }
        }

        if(contadorOk==2){
            if(utn_getNumeroEntero(&auxTrabajo.fecha.dia, "Ingrese el dia: ", "\nError. ", 1, 31, 10)==0){
                contadorOk++;
            }
        }

        if(contadorOk==3){
            if(utn_getNumeroEntero(&auxTrabajo.fecha.mes, "Ingrese el mes: ", "\nError. ", 1, 12, 10)==0){
                contadorOk++;
            }
        }

        if(contadorOk==4){
            if(utn_getNumeroEntero(&auxTrabajo.fecha.anio, "Ingrese el anio: ", "\nError. ", 2020, 2030, 10)==0){
                contadorOk++;
            }
        }

        if(contadorOk==5){
            auxTrabajo.isEmpty = 0;
            trabajos[indiceLibre] = auxTrabajo;
            todoOk=1;
        }
    }


    return todoOk;
}

int buscarLibreTrabajo(eTrabajo vec[], int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void inicializarTrabajos (eTrabajo trabajos[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        trabajos[i].isEmpty = 1;
    }
}

int buscarTrabajo (int id, eTrabajo vec[], int tam)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].id==id && vec[i].isEmpty == 0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}


void listarTrabajos (eTrabajo trabajos[], int tam, eServicio servicios[], int tamSer, eNotebook notebooks[], int tamNot)
{

    system("cls");
    printf("****Trabajos****\n\n");
    printf("Id          Notebook       servicio      precio      Fecha\n");


    for(int i=0; i<tam; i++)
    {
        if(trabajos[i].isEmpty==0){
            listarTrabajo(trabajos[i], servicios, tamSer, notebooks, tamNot);
        }
    }

    printf("\n\n");

}

void listarTrabajo(eTrabajo trabajos, eServicio servicios[], int tamSer, eNotebook notebooks[], int tamNot)
{
    char descripcionServicio[20];
    char descripcionNotebook[20];
    float precio;

    cargarDescripcionServicio(descripcionServicio, trabajos.idServicio, servicios, tamSer);
    cargarDescripcionNotebook(descripcionNotebook, trabajos.idNotebook, notebooks, tamNot);
    precio = cargarPrecioServicio(trabajos.idServicio, servicios, tamSer);
    printf("%d %15s %15s    %.2f   %d/%d/%d \n", trabajos.id, descripcionNotebook, descripcionServicio, precio, trabajos.fecha.dia, trabajos.fecha.mes, trabajos.fecha.anio);

}

void cargarDescripcionServicio(char descripcion[], int id, eServicio servicios[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        if(servicios[i].id==id){
            strcpy(descripcion,servicios[i].descripcion);
        }
    }

}

void cargarDescripcionNotebook(char descripcion[], int id, eNotebook notebooks[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        if(notebooks[i].id==id){
            strcpy(descripcion,notebooks[i].modelo);
        }
    }
}

float cargarPrecioServicio(int id, eServicio servicios[], int tam)
{
    float precio;

    for(int i=0; i<tam; i++)
    {
        if(servicios[i].id==id){
            precio = servicios[i].precio;
        }
    }

    return precio;
}

void informar(eNotebook notebooks[], int tamNot, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip,eTrabajo trabajos[], int tamTrb, eServicio servicios[], int tamSer, eCliente clientes[], int tamCli)
{
    int opcion;

    system("cls");


    do{
        opcion=menuInformes();

        switch(opcion){
            case 1:
                informarNotebooksTipo(notebooks, tamNot, tipos, tamTip, marcas, tamMar, clientes, tamCli);
                break;
            case 2:
                informarNotebooksMarca(notebooks, tamNot, tipos, tamTip, marcas, tamMar, clientes, tamCli);
                break;
            case 3:
                informarNotebookMasBarata(notebooks, tamNot, tipos, tamTip, marcas, tamMar, clientes, tamCli);
                break;
            case 4:
                informarNotebooksXMarca(notebooks, tamNot, tipos, tamTip, marcas, tamMar, clientes, tamCli);
                break;
            case 5:
                informarCantidadNotebooksTipoYmarca(notebooks, tamNot, tipos, tamTip, marcas, tamMar, clientes, tamCli);
                break;
            case 6:
                informarMarcaMasElegida(notebooks, tamNot, tipos, tamTip, marcas, tamMar, clientes, tamCli);
                break;
            case 7:
                informarTrabajoNotebook(trabajos, tamTrb, servicios, tamSer, notebooks, tamNot, clientes, tamCli, marcas, tamMar, tipos, tamTip);
                 break;
            case 8:
                informarPrecioServiciosANotebook(trabajos, tamTrb, servicios, tamSer, notebooks, tamNot, clientes, tamCli, marcas, tamMar, tipos, tamTip);
                break;
            case 9:
                informarNotebooksServicio(trabajos, tamTrb, servicios, tamSer, notebooks, tamNot, marcas, tamMar, tipos, tamTip, clientes, tamCli);
                break;
            case 10:
                informarServiciosXFecha(trabajos, tamTrb, servicios, tamSer, notebooks, tamNot);
                break;

        }
    }while(opcion!=11);
}

int menuInformes()
{
        int opcion;

        printf("\n******Menu de informes******\n\n");
        printf("1. Informar notebooks del tipo seleccionado por el usuario\n");
        printf("2. Informar notebook de la marca seleccionada por el usuario\n");
        printf("3. Informar notebook mas barata\n");
        printf("4. Informar notebooks por marca\n");
        printf("5. Informar cantidad de notebooks de tipo y marca seleccionados\n");
        printf("6. Informar marca mas elegida\n");
        printf("7. Informar trabajos hechos a una notebook\n");
        printf("8. Informar precio de servicios a una notebook\n");
        printf("9. Informar notebooks a las que se les realizo un servicio seleccionado por el usuario\n");
        printf("10. Informar los servicios hechos en una fecha\n");
        printf("11. Salir\n");

        utn_getNumeroEntero(&opcion, "Ingrese una opcion: ", "Error. ", 1, 11, 10);

        return opcion;
}

void informarNotebooksTipo(eNotebook notebooks[], int tamNot, eTipo tipos[], int tamTip, eMarca marcas[], int tamMar, eCliente clientes[], int tamCli)
{
    int idTipo;
    int flag=0;
    system("cls");
    printf("****Informar notebooks tipo****\n");

    listarTipos(tipos, tamTip);
    utn_getNumeroEntero(&idTipo, "Ingrese el id del tipo: ", "Error. ", 1, 4, 10);


    for(int i=0;i<tamNot;i++){
        if(notebooks[i].idTipo==idTipo&&notebooks[i].isEmpty==0){
            mostrarNotebook(notebooks[i], marcas, tamMar, tipos, tamTip, clientes, tamCli);
            flag=1;
        }
    }

    if(!flag){
        printf("\nNo hay notebooks de este tipo\n");
    }

}

void informarNotebooksMarca(eNotebook notebooks[], int tamNot, eTipo tipos[], int tamTip, eMarca marcas[], int tamMar, eCliente clientes[], int tamCli)
{
    int idMarca;
    int flag=0;
    system("cls");
    printf("****Informar notebooks marca****\n");

    listarMarcas(marcas, tamMar);
    utn_getNumeroEntero(&idMarca, "Ingrese el id de la marca: ", "Error. ", 1, 4, 10);


    for(int i=0;i<tamNot;i++){
        if(notebooks[i].idMarca==idMarca&&notebooks[i].isEmpty==0){
            mostrarNotebook(notebooks[i], marcas, tamMar, tipos, tamTip, clientes, tamCli);
            flag=1;
        }
    }

    if(!flag){
        printf("\nNo hay notebooks de esta marca\n");
    }

}

void informarNotebookMasBarata(eNotebook notebooks[], int tamNot, eTipo tipos[], int tamTip, eMarca marcas[], int tamMar, eCliente clientes[], int tamCli)
{
    int flag=0;
    float precioMin;
    int indiceMin;

    system("cls");

    for(int i=0; i<tamNot;i++){
       if(notebooks[i].isEmpty==0){
            if(!flag){
                precioMin = notebooks[i].precio;
                indiceMin = i;
                flag=1;
            }
            if(precioMin > notebooks[i].precio){
                precioMin = notebooks[i].precio;
                indiceMin = i;
            }
       }
    }

    printf("La notebook/s mas barata/s es: \n");
    mostrarNotebook(notebooks[indiceMin], marcas, tamMar, tipos, tamTip, clientes, tamCli);

    for(int i=0; i<tamNot;i++){
        if(notebooks[indiceMin].precio == notebooks[i].precio && notebooks[i].isEmpty == 0 && indiceMin != i)
            mostrarNotebook(notebooks[i], marcas, tamMar, tipos, tamTip, clientes, tamCli);
    }
}

void informarNotebooksXMarca(eNotebook notebooks[], int tamNot, eTipo tipos[], int tamTip, eMarca marcas[], int tamMar, eCliente clientes[], int tamCli)
{
    int flag;

    system("cls");

    for(int m=0; m<tamMar; m++){
        printf("\nMarca: %s\n", marcas[m].descripcion);
        flag=0;

        for(int i=0;i<tamNot;i++){
            if(notebooks[i].idMarca==marcas[m].id&&notebooks[i].isEmpty==0){
                mostrarNotebook(notebooks[i], marcas, tamMar, tipos, tamTip, clientes, tamCli);
                flag=1;
            }
        }

        if(!flag){
            printf("No hay notebooks de esta marca en el sistema\n");
        }
    }

}

void informarCantidadNotebooksTipoYmarca(eNotebook notebooks[], int tamNot, eTipo tipos[], int tamTip, eMarca marcas[], int tamMar, eCliente clientes[], int tamCli)
{
    int contador=0;
    int idTipo;
    int idMarca;
    int flag=0;
    system("cls");
    printf("****Cantidad de notebooks por tipo y marca****\n");

    listarTipos(tipos, tamTip);
    utn_getNumeroEntero(&idTipo, "Ingrese el id del tipo: ", "Error. ", 1, 4, 10);

    listarMarcas(marcas, tamMar);
    utn_getNumeroEntero(&idMarca, "Ingrese el id de la marca: ", "Error. ", 1, 4, 10);

    for(int i=0; i<tamNot; i++)
    {
        if(notebooks[i].idMarca == idMarca && notebooks[i].idTipo == idTipo && notebooks[i].isEmpty == 0){
            contador++;
            flag=1;
        }
    }

    if(flag==1){
    printf("\nDe la marca y tipo seleccionados hay %d notebooks cargadas en el sistema\n\n", contador);
    }else{
        printf("\nNo hay notebooks de este tipo y marca cargadas en el sistema\n\n");
    }
}

void informarMarcaMasElegida(eNotebook notebooks[], int tamNot, eTipo tipos[], int tamTip, eMarca marcas[], int tamMar, eCliente clientes[], int tamCli)
{
    int contadorMarca[4]={0, 0, 0, 0};
    int contadorMax;
    int flag=0;
    char descripcionMarca[20];

    for(int m=0; m<tamMar; m++){

        for(int i=0; i<tamMar; i++)
            if(notebooks[i].idMarca == marcas[m].id){
                contadorMarca[m]++;
            }
    }

    for(int m=0; m<tamMar; m++){
        if(!flag){
            contadorMax = contadorMarca[m];
            flag=1;
        }else if(contadorMax<contadorMarca[m]){
            contadorMax = contadorMarca[m];
        }
    }


    printf("Las marcas mas elegidas por los usuarios son:\n");

    for(int m=0; m<tamMar; m++){
        if(contadorMarca[m]==contadorMax){
            cargarDescripcionMarca(descripcionMarca, marcas[m].id, marcas, tamMar);
            printf("%s\n", descripcionMarca);
        }
    }



}

void informarTrabajoNotebook(eTrabajo trabajos[], int tamTrb, eServicio servicios[], int tamSer, eNotebook notebooks[], int tamNot, eCliente clientes[], int tamCli, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip)
{
    int idNotebook;
    int flag=0;
    system("cls");
    printf("****Informar trabajos por notebook****\n");

    listarNotebooks(notebooks, tamNot, marcas, tamMar, tipos, tamTip, clientes, tamCli);
    utn_getNumeroEntero(&idNotebook, "Ingrese el id de la notebook: ", "Error. ", 1000, 2000, 10);


    for(int i=0;i<tamTrb;i++){
        if(trabajos[i].idNotebook==idNotebook&&trabajos[i].isEmpty==0){
            listarTrabajo(trabajos[i], servicios, tamSer, notebooks, tamNot);
            flag=1;
        }
    }

    if(!flag){
        printf("\nNo se le hizo ningun trabajo a esta notebook\n");
    }



}

void informarPrecioServiciosANotebook(eTrabajo trabajos[], int tamTrb, eServicio servicios[], int tamSer, eNotebook notebooks[], int tamNot, eCliente clientes[], int tamCli, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip)
{
    int idNotebook;
    int flag=0;
    float acumuladorPrecio=0;
    float precioServicio;
    char descripcionNotebook[20];
    system("cls");
    printf("****Informar precio total de servicios a notebook****\n");

    listarNotebooks(notebooks, tamNot, marcas, tamMar, tipos, tamTip, clientes, tamCli);
    utn_getNumeroEntero(&idNotebook, "Ingrese el id de la notebook: ", "Error. ", 1000, 2000, 10);


    for(int i=0;i<tamTrb;i++){
        if(trabajos[i].idNotebook == idNotebook){
            precioServicio = cargarPrecioServicio(trabajos[i].idServicio, servicios, tamSer);
            acumuladorPrecio += precioServicio;
            flag=1;
        }

    }


    if(!flag){
        printf("\nNo se le hizo ningun trabajo a esta notebook\n");
    }else{
        cargarDescripcionNotebook(descripcionNotebook, idNotebook, notebooks, tamNot);
        printf("El precio total de los servicios que se le hicieron a la %s es: %.2f", descripcionNotebook, acumuladorPrecio);
    }
}

void informarServiciosXFecha(eTrabajo trabajos[], int tamTrb, eServicio servicios[], int tamSer, eNotebook notebooks[], int tamNot)
{
    int auxDia;
    int auxMes;
    int auxAnio;
    int flag=-1;

    system("cls");
    printf("****Informar servicios por fecha****\n\n");
    //minimo 2020 y maximo 2030 ya que fue lo que le permitimos al usuario al ingresar un trabajo
    utn_getNumeroEntero(&auxDia, "Ingrese el dia: ", "Error. ", 1, 31, 10);
    utn_getNumeroEntero(&auxMes, "Ingrese el mes: ", "Error. ", 1, 12, 10);
    utn_getNumeroEntero(&auxAnio, "Ingrese el anio: ", "Error. ", 2020, 2030, 10);

    for(int i=0; i<tamTrb; i++)
    {
        if(trabajos[i].fecha.anio == auxAnio && trabajos[i].fecha.mes == auxMes && trabajos[i].fecha.dia == auxDia && trabajos[i].isEmpty==0){
            listarTrabajo(trabajos[i], servicios, tamSer, notebooks, tamNot);
            flag=0;
        }
    }

    if(flag==-1){
            printf("No hay servicios hechos en esta fecha\n\n");
        }


}

void informarNotebooksServicio(eTrabajo trabajos[], int tamTrb, eServicio servicios[], int tamSer, eNotebook notebooks[], int tamNot, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip, eCliente clientes[], int tamCli)
{
    int idServicio;
    int flag=0;
    int indiceNotebook;
    system("cls");
    printf("****Informar notebooks a las que se les hizo un servicio****\n");

    listarServicios(servicios, tamSer);
    utn_getNumeroEntero(&idServicio, "Ingrese el id del servicio: ", "Error. ", 20000, 20004, 10);


    for(int i=0;i<tamTrb;i++){
        if(trabajos[i].idServicio==idServicio&&trabajos[i].isEmpty==0){
            indiceNotebook = buscarNotebook(trabajos[i].idNotebook, notebooks, tamNot);

            printf("Fecha: %d/%d/%d  Notebook:    ", trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
            mostrarNotebook(notebooks[indiceNotebook], marcas, tamMar, tipos, tamTip, clientes, tamCli);
            flag=1;
        }
    }

    if(!flag){
        printf("\nNo se le realizo este servicio a ninguna notebook\n\n");
    }



}
