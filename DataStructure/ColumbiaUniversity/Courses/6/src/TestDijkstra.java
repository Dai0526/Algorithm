import java.io.IOException;

public class TestDijkstra {

  public static void main(String[] args) throws IOException {
	  MapReader map =new MapReader();
	  Graph graph =new Graph();
	  map.readGraph("ttrvertices.txt", "ttredges.txt");
	  map.g.computeAllEuclideanCosts();
	  
	  
	  graph = map.g.getWeightedShortestPath("Portland", "ElPaso");
	  graph.printAdjacencyList();
	  DisplayGraph display = new DisplayGraph(graph);
	  display.setVisible(true);
  }

}
