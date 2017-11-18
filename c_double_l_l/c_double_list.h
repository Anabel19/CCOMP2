#ifndef C_DOUBLE_LIST_H
#define C_DOUBLE_LIST_H
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
	   do{
		   clear=head->next;
		   delete head;
		   head=clear;
	   }while(clear!=head);
	   head=nullptr;
   }
   void insert(T);
   bool find_(T, node<T>*&);
   void delete_(T);
   void print();
};
#endif //C_DOUBLE_LIST_H