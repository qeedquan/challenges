/*

In this kata, you will be creating a Java Comparator to sort cats by their weight.

The Cat class is preloaded for you., and its signature is given below:

public class Cat implements Comparable<Cat>
{
  public String name;
  public double weight;
  
  public Cat(String name, double weight);
  
  @Override
  public int compareTo(Cat c);
  
  @Override
  public boolean equals(Object o);
}

In the tests, an array of cats will be populated, and then sorted using Arrays.sort().
By default, this will sort the cats by their names. Your job is to complete the implementation of CatWeightComparator so that the cats are sorted by weight.

You may assume that no two cats have the same name.

For more information about Arrays, take a look at https://docs.oracle.com/javase/7/docs/api/java/util/Arrays.html.

For more information about Comparable<T>, see https://docs.oracle.com/javase/7/docs/api/java/lang/Comparable.html.

For more information about Comparator<T>, check out https://docs.oracle.com/javase/7/docs/api/java/util/Comparator.html.

*/

import java.util.Objects;
import java.util.Comparator;

class Cat implements Comparable<Cat> {
	final String name;
	final double weight;

	Cat(String name, double weight) {
		this.name = name;
		this.weight = weight;
	}

	@Override
	public int compareTo(Cat other) {
		return name.compareTo(other.name);
	}

	@Override
	public boolean equals(Object object) {
		if (this == object)
			return true;
		if (!(object instanceof Cat cat))
			return false;
		return Double.compare(weight, cat.weight) == 0 && Objects.equals(name, cat.name);
	}

	@Override
	public int hashCode() {
		return Objects.hash(name, weight);
	}
}

class CatWeightComparator implements Comparator<Cat> {
	@Override
	public int compare(Cat cat1, Cat cat2) {
		return Double.compare(cat1.weight, cat2.weight);
	}
}
