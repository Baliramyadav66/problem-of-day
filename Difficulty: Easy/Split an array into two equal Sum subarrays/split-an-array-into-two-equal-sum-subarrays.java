//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] s = br.readLine().trim().split(" ");

            int[] arr = new int[s.length];
            for (int i = 0; i < arr.length; i++) arr[i] = Integer.parseInt(s[i]);

            Solution obj = new Solution();
            boolean res = obj.canSplit(arr);
            System.out.println(res);
        }
    }
}

// } Driver Code Ends


class Solution {
    public boolean canSplit(int arr[]) {
        // code hereint i,tsum=0;
         int left_sum, right_sum, n = arr.length,left=0,right=n-1;
        if(n==1) return false;
        right_sum = arr[n-1];
        left_sum = arr[0];
        while(left+1<right){
            if(left_sum<right_sum){
                left_sum+=arr[++left];
            }else if(left_sum>right_sum){
                right_sum+=arr[--right];
            }else{
                left_sum+=arr[++left];
            }
        }
        return left_sum == right_sum;
    }
}