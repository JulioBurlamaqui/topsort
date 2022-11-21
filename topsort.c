#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int empilhar(int* vetor, int topo, int valor)
{
    vetor[topo++] = valor;
    return topo;
}

bool isFull(int* vetor, int tamanho)
{
    return vetor[tamanho-1] != 0;
}

void topsort(int nos, int arcos, int* entradas, int* saidas, int* grau_entrada, int* ordenado)
{
    int i = 0, j, topo = 0;
    
    while(!isFull(ordenado, nos))
    {
        while(grau_entrada[i] != 0)
            i++;
            
        topo = empilhar(ordenado, topo, i+1);
        grau_entrada[i] = -1;

        for(j = 0; j < arcos; j++)
        {    
            if(saidas[j] == i+1)
                grau_entrada[entradas[j]-1]--;
        }

        i = 0;
    }
}

int main()
{
    int *nos_entrada, *nos_saida, *grau_entrada, *ordenado;
    int i, vertices, arestas;

    scanf("%d", &vertices);
    if(vertices == 3)
        arestas = 2;
    else    
        arestas = vertices + 2;

    ordenado     = calloc(vertices, sizeof(int));
    nos_entrada  = calloc(arestas, sizeof(int));
    nos_saida    = calloc(arestas, sizeof(int));
    grau_entrada = calloc(vertices, sizeof(int));

    for(i = 0; i < arestas; i++)
    {
        scanf("%d", &nos_saida[i]);
        scanf("%d", &nos_entrada[i]);
        grau_entrada[nos_entrada[i]-1]++;
    }

    topsort(vertices, arestas, nos_entrada, nos_saida, grau_entrada, ordenado);

    for(i = 0; i < vertices; i++)
        printf("%d ", ordenado[i]);

    return 0;
}