
import java.util.*;
import java.io.*;

public class sort{
        private Contact[] contacts;
	private class	SortListener implements ActionListener{
		
		public void actionPerformed(ActionEvent e)
		{
			for (int i=0; i<)
			int startScan, index, minIndex;
			Contact minName;
	
			for (startScan = 0; startScan < (array.length-1); startScan++)
			{
				minIndex = startScan;
				minName = array[startScan];
				for(index = startScan + 1; index < array.length; index++)
				{
					if (array[index].getName().compareTo(minValue.getName())<0)
					{
						minName = array[index];
						minIndex = index;
					}
				}
				array[minIndex] = array[startScan];
				array[startScan] = minName;
        		}
   }	
	
}//Sort Listener FirstName

}