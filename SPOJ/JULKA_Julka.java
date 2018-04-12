

import java.math.BigInteger;
import java.util.Scanner;

public class JULKA_Julka {
	
	public static void main(String[] args) {
		
		for ( int i = 1; i <= 10 ; i ++){

			Scanner scan = new Scanner (System.in);
			
			BigInteger total = scan.nextBigInteger ();
			BigInteger difference = scan.nextBigInteger();

			BigInteger natalia = (total.subtract(difference)).divide(new BigInteger("2"));

			BigInteger klaudia = natalia.add(difference);

			System.out.print(klaudia.toString() + "\n" + natalia.toString() + "\n");
		}

	}

}