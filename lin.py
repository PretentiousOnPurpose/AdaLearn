import numpy as np

x1 = np.linspace(100, 750, 500)
# x2 = np.linspace(2, 10, 500)

y = 2 * x1 + 3

X = 1

if X:
	for i in y:
		print(i)
else:
	for i in range(len(x1)):
		print(str(x1[i]) + "," + str(x2[i]))
