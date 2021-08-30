import java.io.IOException;

public class TestBfs {

  public static void main(String[] args) throws IOException {
	  Graph test=new Graph();
	  //MapReader map =new MapReader();
	  Graph graph =MapReader.readGraph("ttrvertices.txt", "ttredges.txt");
	  
	  //map.readGraph("ttrvertices.txt", "ttredges.txt");
	  test=graph.getUnweightedShortestPath("Portland", "ElPaso");
	  
	  test.printAdjacencyList();
	  DisplayGraph display = new DisplayGraph(test);
	  display.setVisible(true);
	  
    
	  //TODO
  }

}
