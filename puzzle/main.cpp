#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>//random_shuffle
#include <conio.h>
#include <windows.h>    // Para uso de la función Sleep

#define FLECHA 224    // Codigo Ascii común a flecha
#define LEFT 75    // Codigo Ascii flecha izquierda
#define RIGHT 77    // Codigo Ascii flecha derecha
#define UP 72    // Codigo Ascii flecha arriba
#define DOWN 80    // Codigo Ascii flecha abajo
#define ENTER 13
#define NULO ' '

using namespace std;
/*int table[4][4]={{1 ,2 ,3 ,4 },
{5 ,6 ,7 ,8},
{9 ,10,11,12},
{13,14,15, }};*/

int table[4][4];
int (*F)[4]=table;
int *C=*F;
int *x;//columnas
int (*y)[4];//filas

int *aux_x=C;//columnas
int (*aux_y)[4]=F;//filas
//int x=3, y=3;
int ff,cc;

char maybe_flecha ( char pulsacion)
{
	if (pulsacion==FLECHA)
		pulsacion=getch();

	return pulsacion;
}
int up()
{
    if(ff<=2){
         aux_y+=ff+1;
         aux_x=*aux_y;
         aux_x+=cc;
         *x=*aux_x;
         *aux_x=0;
        ff++;
    }
    x=aux_x;
    aux_x=C;
    aux_y=F;

	return 1;
}
int down()
{
    if(ff>=1){
         aux_y+=ff-1;
         aux_x=*aux_y;
         aux_x+=cc;
         *x=*aux_x;
         *aux_x=0;
        ff--;
    }
    x=aux_x;
    aux_x=C;
    aux_y=F;

	return 1;
}

int left()
{
    if(cc<=2){
         aux_y+=ff;
         aux_x=*aux_y;
         aux_x+=cc+1;
         *x=*aux_x;
         *aux_x=0;
        cc++;
    }
    x=aux_x;
    aux_x=C;
    aux_y=F;

	return 1;
}
int right()
{
    if(cc>=1){
         aux_y+=ff;
         aux_x=*aux_y;
         aux_x+=cc-1;
         *x=*aux_x;
         *aux_x=0;
        cc--;
    }
    x=aux_x;
    aux_x=C;
    aux_y=F;

	return 1;
}

int update_board(int (*t)())
{
    int i;
    int *col=C;
	if(t()>0){
        while(*C<16){
          i=0;
          while(i<4){
            if(*C!=0){
				printf("[%2i]", *C);}
			else{
                printf("[  ]");
            }
            i++;
            C++;
          }
          cout<<endl;
        }
	}
	C=col;
	return 0;
}

int disaster()
{
	int a=3,b=3;
	int *col=C;
	int (*fil)[4]=F;
	char opcion;
	cout<<endl;
	cout<<"[y]. PUZZLE "<<endl;
	cout<<"[s] start... "<<endl;
	cin>>opcion;
	if(opcion=='y'){
		int c=1;
		int i;
		while(*C<16){
          i=0;
          while(i<4){
              *C=c;
            c++;
            i++;
            C++;
          }
          cout<<endl;
        }
        //posiciono el 0[en lugar del 16]
        F+=a;
        C=*F;
        C+=b;
        *C=0;

		C=col;
		F=fil;
		return 1;
	}

	if(opcion=='s'){
        int i;
		srand(time(NULL));
		int num, um;
		int *aux_col=C;
		int (*aux_fil)[4]=F;

		y=F;
        x=C;
		while(*C<16){
          i=0;
          while(i<4){
            num=rand()%3;
            um=rand()%3;
            aux_fil+=num;
            aux_col=*aux_fil;
            aux_col+=um;
            swap(*aux_col,*C);

            aux_fil=fil;
            aux_col=col;

            i++;
            C++;
          }
          cout<<endl;
        }

        int it,j=0,cont,k=0,contf;//[cont-contador col]
        int tam=C-aux_col;
        aux_col=*F;
        while(j<tam)
        {
            it=0;
            //cont=0;
            while(it<4){
              if(*aux_col==0){
					cont=it;
                    contf=(k%4);
                    y+=contf;
                    x=*y;
                    x+=cont;
               }
               it++;
               aux_col++;
               j++;

            }
            k++;
        }
        ff=contf;
        cc=cont;
        C=col;
       return 1;
	}
}
void revisar()
{
    cout<<"revision..."<<endl;
    int i;
    int *col=C;
    int num=1;
    int valor=0;
    while(*C<16 and valor<16){
        i=0;
        while(i<4){
            if(*C==num){
				valor++;
            }
            num++;
            i++;
            C++;
          }
          cout<<endl;
    }
    if(valor==15){cout<<"GANASTE"<<endl;}
	C=col;
}
int puzzle()
{
	char tecla_pulsada;
	while(1)
	{
		if (kbhit())
			tecla_pulsada=maybe_flecha(getch());
		else
			Sleep ((DWORD)100);

		switch (tecla_pulsada)
		{
		case UP: system("cls");
			update_board(up); fflush(stdout); break; //se almacenan en un area de almacenamiento temporal[buffer]
		case DOWN: system("cls");
			update_board(down);	fflush(stdout); break;
		case RIGHT: system("cls");
			update_board(right); fflush(stdout); break;
		case LEFT: system("cls");
			update_board(left); fflush(stdout); break;
        case ENTER: system("cls");
            revisar();
		default: break;
		}

		tecla_pulsada=NULO;
	}

	return 0;
}

int main()
{
	update_board(disaster);
	update_board(disaster);
	puzzle();
	return 0;
}





