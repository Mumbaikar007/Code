import java.util.*;

class LOSTMAX {
	public static void main(String[] args) {
	       
               Scanner sc = new Scanner(System.in);
               int tests = Integer.parseInt(sc.next());
               String string = sc.next();
                        
               for ( int i = 0 ; i < tests ; i ++){


                      	int result = 0, max = 0;
                        
                        /*System.out.println("Enter the value");
                        String string = sc.nextLine();
                        
                        //string = string.replace("x", "");
                        String[] strArray = string.split(" ");
                        //int [] numbers = new int[strArray.lengtj - 1];
                        int size = strArray.length() - 1;*/

                        String line = sc.nextLine();
                        String[] tokens = line.split(" ");
                        //int[] numbers = new int[tokens.length];
                        int size = tokens.length - 1;

                        for (String str : tokens) {
                                result = Integer.valueOf(str);
                                if ( result == size){
                                        size = 0;
                                }
                                else if ( max < result){
                                        max = result;
                                }
                        }
                
                        System.out.println(max);	

                }
	
        }
}