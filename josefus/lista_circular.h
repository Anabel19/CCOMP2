#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H
#include <iostream>

using namespace std;

class nodo
{
    public:
        int elemento;
        nodo *ptr_siguiente;
        nodo(int);
};

class lista
{
    public:
    nodo *ptr_cabeza,*ptr_cola;

    lista();
    ~lista();
    void insertar(int);
    void imprimir();
    void Josefus(int,int);

};

#endif // LISTA_CIRCULAR_H
