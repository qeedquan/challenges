/*

Java Iterator class can help you to iterate through every element in a collection. Here is a simple example:

import java.util.*;
public class Example{

    public static void main(String []args){
        ArrayList mylist = new ArrayList();
        mylist.add("Hello");
        mylist.add("Java");
        mylist.add("4");
        Iterator it = mylist.iterator();
        while(it.hasNext()){
            Object element = it.next();
            System.out.println((String)element);
        }
    }
}
In this problem you need to complete a method func. The method takes an ArrayList as input. In that ArrayList there is one or more integer numbers, then there is a special string "###", after that there are one or more other strings. A sample ArrayList may look like this:

element[0]=>42
element[1]=>10
element[2]=>"###"
element[3]=>"Hello"
element[4]=>"Java"
You have to modify the func method by editing at most 2 lines so that the code only prints the elements after the special string "###". For the sample above the output will be:

Hello
Java

Note: The stdin doesn't contain the string "###", it is added in the main method.

*/

import java.util.ArrayList;

public class Iterator {
	public static void main(String[] args) {
		var list = new ArrayList<Object>();
		list.add(42);
		list.add(10);
		list.add("###");
		list.add("Hello");
		list.add("Java");

		var iterator = list.iterator();
		var print = false;
		while (iterator.hasNext()) {
			var value = iterator.next();
			if (print) {
				System.out.println(value);
			}
			if (value.equals("###")) {
				print = true;
			}
		}
	}
}
