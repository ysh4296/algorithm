import sys
import pandas as pd
from sklearn import linear_model

# 데이터 세팅
dataset = pd.read_csv('trainingdata.txt', header=None)

# 과충전된 경우를 학습에서 제외한다
dataset = dataset[dataset.iloc[:,1] < 8]

dataset.insert(0, len(dataset.columns), 0)

# X( 충전 시간 ) 와 Y( 사용량 ) 에 대한 데이터를 뽑아낸다
X = dataset.iloc[:,1].to_numpy()
Y = dataset.iloc[:,2].to_numpy()

# LinearRegression을 위한 객체 생성  및 학습
model = linear_model.LinearRegression()
model.fit(X.reshape(-1,1), Y)

# 결과 예측,
# 베터리 총 용량이 8시간이기 때문에 이경우에 주의한다.
timeCharged = float(input().strip())
result = model.predict([[timeCharged]])
if result[0] > 8:
    print (8.0)
else:
    print (round(result[0],2))
