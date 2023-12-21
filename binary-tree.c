#include <stdio.h> 
#include <stdlib.h> 



typedef struct no{
    int conteudo; 
    struct no *direita; 
    struct no *esquerda; 
}No; 

typedef struct arvore{
    No *raiz; 
}arv; 


void inserirDireita (No *pd, int valor); 

void inserirEsquerda (No *pe, int valor){
    if (pe->esquerda == NULL){
        No *novo = malloc(sizeof(No)); 
        novo->conteudo = valor; 
        novo->direita = NULL; 
        novo->esquerda = NULL; 
        pe->esquerda = novo; 
    }else {
        if (valor <pe->esquerda->conteudo){
            inserirEsquerda(pe->esquerda, valor); 
        }else{
            inserirDireita(pe->esquerda, valor); 
        }
    }
}

void inserirDireita (No *pd, int valor){
    if (pd->direita == NULL){
        No *novo = malloc(sizeof(No)); 
        novo->conteudo = valor;
        novo->esquerda = NULL; 
        novo->direita = NULL; 
        pd->direita = novo; 
    }else{
        if (valor < pd->direita->conteudo){
            inserirEsquerda(pd->direita, valor); 
        }else{
            inserirDireita(pd->direita, valor); 
        }
    }
}



void imprimir(No *raiz){
    if (raiz != NULL){
        imprimir(raiz->esquerda); 
        imprimir(raiz->direita); 
        printf(" [%d] ", raiz->conteudo); 
    }
}

void inserir(arv *p_arv, int valor){
    if (p_arv->raiz == NULL ){
        No *novo = malloc(sizeof(No)); 
        novo->conteudo = valor; 
        novo->esquerda = NULL; 
        novo->direita = NULL; 
        p_arv->raiz = novo; 
    }else{
        if (valor < p_arv->raiz->conteudo){
            inserirEsquerda(p_arv->raiz, valor); 
        }else{
            inserirDireita(p_arv->raiz, valor); 
        }
    }
}


int buscar (No *raiz, int chave){
    if (raiz == NULL){
        return -1; 
    }else{
        if (chave == raiz->conteudo){
            return chave; 
        }
        if (chave < raiz->conteudo){
            buscar(raiz->esquerda, chave); 
        }else{
           buscar(raiz->direita, chave); 
    }
}

}


No *remover (No *raiz, int valor){
    if (raiz == NULL){
        printf("Valor nao encontrado!"); 
        return NULL; 
    }else{
        if (valor == raiz->conteudo){
        if (raiz->direita == NULL && raiz->esquerda == NULL){
            free(raiz);
        }
        }
        
        else{
            if (valor <raiz->conteudo){
                raiz->esquerda = remover(raiz->esquerda, valor); 
            }else{
                raiz->direita = remover(raiz->direita, valor); 
                return raiz; 
            }
        }
    }
}

int main (void){
    
    arv Arv; 
    Arv.raiz = NULL; 
    No *raiz = NULL; 
    
    int op, valor; 
    do {
        
        printf("\n0-Sair\n1-Inserir\n2-Imprimir\n3-Buscar\n4-Remover\n"); 
        scanf("%d", &op); 
        
        
        switch(op){
            case 0: printf("programa encerrado!"); 
            break; 
            
            case 1: printf("Insira o valor: ");
            scanf("%d", &valor); 
            inserir(&Arv, valor);
            break; 
            
            case 2: imprimir(Arv.raiz); 
            break; 
            
            case 3: printf("Digite o valor a ser buscado: ");
                    scanf("%d", &valor); 
                   // buscar(Arv.raiz, valor); 
                    printf("Resultado da busca: %d ", buscar(Arv.raiz, valor));
                    break;
                    
                    
            case 4: printf("Insira o valor a ser removido: "); 
                    scanf("%d", &valor); 
                    raiz = remover(Arv.raiz, valor); 
                    break; 
        }
    }while(op != 0); 
    
}

