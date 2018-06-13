/* Least Common Multiple
 ** \log a + \log b
 * Calculates the lcm of two numbers $a$ and $b$ or of an array of numbers $input$.\\
 * \emph{Input:} Numbers $a$ and $b$ or array of numbers $input$\\
 * \emph{Output:} Least common multiple of the input
 */
//START
long long lcm(long long a, long long b) {
    return a * (b / gcd(a, b));
}

long long lcm(vector<long long> &input) {
	long result = input[0];
	for(int i = 1; i < input.size(); i++)
		result = lcm(result, input[i]);
	return result;
}
//END
