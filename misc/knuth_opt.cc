/* Knuth optimization (DP)
** n^2
*/

//START
//s - length(size) of substring
for (int s = 0; s<=k; s++) {             
    for (int i = 0; i+s<=k; i++) {             
        int j = i + s;                            
        if (s < 2) {                              
            res[i][j] = 0;
            // at the start mid is equal to left border
            mid[i][j] = l;                          
            continue;
        }
        //Knuth's trick: getting bounds on m
        int mleft = mid[i][j-1];                  
        int mright = mid[i+1][j];
        res[l][r] = 1000000000000000000LL;
         //iterating for m in the bounds only
        for (int m = mleft; m<=mright; m++) {    
            int tres = res[i][m] + res[m][j] + (x[j]-x[i]);
            if (res[i][j] > tres) {                
                res[i][j] = tres;
                mid[i][j] = m;
            }
        }
    }
 }
//END
