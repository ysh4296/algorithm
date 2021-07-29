int indegree[MAX];
vector<int> adj[MAX];
int result[MAX];
queue<int> q;
for (int i = 1; i <= N; i++) {
  if (indegree[i] == 0) q.push(i);
}
int cnt = 0;
while (!q.empty() && cnt < N) {
  int cur = q.front();
  q.pop();
  cnt++;
  result[cnt] = cur;
  for (int next : adj[cur]) {
    if (--indegree[next] == 0) {
      q.push(next);
    }
  }
}
if (cnt < N) { // can't reach every node == found cycle
  cout << 0 << "\n";
}
else {//print sorted order
  for (int i = 1; i <= N; i++) {
    cout << result[i] << "\n";
  }
}
//in this method we can find cycle in DAG
