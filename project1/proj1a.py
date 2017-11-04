import matplotlib.pyplot as plt
import numpy as np

# Importing Data
xval = np.loadtxt('z.txt')
ex = np.loadtxt('f.txt')
p4 = np.loadtxt('p4.txt')
p8 = np.loadtxt('p8.txt')
p12 = np.loadtxt('p12.txt')
err4 = np.loadtxt('err4.txt')
err8 = np.loadtxt('err8.txt')
err12 = np.loadtxt('err12.txt')

# Plotting functions
plt.figure(1)
plt.plot(xval, ex, 'r--', xval, p4, 'b--', xval, p8, 'g--', xval, p12, 'k--')
plt.xlabel('x')
plt.ylabel('y')
plt.title('f(x) = e^x and Taylor Polynomials')
plt.show()

plt.figure(2)
plt.subplot(221)
plt.plot(xval, ex, 'r--')
plt.xlabel('x')
plt.ylabel('y')
plt.title('f(x) = e^x')

plt.subplot(222)
plt.plot(xval, p4, 'b--')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Taylor Polynomial of degree 4')

plt.subplot(223)
plt.plot(xval, p8, 'g--')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Taylor Polynomial of degree 8')

plt.subplot(224)
plt.plot(xval, p12, 'k--')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Taylor Polynomial of degree 12')

# Pad subplots to stop overlap
plt.tight_layout(pad=1)
plt.show()

# Plotting Error
plt.figure(1)
plt.semilogy(xval, err4, 'b--', xval, err8, 'g--', xval, err12, 'k--')
plt.xlabel('x')
plt.ylabel('Absolute Error')
plt.title('Errors in Taylor Polynomial')
plt.show()
