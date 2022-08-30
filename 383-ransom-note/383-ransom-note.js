function makeArray( length, val) {
  var arr = [];
  for(let i = 0; i < length; i++) {
      arr[i] = val;
  }
  return arr;
}
 
var canConstruct = function(ransomNote, magazine) {
   // var visited = makeArray(grid[0].length,grid.length,0);
  var visited = makeArray(26,0);

  if(ransomNote.length > magazine.length) return false;
  for(var c in magazine){
      visited[magazine.charCodeAt(c)- 'a'.charCodeAt(0)]++;
  }

  for(var c in ransomNote){
      if(visited[ransomNote.charCodeAt(c)- 'a'.charCodeAt(0)] == 0) return false;
      visited[ransomNote.charCodeAt(c)- 'a'.charCodeAt(0)]--;
  }
  return true;
  
};
