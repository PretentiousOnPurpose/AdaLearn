import numpy as np

x1 = np.linspace(0.66, 1, 20000)
x2 = np.linspace(0.31, 0.65, 20000)
x3 = np.linspace(0, 0.3, 20000)
x4 = np.linspace(0, -1, 100000)
x5 = np.linspace(0, 1, 10000)

y = 1 * x1 + 0.5 * x2 + 2.75 * x3

X = 0

if X:
	for i in y:
		print(i)
else:
	for i in range(len(x1)):
		print(str(x1[i]) + "," + str(x2[i]) + "," + str(x3[i]))
