#include<iostream>
#include "circular_list.h"
using namespace std;

template<typename T>
void list<T>::insert(T element)
{
	if(!head){
		head=new node<T>(element,head);
		head->next=head;
		tail=head;
	}
	else if(find_(element)==false){ //insert after tail
		if(element>=tail->value){
			tail->next=new node<T>(element, head);
			tail=tail->next;
		}
		else{
			node<T>*tmp=head;  
			if(head->value > element){ //insert before head
					head=new node<T>(element, tmp);	
				    //tmp=tmp->next;
					tail->next=head;
			}
			else{
			      do{
				    if(tmp->value < element and tmp->next->value > element){ //insert others
					  tmp->next=new node<T>(element,tmp->next);	
				   }	
				   tmp=tmp->next;
				 }while(tmp!=head);
			}
		}
	}	
	
}
template<typename T>
bool list<T>::find_(T element)
{
	node<T> *tmp=head;
	do{
		if(tmp->value== element){
			return true;
		}
		tmp=tmp->next;
	}	
	while(tmp!=head);
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
}*/
/*
bool find(T element, *ptr){
	
}
*/
template<typename T>
node<T>* list<T>::find_Ebefore(T element)
{
	node<T> *tmp=head;  
	if(tmp->value==element){ //????envio the last[head]
		return tmp=tail;
	}
	else{
		do{
			if(tmp->value < element and (tmp->next->next==head or tmp->next->next->value > element)){//buscamos the last && other
				return tmp;
			}
			tmp=tmp->next;
		}while(tmp!=head);
	}
}

template<typename T>
void list<T>::delete_(T element)
{
	node<T> *tmp;  node<T> *tmp2;
	if(find_(element)==true){
		tmp=find_Ebefore(element);
		if(tmp==tail){ //delete[head]
		    tmp2=tmp->next;
			tmp->next=tmp2->next;
			head=tmp->next;
			delete tmp2;  
		}
     	else{  
				if(tmp->next->next==head){ //delete[last]
					tmp2=tmp->next;		
					tmp->next=head;
					delete tmp2;
				}
				else{  //delete anything
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
	do{		
		cout<<"&:"<<tmp<<" "<<tmp->value<<" ";
		tmp=tmp->next;
	}
	while(tmp!=head);
}

int main()
{
	list<int> lista;
	lista.insert(3);
	lista.insert(4);
	lista.insert(2);
	lista.insert(7);
	lista.insert(9);
	lista.insert(5);
	//lista.insert(10);
	cout<<endl<<"insert list ordenada: "<<endl;
	lista.print();
	lista.delete_(2); //?????????problems wirh 3[it is probably por ser first]-4[it s probably por ser insertado]
	cout<<endl<<"list elimina valor: "<<endl;
	lista.print();
	return 0;
}
