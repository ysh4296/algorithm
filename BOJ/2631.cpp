#include <iostream>

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int N;
	int a[201], d[201];
	int max = 0;
	cin >> N;
	
    for (int i = 1; i <= N; i++) cin >> a[i];

	for (int i = 1; i <= N; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) 
		    if (a[j] < a[i] && d[i] < d[j] + 1)
				d[i]++;
		if (max < d[i]) max = d[i];
	}
	cout << N-max;
	return 0;
}
