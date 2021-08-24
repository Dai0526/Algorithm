import java.util.LinkedList;
import java.util.List;

public class Trie {

<<<<<<< HEAD
	private TrieNode root;
	public static final char NULL = '0';

	public Trie() {
		root = new TrieNode(NULL, false);
	}

	// implement your methods here
	// feel free (and you probably should) add helper private methods
	// problem 4a
	public void addWord(String word) throws IllegalArgumentException {
		for (int i = 0; i < word.length(); i++) {
			char data = word.charAt(i);
			System.out.println(data);
			if (data > 122 || data < 97)
				throw new IllegalArgumentException("input can only be lowercase char");
		}
		this.addWord(word, root);
	}

	private void addWord(String word, TrieNode node) {
		char data;
		TrieNode addNode;

		for (int i = 0; i < word.length(); i++) {
			data = word.charAt(i);
			int position = data - 'a';

			if (node.children[position] == null) {
				addNode = new TrieNode(data, false); // add the nodes and
														// elements into the
														// array
				node.children[position] = addNode;
			}

			node = node.children[position]; // update the node

		}
		node.endOfWord = true; // mark the ending words

	}

	// problem 4b
	public boolean contains(String word) {
		char data;
		TrieNode checkNode = this.root; // set this node as a check point
		boolean exist = false;

		for (int i = 0; i < word.length(); i++) {
			data = word.charAt(i);
			int pos = data - 'a';
			if (checkNode.children[pos] == null) {
				return exist; // return false since exist won't be modified to
								// true until the last step
			} else {
				checkNode = checkNode.children[pos];
			}
		}
		// after for loop, checkNode will stop at the Node where the last char
		// is
		// It cannot be null if it can pass the for-loop test
		if (checkNode.endOfWord) {
			exist = true; // if the last char in trie has a endWordMarker, exist
							// is true
		}

		return exist;
	}

	// problem 4c
	public List<String> getStrings() {
		LinkedList<String> ls = new LinkedList<>();
		String temp = "";
		getString(this.root, ls, temp);
		return ls;

	}

	// why stringbuilder will fail?
	private void getString(TrieNode node, LinkedList<String> ls, String temp) {
		if (node == null) {
			return;
		}
		if (node.letter != NULL) {

			if (node.endOfWord == true) {
				ls.add(temp + node.letter);
			}
			temp = temp + node.letter;

			for (int i = 0; i < 26; i++) {
				getString(node.children[i], ls, temp);
			}
		} else {
			for (int i = 0; i < 26; i++) {
				getString(node.children[i], ls, temp);
			}
		}

	}

	// problem 4d
	public List<String> getStartsWith(String prefix) {
		LinkedList<String> ls = new LinkedList<>();
		TrieNode node = this.root;
		String temp = prefix.substring(0, prefix.length() - 1);

		if (isEmpty(root)) {
			return ls;
		} else {
			// locate the node at the last character of the prefix
			for (int i = 0; i < prefix.length(); i++) {
				node = node.children[prefix.charAt(i) - 'a'];
			}
		}
		// check if this node is Empty
		getString(node, ls, temp);

		return ls;
	}

	public boolean isEmpty(TrieNode node) {
		boolean empty = true;
		for (int i = 0; i < 26; i++) {
			if (node.children[i] != null) {
				empty = false; // as long as there is one node has letters, it
								// is not empty
			}
		} // for
		return empty;
	}

	public String toString() {
		StringBuilder sb = new StringBuilder();
		buildString(root, sb, NULL);
		return sb.toString().trim();
	}

	private void buildString(TrieNode node, StringBuilder sb, int layer) {
		for (int i = 0; i < layer; i++) { // print some indentation
			sb.append(" ");
		}
		sb.append(node); // print the node itself
		sb.append("\n");
		for (TrieNode child : node.children) { // recursively print each subtree
			if (child != null) {
				buildString(child, sb, layer + 1);
			}
		}
	}

	private class TrieNode {
		public char letter;
		public boolean endOfWord;
		public TrieNode[] children;

		public TrieNode(char letter, boolean endOfWord) {
			this.letter = letter;
			this.endOfWord = endOfWord;
			children = new TrieNode[26]; // number of letters in English
											// alphabet
		}

		public String toString() {
			return endOfWord ? Character.toString(Character.toUpperCase(letter)) : Character.toString(letter);
		}
	}

	public static void main(String[] args) {
		Trie trie = new Trie();
		trie.addWord("do");
		trie.addWord("dog");
		trie.addWord("doll");
		trie.addWord("dock");
		trie.addWord("doctor");
		System.out.println(trie.getStartsWith("do"));
		// System.out.println(trie);
		// System.out.println(trie.getStrings());
		// System.out.println(trie.contains("doctor"));
	}
=======
  private TrieNode root;
  public static final char NULL = '0';

  public Trie() {
    root = new TrieNode(NULL, false);
  }

  // implement your methods here
  // feel free (and you probably should) add helper private methods
  // problem 4a
  public void addWord(String word) {
  }

  // problem 4b
  public boolean contains(String word) {
    return false;
  }

  // problem 4c
  public List<String> getStrings() {
    return null;
  }

  // problem 4d
  public List<String> getStartsWith(String prefix) {
    return null;
  }

  public String toString() {
    StringBuilder sb = new StringBuilder();
    buildString(root, sb, 0);
    return sb.toString().trim();
  }
  
  private void buildString(TrieNode node, StringBuilder sb, int layer) {
    for (int i = 0; i < layer; i++) {  // print some indentation
      sb.append(" ");
    }
    sb.append(node);    // print the node itself
    sb.append("\n");
    for (TrieNode child : node.children) {  // recursively print each subtree
      if (child != null) {
        buildString(child, sb, layer + 1);
      }
    }
  }

  private class TrieNode {
    public char letter;
    public boolean endOfWord;
    public TrieNode[] children;

    public TrieNode(char letter, boolean endOfWord) {
      this.letter = letter;
      this.endOfWord = endOfWord;
      children = new TrieNode[26]; // number of letters in English alphabet
    }

    public String toString() {
      return endOfWord ? Character.toString(Character.toUpperCase(letter)) : Character.toString(letter);
    }
  }

  public static void main(String[] args) {
    Trie trie = new Trie();
    trie.addWord("hello");
    trie.addWord("help");
    System.out.println(trie);
    System.out.println(trie.getStartsWith("hell"));
  }
>>>>>>> c76689b2d20da3e517d3501e3888383a618fec90
}
