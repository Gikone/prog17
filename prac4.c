/**
*Title: Practica 4
*Descripcion: Ejercicios correspondientes a las practicas 3
*@author:D.G.Roman
*@organization: Univesity of Burgos
*@date: 2017-03-01
*@version: 1.0
*/

//EJERCICIO 2 
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


//EJERCICIO 2 otro apartado


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


//EJERCICIO 2 otro apartado, este con voids


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
