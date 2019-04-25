import numpy as np
import sys
import time

# y = np.random.normal(0, 1.5, (int(sys.argv[1]), int(sys.argv[2])))

np.random.seed(int(time.time()))	
y = np.random.normal(0, 0.25, (int(sys.argv[1]), int(sys.argv[2]))) / 5

end1 = ""
end2 = ""

for i in range(len(y)):
    for j in range(len(y[0])):

        if j != len(y[0])-1:
            end1 = ","
        elif i == len(y)-1 and j == len(y[0])-1:
            end1 = ""
        else:
            end1="\n"

        print(y[i][j], end = end1)
    
