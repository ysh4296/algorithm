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
