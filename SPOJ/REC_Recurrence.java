

import java.math.BigInteger;
import java.util.Scanner;

public class REC_Recurrence {

	public static void main( String [] args){

		Scanner scan = new Scanner (System.in);

		int t = scan.nextInt();

		while ( t-- != 0){

			BigInteger a, b, n, M;

			a = scan.nextBigInteger();
			b = scan.nextBigInteger();
			n = scan.nextBigInteger();
			M = scan.nextBigInteger();

			BigInteger fn = BigInteger.ONE;

			while ( !n.equals(BigInteger.ZERO) ){

				fn = (a.multiply(fn)).add(b);
				n = n.subtract(BigInteger.ONE);

			}

			System.out.println(fn.remainder(M));

		} 

	}

}