//http://www.spoj.com/problems/BISHOPS/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.io.IOException;


class Main
{
	public static void main (String[] args) throws IOException
	{
		BufferedReader buffer=new BufferedReader(new InputStreamReader(System.in));
		String s;
		while((s=buffer.readLine())!=null){
			if(s.equals("1"))
				System.out.println("1");
			else{
		BigInteger big=new BigInteger(s);

		big=big.subtract(new BigInteger("1"));
		big=big.multiply(new BigInteger("2"));
		System.out.println(big.toString());
	}
		}
	}
}
