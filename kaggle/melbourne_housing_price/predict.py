#!/usr/bin/env python3

"""

Given a set of house characteristics, predict the price
Use a decision tree regressor to do this. The regressor automatically generates a decision tree based on the features given

"""

import pandas as pd
from sklearn.tree import DecisionTreeRegressor, export_graphviz

def main():
    melbourne_data = pd.read_csv("melb_data.csv")
    melbourne_data = melbourne_data.dropna(axis=0)
    
    melbourne_features = ['Rooms', 'Bathroom', 'Landsize', 'Lattitude', 'Longtitude']

    Y = melbourne_data.Price
    X = melbourne_data[melbourne_features]
    
    melbourne_model = DecisionTreeRegressor(random_state=1)
    melbourne_model.fit(X, Y)

    print("Making predictions for the following 5 houses:")
    print(X.head())
    print("The predictions are")
    print(melbourne_model.predict(X.head()))

    export_graphviz(melbourne_model, out_file ='tree.dot', feature_names=melbourne_features)  

main()
