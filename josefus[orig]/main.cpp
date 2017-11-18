#include <iostream>
#include "list_c.h"

using namespace std;

int main()
{
    lista lista1;
    int num,c_;
    cout<<"Ingresa el num_sold: "<<endl;
    cin>>num;
    cout<<"Ingresa c/cuanto kill: "<<endl;
    cin>>c_;
    for(int i=1;i<=num;i++){
        lista1.insertar(i);
    }
    lista1.Josefus(num,c_);

    return 0;
}
