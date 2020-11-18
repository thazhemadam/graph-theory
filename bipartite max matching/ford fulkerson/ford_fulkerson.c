#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool bipartite_match (bool **graph, int M, int N, int u, bool seen[], int matchR[])
{
	for (int v = 0; v < N; v++) {
		if (graph[u][v] && !seen[v]) {
			seen[v] = true;

			if (matchR[v] < 0 || bipartite_match (graph, M, N, matchR[v], seen, matchR)) {
				matchR[v] = u;
				return true;
			}
		}
	}
	return false;
}

int max_matching(bool **graph, int M, int N)
{

	int matchR[N];

	memset(matchR, -1, sizeof(matchR));

	int result = 0;
	for (int i = 0; i < M; i++) {
		bool seen[N];
		memset(seen, 0, sizeof(seen));

		if (bipartite_match (graph, M, N, i, seen, matchR))
			result++;
	}
	return result;
}

int main(void)
{
	int M, N;

	scanf("%d %d", &M, &N);
	bool **bp_graph = (bool **)malloc(sizeof(bool *) * M);

	for (int i = 0; i < M; i++) {
		bp_graph[i] = (bool *)malloc(sizeof(bool) * N);
		memset(bp_graph[i], 0, N * sizeof(bool));
	}

	int total;
	scanf("%d", &total);

	for (int i = 0; i < total; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		bp_graph[x][y] = 1;
	}

	printf("\n\nMaximum number of matches: %d\n\n", max_matching(bp_graph, M, N));

	for(int i = 0; i < M; i++)
		free(bp_graph[i]);
	free(bp_graph);
	return 0;
}
