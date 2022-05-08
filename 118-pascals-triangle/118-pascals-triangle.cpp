class Solution {
public:
 
vector<vector<int>> generate(int numRows) {
    //https://leetcode.com/problems/pascals-triangle/
   
    vector<vector<int>> matrix = {{1}};
    if(numRows == 1)
        return matrix;
    matrix.push_back({1,1});
    int current = 3;
    while(current<=numRows) {
        vector<int> v = {1};
        for (int i = 1; i <current-1 ; ++i) {
            v.push_back(matrix[current-2][i-1]+matrix[current-2][i]);
        }
        v.push_back(1);
        current++;
        matrix.push_back(v);
    }
    return matrix;
}

};