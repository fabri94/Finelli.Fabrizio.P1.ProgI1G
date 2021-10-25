#include <stdio.h>
#include <stdlib.h>

#define TAM_VAC 5


typedef struct{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;

}eVacuna;

int reemplazarCaracteres(char cad[], char car1, char car2);
float aplicarAumento(float precio);
int ordenamientoPorTipoYEfectividad(eVacuna vacunas[], int tam);

int main()
{
    char cadena[20]="elpepe";
    char caracter1='e';
    char caracter2='a';
    int contadorDeCaracteresCambiados;
    float precio=400.50;
    float precioFinal;
    eVacuna vacunas[TAM_VAC]={
    {5000,"Astrazeneca",'a',90},
    {5001,"Astrazeneca",'a',100},
    {5002,"Pfizer",'b',45.15},
    {5003,"Pfizer",'c',60.5},
    {5004,"China",'d',70.99}
    };

    for(int i=0; i<TAM_VAC-1;i++)
    {
        printf("%d %s  %c   %.2f\n\n",vacunas[i].id
               ,vacunas[i].nombre
               ,vacunas[i].tipo
               ,vacunas[i].efectividad);
    }

    ordenamientoPorTipoYEfectividad(vacunas,TAM_VAC);

    for(int i=0; i<TAM_VAC-1;i++)
    {
        printf("%d %s  %c   %.2f\n\n",vacunas[i].id
               ,vacunas[i].nombre
               ,vacunas[i].tipo
               ,vacunas[i].efectividad);
    }

    contadorDeCaracteresCambiados=reemplazarCaracteres(cadena,caracter1,caracter2);

    printf("Se reemplazo el caracter %c por %c %d veces en la cadena original %s\n\n",caracter1,caracter2,contadorDeCaracteresCambiados,cadena);

    precioFinal=aplicarAumento(precio);

    printf("El precio original era %.2f, y este aumento a %.2f ",precio,precioFinal);
    return 0;
}


int reemplazarCaracteres(char cad[], char car1, char car2)
{
    int vecesQueSeReemplazo=0;
    if(cad!=NULL)
    {
        for(int i=0;cad[i]!='\0';i++)
        {
            if(cad[i]==car1)
            {
                cad[i]==car2;
                vecesQueSeReemplazo++;
            }
        }
    }


    return vecesQueSeReemplazo;
}

float aplicarAumento(float precio)
{
    float precioConAumento;

    precioConAumento=precio*1.05;

    return precioConAumento;

}

int ordenamientoPorTipoYEfectividad(eVacuna vacunas[], int tam)
{
    int todoOk=0;
    eVacuna auxVacuna;

    if(vacunas!=NULL&&tam>0)
    {
        for(int i=0; i<tam-1;i++)
        {
            for(int j=i+1;j<tam;j++)
            {
                if((vacunas[i].tipo>vacunas[j].tipo) ||
                   (vacunas[i].tipo==vacunas[j].tipo &&
                   (vacunas[i].efectividad<vacunas[j].efectividad)>0
                   ))
                {
                    auxVacuna=vacunas[i];
                    vacunas[i]=vacunas[j];
                    vacunas[j]=auxVacuna;
                }
            }
        }
        todoOk=1;
    }

    return todoOk;
}
