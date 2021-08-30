import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class MapReader {
	public static Graph g;

	public MapReader() {
		g = new Graph();
	}

	public static Graph readGraph(String vertexfile, String edgefile) throws IOException {
		g = new Graph();// everytime you need a new graph to store the data, so
						// I instantiate graph again
		String[] words; // data for buffer
		String lines; // data for buffer

		String city; // data for vertex
		int x, y;

		String s, t; // data for edge: source city and target city

		try {
			// read vertex file
			FileReader vfile = new FileReader(vertexfile);
			BufferedReader vertexBuffer = new BufferedReader(vfile);
			while ((lines = vertexBuffer.readLine()) != null) {
				words = lines.split(",");
				city = words[0];
				x = Integer.parseInt(words[1]);
				y = Integer.parseInt(words[2]);
				g.addVertex(new Vertex(city, x, y));
			}
			vfile.close();
			vertexBuffer.close();

			// read edge file
			FileReader efile = new FileReader(edgefile);
			BufferedReader edgeBuffer = new BufferedReader(efile);
			while ((lines = edgeBuffer.readLine()) != null) {
				words = lines.split(",");
				s = words[0];
				t = words[1];
				g.addUndirectedEdge(s, t, 1.0);
			}
			efile.close();
			edgeBuffer.close();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		return g; // TODO
	}

	public static void main(String[] args) throws IOException {
		MapReader map = new MapReader();
		map.g.printAdjacencyList();
		map.readGraph("ttrvertices.txt", "ttredges.txt");

		DisplayGraph display = new DisplayGraph(g);
		display.setVisible(true);
		// System.out.println("No operation."); // TODO
		System.out.println(g);
	}

}
