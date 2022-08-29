/**
 * @param {character[][]} grid
 * @return {number}
 */
function makeArray(w, h, val) {
    var arr = [];
    for(let i = 0; i < h; i++) {
        arr[i] = [];
        for(let j = 0; j < w; j++) {
            arr[i][j] = val;
        }
    }
    return arr;
}
function exploreNode( grid, visited, x, y){
    if(x < 0 || y < 0 || x == grid.length || y == grid[x].length || visited[x][y]){
        return true;
    }
    visited[x][y] = true;
    if(grid[x][y] == '1'){
        // explore
        exploreNode(grid,visited, x-1,y); exploreNode(grid,visited, x,y-1);

        exploreNode(grid,visited, x+1,y); exploreNode(grid,visited, x,y+1);
    }
    return true;

}

var numIslands = function(grid) {
var visited = makeArray(grid[0].length,grid.length,0);
    
    var count = 0
    for (var i = 0; i <grid.length ; ++i) {
        for (var j = 0; j <grid[i].length; ++j) {
            if(visited[i][j] == 0 && grid[i][j] == '1') count += exploreNode(grid, visited,i,j);
        }
    }
    return count
    
};