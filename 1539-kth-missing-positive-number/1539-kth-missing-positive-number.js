/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var findKthPositive = function(arr, k) {
    // arr = [2,3,4,7,11], k = 5
    
    // 1- Generate missing array
    //      Generated: [1,5,6,8,9,10,12,13,...]
    
    // 2- Return kth element
    
    
    let i = 1
    let index = 0
    // 1.1- Create generated array
    let kth = 0
    let kthCounter = 0
    // 1.2- Generate k elements
    while (kthCounter < k){
        // Keep generating
        
        // Push i if i doesn't exist in arr
        if (arr[index] !== i){
            // Not found
            ++kthCounter
            kth = i
        } else 
            ++index
        ++i
    }
    return kth
};

    