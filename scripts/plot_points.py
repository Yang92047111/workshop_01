from matplotlib import pyplot as plt
import numpy as np
import csv

x=[]
y=[]
with open("../data/test.csv",'r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(float(row[0]))
        # print("x:", x)
        y.append(float(row[1]))
        # print("y:", y)

x_rot = []
y_rot = []
with open("../data/rectangle_points10_retated.csv",'r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x_rot.append(float(row[0]))
        # print("x:", x)
        y_rot.append(float(row[1]))
        # print("y:", y)
#畫折線圖
plt.scatter(x, y)
plt.scatter(x_rot, y_rot)
plt.xlabel('x')
plt.ylabel('y')
plt.xlim(-5, 5)
plt.ylim(-5, 5)
# plt.legend()
plt.show()