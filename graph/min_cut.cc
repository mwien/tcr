/* find min cut edges
 */
//START
// do a maxflow
// go through residual graph with dfs or bfs traversing edges with left cap > 0 and
// back edges with flow > 0, mark all visited nodes
// then output all edges from a marked to an unmarked node (maybe another BFS or something)
//END
