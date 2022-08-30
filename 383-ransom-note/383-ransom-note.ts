

function makeArrayts( length : number, val : number) : Array<number>{
    var arr : Array<number> = [];
    for(let i = 0; i < length; i++) {
        arr[i] = val;
    }
    return arr;
  }
   
  function canConstruct(ransomNote: string, magazine: string): boolean {
     // var visited = makeArray(grid[0].length,grid.length,0);
    var visited = makeArrayts(26,0);
  
    if(ransomNote.length > magazine.length) return false;
    for(var c of magazine){
        visited[c.charCodeAt(0)- 'a'.charCodeAt(0)]++;
    }
  
    for(var c of ransomNote){
        if(visited[c.charCodeAt(0)- 'a'.charCodeAt(0)] == 0) return false;
        visited[c.charCodeAt(0)- 'a'.charCodeAt(0)]--;
    }
    return true;
    
  };