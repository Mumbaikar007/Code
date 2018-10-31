/*
	References:
		https://codereview.stackexchange.com/questions/84019/project-euler-25-1000-digit-fibonacci-number
*/


import java.math.BigInteger;

public class DigitFibonacciNumber25 {

	public static void main(String [] args){

		int answer = 2;

		BigInteger [] fib = new BigInteger [3] ;
		BigInteger limit = new BigInteger("10").pow(999);


		fib[0] = BigInteger.ONE;
		fib[2] = BigInteger.ONE;

		int i = 0;
		while ( fib[i].compareTo(limit) < 0){
			i = ( i + 1 ) % 3;
			fib[i] = fib[(i+1) % 3].add(fib[(i+2) % 3]);
			answer ++;
		}

		System.out.println(answer);

	}

}