/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var findKthPositive = function(arr, k) {
    const missing = []
    let current = 1
    let index = 0
    while (missing.length < k){
        if (arr[index] === current)
            ++index
        else
            missing.push(current)
        ++current
    }
    return missing[k-1]
};
