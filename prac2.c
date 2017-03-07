/**
*Title: Practica 2
*Descripcion: Ejercicios correspondientes a las practicas 2
*@author:D.G.Roman
*@organization: Univesity of Burgos
*@date: 2017-02-13
*@version: 1.0
*/

//EJERCICIO 2

#include <stdio.h>
main(){
  int dint; //definimos la variable dint como int que es numeros enteros, 
  float dfloat; //definimos " " dfloat como float que es punto flotante, osea decimales
  double ddouble; //definimos " " ddouble como double que es numeros grandes
  scanf("%d %g %lf", &dint, &dfloat, &ddouble); //scanf pide %d %g %lf que son int, float y double, el & guarda el valor en la variable
  printf("\n Has introducido %d, %g, %lf", dint, dfloat, ddouble);
return 0;
}

//EJERCICIO 3

#include <stdio.h>
main(){
  int dint;
  printf("Escribe un numero entre 48 y 122: ");
  scanf("%d", &dint);
  printf("\nHas introducido %c\n", (char)dint); //char dice que uses el dint como caracter en ascii, %c te devuelve el caracter
return 0;
}


//EJERCICIO 4

#include <stdio.h>
main(){
  int dint, dint2, dint3;
  printf("Escribe tres numeros enteros separados por comas: ");
  int x= scanf("%d,%d,%d", &dint, &dint2, &dint3); //la funcion scanf devuelve el numero de parametros leidos es int
  printf("\nHa leido %d numeros\n", x); 
return 0;
}



//EJERCICIO 5

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
