#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <stdlib.h>
using namespace std;
template<typename T>
class nodo
{
  public:
      T element;
      nodo <T>*next;
      nodo <T>(T);
};

template<typename T>
class lista
{
  public:
      nodo <T>*raiz; nodo <T>*first;
      nodo <T>*last;

      lista <T>();
      ~lista<T>();
      void insertar(T);
      void imprimir();
      void mergeLists(lista &lista0, lista &lista1, lista &unida);
};
#endif //LISTA_H
