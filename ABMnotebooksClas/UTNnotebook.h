#ifndef UTNNOTEBOOK_H_INCLUDED
#define UTNNOTEBOOK_H_INCLUDED


typedef struct
{
    int id;
    char descripcion[20];

}eMarca;

typedef struct
{
    int id;
    char descripcion[20];

}eTipo;

typedef struct
{
    int id;
    char nombre[40];
    char sexo;

}eCliente;

typedef struct
{
    int id;
    int idCliente;
    char modelo[20];
    int idMarca;
    int idTipo;
    float precio;
    int isEmpty;

}eNotebook;
#endif // UTNNOTEBOOK_H_INCLUDED


int altaNotebook(eNotebook notebooks[], int tam, eCliente clientes[], int tamCli, eTipo tipos[], int tamTip, eMarca marcas[], int tamMar, int idSugerido);
int buscarLibre(eNotebook vec[], int tam);
int buscarClienteLibre(eCliente vec[], int tam);
void inicializarNotebooks (eNotebook notebooks[], int tam);
int buscarNotebook (int id, eNotebook vec[], int tam);
void modificarNotebook(eNotebook vec[], int tam, eTipo tipos[], int tamTip, eMarca marcas[], int tamMar, eCliente clientes[], int tamCli);
void bajaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip, eCliente clientes[], int tamCli);
void mostrarNotebook(eNotebook vec, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip, eCliente clientes[], int tamCli);
void listarNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip, eCliente clientes[], int tamCli);
void listarMarcas(eMarca marcas[], int tam);
void listarTipos(eTipo tipos[], int tam);
void cargarDescripcionTipo(char descripcion[], int id, eTipo tipos[], int tam);
void cargarDescripcionMarca(char descripcion[], int id, eMarca marcas[], int tam);
void cargarNombreCliente(char nombre[], int id, eCliente clientes[], int tam);
void listarClientes(eCliente clientes[], int tam);

