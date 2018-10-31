
import java.util.*;
import java.math.BigInteger;

class FLOWO18{

	public static void main(String[] args) {
		
		Scanner scan = new Scanner (System.in);

		int test = scan.nextInt();

		for ( int i = 0 ; i < test ; i ++){

			Scanner sc = new Scanner(System.in);
			BigInteger bn = sc.nextBigInteger();

			int number = bn.intValue();


			for ( int j = 0 ; j < number ; j ++){
				bn.multiply(bn.subtract(BigInteger.ONE));
				bn.subtract(BigInteger.ONE);
			}

			System.out.println(bn);

		}

	}


}