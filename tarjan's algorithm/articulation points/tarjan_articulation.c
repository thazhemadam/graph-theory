#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static inline int min(int x, int y)
{
	return x < y ? x : y;
}
typedef struct
{
	int V;
	int E;
	int **adj;
} graph;

void initialize_graph(graph *g, int V, int E)
{
	g->V = V;
	g->adj = (int **)malloc(sizeof(int *) * V);
	for (int i = 0; i < V; i++) {
		g->adj[i] = (int *)malloc(sizeof(int) * V);
		memset(g->adj[i], -1, sizeof(int) * V);
	}
}

void ap_utils(graph *g, int u, bool *visited, int *disc, int *low, int *parent, bool *ap)
{
	static int time = 0;
	int children = 0;
	visited[u] = true;
	disc[u] = low[u] = ++time;
	int *i;
	i = g->adj[u];

	for (int index = 0; index < g->V; index++) {
		int v = *(i + index);

		if (v < 0)
			continue;

		if (!visited[v]) {
			children++;
			parent[v] = u;
			ap_utils(g, v, visited, disc, low, parent, ap);

			low[u] = min(low[u], low[v]);

			if (parent[u] == -1 && children > 1)
				ap[u] = true;

			if (parent[u] != -1 && low[v] >= disc[u])
				ap[u] = true;
		}

		else if (v != parent[u])
			low[u] = min(low[u], disc[v]);
	}
}

void articulation_points(graph *g)
{
	bool visited[g->V], ap[g->V];
	int disc[g->V], low[g->V], parent[g->V];

	for (int i = 0; i < g->V; i++) {
		parent[i] = -1;
		visited[i] = false;
		ap[i] = false;
	}
	for (int i = 0; i < g->V; i++)
		if (visited[i] == false)
			ap_utils(g, i, visited, disc, low, parent, ap);

	bool no_ap = 1;
	printf("\nThe Articulation Points in the graph are:\n");
	for (int i = 0; i < g->V; i++) {
		if (ap[i] == true) {
			printf("%d ", i);
			no_ap = 0;
		}
	}
	if(no_ap)
		printf("No articulation points.");

	printf("\n");
}

int main(void)
{
	graph *g;
	int V, E;
	scanf("%d %d", &V, &E);
	initialize_graph(g, V, E);

	for (int i = 0; i < E; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		g->adj[x][y] = y;
		g->adj[y][x] = x;
	}

	articulation_points(g);

	for (int i = 0; i < V; i++)
		free(g->adj[i]);

	free(g->adj);
	return 0;
}
