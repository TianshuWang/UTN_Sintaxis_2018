#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
 	INICIO,FIN,LEER,ESCRIBIR,ID,CONSTANTE,PARENIZQ,PARENDERECHO,
 	PUNTOYCOMA,COMA,ASIGNACION,SUMA,RESTA,FDT
} TOKEN;

struct tabla{
    char id;
    TOKEN t;
} ;

char buffer[1024];


FILE * fuente;
FILE * archivoFinal;

void agregarCaracter(char c,int i){
    buffer[i] = c;
}

void limpiarBuffer(){
     memset(buffer, '\0', sizeof(buffer));
}

int columna(char n){
    if(isalpha(n)) return 1;
    if(isdigit(n)) return 3;
    if(n == '+') return 5;
    if(n == '-') return 6;
    if(n == '(') return 7;
    if(n == ')') return 8;
    if(n == ',') return 9;
    if(n == ';') return 10;
    if(n == ':') return 11;
    if(n == '=') return 14;
    if(n == EOF) return 13;
    if(isspace(n)) return 0;
    return 14;
}

TOKEN esReservada(char palabra[]){
    if(strcmp(palabra,"inicio")) return INICIO;
    else if(strcmp(palabra,"fin")) return FIN;
    else if(strcmp(palabra,"leer")) return LEER;
    else if(strcmp(palabra,"escribir")) return ESCRIBIR;
    else return ID;
}

TOKEN scanner(void){
    int mat[15][13] = {{1,3,5,6,7,8,9,0,11,14,13,0,14},//estado 0
                       {1,1,2,2,2,2,2,2,2,2,2,2,2},//estado 1
                       {14,14,14,14,14,14,14,14,14,14,14,14,14},//estado 2
                       {4,3,4,4,4,4,4,4,4,4,4,4,4},//estado 3
                       {14,14,14,14,14,14,14,14,14,14,14,14,14},//estado 4
                       {14,14,14,14,14,14,14,14,14,14,14,14,14},//estado 5
                       {14,14,14,14,14,14,14,14,14,14,14,14,14},//estado 6
                       {14,14,14,14,14,14,14,14,14,14,14,14,14},//estado 7
                       {14,14,14,14,14,14,14,14,14,14,14,14,14},//estado 8
                       {14,14,14,14,14,14,14,14,14,14,14,14,14},//estado 9
                       {14,14,14,14,14,14,14,14,14,14,14,14,14},//estado 10
                       {14,14,14,14,14,14,14,14,14,12,14,14,14},//estado 11
                       {14,14,14,14,14,14,14,14,14,14,14,14,14},//estado 12
                       {14,14,14,14,14,14,14,14,14,14,14,14,14},//estado 13
                       {14,14,14,14,14,14,14,14,14,14,14,14,14},//estado 14
                      };
    limpiarBuffer();
    int estado = 0,i = 0;
    char caracter;
    while(!feof(fuente)){
        int col;
        caracter = fgetc(fuente);
        col = columna(caracter);
        estado = mat[estado][col];
        switch(estado){
            case 1:
            case 3:
                agregarCaracter(caracter,i);
                i++;
                break;
            case 2:ungetc(caracter,fuente);
                if(esReservada(buffer)){
                    printf("Re \t   %s \n", buffer);
                }
                else{
                    if(strlen(buffer) < 32){
                        return ID;
                    }
                }
                break;
            case 4:ungetc(caracter,fuente);
                return CONSTANTE;
                break;
            case 5: return SUMA;
            case 6: return RESTA;
            case 7: return PARENIZQ;
            case 8: return PARENDERECHO;
            case 9: return COMA;
            case 10: return PUNTOYCOMA;
            case 11: return ASIGNACION;
            case 14: errorLexico();
        }
    }
    if (feof(fuente)) return FDT;
}

void errorLexico(void) {
    printf("Error lexico\n");
    fprintf(archivoFinal, "Error lexico\n");
}

int main(int argc, char* argv[]) {
    fuente = fopen("fuente.txt","r");
    fclose(fuente);
}
