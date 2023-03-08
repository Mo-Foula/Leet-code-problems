/**
 * @param {number[]} piles
 * @param {number} h
 * @return {number}
 */

const validate = function(params, k){
    let { piles, h } = params
    let index = 0
    while(h && index < piles.length){
        let hours = Math.ceil(piles[index]/k)
        if(hours <= h){
            // can eat
            h -= hours
            ++index
        }else{
            break
        }
    }
    return index == piles.length
}

const firstTrueBS = function(size, validationFunction, params){
    let left = 0, right = size-1, mid = 0
    let soln = mid
    while(left <= right){
        mid = left + Math.floor((right - left)/2)
        const calculation = validationFunction(params, mid)
        if(calculation){
            right = mid - 1
            soln = mid
        } else {
            left = mid + 1
        }
    }
    return soln
}



var minEatingSpeed = function(piles, h) {
    // 1, 2, 3, k, 5, 6, 7, 8, 9,....
    // F, F, F, S, S, S, S, S, S,....
    // Searching for first true
    return firstTrueBS(10e9, validate, {piles, h})
};