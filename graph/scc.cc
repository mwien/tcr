/* strongly connected components
** |E| + |V|
 */

//START
// use two DFSs
// 1. DFS: topological sort produces list l
// 2. DFS: go through sorting and for transposed graph (edges are flipped) do the DFS, all reached nodes get the same label (are in the same component), of course BFS could also be used
//END
