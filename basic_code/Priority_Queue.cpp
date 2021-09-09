struct cmp{
  bool operator()(int a ,int b){
    return a > b;// make priority_queue in increasing order 
  }
};
priority_queue<int, vector<int>, cmp> pq;
