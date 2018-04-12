#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int longitud(char *car){
    int lon = 0;
    while(car[lon++] != '\0')
    {;
	}
    return lon;
}

int esVacia(char *car){
    int res = -1;
    if(*car != '\0')    {
        res = 1;
    }
    return res;
}

void concatenar(char c1[],char c2[]){
    int i,j;
    int tam1 = longitud(c1);
    int tam2 = longitud(c2);
    char c3[tam1+tam2];
	for(i=0;c1[i]!= '\0';i++)
	{
		c3[i] = c1[i];
	}
	for(j=0;c2[j]!='\0';j++)
	{
		c3[i+j] = c2[j];
	}
	c3[i+j] = '\0';
	printf("Cadena concatenada: %s\n",c3);
}

void insertarCar(char cadena[],char *insertar,int pos){
    int tam = longitud(cadena), i;
    if(pos < tam){
        for(i=tam-1;i>=pos;i--){
            cadena[i+1] = cadena[i];
        }
        cadena[pos] = *insertar;
        tam++;
        cadena[tam] = '\0';
        printf("Cadena: %s\n",cadena);
    }
    else{
        printf("Error,posicion superada.\n");
    }
}

void eliminarCar(char cadena1[],char aborrar){
    int i,j;
    int tam = longitud(cadena1);
    for(i=0;i<tam;i++)
    {
        if(cadena1[i] == aborrar)
        {
            for(j=i;j<tam-1;j++)
            {
                cadena1[j] = cadena1[j+1];
            }
            tam--;
            --i;
        }
    }
    printf("Cadena: %s\n",cadena1);
}

int main()
{
    printf("a) Calcular la longitud de una cadena.\n");
    char cad[] = {'H','e','l','l','o',',','W','o','r','l','d','!','\0'};
    printf("Cadena: %s\n",cad);
    int lon = longitud(cad);
    printf("La longitud de la cadena es: %i\n",lon);
    printf("\n");

    printf("b) Determinar si una cadena dada es vacia.\n");
    int res = esVacia(cad);
    printf("La cadena %s",cad);
    if(res == -1)
        printf(" es vacia.\n");
    else
        printf(" NO es vacia.\n");
    printf("\n");

    printf("c) Concatenar dos cadenas.\n");
    char c1[] = {'H','o','l','a',',','\0'};
    char c2[] = {'M','u','n','d','o','\0'};
    printf("Cadena1: %s\n",c1);
    printf("\n");
    printf("Cadena2: %s\n",c2);
    printf("\n");
    concatenar(c1,c2);

    printf("\n");

    printf("d) Insertar un caracter en una determinada posicion de una cadena.\n");
    char cadena[]={'a','b','c','d','e','\0'};
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
    char cadena1[] = {'B','A','B','D','E','B','G','\0'};
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

