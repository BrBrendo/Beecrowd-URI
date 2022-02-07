#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct Cartas 	
{char carta;
struct Cartas *prox;
}Cartas;

typedef struct Pilha 	
{ Cartas *topo, *final;
int qtd;
}Pilha;

int main()
{
	int discarded[50], qtd, c=0, k=0;
	Pilha	pilhar;
	Cartas *aux;

	while (scanf("%d", &qtd) && qtd != 0)
	{
		for(c=0; c < 50; c++)
			discarded[c] = 0;

		k = 0;

		pilhar.topo = NULL;
		pilhar.qtd = 0;

		for(c= qtd; c > 0; c--)
		{
			aux = (Cartas *) malloc(sizeof(Cartas));

			if(aux == NULL)
				break;

			aux->carta = c;
			aux->prox = pilhar.topo;

			pilhar.topo = aux;
			pilhar.qtd++;

			if(c == qtd)
				pilhar.final = aux;
		}

		while (pilhar.qtd >= 2)
		{
			aux = pilhar.topo;
			pilhar.topo = aux->prox;
			discarded[k] = aux->carta;
			free(aux);
			pilhar.qtd--;
			k++;
			aux = pilhar.topo->prox;
			pilhar.final->prox = pilhar.topo;
			pilhar.final = pilhar.topo;
			pilhar.topo = aux;
		}

		printf("Discarded cards:");
		for(c=0; c < k; c++)
		{
			printf(" %d", discarded[c]);
			if(c != k-1)
				printf(",");
		}
		printf("\nRemaining card: %d\n", pilhar.final->carta);
	}

	return 0;
}