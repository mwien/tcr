/* DP Divide and conquer optimization
** kn \log n
* works when dp[i][j] = min_{k<j}(dp[i-1][k] + C[k+1][j])
* and the optimal k is monotone
*/
//START
long long T[2005][2005];

void optdp(int i, int jleft, int jright, int kleft, int kright)
{
    if(jleft > jright) return;
    int jmid = (jleft + jright) / 2;
    T[i][jmid] = (1LL << 62);
    int bestk = -1;
    for(int k = kleft; k <= kright && k < jmid; ++k) {
	if(T[i-1][k] + C[k+1][jmid] < T[i][jmid]) {
	    T[i][jmid] = T[i-1][k] + C[k+1][jmid];
	    bestk = k;
	}
    }
    optdp(i, jleft, jmid-1, kleft, bestk);
    optdp(i, jmid+1, jright, bestk, kright);
}

int main()
{
    for(int j = 1; j <= n; ++j) {
	T[1][j] = C[1][j];
    }
    for(int i = 2; i <= g; ++i) {
	optdp(i, 1, n, 1, n);
    }
}
//END
