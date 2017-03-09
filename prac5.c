/**
*Title: Practica 
*Descripcion: Ejercicios correspondientes a las practicas 5
*@author:D.G.Roman and R.D.Garcia
*@organization: Univesity of Burgos
*@date: 2017-03-08
*@version: 1.0
*/


// compilar asi: gcc ecuacion.c -o ecuacion lm
//./ecuacion

#include <stdio.h>
#include <math.h>

void  leeCoeficientes(int *, int *, int *);
int determinaTipo(int, int, int);
int calculaRadicando(int,int,int);
void muestraResultado(int, int, int, int);

int main(){
  int a, b, c;
  leeCoeficientes(&a, &b, &c);
  //printf("%d\n",determinaTipo(a,b,c));
  muestraResultado(determinaTipo(a,b,c),a,b,c);
}

void leeCoeficientes(int *a,int *b, int *c){
  printf("Introduce valores a, b, c separados por comas\n");
  scanf("%d,%d,%d", &*a,&*b,&*c);
}

int determinaTipo(int a, int b, int c){
  int tipo=3;
  if(a==0){
    if(b==0){
      tipo=1;
    }else{
    tipo=2;
      }
  }
return tipo;
}

void muestraResultado(int tipo, int a, int b, int c){
  int radicando;
  printf("El resultado es: ");
  if(tipo==1){
    printf("ecuación degradada.\n");
  }else{
    if(tipo==2){
      printf("ecuacion de primer grado cuya solucion es x=%d\n",-c/b);
    }else{
      radicando=calculaRadicando(a,b,c);
      if(radicando==0){
        printf("ecuación de segundo grado cuya solucion es x=%lf\n",-b/pow(b,2));
      }else{
        if(radicando>0){
          printf("ecuación de segundo grado cuya solucion es x1=%lf y x2=%lf\n",(-b+sqrt(radicando))/(2*a),(-b-sqrt(radicando))/(2*a));
        }else{
          printf("ecuación de segundo grado cuya solucion es x1=%lf y x2=%lf\n",(-b+sqrt(-radicando))/(2*a),(-b-sqrt(-radicando))/(2*a));
        }
      }
    }
  }
}



int calculaRadicando(int a, int b,int c){
  return pow(b,2)-4*a*c;
}


//Version Rodrigo

#include <stdio.h>
#include <math.h>

void  leeCoeficientes(float *, float *, float *);
int determinaTipo(float, float, float);
void muestraResultado(int, float, float, float);
int calculaRadicando(float, float, float);

int main(){
	float a, b, c;
	leeCoeficientes(&a, &b, &c);
	muestraResultado(determinaTipo(a, b, c), a, b, c);
	return 0;
}

void leeCoeficientes(float *a, float *b, float *c){
	printf("Introduce valores a, b, c separados por comas\n");
	scanf("%f,%f,%f", &*a,&*b,&*c);
}

int determinaTipo(float a, float b, float c){
	int tipo=3;
	if(a==0){
		if(b==0){
			tipo=1;
		}else{
			tipo=2;
		}
	}
	return tipo;
}

void muestraResultado(int tipo, float a, float b, float c){
	float radicando;
	printf("Es una ecuacion de ");
	if(tipo==1){
		printf("grado cero");
		if(c!=0){
			printf(" invalida");
		}
	}else{
		if(tipo==2){
			printf(" primer grado con solucion x=%g",-c/b);
		}else{
			printf(" segundo grado con solucion x=");
			radicando=calculaRadicando(a,b,c);
			if(radicando==0){
				printf("=%g\n",-b/pow(b,2));
			}else{
				if(radicando>0){
					if(b==0){
						printf("\u00B1%g",(-b+sqrt(radicando))/(2*a));
					}else{
						printf("%g, x=%g",(-b+sqrt(radicando))/(2*a),(b+sqrt(radicando))/(2*a));
					}
				}else{
					printf("%.3g\u00B1%.3gi",-b/(2*a),sqrt(-radicando)/(2*a));
				}
			}
		}
	}
	printf("\n");
}

int calculaRadicando(float a, float b,float c){
	return pow(b,2)-4*a*c;
}
