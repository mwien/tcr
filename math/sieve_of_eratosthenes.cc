/* Sieve of Eratosthenes
 ** n
 * Calculates Sieve of Eratosthenes. \\
 * \emph{Input:} A integer $N$ indicating the size of the sieve. \\
 * \emph{Output:} A boolean array, which is true at an index $i$ iff i is prime.
 */

//START
vector<boolean> is_prime (n+1);
for (int i = 2; i <= n; i++) is_prime[i] = true;
for (int i = 2; i*i <= n; i++)
    if (is_prime[i])
	for (int j = i*i; j <= n; j+=i)
	    is_prime[j] = false;
//END
