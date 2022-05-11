class Solution {
public:
    vector <char> Chars={'a', 'e', 'i', 'o', 'u'}  ;
    int recursion(int n, int index) {
        if(0 == n) {
            return 1;
        } 
        int sum = 0;
        for(int i =index; i < Chars.size(); i++) {
            sum += recursion (n-1, i);
        } 
        return sum;
    } 
    int countVowelStrings(int n) {
        return recursion(n, 0);
    }
};