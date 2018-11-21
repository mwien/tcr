/* Fenwick-Tree
 ** log n
 * Can be used for computing prefix sums.
 */

//START
//note that 0 can not be used
//globally create array
int fwktree[1000001];
//END

//START
int read(int index) {
   int sum = 0;
   while (index > 0) {
      sum += fwktree[index];
      index -= (index & -index);
   }
   return sum;
}
//END

//START
// n is the actual size of the tree (e.g. the array is used from 1 to n-1)
void update(int index, int addValue, int n) {
   while (index <= n - 1) {
      fwktree[index] += addValue;
      index += (index & -index);
   }
}
//END
