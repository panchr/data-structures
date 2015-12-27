// Rushy Panchal
// Queue.java

public class QueueTester {
	private static Queue<Integer> q = new Queue<Integer>();

	public static void main(String[] args) {
		// Test the Queue implementation
		for (int i = 0; i < args.length; i++) {
			q.enqueue(Integer.parseInt(args[i]));
			assert q.size() == i + 1;
			}
		System.out.print("Queue: ");
		for (int n: q) {
			System.out.print(n + " ");
			}
		System.out.println();

		int current = 0;
		while (! q.isEmpty()) {
			int result = q.dequeue();
			assert result == Integer.parseInt(args[current++]);
			}
		}
	}
