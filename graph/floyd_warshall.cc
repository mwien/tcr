/* FloydWarshall
 ** |V|^3
 * Finds all shortest paths. Paths in array next, distances in ans.
 */
//START
int MAX_VALUE = (1 << 30);

void floydWarshall(int[][] graph,
                   int[][] next, int[][] ans, int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ans[i][j] = graph[i][j];
    
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (ans[i][k] + ans[k][j] < ans[i][j]
                    && ans[i][k] < MAX_VALUE
                    && ans[k][j] < MAX_VALUE) {
                    ans[i][j] = ans[i][k] + ans[k][j];
                    next[i][j] = next[i][k];
                }
}
//END
