#include<stdio.h>
#include<stdlib.h>

struct nodoArbol{
    struct nodoArbol* ptrIzq;
    int dato;
    struct nodoArbol* prtDer;
};

typedef struct nodoArbol NodoArbol;
typedef NodoArbol* ptrNodoArbol;

void insertaNodo(ptrNodoArbol* ptrArbol,int valor);
void inOrden(ptrNodoArbol ptrArbol);
void preOrden(ptrNodoArbol ptrArbol);
void postOrden(ptrNodoArbol ptrArbol);

int main(){
    int i;
    int elemento;
    ptrNodoArbol ptrRaiz = NULL;

    printf("Los numeros colocados en el arbol son:\n");
    for(i=1;i<=7;i++){
        printf("ingrese nodo: ");
        scanf("%d",&elemento);
        insertaNodo(&ptrRaiz,elemento);
    }
    printf("\n\nEl recorrido en pre orden es:\n");
    preOrden(ptrRaiz);
    printf("\n\nEl recorrido in orden es:\n");
    inOrden(ptrRaiz);
    printf("\n\nEl recorrido en pos orden es:\n");
    postOrden(ptrRaiz);
    return 0;
}
void insertaNodo(ptrNodoArbol* ptrArbol,int valor)
{

    if(*ptrArbol == NULL){
        *ptrArbol = malloc(sizeof(NodoArbol));
        if(*ptrArbol != NULL){
            (*ptrArbol)->dato=valor;
            (*ptrArbol)->ptrIzq=NULL;
            (*ptrArbol)->prtDer=NULL;
        }else{
            printf("no se inserto %d.No hay memoria disponible.\n",valor);
        }
    }else{
        if(valor<(*ptrArbol)->dato){
            insertaNodo(&(*ptrArbol)->ptrIzq,valor);
        }else if(valor>(*ptrArbol)->dato){
            insertaNodo(&(*ptrArbol)->prtDer,valor);
        }else{
            printf("duplicado");
        }
    }
}

void inOrden(ptrNodoArbol ptrArbol)
{

if(ptrArbol!=NULL){
inOrden(ptrArbol->ptrIzq);
printf("%3d",ptrArbol->dato);
inOrden(ptrArbol->prtDer);
}
}

void preOrden(ptrNodoArbol ptrArbol)
{

if(ptrArbol != NULL){
printf("%3d",ptrArbol->dato);
preOrden(ptrArbol->ptrIzq);
preOrden(ptrArbol->prtDer);
}
}
void postOrden(ptrNodoArbol ptrArbol)
{

if(ptrArbol!=NULL){
postOrden(ptrArbol->ptrIzq);
postOrden(ptrArbol->prtDer);
printf("%3d",ptrArbol->dato);
}
}
