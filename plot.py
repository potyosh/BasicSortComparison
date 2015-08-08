#!/usr/bin/python

import pylab as pl
import numpy as np
import matplotlib.pyplot as plt

data_insertion = np.loadtxt('result_insertion.txt', delimiter=',')
data_bubble = np.loadtxt('result_bubble.txt', delimiter=',')
data_shell = np.loadtxt('result_shell.txt', delimiter=',')
data_selection = np.loadtxt('result_selection.txt', delimiter=',')

## bubble
x=data_bubble[:,0]
y=data_bubble[:,1]

plt.plot(x,y, '-', label="bubble")
plt.legend()

## selection
x=data_selection[:,0]
y=data_selection[:,1]

plt.plot(x,y, '--', label="selection")
plt.legend()

# insertion
x=data_insertion[:,0]
y=data_insertion[:,1]

plt.plot(x,y, 'o', label="insertion")
plt.legend()

## shell
x=data_shell[:,0]
y=data_shell[:,1]

plt.plot(x,y, '^', label="shell")
plt.legend()
plt.xlabel("Data Count")
plt.ylabel("Time[sec]")
#plt.show()
plt.savefig('result.png')

# X = np.linspace(-np.pi, np.pi, 256, endpoint=True)
# C, S = np.cos(X), np.sin(X)

# pl.plot(X, C)
# pl.plot(X, S)

# pl.show()