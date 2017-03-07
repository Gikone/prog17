/**
*Title: Practica 3
*Descripcion: Ejercicios correspondientes a las practicas 3
*@author:D.G.Roman
*@organization: Univesity of Burgos
*@date: 2017-02-20
*@version: 1.0
*/

//EJERCICIO 1

#define PI 3.141592
#include <stdio.h>

int main(){
float radio;
printf("Inserte valor del radio: ");
scanf("%f", &radio);
printf("\nEl perimetro es: %.2f, el area es %.2f\n", 2*PI*radio, PI*radio*radio);
return 0;
}


//EJERCICIO 1 otra manera de hacerlo

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


//EJERCICIO 1 hecho por referencia

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

//EJERCICIO 1 con void


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



//EJERICIO nose nos equivocamos y salia asi y funciona


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
