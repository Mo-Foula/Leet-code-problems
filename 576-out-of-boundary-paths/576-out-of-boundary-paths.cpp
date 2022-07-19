class Solution {
public:
    
 map<pair<pair<int,int>,int>, int> memoization;
//            row col moves

vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
int findPaths(int rows, int columns, int maxMove, int startRow, int startColumn) {
    if(memoization.find({{startRow,startColumn},maxMove}) != memoization.end()){
        return memoization[{{startRow,startColumn},maxMove}];
    }
    if(startRow >= rows || startRow < 0 || startColumn >= columns || startColumn < 0 ){
        // outside
        return 1;
    }
    else if(!maxMove){
        // inside and out of moves
        return 0;
    }
    int ways = 0;
    for(auto move : moves){
        ways+=findPaths(rows,columns,maxMove-1, startRow +move.first,startColumn+move.second);
    ways = ways %(1000000007);
    }
    memoization[{{startRow,startColumn},maxMove}] = ways;
    return ways;
}

};