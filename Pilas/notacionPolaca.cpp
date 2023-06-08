#include<iostream>
#include <cstring>
using namespace std;

void posfija(char*,char*,char*);
void prefija(char*,char*, char*);
bool operador(char);
int prioridad(char);

int main(){
    char ei[30];
    char pila[30];
    char epos[30];
    char epre[30];
    cout << "Ingrese la expresion infija: ";
    cin>>ei;

    cout << "\nExpresion posfija: ";
    posfija(ei, pila, epos);

    cout << "\nExpresion prefija: ";
    prefija(ei, pila, epre);
    
    return 0;
}

void posfija(char *ei,char *pila, char *epos){
    int tope=-1;
    int n=strlen(ei);
    int i=0;
    int j=0;
    while(i<n){
        if(ei[i]=='('){
            tope++;
            pila[tope]=ei[i];
        }
        else{
            if(ei[i]==')'){
                while(pila[tope]!='('){
                    epos[j]=pila[tope];
                    tope--;
                    j++;
                }
                tope--;
            }
            else{
                if(!operador(ei[i])){
                    j++;
                    epos[j]=ei[i];
                }
                else{
                    while((tope >= 0) && (prioridad(ei[i]) == prioridad(pila[tope]))){
                        epos[j]=pila[tope];
                        tope--;
                        j++;
                    }
                    tope++;
                    pila[tope]=ei[i];
                }
            }
        }
        i++;
    }
    while(tope>=0){
        epos[j]=pila[tope];
        tope--;
        j++;
    }
    for(i=0; i<j;i++){
        cout<<epos[i];
    }
}

void prefija(char* ei, char* pila, char* epre) {
    int tope = -1;
    int n = strlen(ei);
    int j = -1;
    while (n != 0) {
        if (ei[n-1] == '(') {
            tope++;
            pila[tope] = ei[n - 1];
        }
        else {
            if (ei[n-1] == ')') {
                while (pila[tope] != ')') {
                    j++;
                    epre[j] = pila[tope];
                    tope--;
                }
                tope--;
            }
            else {
                if (!operador(ei[n-1])) {
                    j++;
                    epre[j] = ei[n-1];
                }
                else {
                    while ((tope >= 0) && (prioridad(ei[n-1]) < prioridad(pila[tope]))){
                        j++;
                        epre[j] = pila[tope];
                        tope--;
                    }
                    tope++;
                    pila[tope] = ei[n-1];
                }
            }
        }
        n--;
    }
    while (tope >= 0) {
        j++;
        epre[j] = pila[tope];
        tope--;
    }
    for (int i = j; i >= 0; i--) {
        cout << epre[i];
    }
}

bool operador(char caracter) {
    switch(caracter){
        case '+':{ 
            return true;
            }
        case '-':{ 
            return true;
            }
        case '*':{  
            return true;
            }
        case '/':{  
            return true;
            }
        case '^':{  
            return true;
            }
        default:{  
            return false;
            }
    }
}

int prioridad(char operador){
    if (operador == '+' || operador == '-') {
        return 1;
    }
    else if (operador == '*' || operador == '/') {
        return 2;
    }
    else if (operador == '^') {
        return 3;
    }
}