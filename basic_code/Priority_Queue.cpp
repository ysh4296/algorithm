struct cmp{
  bool operator()(int a ,int b){
    return a > b;// make priority_queue in increasing order 
  }
};

priority_queue<int, vector<int>, cmp> pq;

struct Point {
    public:
        int value,row,column;
        Point(int v, int r, int c) { // constructor
            value = v;
            row = r;
            column = r;
        } 
};

struct compare {
    bool operator()(Point &a, Point &b) {
        if(a.value != b.value) return a.value > b.value; // smaller value comes top
        else if(a.row != b.row) return  a.row > b.row; // smaller row comes top
        else if (a.column != b.column) return a.column > b.column; // smaller column comes top
        else return true;
    };
};

priority_queue <Point,vector<Point>,compare> pq;
