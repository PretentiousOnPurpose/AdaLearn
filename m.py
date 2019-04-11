import numpy as np
import pandas as pd

ds = pd.read_csv('d.csv')
X = np.array(ds.iloc[: , 1:-1].values)
y_temp = np.array(ds.iloc[: , -1:])
y = []
for i in y_temp:
    if i == 'M':
        y.append(1)
    elif i == 'B':
        y.append(0)
        
w = np.random.rand(31)

from sklearn.preprocessing import MinMaxScaler
MMS = MinMaxScaler()
MMS.fit(X)
X = MMS.transform(X)
X = np.append(arr=np.ones((569, 1)), values=X, axis=1)
from sklearn.model_selection import train_test_split
xtr, xts,  ytr, yts = train_test_split(X, y, test_size=0.2)

def train(xtr, ytr, steps):
    for s in range(steps):
        for i in range(len(xtr)):
            y = np.array(xtr[i]).dot(w)
            err = ytr[i] - sigmoid(y)
            # err = sigmoid(y) * (1 - sigmoid(y));
            backprop(err, xtr[i], 0.05)
            print(err)
            
def test(xts, yts):
    acc = 0
    for i in range(len(xts)):
        y = np.array(xts[i]).dot(w)
        if sigmoid(y) > 0.5 and yts[i] == 1:
            acc += 1
        elif sigmoid(y) <= 0.5 and yts[i] == 0:
            acc += 1
            
    return acc/len(xts)

def Predict(InV):
    if sigmoid(np.array(InV).dot(w)) > 0.5:
        print("Yes, Cancer Detected")
    else:
        print("No , Cancer")

def backprop(error, inp, rate):
    for i in range(len(w)):
        w[i] = w[i] + rate*error*inp[i]
        
def sigmoid(X):
    return 1/(1+np.exp(-X))

train(xtr, ytr,100)
print(test(xts , yts))
