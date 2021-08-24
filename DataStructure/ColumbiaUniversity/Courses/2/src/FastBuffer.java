
// This class should contain your implementation of the Buffer interface.

import java.util.Deque;
import java.util.LinkedList;

public class FastBuffer implements Buffer {

	private Deque<Character> left;
	private Deque<Character> right;

	public FastBuffer() {
		init();
	}

	private void init() {
		left = new LinkedList<Character>();
		right = new LinkedList<Character>();
	}

	@Override
	public int size() {
		return left.size() + right.size();
	}

	@Override
	public void load(char[] initial, int cursorPosition) {
		init();
		for (char c : initial) {
			left.addFirst(c);
		}
		setCursor(cursorPosition);
	}

	@Override
	public char[] toArray() {
		char[] array = new char[size()];
		int i = 0;
		for (Character c : left) {
			array[left.size() - 1 - i] = c;
			i++;
		}
		for (Character c : right) {
			array[i] = c;
			i++;
		}
		return array;
	}

	@Override
	public int getCursor() {
		return left.size();
	}

	@Override
	public void setCursor(int j) {
		while (getCursor() != j) {
			if (j < getCursor()) {
				moveLeft();
			}
			if (j > getCursor()) {
				moveRight();
			}
		}
	}

	@Override
	public void moveRight() {
		left.addFirst(right.removeFirst());
	}

	@Override
	public void moveLeft() {
		right.addFirst(left.removeFirst());
	}

	@Override
	public void insertLeft(char c) {
		left.addFirst(c);
	}

	@Override
	public char deleteRight() {
		return right.removeFirst();
	}

	@Override
	public char deleteLeft() {
		return left.removeFirst();
	}

}
