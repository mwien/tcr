/* Next number with n bits set
 ** 1
 * From $x$ the smallest number greater than $x$ with the same amount of bits set is computed.
 * Little changes have to be made, if the calculated number has to have length less than 32 bits.\\
 * \emph{Input:} number $x$ with $n$ bits set $(x = (1 << n) -1)$\\
 * \emph{Output:} the smallest number greater than $x$ with $n$ bits set
 */
//START
int nextNumber(int x) {
	//break when larger than limit here
	if(x == 0) return 0;
	int smallest = x & -x;
	int ripple = x + smallest;
	int new_smallest = ripple & -ripple;
	int ones  = ((new_smallest/smallest) >> 1) - 1;
	return ripple | ones;
}
//END
