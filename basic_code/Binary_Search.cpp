int binary_search(int target){
  int l = 0;
  int r = n-1;
  while(l <= r){
    int mid = (l+r)/2;
    if(list[mid] < target){
      l = mid+1;
    }
    else if(list[mid] > target){
      r = mid-1;
    }
    else{
      return 1; // found target 
    }
  }
  return 0;// non found
}

int find_lower_index(vector<int> a, int value) {
	int r = (int)a.size(), l = 0, m;
	while (l < r) {
		m = (l + r) / 2;
		if (a[m] < value) {
			l = m+1;
		}
		else {
			r = m;
		}
	}
	return l;
}

int find_upper_index(vector<int>a, int value) {
	int r = (int)a.size(), l = 0, m;
	while (l < r) {
		m = (l + r) / 2;
		if (a[m] <= value) {
			l = m + 1;
		}
		else {
			r = m;
		}
	}
	return l;
}
