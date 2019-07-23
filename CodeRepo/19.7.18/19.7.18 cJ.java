import java.util.*;
import java.math.*;
import java.io.*;
import java.text.*;

public class Main
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);

        while (input.hasNext())
        {
            BigInteger x = input.nextBigInteger();
            BigInteger a = input.nextBigInteger();
            BigInteger y = input.nextBigInteger();
            BigInteger b = input.nextBigInteger();

            BigInteger ay = a.multiply(y);
            BigInteger bx = b.multiply(x);
            
            if (ay.compareTo(bx) == 1)
            {
                System.out.println("<");
            }
            else if (ay.compareTo(bx) == -1)
            {
                System.out.println(">");
            }
            else
            {
                System.out.println("=");
            }
            
        }

        input.close();
    }
}