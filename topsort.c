#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No* proximo;
}No;


typedef struct Pilha
{
    struct No topo;
    int tamanho;
}Pilha;

void empilhar(struct Pilha* pilha, int numero)
{
    struct No novo = (No)malloc(sizeof(No));
    novo->valor = numero;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
    pilha->tamanho++;
}

void topsort(int nos, int* entradas, int* saidas, int* grau_entrada, struct Pilha* ordenado)
{
    int i;
    
    for(i = 0; i < nos; i++)
    {
        if(grau_entrada[i] != 0)
            continue;
        empilhar(ordenado, i+1);
        grau_entrada[i] = -1;

        if(saidas[i] == i+1)
            grau_entrada[entradas[i]-1] -= 1;
    }
}

    

int main()
{
    struct Pilha* ordenado = NULL;
    int *nos_entrada, *nos_saida, *grau_entrada;
    int i, vertices, arestas;

    scanf("%d", &vertices);
    arestas = vertices + 2;

    ordenado     = malloc(vertices* sizeof(int));
    nos_entrada  = calloc(vertices, sizeof(int));
    nos_saida    = calloc(vertices, sizeof(int));
    grau_entrada = calloc(vertices, sizeof(int));

    for(i = 0; i < arestas; i++)
    {
        scanf("%d", &nos_saida[i]);
        scanf("%d", &nos_entrada[i]);
        grau_entrada[nos_entrada[i]-1]++;
    }

    topsort(vertices, nos_entrada, nos_saida, grau_entrada, ordenado);

    for(i = 0; i < vertices; i++)
        printf("%d ", ordenado[i]);

    return 0;
}