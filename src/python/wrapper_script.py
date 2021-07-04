# This script intends to run the executable files provided by the C++ code
import numpy as np
import matplotlib.pyplot as plt
import subprocess as sub
import os

if __name__ == '__main__':
	# print('This is a printout!!!')
	sub.run(["ls", "-ltr"])

	main_path = os.path.normpath('./build/main.o')
	test_path = os.path.normpath('./build/testing.o')

	sub.run([main_path])
	sub.run([test_path])
	# plt.figure(3, clear=True)
	# x = np.arange(0, 10, 1)
	# y = x**2
	# plt.plot(x, y)
	# plt.show()

