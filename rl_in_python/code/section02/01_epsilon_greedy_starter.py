import matplotlib.pyplot as plt
import numpy as np

NUM_TRIALS = 1000
EPS = 0.1
BANDIT_PROBABILITIES = [0.2, 0.5, 0.75]

class Bandit:
    def __init__(self, p):
        # p: win rate
        self.p = p
        self.p_estimate = 
        self.N = 

    def pull(self):
        # draw a 1 with probability p
        return np.random.random() < self.p

    def update(self, x):
        self.N = 
        self.p_estimate =

def experiment():
    bandits = [Bandit(p) for p in BANDIT_PROBABILITIES]

    rewards = np.zeros(NUM_TRIALS)
    num_times_explored = 0
    num_times_exploited = 0
    num_optimal = 0
    optimal_j = np.argmax([b.p for b in bandits])
    print("optimal j: ", optimal_j)

    for i in range(NUM_TRIALS):
        # use epsilon-greedy to select the next bandit
        if np.random.random() < EPS:
            num_times_explored += 1
            j = 
        else:
            num_times_exploited += 1
            j = 

        if j == optimal_j:
            num_optimal += 1

        # pull the arm of the bandit with the largest sample
        x = bandits[j].pull()

        # update rewards log
        reward[i] = x

        # update the distribution for the bandit whose arm we just pulled
        bandits[j].update(x)

    # print mean estimates for each bandit
    for b in bandits:
        print("mean estimate: ", b.p_estimate)

    # print total reward
    print("total reward earned: ", rewards.sum())
    print("overall win rate: ", rewards.sum()/NUM_TRIALS)
    print("num_times_explored: ", num_times_explored)
    print("num_times_exploited: ", num_times_exploited)
    print("num times selected optimal bandit: ", num_optimal)

    # plot the results
    cumulative_rewards = np.cumsum(rewards)
    win_rates = cumulative_rewards/(np.arange(NUM_TRIALS) + 1)
    plt.plot(win_rates)
    plt.plot(np.ones(NUM_TRIALS)*np.max(BANDIT_PROBABILITIES))
    plt.show()

if __name__ == "__main__":
    experiment()
