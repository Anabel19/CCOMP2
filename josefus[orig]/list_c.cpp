#include "list_c.h"
#include <iostream>

using namespace std;

nodo::nodo(int elemento)
{
    this->elemento=elemento;
    ptr_siguiente=NULL;
}


lista::lista()
{
    ptr_cabeza=ptr_cola=NULL;
}
lista::~lista()
{
    nodo *ptr_elim=ptr_cabeza;
    while(ptr_elim)
    {
        ptr_elim=ptr_cabeza->ptr_siguiente;
        delete ptr_cabeza;
        ptr_cabeza=ptr_elim;
        if(ptr_cabeza==ptr_cola)
        {
            delete ptr_cabeza;
            ptr_cabeza=NULL;
            delete ptr_elim;
            ptr_elim=NULL;
            delete ptr_cola;
            ptr_cola=NULL;
        }
    }
}

void lista::insertar(int elemento)
{
    if(!ptr_cabeza)
    {
        ///cout<<"Ingrese"<<elemento<<endl;
        ptr_cabeza=new nodo(elemento);
        ptr_cola=ptr_cabeza;
        ptr_cola->ptr_siguiente=ptr_cabeza;

    }
    else
    {
        ///cout<<"Ingrese"<<elemento<<endl;
        ptr_cola->ptr_siguiente=new nodo(elemento);
        ptr_cola=ptr_cola->ptr_siguiente;
        ptr_cola->ptr_siguiente=ptr_cabeza;
    }
}

void lista::imprimir()
{
    nodo *ptr_temp=ptr_cabeza;
    int cont=0;
    while(cont<=1)
    {
        if(ptr_temp==ptr_cabeza)
        {
            cout<<ptr_temp->elemento;
            ptr_temp=ptr_temp->ptr_siguiente;
            cont++;
        }
        else
        {
            cout<<ptr_temp->elemento;
            ptr_temp=ptr_temp->ptr_siguiente;
        }
    }
}


void lista::Josefus(int soldados,int conteo)
{
    nodo *ptr_matador=ptr_cabeza;
    while(soldados>2)
    {
        if(conteo==1)
        {
            if(ptr_cabeza==ptr_matador)
            {
                ptr_cabeza=ptr_cabeza->ptr_siguiente;
                delete ptr_matador;
                ptr_matador=ptr_cabeza;
                soldados--;
            }
        }
        else
        {
            for(int i=0;i<conteo-1;i++)
            {
                ptr_cola=ptr_matador;
                ptr_matador=ptr_matador->ptr_siguiente;
                if(ptr_cabeza==ptr_matador)
                {
                    ptr_cabeza=ptr_cabeza->ptr_siguiente;
                }
            }
            ptr_cola->ptr_siguiente=ptr_matador->ptr_siguiente;
            delete ptr_matador;
            ptr_matador=ptr_cola->ptr_siguiente;
            soldados--;
        }
    }
    for(int i=0;i<2;i++)
    {

        cout<<ptr_cabeza->elemento<<"->";
        ptr_cabeza=ptr_cabeza->ptr_siguiente;
    }
}
