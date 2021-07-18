/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
#define MAX 101010
using namespace std;

int Answer;
vector<int> Di;
int parent[MAX] = {0,};
int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = find(parent[x]);
	}
}
void Union(int x,int y) {
	x = find(x);
	y = find(y);
	if (x > y) swap(x, y);
	Answer--;
	parent[y] = x;
	return;
}
int main(int argc, char** argv)
{
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
		int N;
		cin >> N;
		Answer = N;
		for (int i = 0; i < N; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			Di.push_back(temp);
			if (i+ temp < N && find(i) != find(i+temp)) {
				Union(i,i+temp);
			}
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
//어렵지않은 union find 문제
//최적화 수준은 나쁘지 않다고 생각함
