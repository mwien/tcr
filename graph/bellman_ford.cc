/* BellmanFord
 ** |V|\cdot |E|
 * Finds shortest pathes from a single source. Negative edge weights are allowed. Can be used for finding negative cycles.
 */

//START
// globally create arrays and graph
vector<vector<pair<int, int>>> g;
int dist[n];
int MAX_VALUE = (1 << 30);

bool bellmanFord() {
    //source is 0
    dist[0] = 0;
    //calc distances
    //the path has max length |V|-1
    for(int i = 0; i < n-1; i++) {
        //each iteration relax all edges
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < g[j].size(); ++k) {
                pair<int, int> e = g[j][k];
                if(dist[j] != MAX_VALUE 
                   && dist[e.first] > dist[j] + e.second) {
                    dist[e.first] = dist[j] + e.second;
                }
            }
        }
    }
    //check for negative-weight cycle
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < g[i].size(); ++j) {
            if(dist[i] != Integer.MAX_VALUE
               && dist[e.first] > dist[i] + e.second) {
                return true;
            }
        }
    }
    return false;
}
//END
