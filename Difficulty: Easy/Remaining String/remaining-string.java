//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String s = sc.next();
            char ch = sc.next().charAt(0);
            int count = sc.nextInt();
            Solution ob = new Solution();
            String result = ob.printString(s, ch, count);

            System.out.println(result);
        }
    }
}
// } Driver Code Ends

class Solution {
    public String printString(String s, char ch, int count) {
        
        int i = 0;
        int n = s.length();
        for(i=0; i<n; i++)
        {
            if(ch==s.charAt(i)) count--;
            if(count==0) break;
        }
        
        if(i<n-1) return s.substring(i+1, n);
        
        else return "";
    }
}