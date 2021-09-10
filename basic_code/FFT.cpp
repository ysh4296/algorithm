#include <complex>
#include <vector>
typedef complex<double> cpx;
const double pi = acos(-1);

void FFT(vector<cpx>& f, cpx w) {
	int n = f.size();
	if (n == 1) return; // leaf node end divide
	vector<cpx> even(n >> 1),odd(n >> 1);
  // dividing the list in to two part for calculating efficiency
	for (int i = 0; i < n; i++) {
		if (i & 1)odd[i >> 1] = f[i];
		else even[i >> 1] = f[i];
	}
	// conquer
	FFT(even, w * w); FFT(odd, w * w);
	cpx wp(1, 0);
	for (int i = 0; i < n / 2; i++) {
		f[i] = even[i] + wp * odd[i];
		f[i + n / 2] = even[i] - wp * odd[i];
		wp *= w;
	}
}

vector<cpx> mul(vector<cpx> a , vector<cpx> b) {
	int n = 1;
	while (n <= a.size() || n < b.size()) n <<= 1;
	n <<= 1;
	a.resize(n); b.resize(n); vector<cpx> c(n);
	cpx w(cos(2*pi/n), sin(2*pi/n));
	FFT(a, w); FFT(b, w);
	// conversion completed
	for (int i = 0; i < n; i++) c[i] = a[i] * b[i];
	FFT(c, cpx(1,0)/w);
	for (int i = 0; i < n; i++) {
		c[i] /= cpx(n, 0);
		c[i] = cpx(round(c[i].real()), round(c[i].imag()));
	}
	return c;
}
