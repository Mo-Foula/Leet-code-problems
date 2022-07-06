class Solution {
public:
    int fib(int n) {
        if(n == 1 || n ==0) return n;
        int min1 = 1;
        int min2 = 0;
        int temp;
        n--;
        while(n--){
            temp = min1;
            min1 = min2+min1;
            min2 = temp;
        }
        return min1;
    }
};