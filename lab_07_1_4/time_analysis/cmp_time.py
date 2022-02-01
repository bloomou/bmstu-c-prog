import matplotlib.pyplot as plt


def graph(number):
    mysort_data = []
    with open("time_mysort_" + str(number) + ".txt") as f:
        for line in f:
            mysort_data.append([float(x) for x in line.split()])

    qsort_data = []
    with open("time_qsort_" + str(number) + ".txt") as f:
        for line in f:
            qsort_data.append([float(x) for x in line.split()])

    x = [i for i in range(100, 1000, 100)]
    y1 = mysort_data
    y2 = qsort_data
    plt.xlabel("COUNT IN ARRAY")
    plt.ylabel("TIME")
    plt.grid()
    plt.title("TIME(COUNT)")
    plt.plot(x, y1, label="mysort")
    plt.plot(x, y2, label="qsort")
    plt.legend()
    plt.show()


for j in range(1, 4):
    graph(j)
