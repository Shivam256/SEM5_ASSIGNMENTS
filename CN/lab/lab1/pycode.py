import matplotlib.pyplot as plt
from scipy import signal
import numpy as np

x_axis = [0,0.5,1.0,1.5,2.0,2.5,3.0,3.5]
y_axis = [1,1,1,1,0,0,0,0]

s = "1011010101010"

temp = np.linspace(0,1,1000,endpoint=True)

# days=[0.0,0.5,1.0,1.5,1.99,2.0,2.5,3.0,4.0,4.5,5.0,5.5,6.0]
# y=[5,5,5,5,0,0,0,0,0,5,5,5,5]


# plt.plot(x_axis,y_axis)
plt.plot(temp,signal.square(2*np.pi*5*temp))
plt.title("line coding")
plt.show();