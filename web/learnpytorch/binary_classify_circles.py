#!/usr/bin/env python3

"""

Given sample of points and labels with which of the two circles that point correspond to;
The task is to do binary classification, given a point, figure out which circle it belongs to.

One circle always has a larger radius than the circle with a smaller radius
The sample points can be "noisy", not necessarily on the circle exterior exactly, but is located near the radius.

This problem can be solved just by adding more layers with higher number of hidden weights

"""

from sklearn.datasets import make_circles
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
import torch
from torch import nn

class CircleModelV0(nn.Module):
    def __init__(self):
        super().__init__()
        self.layer_1 = nn.Linear(in_features=2, out_features=5)
        self.layer_2 = nn.Linear(in_features=5, out_features=1)

    def forward(self, x):
        x = self.layer_1(x)
        x = self.layer_2(x)
        return x

class CircleModelV2(nn.Module):
    def __init__(self):
        super().__init__()
        self.layer_1 = nn.Linear(in_features=2, out_features=1000)
        self.layer_2 = nn.Linear(in_features=1000, out_features=1000)
        self.layer_3 = nn.Linear(in_features=1000, out_features=1000)
        self.layer_4 = nn.Linear(in_features=1000, out_features=1)
        self.relu = nn.ReLU() # <- add in ReLU activation function
        # Can also put sigmoid in the model 
        # This would mean you don't need to use it on the predictions
        # self.sigmoid = nn.Sigmoid()

    def forward(self, x):
      # Intersperse the ReLU activation function between layers
       return self.layer_4(self.layer_3(self.relu(self.layer_2(self.relu(self.layer_1(x))))))


def plot_circles(X, y):
    plt.scatter(x=X[:, 0], y=X[:, 1], c=y, cmap=plt.cm.RdYlBu)
    plt.savefig('two_circles.png', dpi=300, bbox_inches='tight')

def accuracy_fn(y_true, y_pred):
    correct = torch.eq(y_true, y_pred).sum().item() # torch.eq() calculates where two tensors are equal
    acc = (correct / len(y_pred)) * 100 
    return acc

def train_it(device, model, X_train, X_test, y_train, y_test):
    # Set the number of epochs
    epochs = 100

    # Put data to target device
    X_train, y_train = X_train.to(device), y_train.to(device)
    X_test, y_test = X_test.to(device), y_test.to(device)

    loss_fn = nn.BCEWithLogitsLoss()
    optimizer = torch.optim.SGD(params=model.parameters(), lr=0.1)
    # Build training and evaluation loop
    print("Starting training")
    for epoch in range(epochs):
        ### Training
        model.train()

        # 1. Forward pass (model outputs raw logits)
        y_logits = model(X_train).squeeze() # squeeze to remove extra `1` dimensions, this won't work unless model and data are on same device 
        y_pred = torch.round(torch.sigmoid(y_logits)) # turn logits -> pred probs -> pred labls
      
        # 2. Calculate loss/accuracy
        # loss = loss_fn(torch.sigmoid(y_logits), # Using nn.BCELoss you need torch.sigmoid()
        #                y_train) 
        loss = loss_fn(y_logits, # Using nn.BCEWithLogitsLoss works with raw logits
                       y_train) 
        acc = accuracy_fn(y_true=y_train, 
                          y_pred=y_pred) 

        # 3. Optimizer zero grad
        optimizer.zero_grad()

        # 4. Loss backwards
        loss.backward()

        # 5. Optimizer step
        optimizer.step()

        ### Testing
        model.eval()
        with torch.inference_mode():
            # 1. Forward pass
            test_logits = model(X_test).squeeze() 
            test_pred = torch.round(torch.sigmoid(test_logits))
            # 2. Caculate loss/accuracy
            test_loss = loss_fn(test_logits,
                                y_test)
            test_acc = accuracy_fn(y_true=y_test,
                                   y_pred=test_pred)

        # Print out what's happening every 10 epochs
        if epoch % 10 == 0:
            print(f"Epoch: {epoch} | Loss: {loss:.5f}, Accuracy: {acc:.2f}% | Test loss: {test_loss:.5f}, Test acc: {test_acc:.2f}%")


def main():
    # create 2 circles and their labels
    n_samples = 10000
    X, y = make_circles(n_samples, noise=0.03, random_state=42)
    
    plot_circles(X, y)
    
    # turn into tensor for training
    X = torch.from_numpy(X).type(torch.float)
    y = torch.from_numpy(y).type(torch.float)

    # split 20% test, 80% train
    X_train, X_test, y_train, y_test = train_test_split(X,
                                                    y,
                                                    test_size=0.2,
                                                    random_state=42) 

    device = "cuda" if torch.cuda.is_available() else "cpu"
    model_0 = CircleModelV0().to(device)
    model_2 = CircleModelV2().to(device)
    
    # show untrained predictions before training
    untrained_preds = model_0(X_test.to(device))
    print(f"Length of predictions: {len(untrained_preds)}, Shape: {untrained_preds.shape}")
    print(f"Length of test samples: {len(y_test)}, Shape: {y_test.shape}")
    print(f"\nFirst 10 predictions:\n{untrained_preds[:10]}")
    print(f"\nFirst 10 test labels:\n{y_test[:10]}")

    #torch.manual_seed(42)
    train_it(device, model_0, X_train, X_test, y_train, y_test)
    train_it(device, model_2, X_train, X_test, y_train, y_test)

main()
