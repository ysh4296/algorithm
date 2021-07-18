/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
#include <iostream>
#include <vector>
#include <queue>
#define MAX 20020
using namespace std;
typedef long long int l;
l Answer;
int N, M;
class chunk {
public:
	l a, b, c, d;
	int oe;
	chunk(int a,int b,int c,int d, int oe) {
		this->oe = oe;
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}
};
struct cmp {
	bool operator()(chunk a , chunk b) {
		if (a.c + a.d == b.c + b.d) {
			return a.oe > b.oe; // 0 even , 1 odd
		}
		return a.c + a.d < b.c + b.d;
	}
};
l a, b, c, d;
priority_queue<chunk, vector<chunk>, cmp> pq;
void min(l temp) {
	if (temp < d) {
		d = temp;
		if (d < c) {
			swap(d, c);
			if (c < b) {
				swap(c, b);
				if (b < a) {
					swap(b, a);
				}
			}
		}
	}
	return;
}
void init() {
	a = 10000001;
	b = 10000001;
	c = 10000001;
	d = 10000001;
	return;
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	 // freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		cin >> N >> M;
		int O = 0,E = 0,odd = 0;
		for (int i = 0; i < N; i++) {
			int num_of_chunk;
			cin >> num_of_chunk;
			init();
			for (int j = 0; j < num_of_chunk; j++) {
				l temp;
				cin >> temp;
				min(temp);
			}
			pq.push(chunk(a,b,c,d,num_of_chunk % 2));
			if (num_of_chunk % 2 == 1) { // odd
				Answer += 2 * a + b + c + d;
				O++;
				odd++;
			}
			else { // even
				Answer += a + b + c + d;
				E++;
			}
		}
		M *= 2;
		chunk max1 = pq.top();
		pq.pop();
		if (max1.oe == 1) O--;
		else E--;
		chunk max2 = pq.top();
		pq.pop();
		if (max2.oe == 1) O--;
		else E--;
		if (O == 0 && E != 0 && odd != 0) { // the baddest situation
			chunk max3 = pq.top();

			l ans2 = Answer - (max1.c + max1.d + max3.c + max3.d);
			l ans1 = 2 * max1.a + max1.b + 2 * max2.a + max2.b;

			while (!pq.empty()) {
				chunk temp = pq.top();
				pq.pop();
				ans1 += 2*temp.a + 2*temp.b + temp.c + temp.d;
			}
			if (ans1 > ans2) {
				Answer = ans2;
			}
			else {
				Answer = ans1;
			}
		}
		else { // normal situation
			Answer -= (max1.c + max1.d + max2.c + max2.d);
		}
		while (!pq.empty()) {
			pq.pop();
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}
	return 0;//Your program should return 0 on normal termination.
}
//예외상황을 찾아 맞추는 기본적인 구현문제 사실 크게 어려운건 없었다.
