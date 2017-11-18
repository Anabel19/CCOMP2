#include<iostream>
#include "list.h"
using namespace std;

template<typename T>
void list<T>::insert(T element)
{   node<T>*tmp;
	if(!head){
		head=new node<T>(element);
		tail=head;
	}
	//else if(find_(element)==false){ //insert after tail
	else if(findA_(element,tmp)==false){
		if(element>=tail->value){
			tail->next=new node<T>(element);
			tail=tail->next;
		}
		else{
			tmp=head;
			if(head->value > element){ //insert before head
					head=new node<T>(element,tmp);	//break;
			   }
			while(tmp){
				 if(tmp->value < element and tmp->next->value > element){
					tmp->next=new node<T>(element,tmp->next);	//break;
				}	
				tmp=tmp->next;
			}	
		}
	}	
	
}
template<typename T>
bool list<T>::findA_(T element, node<T> *&tmp)
{
	tmp=head;
	node<T> *tmp2=head;
	while(tmp){
		if(tmp->value== element){
			tmp=nullptr;			
			return true;
		}
		else{
			if(tmp->value < element and (tmp->next->next==nullptr or tmp->next->next->value > element)){//buscamos the last && other
				return true;
			}
		}
		tmp=tmp->next;
	}	
	return false;
}
/*
template<typename T>
bool list<T>::find_(T element)
{
	node<T> *tmp=head;
	while(tmp){
		if(tmp->value== element){
			return true;
		}
		tmp=tmp->next;
	}	
	return false;
}

template<typename T>
node<T>* list<T>::find_Ebefore(T element)
{
	node<T> *tmp=head;  
	if(tmp->value==element){ //????envio su misma posicion NOT el anterior[head]
		return tmp=nullptr;
	}
	else{
		while(tmp){
			if(tmp->value < element and (tmp->next->next==nullptr or tmp->next->next->value > element)){//buscamos the last && other
				return tmp;
			}
		//	else if(tmp->value < element and tmp->next->next->value > element){
			//	return tmp;
		//	}
			tmp=tmp->next;
		}	
	}
}
*/
/*
bool find(T element, *ptr){
	
}
*/
template<typename T>
void list<T>::delete_(T element)
{
	node<T> *tmp;  node<T> *tmp2;
	if(find_(element)==true){
		tmp=find_Ebefore(element);
		if(tmp==nullptr){ 
		    tmp2=tmp=head;
			tmp=tmp2->next;
			head=tmp;
			delete tmp2;
		}
     	else{  
				if(tmp->next->next==nullptr){
					tmp2=tmp->next;		
					tmp->next=nullptr;
					delete tmp2;
				}
				else{
					tmp2=tmp->next;		
					tmp->next=tmp2->next;
					delete tmp2;
				}
		}
	}
	else{cout<<"no se encuentra el element a eliminar"<<endl;}
}
template<typename T>
void list<T>::print()
{
	node<T> *tmp=head;
	while(tmp){
		cout<<"&:"<<tmp<<" "<<tmp->value<<" ";
		tmp=tmp->next;
	}
}
int main()
{
	list<int> lista;
	lista.insert(3);
	lista.insert(1);
	lista.insert(6);
	lista.insert(6);
	lista.insert(4);
	lista.insert(7);
	lista.insert(8);
	lista.insert(10);
	lista.insert(0);
	cout<<endl<<"insert list ordenada: "<<endl;
	lista.print();
	//lista.delete_(1);
	cout<<endl<<"list elimina valor: "<<endl;
	lista.print();
}

/*
template<typename T>
bool list<T>:: insert (T elemento ){

            node<T>**ptr;

            if ( find_(elemento,ptr ) ) return false;
cout<<"ptr "<<ptr<<" "<<"*ptr "<<*ptr<<endl;
            node<T>* n = new node<T>(elemento);
            n->next = *ptr;
            *ptr = n;
			cout<<"-----*ptr "<<*ptr<<endl;
            return true;

        }

template<typename T>
bool list<T>::find_(T element,node<T> **&tmp)
{
	tmp=&head;
	while(*tmp){
		tmp=&(*tmp)->next;
	}	
	cout<<"*tmp"<<*tmp<<" "<<tmp<<" ";
	//cout<<"(*tmp)->value "<<(*tmp)->value<<endl;
	return *tmp and (*tmp)->value==element;
}*/
