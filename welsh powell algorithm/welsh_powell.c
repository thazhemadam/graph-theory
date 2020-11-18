#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void graph_color(bool **graph, int V)
{
	int color[V];
	color[0] = 0;
	int colorUsed[V];

	for (int i = 1; i < V; i++)
		color[i] = -1;

	for (int i = 0; i < V; i++)
		colorUsed[i] = 0;

	for (int u = 1; u < V; u++) {
		for (int v = 0; v < V; v++) {
			if (graph[u][v]) {
				if (color[v] != -1)
					colorUsed[color[v]] = 1;
			}
		}

		int col;
		for (col = 0; col < V; col++)
			if (!colorUsed[col])
				break;

		color[u] = col;

		for (int v = 0; v < V; v++) {
			if (graph[u][v]) {
				if (color[v] != -1)
					colorUsed[color[v]] = 0;
			}
		}
	}

	int min_count = 0;

	for (int u = 0; u < V; u++)
		if(color[u] > min_count)
			min_count = color[u];

	printf("Minimum number of colours required to colour all vertexes in the graph: %d\n", min_count + 1);

	for (int u = 0; u < V; u++)
		printf("Vertex %d has been assigned colour: %d\n", u, color[u] + 1);
}

int main(void)
{
	int N, E;
	scanf("%d %d", &N, &E);
	bool **graph = (bool **)malloc(sizeof(bool *) * N);
	for (int i = 0; i < N; i++) {
		graph[i] = (bool *)malloc(sizeof(bool) * N);
		memset(graph[i], 0, sizeof(sizeof(bool) * N));
	}

	for(int i = 0; i < E; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	graph_color(graph, N);

	for(int i = 0; i < N; i++)
		free(graph[i]);
	free(graph);
	return 0;
}