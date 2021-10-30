from functools import cmp_to_key


def compare(A,B):
    if(A[1] > B[1]): return 1
    elif(A[1] < B[1]): return -1
    else:
        if(A[0] < B[0]): return 1
        elif(A[0] > B[0]): return -1
        else: return 0

def dist(A,B):
    return pow(A[0] - B[0],2) + pow(A[1] - B[0],2)

def CCW(A,B,C):
    return (B[0] - A[0])*(C[1] - A[1]) - (C[0] - A[0])*(B[1] - A[1])

def degree_compare(A,B): # A 가 B 보다 큼
    cc = CCW(S_point,A,B)
    if(cc > 0): return 1
    elif(cc < 0): return -1

    disa = dist(S_point, A)
    disb = dist(S_point, B)
    if(disa < disb):
        return -1
    elif(disa == disb): return 0
    return 1

def Convex_Hull(list):
    list.insert(0,S_point.copy())
    list.insert(len(list),S_point.copy())
    print("new list  " , list)
    result = []
    result.append(list[0].copy())
    result.append(list[1].copy())
    next = 2
    length = len(list)
    while next < length:
        while len(result) >= 2:
            second = result.pop(-1)
            first = result[-1].copy()
            if(CCW(first,list[next],second) > -0.001):
                result.append(second)
                break
        result.append(list[next])
        next+=1
    return result

S_point = [0,0]

list = []

list.append([0,0])
list.append([1,0])
list.append([2,0])
list.append([3,0])
list.append([3,1])
list.append([3,2])
list.append([3,3])
list.append([2,3])
list.append([1,3])
list.append([0,3])
list.append([0,2])
list.append([0,1])
list.append([1,1])
list.append([1,2])
list.append([2,1])
list.append([2,2])
list.append([3,2])

list = sorted(list, key = cmp_to_key(compare))

print(list)
S_point = list[0].copy()
print("S   :   ",S_point)
list = list[1:]
list = sorted(list,key = cmp_to_key(degree_compare))

pl = S_point.copy()
pc = list[-1]
reverse = []

while True:
    item = list.pop(-1)
    print(reverse)
    if(CCW(pl,pc,item) != 0):
        list.append(item)
        for i in reverse:
            list.append(i)
        break
    reverse.append(item)


print(list)

list = Convex_Hull(list)

print("convex-hull  ;  ",list)

# 개인적으로 만든 convexhull algorithm
# 해당 알고리즘에서 겉표면을 최대한 자세하게 분석하기 위해 보이는 모든 표면의 점을 계산하였다.
# 이과정에서 CCW > 0.001 과 마지막 직선의 정렬을 거꾸로 돌리는 연산을 하였다.
