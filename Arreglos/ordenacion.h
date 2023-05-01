#ifndef ORDENACION_H
#define ORDENACION_H
void ordenacion(int*, int);

void ordenacion(int *x, int n){
    int aux;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1; j++){
            if(x[j]>x[j+1]){
                aux=x[j];
                x[j]=x[j+1];
                x[j+1]=aux;
            }
        }
    }
}
#endif