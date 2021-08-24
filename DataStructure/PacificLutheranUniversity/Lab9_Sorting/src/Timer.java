 /**
 * Timer class used to time statements by recording the starting time 
 * and stoping time using the System.currentTimeMillis() method
 */ 
public class Timer {
	long startTime;
	long stopTime;
	
	/**
	 * record the start time
	 */
	public void start() {
		startTime = System.currentTimeMillis();
	}
	
	/**
	 *  record the stop time
	 */
	public void stop() {
		stopTime = System.currentTimeMillis();
	}
	
	/**
	 *  calculate the elapsed time (in seconds)
	 * @return elapsed time
	 */
	public double getElapsedTime() {
		return (stopTime-startTime)/1000.0;	  
	}
}
	
