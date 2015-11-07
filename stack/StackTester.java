// Rushy Panchal
// StackTester.java

public class StackTester {
	private static LinkedListStack<Integer> s = new LinkedListStack<Integer>();

	public static void main(String[] args) {
		// Test the Stack implementation
		for (int i = 0; i < args.length; i++) {
			s.push(Integer.parseInt(args[i]));
			assert s.size() == i;
			}
		System.out.print("Stack: ");
		for (int n: s) {
			System.out.print(n + " ");
			}
		System.out.println();

		int current = args.length - 1;
		while (! s.isEmpty()) {
			int result = s.pop();
			assert result == Integer.parseInt(args[current--]);
			System.out.println(result);
			}
		}
	}
