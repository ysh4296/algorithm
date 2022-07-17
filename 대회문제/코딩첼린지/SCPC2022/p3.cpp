/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101010

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

ll Answer;
vector<ii> points;
vector<int> rowLines[101010], columnLines[101010];
vector<int> rowList, columnList;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int errorRow = -1, errorColumn = -1;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int row, column;
			cin >> row >> column;
			rowList.push_back(row);
			columnList.push_back(column);
			points.push_back({ row,column });
		}
		sort(rowList.begin(), rowList.end());
		sort(columnList.begin(), columnList.end());
		rowList.erase(unique(rowList.begin(),rowList.end()),rowList.end());
		columnList.erase(unique(columnList.begin(), columnList.end()),columnList.end());
		Answer = 0;
		for (int i = 0; i < N; i++) {
			ii cur = points[i];
			rowLines[lower_bound(rowList.begin(), rowList.end(), cur.first) - rowList.begin()].push_back(cur.second);
			columnLines[lower_bound(columnList.begin(), columnList.end(), cur.second) - columnList.begin()].push_back(cur.first);
		}
		//find error
		for (int i = 0; i < (int)rowList.size(); i++) {
			if ((int)rowLines[i].size() % 2 != 0) {
				errorRow = i;
				continue;
			}
			sort(rowLines[i].begin(),rowLines[i].end());
			for (int j = 0; j < (int)rowLines[i].size(); j+=2) {
				Answer += rowLines[i][j + 1] - rowLines[i][j];
			}
		}
		for (int i = 0; i < (int)columnList.size(); i++) {
			if ((int)columnLines[i].size() % 2 != 0) {
				errorColumn = i;
				continue;
			}
			sort(columnLines[i].begin(), columnLines[i].end());
			for (int j = 0; j < (int)columnLines[i].size(); j+=2) {
				Answer += columnLines[i][j + 1] - columnLines[i][j];
			}
		}
		//solve error
		if (errorRow != -1 && errorColumn != -1) {
			rowLines[errorRow].push_back(columnList[errorColumn]);
			sort(rowLines[errorRow].begin(), rowLines[errorRow].end());
			columnLines[errorColumn].push_back(rowList[errorRow]);
			sort(columnLines[errorColumn].begin(), columnLines[errorColumn].end());
			for (int j = 0; j < (int)rowLines[errorRow].size(); j += 2) {
				Answer += rowLines[errorRow][j + 1] - rowLines[errorRow][j];
				}
			for (int j = 0; j < (int)columnLines[errorColumn].size(); j += 2) {
				Answer += columnLines[errorColumn][j + 1] - columnLines[errorColumn][j];
				}
		}
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
		for (int i = 0; i < (int)rowList.size(); i++)rowLines[i].clear();
		for (int i = 0; i < (int)columnList.size(); i++) columnLines[i].clear();
		rowList.clear();
		columnList.clear();
		points.clear();
	}
	return 0;
}
