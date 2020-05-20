#include "UTNnotebook.h"

#ifndef UTNTRABAJOYSERVICIO_H_INCLUDED
#define UTNTRABAJOYSERVICIO_H_INCLUDED


typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int id;
    char descripcion[20];
    float precio;

}eServicio;

typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

#endif // UTNTRABAJOYSERVICIO_H_INCLUDED


void listarServicios(eServicio servicios[], int tam);
int buscarLibreTrabajo(eTrabajo vec[], int tam);
int buscarTrabajo (int id, eTrabajo vec[], int tam);
void inicializarTrabajos (eTrabajo trabajos[], int tam);
int altaTrabajo(eTrabajo trabajos[], int tam, eNotebook notebooks[], int tamNot, eServicio servicios[], int tamSer, int proximoId, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip, eCliente clientes[], int tamCli);
void listarTrabajos (eTrabajo trabajos[], int tam, eServicio servicios[], int tamSer, eNotebook notebooks[], int tamNot);
void listarTrabajo(eTrabajo trabajos, eServicio servicios[], int tamSer, eNotebook notebooks[], int tamNot);
void cargarDescripcionServicio(char descripcion[], int id, eServicio servicios[], int tam);
void cargarDescripcionNotebook(char descripcion[], int id, eNotebook notebooks[], int tam);
float cargarPrecioServicio(int id, eServicio servicios[], int tam);
void informar(eNotebook notebooks[], int tamNot, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip, eTrabajo trabajos[], int tamTrb, eServicio servicios[], int tamSer, eCliente clientes[], int tamCli);
int menuInformes();
void informarNotebooksTipo(eNotebook notebooks[], int tamNot, eTipo tipos[], int tamTip, eMarca marcas[], int tamMar, eCliente clientes[], int tamCli);
void informarNotebooksMarca(eNotebook notebooks[], int tamNot, eTipo tipos[], int tamTip, eMarca marcas[], int tamMar, eCliente clientes[], int tamCli);
void informarNotebookMasBarata(eNotebook notebooks[], int tamNot, eTipo tipos[], int tamTip, eMarca marcas[], int tamMar, eCliente clientes[], int tamCli);
void informarNotebooksXMarca(eNotebook notebooks[], int tamNot, eTipo tipos[], int tamTip, eMarca marcas[], int tamMar, eCliente clientes[], int tamCli);
void informarCantidadNotebooksTipoYmarca(eNotebook notebooks[], int tamNot, eTipo tipos[], int tamTip, eMarca marcas[], int tamMar, eCliente clientes[], int tamCli);
void informarMarcaMasElegida(eNotebook notebooks[], int tamNot, eTipo tipos[], int tamTip, eMarca marcas[], int tamMar, eCliente clientes[], int tamCli);
void informarTrabajoNotebook(eTrabajo trabajos[], int tamTrb, eServicio servicios[], int tamSer, eNotebook notebooks[], int tamNot, eCliente clientes[], int tamCli, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip);
void informarPrecioServiciosANotebook(eTrabajo trabajos[], int tamTrb, eServicio servicios[], int tamSer, eNotebook notebooks[], int tamNot, eCliente clientes[], int tamCli, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip);
void informarServiciosXFecha(eTrabajo trabajos[], int tamTrb, eServicio servicios[], int tamSer, eNotebook notebooks[], int tamNot);
void informarNotebooksServicio(eTrabajo trabajos[], int tamTrb, eServicio servicios[], int tamSer, eNotebook notebooks[], int tamNot, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip, eCliente clientes[], int tamCli);
