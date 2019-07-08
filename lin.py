# import numpy as np
#
# x1 = np.linspace(0.1, 0.75, 20000)
# x2 = np.linspace(0.35, 0.55, 20000)
#
# y = 0.25 * x1 + 0.9 * x2
#
# X = 1
#
# if X:
# 	for i in y:
# 		print(i)
# else:
# 	for i in range(len(x1)):
# 		print(str(x1[i]) + "," + str(x2[i]))


import numpy as np

x1 = np.linspace(0.1, 0.75, 20000)
x2 = np.linspace(0.35, 0.55, 20000)

y = 0.5 * x1;

for i in x1:
	print(i)
