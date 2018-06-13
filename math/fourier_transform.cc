/* Fourier transform
 * calculates the fourier transform for a given vector
 * here used for polynom multiplication in O(n log n)
 */

//START
// pol is the vector that should be transformed
// fft is the resulting vector (note the complex numbers)
// n is the size of pol and fft which has to be of the form 2^k (just fill up with zeros and choose big enough size)
// if inv = true the inverse transform is calculated (here too the result can be found in fft!)
void iterativefft(const vector<long long> &pol, vector<complex<double>> &fft, int n, bool inv)
{
    //copy pol into fft
    if(!inv) {
        for(int i = 0; i < n; ++i) {
            complex<double> cp (pol[i], 0);
            fft[i] = cp;
        }
    }
    //swap positions accordingly
    for(int i = 0, j = 0; i < n; ++i) {
        if(i < j) swap(fft[i], fft[j]);
        int m = n >> 1;
        while(1 <= m && m <= j) j -= m, m >>= 1;
        j += m;
    }
    for(int m = 1; m <= n; m <<= 1) { //<= or <
        double theta = (inv ? -1 : 1) * 2 * M_PI / m;
        complex<double> wm(cos(theta), sin(theta));
        for(int k = 0; k < n; k += m) {
            complex<double> w = 1;
            for(int j = 0; j < m/2; ++j) {
                complex<double> t = w * fft[k + j + m/2];
                complex<double> u = fft[k + j];
                fft[k + j] = u + t;
                fft[k + j + m/2] = u - t;
                w = w*wm;
            }
        }
    }
    if(inv) {
        for(int i = 0; i < n; ++i) {
            fft[i] /= complex<double> (n);
        }
    }
}
//END

//START
// the polynom pol gets squared, the result is put in res
vector<complex<double>> fft (n);
iterativefft(pol, fft, n, false);
for(int i = 0; i < n; ++i) {
    fft[i] *= fft[i];
 }
iterativefft(pol, fft, n, true);
vector<long long> res(n);
for(int i = 0; i < n; ++i) {
    res[i] = round(fft[i].real());
 }
//END
