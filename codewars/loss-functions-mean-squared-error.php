<?php

/*

Loss Functions: Mean Squared Error
The Mean Squared Error (MSE) is a widely used metric to evaluate the performance of regression models. It measures the average squared difference between the true values and the predicted values.

Formula
The formula to calculate mean squared error is as follows:

1/n * Sum[i=1, n] (y_true[i] - y_pred[i])^2

Where:
n is the number of samples.
y(true)i is the true label for the i-th sample.
y(pred)i is the predicted label for the i-th sample.
AKA:
Compute the squared differences between each of your preds and each of your actuals.
Add up all the squared differences
Divide by the number of samples

Your Task
Write a mean_squared_error function that takes in two input arrays y_true and y_pred, and returns the Mean Squared Error between true labels and predicted labels.
 
*/

function mse($y_true, $y_pred) {
	$sum = 0.0;
	$len = count($y_true);
	for ($i = 0; $i < $len; $i++) {
		$value = $y_true[$i] - $y_pred[$i];
		$sum += $value*$value;
	}
	return $sum / $len;
}

printf("%f\n", mse([1, 2, 3, 4], [1, 2, 3, 4]));
printf("%f\n", mse([1, 2, 3, 4], [8, 9, 10, 11]));
printf("%f\n", mse([1, 2.1, 3.5, 4.3], [8, 9, 10.6, 11]));

?>
