dp = []#dp of weight
item_list = []
def quick_sort(arr,i):
    def sort(low,high):
        if high <= low:
            return
        mid = partition(low,high)
        sort(low,mid-1)
        sort(mid,high)
    def partition(low,high):
        pivot = arr[(low+high)//2][i]
        while low <= high:
            while arr[low][i] > pivot:
                low += 1
            while arr[high][i] < pivot:
                high -=1
            if low <= high:
                arr[low],arr[high] = arr[high],arr[low]
                low,high = low + 1,high-1
            return low
    return sort(0,len(arr)-1)

if __name__ == '__main__':
    n = int(input())
    cap = int(input())
    item = [[0, 0 , 0]for i in range(n)]
    item_list = [[[] for i in range(cap+1)]for j in range(n+1)]
    dp = [[0 for i in range(cap+1)]for j in range(n+1)]
    for i in range(n):
        item[i][0] = int(input()) # weight
        item[i][1] = int(input()) # value
        item[i][2] = i+1
    quick_sort(item,1)
    print("sort with value : ",item)
    quick_sort(item,0)
    print("sort with weight : ",item)
    for i in range(n):
        w = item[i][0]
        v = item[i][1]
        for p in range(cap+1):
            if dp[i][p] <= v + dp[i][p - w] and p >= w: # add new item
                dp[i+1][p] = v + dp[i][p - w]
                item_list[i+1][p] = item_list[i][p-w][:]
                item_list[i+1][p].append(item[i][2])
            else:
                dp[i+1][p] = dp[i][p]# same with prev
                item_list[i+1][p] = item_list[i][p][:]
    print("the max value of napsack is : ",dp[n][cap])
    print("the optimized item is : ",item_list[n][cap])
