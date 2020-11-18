
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static inline int min(int a, int b)
{
	return (a < b) ? a : b;
}

static void findComponent(int **graph, int u, int disc[], int low[], int NODE, int *stk, int *top, bool stkItem[])
{
	static int time = 0;
	disc[u] = low[u] = ++time; //initially discovery time and low value is 1
	stk[++(*top)] = u;

	stkItem[u] = true; //flag as u in the stack

	
	for (int v = 0; v < NODE; v++) {
		if (graph[u][v]) {
			if (disc[v] == -1) { //when v is not visited
				findComponent(graph, v, disc, low, NODE, stk, top, stkItem);
				low[u] = min(low[u], low[v]);
			}

			else if (stkItem[v]) //when v is in the stack, update low for u
				low[u] = min(low[u], disc[v]);
		}
	}

	
	int poppedItem = 0;
	if (low[u] == disc[u])
	{
		while (stk[*top] != u) {
			poppedItem = stk[(*top)--];
			printf("%d ", poppedItem);
			stkItem[poppedItem] = false; //mark as item is popped
		}

		poppedItem = stk[(*top)--];
		printf("%d\n", poppedItem);

		stkItem[poppedItem] = false;
	}
}

static void strongConComponent(int **graph, int NODE)
{
	int disc[NODE], low[NODE];
	bool stkItem[NODE];
	int *stk = (int *)malloc(sizeof(int)*NODE);
	int top = -1;

	for (int i = 0; i < NODE; i++) { //initialize all elements
		disc[i] = low[i] = -1;
		stkItem[i] = false;
	}

	for (int i = 0; i < NODE; i++)
		if (disc[i] == -1)
			findComponent(graph, i, disc, low, NODE, stk, &top, stkItem);
}

int main(void)
{
	int vertex_count, edge_count;
	scanf("%d", &vertex_count);
	int **graph;
	graph = (int **) malloc(vertex_count*sizeof(int *));
	for(int i = 0; i < vertex_count; i++) {
		graph[i] = (int *)malloc(vertex_count * sizeof(int));
		memset(graph[i], 0, (vertex_count)*sizeof(int));
	}

	scanf("%d", &edge_count);
	for(int i = 0; i < edge_count; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
	}

	strongConComponent(graph, vertex_count);
}
