import numpy as np
import matplotlib.pyplot as plt

# y = w1 + w2*x
# x_t = [[1, 1, 1, ..., 1], [x1, x2, x3, ..., xn]]
# x = transpose(x)
# so, y = x*w
#x_t = np.array(((1, 1, 1, 1, 1), (1, 2, 3, 4, 5)))
#x = np.transpose(x_t)
#y = np.array((3, 5, 7, 11, 14))

np.random.seed(0)

n_samples = 100 # number of samples

x_t = np.array((np.ones(n_samples), np.linspace(0, 10, n_samples)))
x = np.transpose(x_t)
noise = np.random.normal(0, 2, n_samples)
slope = 1
intercept = 5
y = slope * x[:,1] + intercept + noise

w = np.array([0, 0]) # weights
lr = 0.01 # learning rate

w_log = []
loss_log = []
check = True

while check:
    w_log.append(w)
    y_hat = np.matmul(x, w)
    n = len(y_hat)
    mse = 1/n * np.sum((y - y_hat) ** 2) # same as J
    grad_mse = 2/n * np.matmul(x_t, np.matmul(x, w) - y) # grad_w J

    loss_log.append(mse)
    print (f'W: {w}, J: {mse}')

    # update weights
    if np.linalg.norm(grad_mse) > 1e-6 or len(w_log) <= 1:
        w = w - lr * grad_mse
    else:
        w = w_log[-2] # previous one (-1 is already pushed current w value)
        check = False

print(f'optimal parameters: {w}')

ls = list(range(0, len(loss_log)))
plt.plot(ls, loss_log)
plt.xlabel("Iteration")
plt.ylabel("Loss")
plt.title("Loss vs. Iteration")
plt.show()

