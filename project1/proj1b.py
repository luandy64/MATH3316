import matplotlib.pyplot as plt
import numpy as np

# Importing Data
n = np.loadtxt('n.txt')
h = np.loadtxt('h.txt')
r = np.loadtxt('r.txt')
R = np.loadtxt('upper.txt')

# Plotting n vs. r and n vs. R
plt.figure(1)
plt.semilogy(n, r, 'b-', n, R, 'r--')
plt.title('Plotting r vs. n and R vs. n')
plt.xlabel('2^n')
plt.ylabel('relative error')
plt.show()

# Plotting r vs. h and R vs. h
plt.figure(2)
plt.loglog(h, r, 'b-', h, R, 'r--')
plt.title('Plotting h vs. r and h vs. R')
plt.xlabel('h = 2 ^ x')
plt.ylabel('relative error')
plt.show()
