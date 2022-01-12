import numpy as np
import matplotlib.pyplot as plt
n = 1000
x1 = np.random.rand(n)
x2 = np.random.rand(n)
y = np.minimum(x1,x2)
z = np.maximum(x1,x2)
print(np.mean(y))
print(np.mean(z))
print(np.corrcoef(y,z))
