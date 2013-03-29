import java.io.*;
import java.math.*;
import java.util.*;

class Main{
	public static void main(String[] args)
	{
	    int n,ci,ca,cc,cv,cal,tm;
	    int i,j;
	    Scanner Input = new Scanner(System.in);
	    n = Input.nextInt();
	    	ci = Input.nextInt();
	    	ca = Input.nextInt();
	    	cc = Input.nextInt();
	    	cv = Input.nextInt();
	    	cal = ca + cc;
	    	BigInteger dp[] = new BigInteger[n+1];
	    	BigInteger dpca[] = new BigInteger[n+1];
	    	BigInteger dpcc[] = new BigInteger[n+1];
	    	dp[0] = new BigInteger("0");
	    	dpca[0] = new BigInteger("0");
	    	dpcc[0] = new BigInteger("0");
	    	BigInteger n1 = new BigInteger("1");
	    	BigInteger n3 = new BigInteger("1");
	    	for(i = 1;i <= n;i ++)
	    	{
	    		dp[i] = new BigInteger("0");
	    		dpca[i] = new BigInteger("0");
	    		dpcc[i] = new BigInteger("0");
	    		if(i >= ci){
	    			dp[i] = dp[i-ci].add(n1);
	    		}
	    		dp[i] = dp[i-1].max(dp[i]);
	    		if(i >= cal+cv)
	    		{
	    			for(j = cv;j + cal <= i;j += cv)
	    			{
	    			   tm = j + cal;
	    		       dp[i] = dp[i].max(dp[i-tm].multiply(n3));
	    		       n3 = n3.add(n1);
	    			}
	    			n3 = n1;
	    		}
	    	}
	    	System.out.println(dp[n]);
	    }
}