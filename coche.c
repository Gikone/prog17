/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* FILENAME :	E5-1.c
*
* DESCRIPTION :
*   Shows different propierties for a given file formatted file
*
* NOTES :
*   This program is the solution to the proposed exercise
*   in the seventh week of the course 'Programación'
*   (programming) of Burgos University.
*
* AUTHOR : Rodrigo Díaz    START DATE : 27 Mar 2017
*
*TRADUCTOR: Diego Gonzalez
*
* CHANGES:
* 1.0 [29MAR2017] - Initial release
*/

#include <stdio.h>
#include <math.h>

int solicitaOpcionMenu();
void seleccionaOpcion(int);
int numeroFilas();
int numeroCols();
int numeroChar();
int fileMax();
void imprimeFila();
void imprimeFile();
int clean_stdin();

int main() {
  int opcionSeleccionada;
  do {
    FILE *f; //define la variable f como FILE
    f = fopen("car.txt", "r"); //abre la variable f como car.txt y "r" es modo lectura (w seria escritura)
    if (f!=NULL) { //si el archivo no esta vacio...
      opcionSeleccionada = solicitaOpcionMenu(); //guarda la opcionSeleccionada como lo que devuelva solicitaOpcionMenu
    }
    else {
      opcionSeleccionada = 0; // Si el archivo esta vacio la opcion seleccionada es la 0
      printf("ERROR READING FILE\n");
    }
    fclose(f); //Cierra el archivo
    seleccionaOpcion(opcionSeleccionada); //llama a la funcion seleccionaOpcion dandole la opcionSeleccionada
  } while (opcionSeleccionada != 0); //mientras la variable sea distinta de 0
  return 0;
}


int clean_stdin(){ //funcion para limpiar stdin osea si te pide 2 cosas y le das 4 da error y no coje nada
  while(getchar() != '\n');
  return 1;
}

int solicitaOpcionMenu(){
  int opcion, leido; //declara las variables opcion y leido
  char enter;
  printf("********************************\n"); 
  printf("*      SELECT AN OPTION _ \u25A1  X *\n");
  printf("*------------------------------*\n");
  printf("*  0.- End Execution           *\n");
  printf("*  1.- Number of Rows          *\n");
  printf("*  2.- Number of Columns       *\n");
  printf("*  3.- Number of Characters    *\n");
  printf("*  4.- Longest Row             *\n");
  printf("*  5.- Print Row               *\n");
  printf("*  6.- Print File              *\n");
  printf("********************************\n");
  while (1) { //bucle infinito
    printf("Insert option number: ");
    leido = scanf("%d%c",&opcion,&enter);
    if(leido != 2 || enter != '\n'){ //si no ha leido 2 cosas o no el caracter no es un enter ...
      printf("Incorrect value, please try again.\n");
      clean_stdin();
    }
    else if (option < 0 || option > 6) { //Si la opcion es menor de 0 o mayor de 6
      printf("Value out of range, please try again.\n");
    }
    else {
      return opcion;
    }
  }
}

void seleccionaOpcion(int opcion) {
  switch (opcion) { //permite seleccionar varias opciones como si fuera if
    case 0:
      break;
    case 1:
      printf("Total number of rows: %d\n\n", numeroFilas());
      break;
    case 2:
      printf("Total number of columns: %d\n\n", numeroCols());
      break;
    case 3:
      printf("Total number of characters: %d\n\n", numeroChar());
      break;
    case 4:
      printf("Longest row: %d\n\n", fileMax());
      break;
    case 5:
      imprimeFila();
      break;
    case 6:
      imprimeFile();
      break;
  }
}

int numeroFilas() {
  char c;
  int filasNumero = 0;
  FILE *f;
  f = fopen("car.txt", "r");
  c = fgetc(f);
  while (!feof(f)) { //mientras no se al final del archivo (feof function end of file de (f )que es el archivo)
    if (c == '\n') { //si el caracter leido es un enter
      ++filasNumero; //aumenta el numero de filas
      c = fgetc(f); //y lee el siguiente caracter
    }
    else {
      c = fgetc(f); //lee el siguiente caracter
      if (feof(f)) //si es el final del archivo
        ++filasNumero; //aumenta
    }
  }
  fclose(f);
  return filasNumero;
}

int numeroCols() {
  char c;
  int columnasNumero = 0;
  FILE *f;
  f = fopen("car.txt", "r"); //lo mismo que en lo anterior
  c = fgetc(f);
  while (!feof(f)) {
    if (c == ',' || c == '\n') { //si es , o enter aumenta el numero de columnas
      ++columnasNumero;
      c = fgetc(f);
    }
    else {
      c = fgetc(f);
      if (feof(f)) {
        ++columnasNumero;
      }
    }
  }
  fclose(f);
  return columnasNumero;
}

int numeroChar() {
  char c;
  int charNumero=0;
  FILE *f;
  f = fopen("car.txt", "r"); //lo mismo que en filas y columnas
  c = fgetc(f);
  while (!feof(f)) {
    ++charNumero;
    c = fgetc(f);
  }
  fclose(f);
  return charNumero;
}

int filasMax() { //calcula la fila que mas ocupa
  char c;
  int tempMax = 0, currentRowCount = 0, currentRowPos = 0, tempMaxPos = 0;
  FILE *f;
  f = fopen("car.txt", "r");
  while (!feof(f)) {
    c = fgetc(f);
    if (c == '\n' || feof(f)) {
      ++currentRowPos;
      if (currentRowCount > tempMax) {
        tempMax = currentRowCount;
        tempMaxPos = currentRowPos;
      }
      currentRowCount = 0;
    }
    else {
      ++currentRowCount;
    }
  }
  fclose(f);
  return tempMaxPos; 
}

void printRow() { //te pide un numero de columna y la muestra
  FILE *f;
  f = fopen("car.txt", "r");
  int rowSelected = -1, rowNum = nRows(f), read, currentRowCount = 0; //valida hasta que este bien puesto
  char enter, c;
  while (rowSelected < 1) {
    printf("Insert row number to print: ");
    read = scanf("%d%c",&rowSelected,&enter);
    if(read != 2 || enter != '\n'){
      printf("Incorrect value, please try again.\n");
      clean_stdin();
      rowSelected=-1;
    }
    else if (rowSelected < 1 || rowSelected > rowNum) {
      printf("Value out of range, please try again.\n");
      rowSelected=-1;
    }
  }
  fclose(f);
  f = fopen("car.txt", "r");
  while (!feof(f) && currentRowCount < rowSelected - 1) {
    if (c == '\n') {
      ++currentRowCount;}
    c = fgetc(f);
  }
  while (!feof(f) && c != '\n') {
    putchar(c);
    c = fgetc(f);
  }
  fclose(f);
  printf("\n\n");
}

void printFile() {
  FILE *f;
  char c;
  f = fopen("car.txt", "r");
  printf("---- FILE CONTENTS ----\n");
  c = fgetc(f);
  do { 
    putchar(c);
    c = fgetc(f); //coge el caracter y mientras no sea fin de archivo repite, cuando se fin cierra
  } while (!feof(f));
  fclose(f);
  printf("\n-----------------------\n\n");
}

