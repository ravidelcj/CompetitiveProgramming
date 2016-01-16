//http://www.spoj.com/problems/UJ/
import java.util.*;
import java.io.*;
import java.math.*;
import java.lang.*;
class main{

	public static void main(String args[]) throws Exception
	{
		Scanner sc=new Scanner(System.in);
		BigInteger bg=sc.nextBigInteger();
		int p=sc.nextInt();


		while(true)
		{

			if(bg.compareTo(BigInteger.ZERO)==0&&p==0)
				break;
			bg=bg.pow(p);
			System.out.println(bg);
			bg=sc.nextBigInteger();
			p=sc.nextInt();
		}
	
	}
}
