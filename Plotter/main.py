import matplotlib.pyplot as plt
import math as m
import numpy as np

if __name__ == '__main__':
    meanArray = np.empty(6)
    meanArray[0] = np.mean(np.loadtxt("100.txt", delimiter=" ")[:, 3])
    meanArray[1] = np.mean(np.loadtxt("1000.txt", delimiter=" ")[:, 3])
    meanArray[2] = np.mean(np.loadtxt("10000.txt", delimiter=" ")[:, 3])
    meanArray[3] = np.mean(np.loadtxt("100000.txt", delimiter=" ")[:, 3])
    meanArray[4] = np.mean(np.loadtxt("1000000.txt", delimiter=" ")[:, 3])
    meanArray[5] = np.mean(np.loadtxt("10000000.txt", delimiter=" ")[:, 3])

    stdArray = np.zeros(6)
    stdArray[0] = np.sqrt(np.var(np.loadtxt("100.txt", delimiter=" ")[:, 3]))
    stdArray[1] = np.sqrt(np.var(np.loadtxt("1000.txt", delimiter=" ")[:, 3]))
    stdArray[2] = np.sqrt(np.var(np.loadtxt("10000.txt", delimiter=" ")[:, 3]))
    stdArray[3] = np.sqrt(np.var(np.loadtxt("100000.txt", delimiter=" ")[:, 3]))
    stdArray[4] = np.sqrt(np.var(np.loadtxt("1000000.txt", delimiter=" ")[:, 3]))
    stdArray[5] = np.sqrt(np.var(np.loadtxt("10000000.txt", delimiter=" ")[:, 3]))

    testArrayX = np.array([100, 1000, 10000, 100000, 1000000, 10000000])

    print(meanArray)
    print(meanArray-m.pi)
    print(stdArray)

    convX = np.linspace(100, 10000000, 10000)

    plt.rcParams['font.size'] = '16'
    plt.rcParams.update({"text.usetex": True})
    plt.title("$\widehat{\sigma_{\pi}}$ for certain $N$\n"
              "$L_0=D_0=1.0$\nIterations per datapoint=1000")
    widths = np.sort(testArrayX)/2
    plt.bar(testArrayX, stdArray, widths, align='center', label="$\widehat{\sigma_{\pi}}$ From simulation")
    plt.plot(testArrayX, (m.pi/np.sqrt(testArrayX)) * (np.sqrt((m.pi/2)-1)),
             label="$\widehat{\sigma_{\pi}} = \\frac{\pi}{\sqrt{N}}\sqrt{\\frac{\pi}{R}-1}$", color='red', marker='x')
    plt.xscale("log")
    plt.yscale("log")
    plt.xlabel("Number of needles $N$")
    plt.ylabel("Uncertainty in $\pi$")
    plt.grid()
    plt.legend()
    plt.show()
