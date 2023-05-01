#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using namespace std;

struct nodo{
    char inf[20];
    nodo *sig;
};

nodo *crear_i(nodo *p){
    nodo *q;
    char op;
    do{
        system("cls");
        q= new (nodo);
        cout<<"\nDATO: ";
        cin>>q->inf;
        q->sig=p;
        p=q;
        cout<<"\n\n\t\tMAS DATOS? (S/N): ";
        cin>>op;
    }while(op=='s'||op=='S');

    return (p);
}

nodo *crear_f(nodo *p){
    nodo *q,*r;
    char op;
    do{
        system("cls");
        q= new (nodo);
        cout<<"\nDATO: ";
        cin>>q->inf;
        q->sig=NULL;
        if(p==NULL){
            p=q;
        }
        else{
            r=p;
            while(r->sig!=NULL){
                r=r->sig;
                r->sig=q;
            }
        }
        cout<<"\n\n\t\tMAS DATOS? (S/N): ";
        cin>>op;
    }while(op=='s'||op=='S');
    return (p);
}

void mostrar(nodo *p){
    nodo *q;
    q=p;
    cout<<"\n\nREPORTE: \n\n";
    while(q!= NULL){
        cout<<q->inf<<"\n\n";
        q=q->sig;
    }
}

#endif