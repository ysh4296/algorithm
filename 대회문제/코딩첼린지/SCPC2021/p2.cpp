/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
struct cmp {
	bool operator()(ii a, ii b) {
		if (a.second == b.second) {
			return a.first > b.first;
		}
		if (a.second > b.second) {
			return true;
		}
		return false;
	}
};
string Answer;
int N, t, l, r;
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
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
		Answer = "";
		int cnt = 0;
		cin >> N >> t;
		vector<int> A(N, -1); // -1 means un assigned
		vector<int> pos;
		pos.clear();
		string str;
		cin >> str;
		for (int i = 0; i < N; i++) {
			int temp = str.at(i) - '0';
			l = i - t;
			r = i + t;
			if (temp == 1) {
				if (l < 0) { // must 1
					cnt++;
					A[r] = 1;
				}
				else if (r >= N) { // must 1
					cnt++;
					A[l] = 1;
				}
				else {
					pos.push_back(i);
				}
			}
			else {// must 0
				if (l >= 0 && A[l] == -1) {
					cnt++;
					A[l] = 0;
				}
				if (r < N && A[r] == -1) {
					cnt++;
					A[r] = 0;
				}
			}
		}
		priority_queue <ii, vector<ii>, cmp> pq;
		for (int i = 0; i < (int)pos.size(); i++) {
			int temp = 0;
			l = pos[i] - t;
			r = pos[i] + t;
			if(l >= 0)
			temp += A[pos[i] - t] == -1 ? 1 : 0;
			if(r < N)
			temp += A[pos[i] + t] == -1 ? 1 : 0;
			if (temp == 0) continue;
			pq.push({pos[i],temp});
		}
		while (!pq.empty() && cnt != N) {
			ii cur = pq.top();
			pq.pop();
			l = cur.first - t;
			r = cur.first + t;
			int temp = 0;
			temp += A[l] == -1 ? 1 : 0;
			temp += A[r] == -1 ? 1 : 0;
			if (cur.second != temp) {
				if (temp == 0) {
					continue;
				}
				pq.push({ cur.first,temp });
				continue;
			}
			if (cur.second == 1) { // l or r un assigned
				if (A[l] == 1 || A[r] == 1) continue;
				if (A[r] == 0) {
					A[l] = 1;
				}
				else {
					A[r] = 1;
				}
				cnt++;
			}
			else { // l and r unassigned
				A[l] = 0;
				if (l - t >= 0) {
					if (str.at(l - t) == 1) {
						if (l - 2 * t >= 0) {
							temp = A[l - 2 * t] == -1 ? 1 : 0;
							if (temp != 0) {
								pq.push({ l - t,temp });
							}
						}
					}
				}
				A[r] = 1;
				cnt += 2;
			}
		}
		while (!pq.empty())pq.pop();
		for (int i = 0; i < N; i++) {
			if (A[i] == -1) {
				Answer += '0';
			}
			else Answer += A[i] + '0';
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << "\n" << Answer << "\n";
	}

	return 0;//Your program should return 0 on normal termination.
}
/*
머리속에 있던 알고리즘을 그대로 구현하는것엔 성공했으나
효율성을 따지자면 매우 많은부분을 실수해버렸다
b->a 의 변환 과정은 b의 첫원소부터 O(n) 의속도로 읽으며 greedy하게 해결할 수 있는 쉬운문제였으나
본인은 priority_queue 를 사용하여 최적요건부터 처리하려 했던것 때문에
알고리즘의 속도는 느린편 이였을것이라 예상한다.
*/
