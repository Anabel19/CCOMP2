#ifndef LIST_C_H_INCLUDED
#define LIST_C_H_INCLUDED
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



#endif // LIST_C_H_INCLUDED
