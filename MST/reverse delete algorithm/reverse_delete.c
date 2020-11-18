#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void dfs(int v, int **graph, int n, int *vertexBelongsTo, int componentId)
{
	vertexBelongsTo[v] = componentId;
	for (int j = 0; j < n; j++) {
		if (graph[v][j] && !vertexBelongsTo[j]) {
			vertexBelongsTo[j] = componentId;
			dfs(j, graph, n, vertexBelongsTo, componentId);
		}
	}
}

void merge(int arr[][3], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1][3], R[n2][3];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) {
		L[i][0] = arr[l + i][0];
		L[i][1] = arr[l + i][1];
		L[i][2] = arr[l + i][2];
	}
	for (j = 0; j < n2; j++) {
		R[j][0] = arr[m + 1 + j][0];
		R[j][1] = arr[m + 1 + j][1];
		R[j][2] = arr[m + 1 + j][2];
	}

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i][2] >= R[j][2]) {
			arr[k][0] = L[i][0];
			arr[k][1] = L[i][1];
			arr[k][2] = L[i][2];
			i++;
		}
		else {
			arr[k][0] = R[j][0];
			arr[k][1] = R[j][1];
			arr[k][2] = R[j][2];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k][0] = L[i][0];
		arr[k][1] = L[i][1];
		arr[k][2] = L[i][2];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k][0] = R[j][0];
		arr[k][1] = R[j][1];
		arr[k][2] = R[j][2];
		j++;
		k++;
	}
}

void mergeSort(int arr[][3], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

int component_count(int **graph, int n, int *vertexBelongsTo)
{
	for (int i = 0; i < n; i++)
		vertexBelongsTo[i] = 0;

	int compId = 1;
	for (int i = 0; i < n; i++) {
		if (vertexBelongsTo[i] == 0) {
			dfs(i, graph, n, vertexBelongsTo, compId);
			compId++;
		}
	}
	return compId - 1;
}

bool only_one_component(int **graph, int V) {

	int *vertexBelongsTo = (int *)malloc(sizeof(int) * V);
	int numberOfComponents = component_count(graph, V, vertexBelongsTo);

	free(vertexBelongsTo);
	return (numberOfComponents == 1);
}

void sort_edges_descending(int edges_array[][3], int E)
{
	mergeSort(edges_array, 0, E - 1);
}

int reverse_delete(int **graph, int edges_array[][3], int V, int E)
{
	sort_edges_descending(edges_array, E);

	int edge_count = E;
	int min_count = 0;

	for(int i = 0; i < E; i++) {
		if(edge_count == (V - 1))
			break;

		int x = edges_array[i][0];
		int y = edges_array[i][1];
		graph[x][y] = 0;
		graph[y][x] = 0;

		if(only_one_component(graph, V))
			edge_count--;

		else {
			graph[x][y] = edges_array[i][2];
			graph[y][x] = edges_array[i][2];
		}
	}

	for(int i = 0; i < V; i++){
		for(int j = 0; j < i; j++)
			min_count+=graph[i][j];
	}

	return min_count;
}

int main(void)
{

	int V, E;
	scanf("%d %d", &V, &E);
	int **graph = (int **)malloc(sizeof(int *) * V);
	int edges_array[E][3];
	memset(edges_array, 0, sizeof(edges_array));

	for (int i = 0; i < V; i++) {
		graph[i] = (int *)malloc(sizeof(int) * V);
		memset(graph[i], 0, sizeof(int)*V);
	}

	for (int j = 0; j < E; j++) {
		int x, y, weight;
		scanf("%d %d %d", &x, &y, &weight);
		graph[x][y] = weight;
		graph[y][x] = weight;
		edges_array[j][0] = x;
		edges_array[j][1] = y;
		edges_array[j][2] = weight;
	}

	int min_cost = reverse_delete(graph, edges_array, V, E);

	printf("\nEdges in the Minimum Spanning Tree:\n");
	for(int i = 0; i < V; i++) {
		for(int j = 0; j < i; j++) {
			if(graph[i][j])
				printf("\n(%d, %d)", i, j);
		}
	}

	printf("\n\nMinimum Cost: %d\n", min_cost);

	for(int i = 0; i < V; i++)
		free(graph[i]);
	free(graph);
	return 0;
}
