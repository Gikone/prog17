//PRACTICAS PROGRAMACION 2017
//AUTHOR Diego Gonzalez Roman
//DESCRIPTION: Distintos ejercicios hechos en clase en CPard
//PRACTICA 2 EJ 2

#include <stdio.h>
main(){
  int dint; //definimos la variable dint como int que es numeros enteros, 
  float dfloat; //definimos " " dfloat como float que es punto flotante, osea decimales
  double ddouble; //definimos " " ddouble como double que es numeros grandes
  scanf("%d %g %lf", &dint, &dfloat, &ddouble); //scanf pide %d %g %lf que son int, float y double, el & guarda el valor en la variable
  printf("\n Has introducido %d, %g, %lf", dint, dfloat, ddouble);
return 0;
}

//PRACTICA 2 EJ  3

#include <stdio.h>
main(){
  int dint;
  printf("Escribe un numero entre 48 y 122: ");
  scanf("%d", &dint);
  printf("\nHas introducido %c\n", (char)dint); //char dice que uses el dint como caracter en ascii, %c te devuelve el caracter
return 0;
}


//PRACTICA 2 EJ 4

#include <stdio.h>
main(){
  int dint, dint2, dint3;
  printf("Escribe tres numeros enteros separados por comas: ");
  int x= scanf("%d,%d,%d", &dint, &dint2, &dint3); //la funcion scanf devuelve el numero de parametros leidos es int
  printf("\nHa leido %d numeros\n", x); 
return 0;
}



//PRACTICA 2 EJ  5

#include <stdio.h>
int main(){
  int dint = 10;
  float dfloat = 19.3;
  double ddouble = 64.8;
  char dchar = 64;
  printf("%g\n",dint + dfloat); //la suma de los valores dint y dfloat te los imprime con decimal al definirlo con %g
  printf("%g\n",ddouble + dchar);
return 0;
}

//PRACTICA 3 EJ 1

#define PI 3.141592
#include <stdio.h>

int main(){
float radio;
printf("Inserte valor del radio: ");
scanf("%f", &radio);
printf("\nEl perimetro es: %.2f, el area es %.2f\n", 2*PI*radio, PI*radio*radio);
return 0;
}


//PRACTICA 3 EJ 1 otra manera de hacerlo

#define PI 3.141592
#include <stdio.h>

float perim(float); //dices que hay una funcion perim pero no la defines
float area(float);  //dices que hay una funcion area pero no la defines

int main(){
  float radio;
  printf("Inserte valor del radio: ");
  scanf("%g", &radio);
  printf("\nEl perimetro es: %.2f, el area es %.2f\n", perim(radio), area(radio));
  return 0;
}

float perim(float rat){ //defines la funcion de perim y el rat
  rat *= 2 * PI;
  return rat;
}

float area(float rat){  //defines la funcion de area y el rat
  rat *= rat * PI;
  return rat;
}


//PRACTICA 3 EJ 1 hecho por referencia

#define PI 3.141592
#include <stdio.h>

void perim(float rat, float *per);
void are(float rat, float *ar);

int main(){
  float radio, perimetro, area;
  printf("Inserte valor del radio: ");
  scanf("%g", &radio);
  perim(radio, &perimetro);
  are(radio, &area);
  printf("\nEl perimetro es: %.2f, el area es %.2f\n", perimetro, area);
  return 0;
}

void perim(float rat, float *per){
  (*per) = rat * 2 * PI;
}

void are(float rat, float *ar){
  (*ar) = rat * rat * PI;

//PRACTICA 3 EJ 1 con void


#define PI 3.141592
#include <stdio.h>

void perim(float);
void are(float);

int main(){
  float radio;
  printf("Inserte valor del radio: ");
  scanf("%g", &radio);
  printf("\nEl perimetro es: ");
  perim(radio);
  are(radio);
  return 0;
}

void perim(float rat){
  printf("%.2f, el area es: ", rat * 2 * PI);
}

void are(float rat){
  printf("%.2f.\n", rat * rat * PI);
}



//PRACTICA 3 EJ nose nos qeuivocamos y salia asi y funciona


#define PI 3.141592
#include <stdio.h>

void perim(float rat, float *per);
void are(float rat, float *ar);

int main(){
  float radio, perimetro, area;
  printf("Inserte valor del radio: ");
  scanf("%g", &radio);
  perim(radio, &perimetro);
  are(radio, &area);
  printf("\nEl perimetro es: %.2f, el area es %.2f\n", perimetro, area);
  return 0;
}

void perim(float rat, float *per){
  (*per) = rat * 2 * PI;
}

void are(float rat, float *ar){
  (*ar) = rat * rat * PI;

//PRACTICA 4 EJ 2 
//(segun el profesor)

#include <stdio.h>
#define HORA 3600
#define SEG_MIN 60
int main(){
  int seg;
  printf("Introduce numero de segundos\n");
  scanf("%d, &seg);
  printf("Horas %d, minutos %d segundos %d", seg/HORA, seg%HORA/SEG_MIN, SEG%HORA%SEG_MIN);
  return 0;
}


//(segun nosotros)

#include <stdio.h>
int main(){
  int sec;
  printf("Introduce los segundos: \n");
  scanf("%d", &sec);
  printf("\nEquivale a %d horas, %d minutos y %d segundos\n", sec/3600, sec/60-(sec/3600)*60, sec-(sec/60)*60);
  return 0;
}


//PRACTICA 4 EJ 2  otro apartado


#include <stdio.h>
  int horas(int *);
  int min(int *);
  int seg(int *);
int main(){
  int sec;
  printf("Introduce los segundos: \n");
  scanf("%d", &sec);
  printf("\nHoras: %d, Minutos: %d, Segundos: %d\n",horas(&sec), min(&sec), seg(&sec));
  return 0;
}

int horas(int *sec){
return (*sec)/3600;
}
int min(int *sec){
return (*sec)%3600/60;
}
int seg(int *sec){
return (*sec)%3600%60;
}


//PRACTICA 4 EJ 2 otro apartado, este con voids


#include <stdio.h>
  void horas(int *);
  void min(int *);
  void seg(int *);
int main(){
  int sec;
  printf("Introduce los segundos: \n");
  scanf("%d", &sec);
 // printf("\nHoras: %d, Minutos: %d, Segundos: %d\n",horas(&sec), min(&sec), seg(&sec));
  horas(&sec);
  min(&sec);
  seg(&sec);
  return 0;
}

void horas(int *sec){
  printf("horas: %d,", (*sec)/3600);
}
void min(int *sec){
  printf("minutos: %d,",(*sec)%3600/60);
}
void seg(int *sec){
  printf("segundos: %d\n",(*sec)%3600%60);
}



