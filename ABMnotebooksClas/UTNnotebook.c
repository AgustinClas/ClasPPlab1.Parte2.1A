#include "UTNnotebook.h"
#include "UTNtrabajoyservicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN.h"

int altaNotebook(eNotebook notebooks[], int tam, eCliente clientes[], int tamCli, eTipo tipos[], int tamTip, eMarca marcas[], int tamMar, int idSugerido)
{
    int indiceLibre;
    int id;
    int existe=-1;
    int contadorOk=0;
    eNotebook auxNotebook;
    int retorno = 1;

    system("cls");
    printf("***Alta Notebook***\n\n");

    indiceLibre=buscarLibre(notebooks, tam);

    if(indiceLibre==-1)
    {
        printf("\nSistema completo\n");
    }
    else
    {
        printf("Id recomendado: %d\n", idSugerido);
        if(utn_getNumeroEntero(&id, "Ingrese Id: ", "Error.", 999, 9999, 10) == 0){
            existe=buscarNotebook(id, notebooks, tam);
            contadorOk++;
        }

        existe=buscarNotebook(id, notebooks, tam);

        if(existe!=-1)
        {
            printf("\nYa existe una notebook registrado con este id\n");
        }
        else
        {
            auxNotebook.id = id;

            if(contadorOk==1){
                if(utn_getString(auxNotebook.modelo, "Ingrese  el modelo: ", "Error. ", 10) == 0){
                    contadorOk++;
                }
            }

            if(contadorOk==2){
                listarClientes(clientes, tamCli);
                if(utn_getNumeroEntero(&auxNotebook.idCliente, "Ingrese  el cliente: ", "Error. ",2000, 2005, 10) == 0){
                    contadorOk++;
                }
            }

            if(contadorOk==3){
                listarTipos(tipos, tamTip);
                if(utn_getNumeroEntero(&auxNotebook.idTipo, "Ingrese el tipo: ", "Error. ", 1, 4, 10)==0){
                    contadorOk++;
                }
            }

            if(contadorOk==4){
                listarMarcas(marcas, tamMar);
                if(utn_getNumeroEntero(&auxNotebook.idMarca, "Ingrese la marca: ", "Error. ", 1, 4, 10)==0){
                    contadorOk++;
                }
            }

            if(contadorOk==5){
                if(utn_getNumeroFlotante(&auxNotebook.precio, "Ingrese el precio: ", "Error. ", 1, 400000, 10)==0){
                    contadorOk++;
                }
            }

            if(contadorOk==6){
                auxNotebook.isEmpty = 0;
                notebooks[indiceLibre] = auxNotebook;
                retorno = 0;
                printf("\n Operacion realizada con exito \n\n");
            }else{
                printf("\n No se ha podido cargar tu notebook\n\n");
            }



        }
    }
    return retorno;
}

int buscarLibre(eNotebook vec[], int tam)
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



void inicializarNotebooks (eNotebook notebooks[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        notebooks[i].isEmpty = 1;
    }
}


int buscarNotebook (int id, eNotebook vec[], int tam)
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

void modificarNotebook(eNotebook vec[], int tam, eTipo tipos[], int tamTip, eMarca marcas[], int tamMar, eCliente clientes[], int tamCli)
{
    int id;
    int indice;
    int opcion;
    char descripcionTipo[20];
    int todoOk = 0;

    system("cls");
    printf("***Modificar Notebook***\n\n");

    listarNotebooks(vec, tam, marcas, tamMar, tipos, tamTip, clientes, tamCli);

    utn_getNumeroEntero(&id, "Ingrese id: ", "Error. ", 999, 9999, 10);

    indice=buscarNotebook(id, vec, tam);


    if(indice==-1)
    {
        printf("\nEste id no existe\n");

    }else{

            cargarDescripcionTipo(descripcionTipo, vec[indice].idTipo, tipos, tamTip);
            printf("\nQue desea modificar?\n");
            printf("1. Precio: %.2f\n", vec[indice].precio);
            printf("2. tipo: %s\n", descripcionTipo);
            if(utn_getNumeroEntero(&opcion, "Ingrese su opcion: ", "Error. ", 1, 2, 10)==0){
                if(opcion == 1){
                    if(utn_getNumeroFlotante(&vec[indice].precio,"Ingrese el nuevo precio: ", "Error. ", 1, 400000, 10)==0){
                        todoOk=1;
                    }
                }else{
                    listarTipos(tipos, tamTip);
                    if(utn_getNumeroEntero(&vec[indice].idTipo, "Ingrese el nuevo tipo: ", "Error. ", 1, 4, 10)==0){
                        todoOk=1;
                    }

                }

            }

        if(!todoOk){
            printf("\nNo se pudo completar la operacion\n");
        }else{
            printf("\nOperacion realizada con exito\n");
        }
    }

}

void bajaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip, eCliente clientes[], int tamCli)
{
    int id;
    int indice;
    char confirmacion;
    char descripcionTipo[20];
    char descripcionMarca[20];
    char nombreCliente[40];

    system("cls");
    printf("***Baja Notebook***\n\n");

    listarNotebooks(vec, tam, marcas, tamMar, tipos, tamTip, clientes, tamCli);

    utn_getNumeroEntero( &id, "Ingrese id: ", "\nError. ", 999, 9999, 10);

    indice=buscarNotebook(id, vec, tam);

    if(indice==-1)
    {
        printf("Este id no existe");
    }
    else
    {
        cargarDescripcionMarca(descripcionMarca, vec[indice].idMarca, marcas, tamMar);
        cargarDescripcionTipo(descripcionTipo, vec[indice].idTipo, tipos, tamTip);
        cargarNombreCliente(nombreCliente, vec[indice].idCliente, clientes, tamCli);

        printf("Modelo: %s\n", vec[indice].modelo);
        printf("Cliente: %s\n", nombreCliente);
        printf("Marca: %s\n", descripcionMarca);
        printf("Tipo: %s\n", descripcionTipo);
        printf("Precio: %.2f\n", vec[indice].precio);

        printf("\nSeguro que desea dar de baja esta Notebook? s/n:  ");
        fflush(stdin);
        scanf("%c", &confirmacion);
        confirmacion = tolower(confirmacion);

        if(confirmacion=='s')
        {
            vec[indice].isEmpty=1;
            printf("Operacion realizada con exito");
        }
        else
        {
            printf("Se cancela la operacion");
        }

    }

}

void listarNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip, eCliente clientes[], int tamCli)
{
    int flag=1;
    char descripcionMarcaI[20];
    char descripcionMarcaJ[20];
    eNotebook auxNotebook;

    printf("****Lista de notebooks****");

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam;j++)
        {
            cargarDescripcionMarca(descripcionMarcaI, vec[i].idMarca,marcas, tamMar);
            cargarDescripcionMarca(descripcionMarcaJ, vec[j].idMarca, marcas, tamMar);
            if(strcmp(descripcionMarcaI, descripcionMarcaJ)==1)
            {
                auxNotebook = vec[i];
                vec[i] = vec[j];
                vec[j] = auxNotebook;

            }else if(strcmp(descripcionMarcaI, descripcionMarcaJ)==0)
            {
                if(vec[i].precio > vec[j].precio){
                    auxNotebook = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxNotebook;
                    }
            }
        }
    }

    printf("\nId                Cliente                  Marca              Tipo            Modelo         Precio\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarNotebook(vec[i], marcas, tamMar, tipos, tamTip, clientes, tamCli);
            flag=0;
        }

    }

    if(flag==1)
    {
        printf("No hay empleados para mostrar");
    }

}

void mostrarNotebook(eNotebook vec, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip, eCliente clientes[], int tamCli)
{
    char descripcionMarca[20];
    char descripcionTipo[20];
    char nombreCliente[40];

    cargarNombreCliente(nombreCliente, vec.idCliente, clientes,  tamCli);
    cargarDescripcionMarca(descripcionMarca, vec.idMarca, marcas, tamMar);
    cargarDescripcionTipo(descripcionTipo, vec.idTipo, tipos, tamTip);

    printf("%d  %25s %15s    %15s    %15s      %.2f\n", vec.id, nombreCliente, descripcionMarca, descripcionTipo, vec.modelo, vec.precio);

}

void listarMarcas(eMarca marcas[], int tam)
{

    printf("****Marcas****\n\n");
    printf("Id      Marca\n");

    for(int i=0; i<tam; i++)
    {
        printf("%d       %s\n", marcas[i].id, marcas[i].descripcion);
    }

    printf("\n\n");
}

void listarTipos(eTipo tipos[], int tam)
{
    printf("****Tipos****\n\n");
    printf("Id       tipo\n");

    for(int i=0; i<tam; i++)
    {
        printf("%d       %s\n", tipos[i].id, tipos[i].descripcion);
    }

    printf("\n\n");

}


void cargarDescripcionTipo(char descripcion[], int id, eTipo tipos[], int tam)
{

    for(int i=0; i<tam; i++)
    {
        if(tipos[i].id==id){
            strcpy(descripcion,tipos[i].descripcion);
        }
    }

}

void cargarNombreCliente(char nombre[], int id, eCliente clientes[], int tam)
{

    for(int i=0; i<tam; i++)
    {
        if(clientes[i].id==id){
            strcpy(nombre,clientes[i].nombre);
        }
    }

}

void cargarDescripcionMarca(char descripcion[], int id, eMarca marcas[], int tam)
{

    for(int i=0; i<tam; i++)
    {
        if(marcas[i].id==id){
            strcpy(descripcion,marcas[i].descripcion);
        }
    }

}

void listarClientes(eCliente clientes[], int tam)
{
    printf("****Clientes****\n\n");
    printf("Id    Nombre     sexo\n");

    for(int i=0; i<tam; i++)
    {
        printf("%d    %20s    %c\n", clientes[i].id, clientes[i].nombre, clientes[i].sexo);
    }

    printf("\n\n");
}



