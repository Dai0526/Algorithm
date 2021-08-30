
public class costVert implements Comparable<costVert> {
	public double cost;
	public Vertex vert;
	
	public costVert(double c,Vertex v){
		cost=c;
		vert = v;
	}

	public int compareTo(costVert cv) {
		if(this.cost>cv.cost){
			return 1;
		}
		else if(this.cost<cv.cost){
			return -1;
		}else{
		return 0;
	}}
}
