#ifndef LIST_H
#define LIST_H
template<typename T>
class node
{
	public:
	T value;
	node<T> *next;
	node<T> *prev;
	node<T>(T dato, node *sgte=nullptr, node *ant=nullptr){
		value=dato;
		next=sgte;
		prev=ant;
	}
};

template<typename T>
class list
{
	public:
   node<T> *head, *tail;
   list<T>(){
       //head=nullptr;
	   head=tail=nullptr;
   }
   ~list<T>(){
	   node<T> *clear=head;
	   while(clear){
		   clear=head->next;
		   delete head;
		   head=clear;
	   }
   }
   void insert(T);
   bool find_(T, node<T>*&);
   void delete_(T);
   void print();
};
#endif //LIST_H