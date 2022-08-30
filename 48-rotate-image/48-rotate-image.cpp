class Solution {
public:
    vector<vector<pair<int,int>>> createMask(int n){
    //  vector<vector<bool         >>       visited (n, vector<bool>         (n,0));
        vector<vector<pair<int,int>>>       mask    (n, vector<pair<int,int>>(n,{0,0}));
        for(int i = 0; i < n/2; i++){
            // top left corner
            
            //top line loop, row = i, column = j
            for(int j = 0; j < n-i-1;j++ ){
                mask[i][j] = {0,1};
            }
            //right line loop, row = j, column = n-i
            for(int j = 0; j < n-i-1;j++ ){
                mask[j][n-i] = {1,0};
            }
            //botom line loop, row = n-i, column = n-j
            for(int j = n-i; j > i;j-- ){
                mask[n-i][n-j] = {0,-1};
            }
            //left line loop, row = n-j, column = i
            for(int j = n-i; j > i;j-- ){
                mask[n-j][i] = {-1,0};
            }
        }
        return mask;
    }
    void rotate1index(vector<vector<int>>& matrix) {
        vector<vector<pair<int,int>>> mask = createMask(matrix.size());
        int n = matrix.size();
        vector<vector<int>> newMatrix (n,vector<int>(n,0));
        pair<int,int> p;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
            p = mask[i][j];
            newMatrix[i+p.first][j+p.second] = matrix[i][j];
        }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        
        // transpose
        vector<vector<int>> newMatrix(matrix.size(),vector<int>(matrix.size()));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix.size(); j++){
                newMatrix[i][j] = matrix[j][i];
            }
        }
        int temp;
        // reverse left to right
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix.size()/2; j++){
                temp = newMatrix[i][matrix.size()-1-j];
                newMatrix[i][matrix.size()-1-j] = newMatrix[i][j];
                newMatrix[i][j] = temp;
            }
        }
                                      matrix = newMatrix;
    }
};