/*

The Calendar class is an abstract class that provides methods for converting between a specific instant in time and a set of calendar fields such as YEAR, MONTH, DAY_OF_MONTH, HOUR, and so on, and for manipulating the calendar fields, such as getting the date of the next week.

You are given a date. You just need to write the method, getDay, which returns the day on that date. To simplify your task, we have provided a portion of the code in the editor.

Example
month = 8
day = 14
year = 2017

The method should return MONDAY as the day on that date.

https://s3.amazonaws.com/hr-assets/0/1514458312-c097047ed4-calendar_class.png


Function Description

Complete the findDay function in the editor below.

findDay has the following parameters:

int: month
int: day
int: year

Returns

string: the day of the week in capital letters

Input Format

A single line of input containing the space separated month, day and year, respectively, in MM DD YYYY  format.

Constraints
2000 < year < 3000

Sample Input

08 05 2015
Sample Output

WEDNESDAY

*/

import java.util.*;
import java.time.*;
import java.text.*;

public class DateAndTime {
	public static void main(String[] args) {
		System.out.println(getDay(8, 14, 2017));
		System.out.println(getDay(8, 5, 2015));
		System.out.println(getDay(8, 18, 2017));
	}

	public static String getDay(int month, int day, int year) {
		String weekday;
		try {
			var format1 = new SimpleDateFormat("dd/MM/yyyy");
			var format2 = new SimpleDateFormat("EEEE");

			var input = String.format("%02d/%02d/%04d", day, month, year);
			var date = format1.parse(input);
			weekday = format2.format(date);
		} catch (Exception e) {
			return "invalid date";
		}
		return weekday;
	}
}
