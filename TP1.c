// TP 1 SSL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define LONG 20

int longitud(char *car)
{
    int lon = 0;
    lon = strlen(car);
    return lon;
}

int esVacia(char *car)
{
    int res = -1;
    if(*car != '\0')
    {
        res = 1;
    }
    return res;
}

void concatenar(char *c1,char *c2)
{
    strcat(c1,c2);
}

void insertarCar(char cadena[],char *insertar,int pos)
{
    int tam = longitud(cadena);
    if(pos < tam)
    {
        for(int i=tam-1;i>=pos;i--)
        {
            cadena[i+1] = cadena[i];
        }
        cadena[pos] = *insertar;
        tam++;
        cadena[tam] = '\0';
        printf("Cadena: %s\n",cadena);
    }
    else
    {
        printf("Error,posicion superada.\n");
    }
}

void eliminarCar(char cadena1[],char aborrar)
{
    int pos;
    int tam = longitud(cadena1);
    int i=0;
    int encontrado = 0;
    while(i<tam && encontrado==0)
    {
        if(cadena1[i] == aborrar)
        {
            pos = i;
            encontrado = 1;
        }
        i++;
    }
    if(encontrado == 1)
    {
        for(int j=pos;j<tam-1;j++)
        {
            cadena1[j] = cadena1[j+1];
        }
        tam--;
        cadena1[tam] = '\0';
        printf("Cadena: %s\n",cadena1);
    }
    else
    {
        printf("Error,caracter NO existe.\n");
    }

}

int main()
{

    printf("a) Calcular la longitud de una cadena.\n");
    char cad[] = {'H','e','l','l','o',',','W','o','r','l','d','!','\0'};
    printf("Cadena: %s\n",cad);
    int lon = longitud(cad);
    printf("La longitud de la cadena es: %i\n",lon);
    printf("\n");

    printf("b) Determinar si una cadena dada es vac¨ªa.\n");
    int res = esVacia(cad);
    printf("La cadena %s",cad);
    if(res == -1)
    {
        printf(" es vacia.\n");
    }
    else
    {
        printf(" NO es vacia.\n");
    }
    printf("\n");

    printf("c) Concatenar dos cadenas.\n");
    char c1[LONG] = {'H','o','l','a',',','\0'};
    char c2[LONG] = {'M','u','n','d','o','\0'};
    printf("Cadena1: %s\n",c1);
    printf("\n");
    printf("Cadena2: %s\n",c2);
    printf("\n");
    concatenar(c1,c2);
    printf("Cadena concatenada: %s\n",c1);
    printf("\n");

    printf("d) Insertar un caracter en una determinada posici¨®n de una cadena.\n");
    char cadena[LONG]={'a','b','c','d','e','\0'};
    printf("Cadena: %s\n",cadena);
    printf("\n");
    char insertar;
    int pos;
    printf("Indique el caracter a insertar: ");
    insertar = getchar();
    printf("Indique la posicion de la cadena a insertarlo: ");
    scanf("%i",&pos);
    insertarCar(cadena,&insertar,pos);
    printf("\n");

    printf("e) Eliminar un caracter dado de una cadena.\n");
    char cadena1[LONG] = {'A','B','C','D','E','F','G','\0'};
    char aborrar;
    printf("Cadena: %s\n",cadena1);
    printf("\n");
    printf("Ingrese un caracter a borrar en la cadena1: ");
    fflush(stdin);
    aborrar = getchar();
    eliminarCar(cadena1,aborrar);

    getch();
    return 0;
}
