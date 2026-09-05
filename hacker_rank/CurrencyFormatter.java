/*

Given a double-precision number, payment, denoting an amount of money, use the NumberFormat class' getCurrencyInstance method to convert payment into the US, Indian, Chinese, and French currency formats. Then print the formatted values as follows:

US: formattedPayment
India: formattedPayment
China: formattedPayment
France: formattedPayment

where formattedPayment is payment formatted according to the appropriate Locale's currency.

Note: India does not have a built-in Locale, so you must construct one where the language is en (i.e., English).

Input Format

A single double-precision number denoting payment.

Constraints

0 <= payment <= 10^9

Output Format

On the first line, print US: u where u is payment formatted for US currency.
On the second line, print India: i where i is payment formatted for Indian currency.
On the third line, print China: c where c is payment formatted for Chinese currency.
On the fourth line, print France: f, where f is payment  formatted for French currency.

Sample Input

12324.134
Sample Output

US: $12,324.13
India: Rs.12,324.13
China: ￥12,324.13
France: 12 324,13 €

*/

import java.io.*;
import java.util.*;
import java.text.NumberFormat;
import java.util.Locale;

public class CurrencyFormatter {
	public static void main(String[] args) {
		currency(12324.134);
	}

	public static void currency(double amount) {
		var us = NumberFormat.getCurrencyInstance(Locale.US);
		var in = NumberFormat.getCurrencyInstance(new Locale("en", "in"));
		var ch = NumberFormat.getCurrencyInstance(Locale.CHINA);
		var fr = NumberFormat.getCurrencyInstance(Locale.FRANCE);

		System.out.println("US: " + us.format(amount));
		System.out.println("India: " + in.format(amount).replace("\u20B9", "Rs."));
		System.out.println("China: " + ch.format(amount).replace("\u00A5", "\uFFE5"));
		System.out.println("France: " + fr.format(amount).replaceAll("\u202F", " "));
	}
}
