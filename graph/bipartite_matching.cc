/* Maximum Bipartite Matching
 ** M\cdot N
 * Finds the maximum bipartite matching in an unweighted graph using DFS. \\
 * \emph{Input:} An unweighted adjacency matrix boolean[M][N] with M nodes being matched to N nodes. \\
 * \emph{Output:} The maximum matching. (For getting the actual matching, little changes have to be made.)
 */

//START
// globally create graph array
// adjacency matrix but smaller as only edges between M and N exist
bool bpGraph[M][N];

// A DFS based recursive function 
// that returns true if a matching
// for vertex u is possible
bool bpm(int u,  vector<bool> &seen, vector<int> &matchR)
{
    // Try every job one by one
    for (int v = 0; v < N; v++)
    {
        // If applicant u is interested in 
        // job v and v is not visited
        if (bpGraph[u][v] && !seen[v])
        {
            // Mark v as visited
            seen[v] = true; 
 
            // If job 'v' is not assigned to an 
            // applicant OR previously assigned 
            // applicant for job v (which is matchR[v]) 
            // has an alternate job available. 
            // Since v is marked as visited in 
            // the above line, matchR[v] in the following 
            // recursive call will not get job 'v' again
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v],
                                     seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
 
// Returns maximum number
// of matching from M to N
int maxBPM()
{
    // An array to keep track of the 
    // applicants assigned to jobs. 
    // The value of matchR[i] is the 
    // applicant number assigned to job i,
    // the value -1 indicates nobody is
    // assigned.
    vector<int> matchR (N);
 
    // Initially all jobs are available
    for(int i = 0; i < N; ++i) {
        matchR[i] = -1;
    }
 
    // Count of jobs assigned to applicants
    int result = 0; 
    for (int u = 0; u < M; u++)
    {
        // Mark all jobs as not seen 
        // for next applicant.
        vector<int> seen (N);
 
        // Find if the applicant 'u' can get a job
        if (bpm(bpGraph, u, seen, matchR))
            result++;
    }
    return result;
}
//END
