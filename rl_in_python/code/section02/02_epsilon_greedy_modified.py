import matplotlib.pyplot as plt
import numpy as np

np.random.seed(100)

class Bandit:
    def __init__(self, m):
        # p: win rate
        self.m = m
        self.m_estimate = 0. # initially 0
        self.N = 0. # initially 0

    def pull(self):
        # draw a 1 with probability p
        #return np.random.random() < self.p
        return np.random.randn() + self.m

    def update(self, x):
        self.N += 1 # add 1 to total number of sample collected until now
        #self.p_estimate = self.p_estimate + (x - self.p_estimate)/self.N # update current estimate
        self.m_estimate = ((self.N - 1)*self.m_estimate + x) / self.N

def run_exp(m1, m2, m3, eps, N):
    bandits = [Bandit(m1), Bandit(m2), Bandit(m3)]

    # count number of suboptimal choices
    means = np.array([m1, m2, m3])
    true_best = np.argmax(means)
    count_suboptimal = 0
    
    data = np.empty(N)

    for i in range(N):
        # epsilon greedy
        p = np.random.random()
        if p < eps:
            j = np.random.choice(len(bandits))
        else:
            j = np.argmax([b.m_estimate for b in bandits])
        x = bandits[j].pull()
        bandits[j].update(x)

        if j != true_best:
            count_suboptimal += 1

        # for the plot
        data[i] = x

    cumulative_average = np.cumsum(data) / (np.arange(N) + 1)

    plt.plot(cumulative_average)
    plt.plot(np.ones(N)*m1)
    plt.plot(np.ones(N)*m2)
    plt.plot(np.ones(N)*m1)
    plt.xscale('log')
    plt.show()

    for b in bandits:
        print(b.m_estimate)

    print("percent suboptimal for epsiolon = %s: " %eps, float(count_suboptimal)/N)

    return cumulative_average

if __name__ == "__main__":
    m1, m2, m3 = 1.5, 2.5, 3.5
    c_1 = run_exp(m1, m2, m3, 0.1, 100000)
    c_05 = run_exp(m1, m2, m3, 0.05, 100000)
    c_01 = run_exp(m1, m2 ,m3, 0.05, 100000)

    # log scale plot
    plt.plot(c_1, label='eps = 0.1')
    plt.plot(c_05, label='eps = 0.05')
    plt.plot(c_01, label='eps = 0.01')
    plt.legend()
    plt.xscale('log')
    plt.show()

    # linear plot
    plt.plot(c_1, label='eps = 0.1')
    plt.plot(c_05, label='eps = 0.05')
    plt.plot(c_01, label='eps = 0.01')
    plt.legend()
    plt.show()

