#!/usr/bin/env python3

"""

Classify what type of plant given a set of characteristics about the plant
Uses the following algorithms:

SVM Linear Multi-Classifier
Decision Tree Classifier
K-Means with Euclidean Distance Metric
K-Nearest Neighbors
Gaussian Naive Bayes

"""

import numpy as np
from sklearn.svm import SVC
from sklearn.tree import DecisionTreeClassifier
from sklearn.cluster import KMeans
from sklearn.neighbors import KNeighborsClassifier
from sklearn.preprocessing import StandardScaler
from sklearn.naive_bayes import GaussianNB
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

def readcsv(name):
    X = np.genfromtxt(name, delimiter=',', skip_header=1, usecols=(1, 2, 3, 4))
    t = np.genfromtxt(name, delimiter=',', skip_header=1, usecols=(5), dtype=None, encoding=None)
    m = {}
    i = 0
    for k in t:
        if k not in m:
            m[k] = i
            i += 1
    
    y = []
    for k in t:
        y.append(m[k])

    return X, np.array(y), len(m)

def main():
    X, Y, n_labels = readcsv('Iris.csv')

    # Split the data into a randomized training set and test set
    X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.2, random_state=None, stratify=Y)

    # Normalize the the data by subtracting the mean and scale by standard deviation
    sc = StandardScaler()
    sc.fit(X_train)
    X_train_std = sc.transform(X_train)
    X_test_std = sc.transform(X_test)

    # SVM classifier
    svm = SVC(kernel='linear', random_state=1, C=1)
    svm.fit(X_train_std, Y_train)

    # Decision tree classfier
    dtc = DecisionTreeClassifier()
    dtc.fit(X_train_std, Y_train)

    # K-Means
    km = KMeans(n_clusters=n_labels, n_init="auto")
    km.fit(X_train_std)

    # K-Nearest Neighbors
    knn = KNeighborsClassifier()
    knn.fit(X_train_std, Y_train)

    # Gaussian Naive Bayes
    gnb = GaussianNB()
    gnb.fit(X_train_std, Y_train)

    # Check performance
    Y_pred = svm.predict(X_test_std)
    print('SVM Accuracy: %.3f' % accuracy_score(Y_test, Y_pred))

    Y_pred = dtc.predict(X_test_std)
    print('DTC Accuracy: %.3f' % accuracy_score(Y_test, Y_pred))

    Y_pred = km.predict(X_test_std)
    print('KM Accuracy: %.3f' % accuracy_score(Y_test, Y_pred))

    Y_pred = knn.predict(X_test_std)
    print('KNN Accuracy: %.3f' % accuracy_score(Y_test, Y_pred))

    Y_pred = gnb.predict(X_test_std)
    print('GNB Accuracy: %.3f' % accuracy_score(Y_test, Y_pred))

main()
