/* topological sort
** |E| + |V|
 */

//START
//two options:
//1. remove nodes with in-degree 0
//2. do DFS and prepend nodes to list when they are done
// (so all the nodes they depend on have already been prepended as they already finished)
//END
