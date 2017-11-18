#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#define tam 10
int cont;
using namespace std;
char tablero[50][50];
//char *tmp;

void sentido();
void more_letter(char *);
char* find_pivote(char *);
void comparar(char (*)[tam]);
void find_position(char *,int );
void rellenar();
void print();

int main()
{
  char  words[ ][10]={{"laptop"},{"mouse"},{"libro"},{0}};//[f][c]
  rellenar();
  comparar(&words[0]);
//  find_position(int);
  print();
  return 0;
}


void sentido(){}
void rellenar()
{//int k=0; char s[500];
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
             *(*(tablero+i)+j)='  |';//itoa(k,s,10); k++;
             //cout<<tablero[i][j]<<" ";
        }
      //cout<<endl;
    }
}
void print()
{
    for(int i=0;i<50;i++){

        for(int j=0;j<50;j++){
          //   *(*(tablero+i)+j)='  |';
            cout<<tablero[i][j]<<" ";
      }
      cout<<endl;
    }
}
void find_position(char *tmp,int i)
{   //cout<<*a1 {c/valor}
   // cout<<*a1<<"----";
     if(*tmp!=0){
        cout<<"inter:  "<<*tmp<<" ";
            cout<<"i: "<<i;

            tablero[0][i]=*tmp; //cout<<tablero[25][i]<<" ";
        tmp++;
    }

}
void more_letter(char *tmp)
{
    cout<<"tmm: "<<tmp<<endl;
        for(int i=0;*tmp!=0;tmp++,i++){
          //cout<<*a1;
          find_position(tmp,i);//envia c/letter
        }
        //print();

}
char * find_pivote(char *a1)
{   //cout<<*a1 [1ra letra de c/fila osea de c/word]
    char *aux=a1; char*tmp;
    int t=0;//cant letters repetidas
    for(int i=1;*a1!=0;a1++,i++){
        for(int j=i;j<tam/2;j++){//WARNING iteracion{cant aprox}
          if(*a1==*(a1+j)){
              t++;
          }
        }
    }
    if(cont<t){cont=t; tmp=aux;}

cout<<"cant: "<<cont<<endl;
cout<<"t: "<<tmp<<endl;
    return tmp;
}

void comparar(char (*a)[tam])
{
//  char **aux=a;
  int j;  char *tmp;
  for(;**a!=0;a++){
  //cout<<*a[word_complete] **a[only filas]
     tmp=find_pivote(*a);
 //     cout<<*a;
   }
   more_letter(tmp);
}
