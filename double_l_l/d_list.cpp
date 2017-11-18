#include<iostream>
#include "d_list.h"
using namespace std;
/*
template<typename T>
void list<T>::insert(T element)
{
	//node<T>*prev_aux;
	if(!head){
		head=new node<T>(element);
		tail=head;
	}
	else if(find_(element)==false){
		if(element>=tail->value){
			tail->next=new node<T>(element);
			tail->next->prev=tail;
			tail=tail->next;
		}
		else{
			node<T>*tmp=head;
			while(tmp){
				if(head->value > element){
					head=new node<T>(element,tmp);	
				}	
				else if(tmp->value < element and tmp->next->value > element){
					tmp->next=new node<T>(element, tmp->next, tmp->next->prev);
					tail=tmp->next;
				}	
				tmp=tmp->next;
			}	
		}
	}	
	else{cout<<"element malo"<<element<<endl;}
}*/
template<typename T>
void list<T>::insert(T element)
{   node<T>*tmp;
	if(!head){
		head=new node<T>(element);
		tail=head;
	}
	else if(find_(element,tmp)==false){ //[insert after tail]
		if(element>=tail->value){
			tail->next=new node<T>(element, nullptr, tail);
			tail=tail->next;
		}
		else{
			tmp=head;
			while(tmp){
				if(head->value > element){ //[insert before head]
					head->prev=new node<T>(element,tmp);
					head=head->prev;
				}	
				else if(tmp->value < element and tmp->next->value > element){
					tmp->next=new node<T>(element, tmp->next, tmp);	//break;	
					tmp->next->next->prev=tmp->next;
				}	
				tmp=tmp->next;
			}	
		}
	}	
	//else{cout<<"element malo"<<element<<endl;}
}

template<typename T>
bool list<T>::find_(T element, node<T> *&tmp)
{
	tmp=head;
	while(tmp){
		if(tmp->value== element){
			return true;
		}
		tmp=tmp->next;
	}	
	return false;
}

template<typename T>
void list<T>::delete_(T element)
{
	node<T> *tmp;  node<T> *tmp2;
	if(find_(element, tmp)==true){	
		if(tmp==head){ //[head]
		    tmp2=tmp;
			tmp=tmp2->next;
			head=tmp;
			delete tmp2;
		}
     	else{  
				if(tmp->next==nullptr){  //[last]
					tmp2=tmp;					
					tmp=tmp2->prev;
					tmp->next=nullptr;
					delete tmp2;
				}
				else{ 
					tmp2=tmp;
					tmp=tmp2->prev;
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
	lista.insert(7);
	lista.insert(8);
	lista.insert(8);
	lista.insert(4);
	lista.insert(10);
	cout<<endl<<"insert list ordenada: "<<endl;
	lista.print();
	lista.delete_(3);
	cout<<endl<<"list elimina valor: "<<endl;
	lista.print();
}