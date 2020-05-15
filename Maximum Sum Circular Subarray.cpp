class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int maxSoFar=arr[0];
        int maxx=arr[0];
        int minSoFar=arr[0];
        int minn=arr[0];
        int sum=arr[0];
        for(int i=1;i<arr.size();i++){
            maxSoFar=max(arr[i],arr[i]+maxSoFar);
            maxx=max(maxSoFar,maxx);
            minSoFar=min(arr[i],arr[i]+minSoFar);
            minn=min(minn,minSoFar);
            sum=sum+arr[i];
        }
        if(sum==minn){
            return maxx;
        }
        return max(maxx,sum-minn);
    }
};




//Explaination
EXPLANATION:-
EX 1:-
   A = [1, -2, 3, -2]
   max = 3   (This means max subarray sum for normal array)
   min = -2  (This means min subarray sum for normal array)
   sum = 0   (total array sum)
   Maximum Sum = 3 (max)

EX2:-
  A = [5, -3, 5]
  max = 7
  min  = -3
  sum = 7
  maximum subarray sum = 7 - (-3) = 10
  
EX3:-
   A = [3, -1, 2, -1]
   max = 4
   min = -1
   sum = 3
   maximum subarray sum  = sum - min = 3 - (-1) = 4

EX4:-
   A = [-2, -3, -1]
   max = -1
   min = -6
   sum = -6
   In this example, if we do (sum - min) then result is 0. but there is no subarray with sum 0.
   So, in this case we return max value. that is -1.
   
From above examples, 
we can understand that 
maximum sum is either max (we get using kadane's algo) or (sum - min).
There is a special case, if sum == min,
then maximum sum is max.

Let's develop an algorithm to solve this problem.
1. Find maximum subarray sum using kadane's algorithm (max) 
2. Find minimum subarray sum using kadane's algorithm (min)
3. Find total sum of the array (sum)
4. Now, if sum == min return max
5. Otherwise, return maximum ( max, sum - min )
