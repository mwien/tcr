/* Iterative EEA 
 ** \log a + \log b
 * Calculates the gcd of $a$ and $b$ and their modular inverse $x = a^{-1} \mod b$ and $y = b^{-1} \mod a$.
 */

//START
// extended euclidean algorithm - iterativ
if (b > a) {
    long tmp = a;
    a = b;
    b = tmp;
 }
long x = 0, y = 1, u = 1, v = 0;
while (a != 0) {
    long q = b / a, r = b % a;
    long m = x - u * q, n = y - v * q;
    b = a; a = r; x = u; y = v; u = m; v = n;
 }
long gcd = b;
// x = a^-1 % b, y = b^-1 % a
// ax + by = gcd
//END
