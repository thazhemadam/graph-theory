#include <stdio.h>
#include <stdlib.h>

typedef struct Subset
{
	int parent;
	int rank;
} subset;
typedef struct Edge
{
	int src;
	int dest;
	int weight;
} edge;

typedef struct Graph
{
	int V;
	int E;
	edge *edge;
} graph;

graph *initialize_graph(int V, int E)
{
	graph *G = (graph *)malloc(sizeof(graph));
	G->V = V;
	G->E = E;
	G->edge = (edge *)malloc(E * sizeof(edge));
	return G;
}

int find_parent(subset subsets[], int pos)
{
	if (subsets[pos].parent != pos)
		subsets[pos].parent = find_parent(subsets, subsets[pos].parent);

	return subsets[pos].parent;
}

void union_sets(subset subsets[], int x, int y)
{
	int x_root = find_parent(subsets, x);
	int y_root = find_parent(subsets, y);

	if (subsets[x_root].rank < subsets[y_root].rank)
		subsets[x_root].parent = y_root;

	else if (subsets[x_root].rank > subsets[y_root].rank)
		subsets[y_root].parent = x_root;

	else {
		subsets[y_root].parent = x_root;
		subsets[x_root].rank++;
	}
}

void boruvka(graph *G)
{
	int V = G->V, E = G->E;
	edge *edge = G->edge;

	subset *subsets = (subset *)malloc(V * sizeof(subset));

	int *min_cost_array = (int *)malloc(V * sizeof(int));
	int i;

	for (i = 0; i < V; i++) {
		subsets[i].parent = i;
		subsets[i].rank = 0;
		min_cost_array[i] = -1;
	}

	int tree_count = V, min_cost = 0;

	while (tree_count > 1) {
		for (i = 0; i < V; i++)
			min_cost_array[i] = -1;

		for (i = 0; i < E; i++) {
			int src_set = find_parent(subsets, edge[i].src);
			int dest_set = find_parent(subsets, edge[i].dest);

			if (src_set == dest_set)
				continue;

			else {
				if (min_cost_array[src_set] == -1 || edge[min_cost_array[src_set]].weight > edge[i].weight)
					min_cost_array[src_set] = i;

				if (min_cost_array[dest_set] == -1 || edge[min_cost_array[dest_set]].weight > edge[i].weight)
					min_cost_array[dest_set] = i;
			}
		}

		for (i = 0; i < V; i++) {
			if (min_cost_array[i] != -1) {
				int src_set = find_parent(subsets, edge[min_cost_array[i]].src);
				int dest_set = find_parent(subsets, edge[min_cost_array[i]].dest);

				if (src_set == dest_set)
					continue;

				min_cost += edge[min_cost_array[i]].weight;
				printf("\n(%d, %d)", edge[min_cost_array[i]].src, edge[min_cost_array[i]].dest);

				union_sets(subsets, src_set, dest_set);
				tree_count--;
			}
		}
	}

	printf("\n\nMinimum Cost: %d\n", min_cost);
	return;
}

int main(void)
{
	int V, E, i;
	scanf("%d %d", &V, &E);

	graph *graph = initialize_graph(V, E);

	for (i = 0; i < E; i++)
		scanf("%d %d %d", &(graph->edge[i].src), &(graph->edge[i].dest), &(graph->edge[i].weight));

	printf("Edges in the Minimum Spanning Tree:");
	boruvka(graph);
	free(graph->edge);
	free(graph);
	return 0;
}