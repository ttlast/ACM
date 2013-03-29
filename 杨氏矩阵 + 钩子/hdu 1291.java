import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
    final static int maxn = 24;
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        BigInteger ans[] = new BigInteger[maxn];
        Integer i,j,k,l,tm;
        
        for(i = 1;i <= 20;i ++)
        {
            j = i*i;
            ans[i] = BigInteger.ONE;
            for(k = 2;k <= j;k ++)
                ans[i] = ans[i].multiply(BigInteger.valueOf(k));
            for(k = 1;k <= i;k ++)
            {
                tm = 0;
                for(l = 1;l <= i;l ++)
                {
                    tm = (i-k+1)+(i-l);
                    ans[i] = ans[i].divide(BigInteger.valueOf(tm));
                }
                
            }
        }
        while(input.hasNext())
        {
            tm = input.nextInt();
            System.out.println(ans[tm].toString());
        }
    }
}