// Rushy Panchal
// LinkedListTester.java

import java.util.Random;

public class LinkedListTester {
	private static final int MIN_ITERATIONS = 250;
	private static final int MAX_ITERATIONS = 750;
	private static final int MAX_VALUE = (int) 1e6;

	public static void main(String[] args) {
		Random random = new Random();

		LinkedList<Integer> linkedList = new LinkedList<Integer>();
		assert linkedList.isEmpty();

		int iterations = random.nextInt((MAX_ITERATIONS - MIN_ITERATIONS)) + MIN_ITERATIONS;

		for (int i = 0; i < iterations; i++) {
			assert linkedList.add(i) == i;
			assert linkedList.size() == i + 1;
			}

		for (int i = 0; i < iterations; i++) {
			int linked = linkedList.get(i);

			assert linkedList.get(i) == i;
			}

		for (int i = 0; i < iterations; i++) {
			linkedList.remove(0);
			assert linkedList.size() == (iterations - i - 1);
			assert linkedList.contains(i) == false;
			}

		linkedList.add(2500);
		assert linkedList.contains(2500);
		// need to make it an Integer to use appropriate method
		assert linkedList.index(new Integer(2500)) == 0;
		}
	}
