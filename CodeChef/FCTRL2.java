import java.util.*;
import java.math.BigInteger;

class FCTRL2{
	
	public static void main(String args[]){
	
		Scanner scan = new Scanner (System.in);
		int tests = scan.nextInt();

		while ( (tests -- ) > 0){
			
			int number = scan.nextInt();
			BigInteger bigInteger = new BigInteger("1");

			for ( int i = 2 ; i <= number ; i ++){
				bigInteger = bigInteger.multiply(BigInteger.valueOf(i));
			}

			System.out.println(bigInteger.toString());

		}

	}
}