class Solution {
public:
 
vector<vector<int>> resultRecursionCombinationSum3;
map<int,bool> mapRecursionCombinationSum3;
void recursionCombinationSum3(int maxReached, int sum,int maxSize,vector<int> numbers,int target){
    if(numbers.size() == maxSize){
        if(sum == target)
            resultRecursionCombinationSum3.push_back(numbers);
        return;
    }
    for (int i = maxReached+1; i <=9 ; ++i) {
        if(mapRecursionCombinationSum3[i])
            continue;
        mapRecursionCombinationSum3[i] = true;
        numbers.push_back(i);
        recursionCombinationSum3(i, sum+i,maxSize,numbers,target);
        numbers.pop_back();
        mapRecursionCombinationSum3[i] = false;
    }

}

vector<vector<int>> combinationSum3(int k, int n) {
    //https://leetcode.com/problems/combination-sum-iii/
    //summation of at most k characters, achieve n;
    vector<int> lll = {};
    recursionCombinationSum3(0,0,k,lll,n);
    return resultRecursionCombinationSum3;
}

};