#include "lista.h"
template<typename T>
nodo<T>::nodo(T date)
{
   this->element=date;
   next=NULL;
}

template<typename T>
lista<T>::lista()
{
   first=last=NULL;
}
template<typename T>
lista<T>::~lista()
{
   nodo <T>*elim=first;
   while(elim)
   {
      elim=first->next;
      delete first;
      first=elim;
   }   
   last=NULL;
}
template<typename T>
void lista<T>::insertar(T date)
{
   if(!first){
      first= new nodo<T>(date);
      last=first;
    }
   else{
      last->next=new nodo<T>(date);
      last=last->next;
    }
}
template<typename T>
void lista<T>::imprimir()
{
   nodo <T>*tmp=first;
   while(tmp)
   {
     cout<<tmp->element<<"="<<&tmp->element<<" ";
     tmp=tmp->next;     
   }
   cout<<endl;
}
template<typename T>
void lista<T>::mergeLists(lista& lista0, lista& lista1, lista& unida)
{ 
  nodo <T>*tmp=unida.first; //=NULL;
  nodo <T>*head=lista0.first;
  nodo <T>*head2=lista1.first;

  //while(head!=NULL and head2!=NULL)
	while(head and head2)  
   {
     if(head->element<=head2->element)
     {
        tmp=head;
        cout<<" "<<tmp->element<<"= "<<&tmp->element;
        head=head->next;    tmp=tmp->next;
     } 
     else if(head->element>head2->element)
     {
         tmp=head2;
         cout<<" "<<tmp->element<<"= "<<&tmp->element;
         head2=head2->next;  tmp=tmp->next;
     }
   }
  
   while(head)//!=NULL)
    {
         tmp=head;
         cout<<" "<<tmp->element<<"= "<<&tmp->element;
         head=head->next;  tmp=tmp->next;
    }
   while(head2)//!=NULL)
    {
        tmp=head2;
        cout<<" "<<tmp->element<<"= "<<&tmp->element;
        head2=head2->next;   tmp=tmp->next;
    }
}

int main()
{
    lista <int>lista1;

    lista1.insertar(1);
    lista1.insertar(5);
    lista1.insertar(7);
    lista1.imprimir();

    cout<<endl;
    lista <int>lista2;
    lista2.insertar(2);
    lista2.insertar(3);
    lista2.insertar(6);
    lista2.insertar(8);
    lista2.imprimir();
    cout<<endl;
    lista2.mergeLists(lista1,lista2,lista2);
    //lista2.imprimir();
    return 0;
}