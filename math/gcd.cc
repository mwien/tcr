/* Greatest Common Divisor
 ** \log a + \log b
 * Calculates the gcd of two numbers $a$ and $b$ or of an array of numbers $input$.\\
 * \emph{Input:} Numbers $a$ and $b$ or array of numbers $input$\\
 * \emph{Output:} Greatest common divisor of the input
 */
//START
long long gcd(long long a, long long b) {
    while (b > 0) {
        long long temp = b;
        b = a % b; // % is remainder
        a = temp;
    }
    return a;
}

long long gcd(vector<long long> &input) {
    long long result = input[0];
    for(int i = 1; i < input.size(); i++)
		result = gcd(result, input[i]);
    return result;
}
//END
