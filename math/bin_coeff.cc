/* binomial coefficient
 ** k
 * gives binomial coefficient (n choose k)
 */
 
//START
// note that if we have to calculate the bin coeff modulo some prime
// we cannot divide, but have to multiply by the inverse of k
// that can be easily computed as k^p-2 % p with modular exponentiation (use successive squaring)
// another approach would be to just calculate n! / ((n-k)!*k!) (again invert denominator and use mod in all steps)
long long bin(int n, int k) {
	if (k == 0)
		return 1;
	else if (k > n/2)
		return bin(n, n-k);
	else
		return n*bin(n-1, k-1)/k;
}
//END
