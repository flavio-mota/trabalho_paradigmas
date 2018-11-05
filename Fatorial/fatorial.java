public class Fatorial {

	public static void main (String args[]){

		double x = 69;
		double f = x;

		while (x > 1){

  			f = f *(x-1);
  			x--;
  		}
  		System.out.println(f);
    }
} 