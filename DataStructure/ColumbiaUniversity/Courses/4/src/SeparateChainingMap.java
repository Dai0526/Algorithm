import java.util.LinkedList;

public class SeparateChainingMap<K extends Comparable<? super K>, V> implements Map<K, V> {

	public static final int SCALE_FACTOR = 2;
	public static final int INITIAL_TABLE_SIZE = 8;
	public static final double MAX_LOAD_FACTOR = 1.0;
	private LinkedList<Pair<K, V>>[] table;

	@SuppressWarnings("unchecked")
	public SeparateChainingMap() {
		table = (LinkedList<Pair<K, V>>[]) new LinkedList[INITIAL_TABLE_SIZE];
		for (int i = 0; i < table.length; i++) {
			table[i] = new LinkedList<Pair<K, V>>();
		}
	}

	public int getSize() {
		// returns number of pairs in map
		int count = 0;
		for (int i = 0; i < this.table.length; i++) {
			for (Pair<K, V> p : this.table[i]) {
				count++;
			}
		}
		return count;
	}

	public int getTableSize() {
		// returns size of table

		return this.table.length;
	}

	public void put(K key, V value) {
		if (this.getSize() / (double) this.getTableSize() > MAX_LOAD_FACTOR) { // check
																				// if
																				// need
																				// to
																				// expand
																				// the
																				// size
			this.upsize();
		}

		int hash = key.hashCode();
		int index = hash % this.getTableSize();
		if (index < 0) {
			index += this.getTableSize(); // make it become positive
		}
		LinkedList<Pair<K, V>> l = table[index];
		for (Pair<K, V> p : l) {
			if (p.key.equals(key)) {
				p.value = value;
				return;
			}
		}
		l.add(new Pair<K, V>(key, value));

	}

	public V get(K key) {
		int hash = key.hashCode();
		int index = hash % this.getTableSize();
		if (index < 0) {
			index += this.getTableSize();
		}
		LinkedList<Pair<K, V>> l = table[index];

		for (Pair<K, V> p : l) {
			if (p.key.equals(key)) {
				return p.value;
			}
		}
		return null;
	}

	/*
	 * step to solve this will be
	 * 1. set up a new list l2 
	 * 2. loop over list1 
	 * 3. list2.put(list1.get) 
	 * 4. list1=list2;
	 * 
	 */
	public void upsize() {
		int tableSize = this.table.length * SCALE_FACTOR;
		LinkedList<Pair<K, V>>[] newTable = (LinkedList<Pair<K, V>>[]) new LinkedList[tableSize];
		for (int i = 0; i < newTable.length; i++) {
			newTable[i] = new LinkedList<Pair<K, V>>();
		}

		// loop over old table
		for (int i = 0; i < this.getTableSize(); i++) {
			for (Pair<K, V> pair : this.table[i]) { // iterate all the pairs in
													// the old table
				int hash = pair.key.hashCode();     //re-hash
				int index = hash % tableSize;
				if (index < 0) {
					index += tableSize; // make it become positive
				}

				for (Pair<K, V> p : newTable[index]) {
					if (p.key.equals(pair.key)) {
						p.value = pair.value;
						return;
					}
				}
				newTable[index].add(pair);
			}
		}
		this.table = newTable;//update the new table

	}// upsize

}
