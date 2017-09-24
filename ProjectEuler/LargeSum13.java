/*
	Problem:
		https://projecteuler.net/problem=13

	References:
		https://www.hackerrank.com/contests/projecteuler/challenges/euler013/forum
*/

import java.util.Scanner;
import java.math.BigInteger;

public class LargeSum13{
	public static void main(String[] args) {
		
		Scanner scanner = new Scanner (System.in);
		BigInteger sum = new BigInteger("0");

		for ( int i = 0; i < 100 ; i ++){
			String temp = scanner.nextLine();
			sum = sum.add(new BigInteger(temp));
		}

		String s = sum.toString();
		System.out.println(s.substring(0,10));
	}
}