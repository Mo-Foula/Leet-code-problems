class NumMatrix {
public:
    vector<vector<int>> myMatrix;
    vector<vector<long long int>> sumMatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        myMatrix = matrix;
        sumMatrix.resize(matrix.size()+1, vector<long long int>(205,0));
         for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                sumMatrix[i+1][j+1] = myMatrix[i][j] +  sumMatrix[i+1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
            // prefix sum for every vector
        long long sum = 0;
        for(int i = row1; i <= row2; i++){
            sum += sumMatrix[i+1][col2+1] - sumMatrix[i+1][col1];
        }
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */