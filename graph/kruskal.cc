/* kruskal algorithm
 * finds the minimum spanning tree
 ** |E| \log(|E|)
 */

//START
// sort edges by increasing weight
// init union find (the nodes are the sets)
// go through the sorted edges and check if the corresponding nodes
// are in the same set, if yes skip the edge, if no the edge is part
// of the minimum spanning tree -> unite nodes
//END
