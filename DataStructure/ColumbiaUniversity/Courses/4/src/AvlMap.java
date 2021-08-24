public class AvlMap<K extends Comparable<? super K>, V> implements Map<K, V> {
	private AvlTree<Pair<K, V>> avlTree;
	
	public AvlMap() {
		avlTree = new AvlTree<Pair<K, V>>();
	}

	@Override
	public void put(K key, V value) {
		//code provided by recitation session on week9
		Pair<K, V> newPair = new Pair<>(key, value);
		this.avlTree.insert(newPair);
		return;
	}

	@Override
	public V get(K key) {
		//code provided by recitation session on week9
		Pair<K, V> tempNull = new Pair<>(key, null);
		Pair<K, V> temp = avlTree.get(tempNull);
		if (temp == null) {
			return null;
		}
		return temp.value;
	}
}
