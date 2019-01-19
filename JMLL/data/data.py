# Python file to create data for sk-learn to use for the c++ library
###  Imports  ###
import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs
from matplotlib.colors import ListedColormap

###  Parameters  ###
n_training_samples = 200
n_testing_samples = 200
n_features = 2
n_classes = 2
center_box = (-5, 5)
cluster_std = 0.5
seed = 1



# Makes the plot colours more distiguishable when more than 2 classes
colors_list = ['red', 'cyan', 'magenta', 'green', 'black', 'blue']
colors = ListedColormap(colors_list)



###  Dataset  ###
# Training Set
x_train, y_train_raw = make_blobs(n_samples = n_training_samples, 
	n_features = n_features,
	centers = n_classes,
	center_box = center_box,
	cluster_std =  cluster_std, 
	random_state = seed)
# Categorically encode the label data for training
y_train = np.zeros((y_train_raw.shape[0], n_classes))
y_train[np.arange(y_train_raw.size), y_train_raw] = 1

# Testing Set
x_test, y_test = make_blobs(n_samples = n_training_samples + n_testing_samples, 
	n_features = n_features,
	centers = n_classes,
	center_box = center_box,
	cluster_std =  cluster_std, 
	random_state = seed)
x_test = x_test[-n_testing_samples:]
y_test = y_test[-n_testing_samples:]



###  Figures  ###
# Training Set
plt.scatter(x_train[:, 0], x_train[:, 1], c = y_train_raw, cmap = colors)
plt.draw()
plt.savefig('train_set.png')
plt.close()
# Testing Set
plt.scatter(x_test[:, 0], x_test[:, 1], c = y_test, cmap = colors)
plt.draw()
plt.savefig('test_set.png')
plt.close()



###  Save Data to CSV Files  ###
np.savetxt('train_x.csv', x_train, delimiter = ',')
np.savetxt('train_y.csv', y_train, delimiter = ',')
np.savetxt('test_x.csv', x_test, delimiter = ',')
np.savetxt('test_y.csv', y_test, delimiter = ',')



###  END OF FILE  ###