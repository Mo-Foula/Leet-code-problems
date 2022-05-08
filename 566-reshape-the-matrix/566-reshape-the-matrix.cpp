class Solution {
public:
   
vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
//https://leetcode.com/problems/reshape-the-matrix/
vector< vector<int> > newMatrix (r,vector<int>(c));
    vector<int> allNumbers;
    for (auto i : mat) {
        for (int j : i) {
            allNumbers.push_back(j);
        }
    }
    if(allNumbers.size() != r*c)
        return mat;
    int counter = 0;
    for (int i = 0; i <r ; ++i) {
        for (int j = 0; j <c ; ++j) {
            newMatrix[i][j] = allNumbers[counter++];  
        }
    }
    return  newMatrix;
}
};