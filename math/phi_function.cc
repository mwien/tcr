/* phi function calculator
** \sqrt(n)
 */
//START
int phi(int n)
{
    double result = n;
    for(int p = 2; p * p <= n; ++p) {
        if(n % p == 0) {
            while(n % p == 0) n /= p;
            result *= (1.0 - (1.0 / (double) p));
        }
    }
    if(n > 1) result *= (1.0 - (1.0 / (double) n));
    return round(result);
}
//END
