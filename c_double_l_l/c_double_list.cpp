#include<iostream>
#include "c_double_list.h"
using namespace std;

template<typename T>
void list<T>::insert(T element)
{   node<T>*tmp;
	if(!head){
		head=new node<T>(element, head, head);
		head->next=head;
		tail=head;
	}
	else if(find_(element,tmp)==false){ //insert after tail
		if(element>=tail->value){
			tail->next=new node<T>(element, head, tail);
			tail=tail->next;
		}
		else{
			tmp=head;    
			if(head->value > element){ //insert before head
					head->prev=new node<T>(element, tmp, tail);		
					head=head->prev;
					tail->next=head;
			}
			else{
			      do{
				    if(tmp->value < element and tmp->next->value > element){ //insert others
					  tmp->next=new node<T>(element,tmp->next,tmp);
                      tmp->next->next->prev=tmp->next; 					  
				   }	
				   tmp=tmp->next;
				 }while(tmp!=head);
			}
			head->prev=tail;
		}
	}	
	
}
template<typename T>
bool list<T>::find_(T element, node<T> *&tmp)
{
	tmp=head;
	do{
		if(tmp->value== element){
			return true;
		}
		tmp=tmp->next;
	}	
	while(tmp!=head);
	return false;
}

template<typename T>
void list<T>::delete_(T element)
{
	node<T> *tmp;  node<T> *tmp2;
	if(find_(element, tmp)==true){
		if(tmp==head){ //delete[head]
		    tmp2=tmp;
			tmp=tmp2->prev;
			tmp->next=tmp2->next;
			head=tmp->next;
			delete tmp2;  
		}
     	else{  
				if(tmp->next==head){ //delete[last] 
					tmp2=tmp;
					tmp=tmp2->prev;
					tmp->next=head;
					delete tmp2;
				}
				else{  //delete anything
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
	lista.insert(5);
	lista.insert(9);
	lista.insert(6);
	lista.insert(0);
	cout<<endl<<"insert list ordenada: "<<endl;
	lista.print();
	lista.delete_(0); //?????????problems wirh 3[it is probably por ser first]-4[it s probably por ser insertado]
	lista.delete_(4);
	cout<<endl<<"list elimina valor: "<<endl;
	lista.print();
	return 0;
}
