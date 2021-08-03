//GCD algorithm with Euclidean
int GCD(int a,int b){//find gcd {a,b}
  int temp;
  if(a < b) swap(a,b);
  while(b != 0){
    temp = a%b;
    a = b;
    b = n;
  }
  return a;
}


//Euclidean extension
//https://www.crocus.co.kr/1232
typedef pair<int,int> ii;
vector<int> s,t,r,q;
ii Extend_Euclid(int a, int b){
  /*
  in equation
  a*s + b*t = gcd(a,b)
  can be satisfied under euclidean extension
  
  in this function we can find s and t in every common divider {a & b}
  */
  s = {1,0};
  t = {0,1};
  r = {a,b};
  int S = 2;//size of array
  while(1){
    int r2 = r[S-2];
    int r1 = r[S-1];
    q.push_back(r2/r1);
    r.push_back(r2%r1);
    if(r[S] == 0) break;
    int s2 = s[S-2];
    int s1 = s[S-1];
    int t2 = t[S-2];
    int t1 = t[S-1];
    int q1 = q[S-2];
    s.push_back(s2 - s1*q1);
    t.push_back(t2 - t1*q1);
    S++;
  }
  return {s[S-1],t[S-1]};
}
