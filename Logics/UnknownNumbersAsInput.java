import java.util.Scanner;

class UnknownNumbersAsInput {
	public static void main(String[] args) {
		int result = 0;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value");
        String string = sc.nextLine();
        //string = string.replace("x", "");
        String[] strArray = string.split(" ");
        for (String str : strArray) {
                result += Integer.valueOf(str);
        }
        System.out.println("Result is " + result);	
	}
}