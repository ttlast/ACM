import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
	final static int maxn = 24;
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		BigInteger ans,tm;
		Integer r,i,j,k,al,tml;
		Integer row[] = new Integer [maxn];
		while(input.hasNext())
		{
			r = input.nextInt();
			al = 0;
			for(i = 0;i < r;i ++)
			{
				row[i] = input.nextInt();
				al += row[i];
			}
			ans = BigInteger.ONE;
			for(i = 2;i <= al;i ++)
				ans = ans.multiply(BigInteger.valueOf(i));
			for(i = 0;i < r;i ++)
			{
				for(j = 1;j <= row[i];j ++)
				{
					tm = BigInteger.valueOf(row[i]-j+1);
					tml = row[i] - j + 1;
					for(k = i+1;k < r;k ++)
					{
						if(row[k] >= j)
							tm = tm.add(BigInteger.ONE);
						else break;
						tml ++;
					}
					ans = ans.divide(tm);
				}
			}
			System.out.println(ans.toString());
		}
	}
}