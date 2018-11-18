public class Fatorial {

	public static void main (String args[]){

		int N = 15;
		int fatorial = N;

		while (N > 1){

  			fatorial = fatorial *(N-1);
  			N--;
  		}
  		System.out.println(fatorial);
    }
} 