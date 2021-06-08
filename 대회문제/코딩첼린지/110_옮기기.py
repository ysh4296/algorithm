from collections import deque
def solution(s):
    answer = []
    cnt = 0
    for st in s:
        stack = []
        cnt = 0
        for c in st:
            if c == '0':
                if stack[-2:] == ['1','1']:
                    cnt+=1
                    stack.pop()
                    stack.pop()
                else:
                    stack.append(c)
            else:
                stack.append(c)
            #stack store st without '110'
        if cnt == 0: #no '110' in st
            answer.append(st)
        else: #find '110' in st
            temp = deque()
            while stack:
                if stack[-1] == '1':
                    temp.append(stack.pop())
                elif stack[-1] == '0':
                    break

            while cnt > 0:
                temp.appendleft('0')
                temp.appendleft('1')
                temp.appendleft('1')
                cnt -= 1
            while stack:
                temp.appendleft(stack.pop())
            answer.append(''.join(map(str,temp)))
    return answer
  """
  1. '110'을 전부 뽑아낸다
  
  2. 사전순으로 110보다 늦은(110의 앞에 올 수 없는) 문자열은 111 밖에 없다.
  이를 검색하여 이중 첫번째 위치 앞에 110을 몰빵
  
  3. 만약 없다면 110을 맨뒤로
  """
