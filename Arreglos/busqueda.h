#ifndef BUSQUEDA_H
#define BUSQUEDA_H

int busqueda(int*, int, int);

int busqueda(int *x, int n, int dato){
    int i=0;
    int pos;
    while((i<=n) && (x[i]<dato)){
        i++;
    }
    if((i>n) || (x[i]>dato)){
        pos=-i;
        return pos;
    }
    else{
        pos=i;
        return pos;
    }
}

#endif