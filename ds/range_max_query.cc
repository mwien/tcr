/* Range maximum query
 * finds maximum in range [i,j] in O(1)
 * preprocessing takes O(n log n)
 */
//START
// create A globally, contains the input
int A[10000];
// M is the DP table has size N*log N
int M[10000][20];
//END

//START
// N is the input size
void process(int N) {
	for(int i = 0; i < N; i++)
		M[i][0] = i;
	// filling table M
	// M[i][j] = max(M[i][j-1], M[i+(1<<(j-1))][j-1]),
	// cause interval of length 2^j can be partitioned
	// into two intervals of length 2^(j-1)
	for(int j = 1; 1 << j <= N; j++) {
		for(int i = 0; i + (1 << j) - 1 < N; i++) {
			if(A[M[i][j-1]] >= A[M[i+(1 << (j-1))][j-1]])
				M[i][j] = M[i][j-1];
			else
				M[i][j] = M[i + (1 << (j-1))][j-1];
		}
	}
}
// range is [i,j], returns index of max
int query(int N, int i, int j) {
	// k = |_ log_2(j-i+1) _|
	int k = (int) (log(j - i + 1) / log(2));
	if(A[M[i][k]] >= A[M[j- (1 << k) + 1][k]])
		return M[i][k];
	else
		return M[j - (1 << k) + 1][k];
}
//END
