/**
 * @param {number[]} height
 * @return {number}
 */

var maxArea = function(height) {
    const n = height.length
    let left = 0, right = n - 1, min = 0, tempLeft, tempRight
    let bestSolution = 0
    while (left <= right){
        tempLeft = left
        tempRight = right
        if (height[left] < height[right]){
            min = height[left++]
        }   else {
            min = height[right--]
        }
        bestSolution = Math.max(min * (tempRight - tempLeft + 0), bestSolution)
        
    }
    bestSolution = Math.max(min * (tempRight - tempLeft + 0), bestSolution)
    return bestSolution
};