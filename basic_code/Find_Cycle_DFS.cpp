int visit[MAX];
bool dfs(int cur){
  if(visit[cur]) return visit[cur] == -1;
  /*
  if cur node is un finished it found cycle
  if cur node is finished it is not cycle
  */
  visit[cur] = -1;// cur node is started
  for(int next : graph[cur]){
    if(dfs(next)) return true; // 
  }
  visit[cur] = 1;//cur node finished
  return false;//in this root we can't find cycle
}
