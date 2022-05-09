class Solution {
public:
 
string digitss;
vector<string> combinations;
map<char,vector<char>> charssss ;
void recursionLetterCombinations(string ans, int digitIndex){
    if(digitIndex == digitss.size()) {
        if(ans != "")
        combinations.push_back(ans);
        return;
    }
    for (char c : charssss[digitss[digitIndex]]) {
        recursionLetterCombinations(ans+ c,digitIndex+1);
    }
}
vector<string> letterCombinations(string digits) {
    //https://leetcode.com/problems/letter-combinations-of-a-phone-number/
    digitss = digits;
    char current = 'a';
    int numberOfChars = 3;
    // build map
    for (int i = 2; i <10 ; ++i) {
        if(i == 7 || i == 9)
            numberOfChars = 4;
        else
            numberOfChars = 3;
        for (int j = 0; j <numberOfChars ; ++j) {
            charssss[('0'+i)].push_back(current++);
        }
    }
    recursionLetterCombinations("",0);
    return combinations;
}

};