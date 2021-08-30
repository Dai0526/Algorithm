import java.util.Collection;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;

public class Graph {

	// Keep a fast index to nodes in the map
	protected Map<String, Vertex> vertices;

	/**
	 * Construct an empty Graph.
	 */
	public Graph() {
		vertices = new HashMap<String, Vertex>();
	}

	public void addVertex(String name) {
		Vertex v = new Vertex(name);
		addVertex(v);
	}

	public void addVertex(Vertex v) {
		if (vertices.containsKey(v.name))
			throw new IllegalArgumentException("Cannot create new vertex with existing name.");
		vertices.put(v.name, v);
	}

	public Collection<Vertex> getVertices() {
		return vertices.values();
	}

	public Vertex getVertex(String s) {
		return vertices.get(s);
	}

	/**
	 * Add a new edge from u to v. Create new nodes if these nodes don't exist
	 * yet. This method permits adding multiple edges between the same nodes.
	 * 
	 * @param u
	 *            the source vertex.
	 * @param w
	 *            the target vertex.
	 */
	public void addEdge(String nameU, String nameV, Double cost) {
		if (!vertices.containsKey(nameU))
			addVertex(nameU);
		if (!vertices.containsKey(nameV))
			addVertex(nameV);
		Vertex sourceVertex = vertices.get(nameU);
		Vertex targetVertex = vertices.get(nameV);
		Edge newEdge = new Edge(sourceVertex, targetVertex, cost);
		sourceVertex.addEdge(newEdge);
	}

	/**
	 * Add a new edge from u to v. Create new nodes if these nodes don't exist
	 * yet. This method permits adding multiple edges between the same nodes.
	 * 
	 * @param u
	 *            unique name of the first vertex.
	 * @param w
	 *            unique name of the second vertex.
	 */
	public void addEdge(String nameU, String nameV) {
		addEdge(nameU, nameV, 1.0);
	}

	/****************************
	 * Your code follow here. *
	 ****************************/
	/**
	 * add a UndirectedEdge
	 * 
	 * @param s
	 * @param t
	 * @param cost
	 */
	public void addUndirectedEdge(String s, String t, double cost) {
		addEdge(s, t, cost);
		addEdge(t, s, cost);

	}

	/**
	 * get the cost of the edge
	 * 
	 * @param ux
	 * @param uy
	 * @param vx
	 * @param vy
	 * @return return the cost of the edge by given index
	 */
	public double computeEuclideanCost(double ux, double uy, double vx, double vy) {
		return Math.sqrt(Math.pow(ux - vx, 2) + Math.pow((uy - vy), 2)); // TODO
	}

	/**
	 * calculate the cost of all the edges
	 */
	public void computeAllEuclideanCosts() {
		int sx, sy, tx, ty;
		// duplicated case?
		for (Vertex v : getVertices()) {
			for (Edge e : v.getEdges()) {
				sx = e.sourceVertex.posX;
				sy = e.sourceVertex.posY;

				tx = e.targetVertex.posX;
				ty = e.targetVertex.posY;

				e.cost = computeEuclideanCost(sx, sy, tx, ty);
			}
		}

	}

	/** BFS */
	/**
	 * The algorithm is followed by the instruction in Class ppt BFS
	 * 
	 * @param s
	 *            the starting point
	 */
	public void doBfs(String s) {
		Queue<Vertex> q = new LinkedList<>();
		Vertex check;

		Vertex begin = this.getVertex(s);

		for (Vertex v : getVertices()) {
			v.cost = 99999999;
		}
		begin.cost = 0;

		q.add(begin);
		while (!q.isEmpty()) {
			check = q.remove();
			check.visited = true;

			for (Edge e : check.getEdges()) {
				if (e.targetVertex.cost == 99999999) {
					e.targetVertex.cost = check.cost + 1;
					e.targetVertex.backpointer = check; // set backpointer

					q.add(e.targetVertex);
				} // if
			} // for
		} // while
	}// bfs

	/**
	 * 
	 * @param s
	 * @param t
	 * @return the graph of Unweighted Shortest Path
	 */
	public Graph getUnweightedShortestPath(String s, String t) {
		Graph unweightShortestPath = new Graph();
		for (Vertex v : this.getVertices()) {
			Vertex temp = new Vertex(v.name, v.posX, v.posY);
			unweightShortestPath.addVertex(temp);
		}
		this.doBfs(s);
		Vertex source = getVertex(s);
		Vertex target = getVertex(t);

		Vertex last = target.backpointer;
		Vertex next = target;

		while (last != source) {
			unweightShortestPath.addEdge(last.name, next.name, 0.1);

			next = last;
			last = last.backpointer;
		}
		unweightShortestPath.addEdge(next.name, source.name, 0.1);
		return unweightShortestPath; // TODO
	}

	/**
	 * Dijkstra's The algorithm is followed by the instruction in Class ppt
	 * 
	 * @param s
	 */
	public void doDijkstra(String s) {

		PriorityQueue<costVert> q = new PriorityQueue<>();
		Vertex start;
		for (Vertex v : getVertices()) {
			v.cost = 99999999;
			v.visited = false;
		}

		start = this.getVertex(s);
		start.cost = 0;

		costVert cv = new costVert(0, start);
		q.add(cv);

		while (!q.isEmpty()) { // u =temp
			costVert temp = q.remove(); // default priorityqueue is a minheap
			if (temp.vert.visited != true) {
				temp.vert.visited = true;

				for (Edge e : temp.vert.getEdges()) {
					// target =v
					Vertex target = e.targetVertex;
					if (target.visited != true) {
						double edgeCost = computeEuclideanCost(temp.vert.posX, temp.vert.posY, target.posX,
								target.posY);
						if (temp.cost + edgeCost < target.cost) {
							target.cost = temp.vert.cost + edgeCost;
							target.backpointer = temp.vert;
							q.add(new costVert(target.cost, target));
						} // if
					} // if
				} // for
			} // if
		} // while

	}

	/**
	 * 
	 * @param s
	 * @param t
	 * @return return the Weighted Shortest Path
	 */
	public Graph getWeightedShortestPath(String s, String t) {
		Graph weightShortestPath = new Graph();
		for (Vertex v : this.getVertices()) {
			Vertex temp = new Vertex(v.name, v.posX, v.posY);
			weightShortestPath.addVertex(temp);
		}

		this.doDijkstra(s);
		Vertex source = getVertex(s);
		Vertex target = getVertex(t);

		Vertex last = target.backpointer;
		Vertex next = target;

		while (last != source) {
			double cost = computeEuclideanCost(last.posX, last.posY, next.posX, next.posY);
			weightShortestPath.addEdge(last.name, next.name, cost);

			next = last;
			last = last.backpointer;

		}
		double cost = computeEuclideanCost(source.posX, source.posY, next.posX, next.posY);
		weightShortestPath.addEdge(source.name, next.name, cost);
		return weightShortestPath; // TODO

	}

	/** Prim's */
	public void doPrim(String s) {
		PriorityQueue<costVert> q = new PriorityQueue<>();
		for (Vertex v : getVertices()) {
			v.cost = 99999999;
			v.visited = false;
		}
		// choose any vertex s
		Vertex start = this.getVertex(s);
		// start.visited=true;
		costVert cv = new costVert(0, start);

		q.add(cv);

		while (!q.isEmpty()) {
			costVert temp = q.remove();
			if (temp.vert.visited == false) {
				temp.vert.visited = true;
				for (Edge e : temp.vert.getEdges()) {
					Vertex target = e.targetVertex;
					if (target.visited == false) {
						double cost = computeEuclideanCost(target.posX, target.posY, temp.vert.posX, temp.vert.posY);
						;
						if (cost < target.cost) {
							target.cost = cost;
							target.backpointer = temp.vert;
							q.add(new costVert(target.cost, target));
						}
					}
				}
			}
		}

	}

	/**
	 * 
	 * @param the
	 *            root vertex s
	 * @return return the minimum Spanning Tree
	 */
	public Graph getMinimumSpanningTree(String s) {
		Graph weightShortestPath = new Graph();
		// add all the vertex to the new graph
		for (Vertex v : this.getVertices()) {
			Vertex temp = new Vertex(v.name, v.posX, v.posY);
			weightShortestPath.addVertex(temp);
		}
		this.doPrim(s);

		// add the edges of the spanning tree
		for (Vertex v : this.getVertices()) {
			for (Edge e : v.getEdges()) {
				Vertex target = e.targetVertex;
				if (target.backpointer == v) {
					weightShortestPath.addEdge(v.name, target.name, e.cost);
				}
			}
		}

		return weightShortestPath;
	}

	/*************************/

	public void printAdjacencyList() {
		for (String u : vertices.keySet()) {
			StringBuilder sb = new StringBuilder();
			sb.append(u);
			sb.append(" -> [ ");
			for (Edge e : vertices.get(u).getEdges()) {
				sb.append(e.targetVertex.name);
				sb.append("(");
				sb.append(e.cost);
				sb.append(") ");
			}
			sb.append("]");
			System.out.println(sb.toString());
		}
	}

	public static void main(String[] args) {
		Graph g = new Graph();
		g.addVertex(new Vertex("v0", 0, 0));
		g.addVertex(new Vertex("v1", 0, 1));
		g.addVertex(new Vertex("v2", 1, 0));
		g.addVertex(new Vertex("v3", 1, 1));

		g.addEdge("v0", "v1");
		g.addEdge("v1", "v2");
		g.addEdge("v2", "v3");
		g.addEdge("v3", "v0");
		g.addEdge("v0", "v2");
		g.addEdge("v1", "v3");

		g.printAdjacencyList();

		DisplayGraph display = new DisplayGraph(g);
		display.setVisible(true);
	}

}
