class Fenwick {
private:
	vector<int> tree;
public:
	Fenwick(int Size) {
		tree.resize(Size);
	}
	void update(int n, int diff) { // update node n
		while (n < tree.size()) {
			tree[n] += diff;
			n += (n & -n);
		}
	}
	int sum(int n) { // sum from 1 to n
		int ans = 0;
		while (n > 0) {
			ans += tree[n];
			n -= (n & -n);
		}
		return ans;
	}
};
