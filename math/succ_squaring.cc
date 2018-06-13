/* successive squaring
 * calculates $g^L$
 * here shown for matrix mult, but can be applied in other cases
 */
//START
void mult(int a[][nos], int b[][nos], int N)
{
    int res[nos][nos] = {0};
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                res[i][j] = (res[i][j] + a[i][k]*b[k][j]) % 10000;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            a[i][j] = res[i][j];
        }
    }
}
//END
//START
// res stores the result and is initialized to the identity matrix
int res[nos][nos] = {0};
for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
	if(i == j) res[i][j] = 1;
    }
 }
for(int i = 0; (1 << i) <= L; i++) {
    if(((1 << i) & L) == (1 << i)) {
	mult(res, g, N);
    }
    mult(g, g, N);
 }
//END
