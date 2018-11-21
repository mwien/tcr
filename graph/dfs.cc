/* Recursive Depth First Search
** |V| + |E|
* Recursive DFS with different options (storing times, connected/unconnected graph).
* this is very much pseudocode, needs a lot of problem adaption anyway\\
* \emph{Input:} A source vertex $s$, a target vertex $t$, and adjlist $G$ and the time (0 at the start)\\
* \emph{Output:} Indicates if there is connection between $s$ and $t$.
*/

//START
// globally create adj list etc
vector<vector<int>> g;
int dtime[n];
int ftime[n];
int vis[n];
int pre[n];
//first call with time = 0                   
void rec_dfs(int u, int time){
    //it might be necessary to store the time of discovery
    time = time + 1;
    dtime[u] = time;
    
    vis[u] = 1; //new vertex has been discovered
    //For cycle check vis should be int and 0 are not vis nodes
    //1 are vis nodes which havent been finished and 2 are finished nodes
    //cycle exists iff edge to node with vis=1
    //when reaching the target return true
    //not necessary when calculating the DFS-tree
    for(int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        //exploring a new edge
        if(!vis[v]) {
            pre[v] = u;
            if(rec_dfs(v, time)) return true;
        }
    }
    //storing finishing time
    time = time + 1;
    ftime[s] = time;
    vis[s] = 2;
    return false;
}

//if we want to visit the whole graph, even if it is not connected we might use this
//make sure all vertices vis value is false etc 
int time = 0;
for(int i = 0; i < n; i++) {
    if(vis[i] == 0) {
        //note that we leave out t so this does not work with the below function
        //adaption will not be too difficult though
        //time should not always start at zero, change if needed
        rec_dfs(i, 0);
    }
 }
}

