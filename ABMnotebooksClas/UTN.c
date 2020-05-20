#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utn.h"
#include <ctype.h>
#include <conio.h>

int utn_getCharacter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
    int retorno = -1;
    char buffer;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%c", &buffer);
            if(buffer == minimo || buffer == maximo)
            {
                *pResultado = buffer;
                retorno = 0;
                break;
            }
            printf("%s", mensajeError);
            reintentos--;

        }
        while(reintentos>=0);

    }

    return retorno;
}

int utn_getNumeroEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int bufferInt;
    int retorno = -1;

    do {

        printf("%s", mensaje);

        if(getInt(&bufferInt) == 0 &&
           bufferInt >= minimo &&
           bufferInt <= maximo)
        {
            *pResultado = bufferInt;
            retorno = 0;
            break;
        }

        printf("%s", mensajeError);
        reintentos--;

    }while(reintentos >=0);

    return retorno;
}

int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[50];

    if(pResultado != NULL &&
            myGets(bufferString,sizeof(bufferString))== 0 &&
            esNumerica(bufferString, sizeof(bufferString)))
    {
        *pResultado = atoi(bufferString);
        retorno = 0;
    }
    return retorno;
}


int myGets(char* cadena, int longitud)
{
    int retorno = -1;
    char bufferString [50];

    if(cadena != NULL && longitud > 0)
    {
        fflush(stdin);
        if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
        {
            if(bufferString[strlen(bufferString)-1] == '\n')
            {
                bufferString[strlen(bufferString)-1] = '\0';
            }
            if(strlen(bufferString) <= longitud)
            {
                strncpy(cadena, bufferString, longitud);
                retorno = 0;
            }
        }
    }
    return retorno;
}

int esNumerica(char* cadena, int limite)
{
    int retorno = 1;

    if(cadena != NULL && limite > 0)
    {
        for(int i=0; i<limite && cadena[i] != '\0'; i++)
        {
            if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
            {
                continue;
            }
            if(cadena[i] < '0' || cadena[i] > '9')
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    float bufferFloat;
    int retorno = -1;

    do {

        printf("%s", mensaje);

        if(getFloat(&bufferFloat) == 0 &&
           bufferFloat >= minimo &&
           bufferFloat <= maximo)
        {
            *pResultado = bufferFloat;
            retorno = 0;
            break;
        }

        printf("%s", mensajeError);
        reintentos--;

    }while(reintentos >=0);

    return retorno;
}

int getFloat(float* pResultado)
{
    int retorno=-1;
    char bufferString[50];

    if(pResultado != NULL &&
            myGets(bufferString,sizeof(bufferString))== 0 &&
            esFlotante(bufferString, sizeof(bufferString)))
    {
        *pResultado = atof(bufferString);
        retorno = 0;
    }
    return retorno;
}

int esFlotante(char* cadena, int limite)
{
    int retorno = 1;

    if(cadena != NULL && limite > 0)
    {
        for(int i=0; i<limite && cadena[i] != '\0'; i++)
        {
            if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
            {
                continue;
            }
            if(cadena[i] == '.')
            {
                continue;
            }
            if(cadena[i] < '0' || cadena[i] > '9')
            {
                retorno = 0;
                break;
            }

        }
    }

    return retorno;
}

int utn_getEmail(char* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
    char bufferMail[50];
    int retorno = -1;

    do {

        printf("%s", mensaje);

        if(getMail(bufferMail) == 0)
        {
            strcpy(pResultado, bufferMail);
            retorno = 0;
            break;
        }

        printf("%s", mensajeError);
        reintentos--;

    }while(reintentos >=0);

    return retorno;
}

int getMail(char* pResultado)
{
    int retorno=-1;
    char bufferString[50];

    if(pResultado != NULL &&
            myGets(bufferString,sizeof(bufferString))== 0 &&
            esMail(bufferString, sizeof(bufferString)))
    {
        strcpy(pResultado, bufferString);
        retorno = 0;
    }
    return retorno;
}

int esMail(char* cadena, int limite)
{
    int retorno = 1;
    int contadorArrobas = 0;

    if(cadena != NULL && limite > 0)
    {
        for(int i=0; i<limite && cadena[i] != '\0'; i++)
        {
            if(cadena[i] == '@' && contadorArrobas == 0)
            {
                contadorArrobas++;
                continue;
            }
            if(cadena[i] == '@')
            {
                retorno = 0;
                break;
            }
            if((cadena[i] < '0' || cadena[i] > '9') &&
               (cadena[i] < 'a' || cadena[i] > 'z') &&
               (cadena[i] < 'A' || cadena[i] > 'Z') &&
               (cadena[i] != '.' && cadena[i]!= '-' && cadena[i] != '_'))
            {
                retorno = 0;
                break;
            }
        }
        if(contadorArrobas==0)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int utn_getString(char* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
    char bufferString[50];
    int retorno = -1;

    do {

        printf("%s", mensaje);

        if(getString(bufferString) == 0)
        {
            strcpy(pResultado, bufferString);
            retorno = 0;
            break;
        }

        printf("%s", mensajeError);
        reintentos--;

    }while(reintentos >=0);

    return retorno;
}

int getString(char* pResultado)
{
    int retorno=-1;
    char bufferString[50];

    if(pResultado != NULL &&
            myGets(bufferString,sizeof(bufferString))== 0 &&
            esString(bufferString, sizeof(bufferString)))
    {
        strcpy(pResultado, bufferString);
        retorno = 0;
    }
    return retorno;
}

int esString(char* cadena, int limite)
{
    int retorno = 1;

    if(cadena != NULL && limite > 0)
    {
        for(int i=0; i<limite && cadena[i] != '\0'; i++)
        {
            if(cadena[i] == 32)
            {
                continue;
            }
            if( (cadena[i] < 'a' || cadena[i] > 'z') &&
               (cadena[i] < 'A' || cadena[i] > 'Z') )
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

void formalizarString(char* pString)
{
    strlwr(pString);

    for(int i=0; i<strlen(pString); i++)
    {
        if(i==0)
        {
            pString[i] = toupper(pString[i]);
        }

        if(pString[i] == 32)
        {
            pString[i+1] = toupper(pString[i+1]);
        }
    }
}
