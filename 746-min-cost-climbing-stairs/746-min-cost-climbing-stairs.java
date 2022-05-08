import java.util.Arrays;

class Solution {
    int minimum;
    int memo[];
    public int minCostClimbingStairs(int[] cost) {
        minimum = Integer.MAX_VALUE;
         memo = new int[cost.length];

        Arrays.fill(memo, -1);
        return      Math.min(minCostClimbingStairs(cost,0,cost[0]),minCostClimbingStairs(cost,1,cost[1]));
    }
     public int minCostClimbingStairs(int[] cost , int index , int val  ) {
        if (cost.length - index <= 2) {
            return cost[index];
        }
        if (val >= minimum)
            return Integer.MAX_VALUE;
        if (memo[index] != -1){
//            System.out.println("Index  "+index +"    memo  "+memo[index]+"    val   "+val);
            return memo[index];
        }
        return memo[index] = cost[index] + Math.min(minCostClimbingStairs(cost, index + 1, cost[index + 1]), minCostClimbingStairs(cost, index + 2,  cost[index + 2]));
 
     }
}