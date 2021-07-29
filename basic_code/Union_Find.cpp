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
