/**
 * @param {number[]} time
 * @param {number} totalTrips
 * @return {number}
 */
const calculateMid = function(left, right){
    return left + Math.floor((right - left)/2)
}

const firstTrueBS = function(size, validationFunction, params){
    let left = 0, right = size-1, mid = 0
    let soln = mid
    while(left <= right){
        mid = calculateMid(left, right)
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
const validationFunction = function (params, k) {
    const { time, totalTrips } = params;
    let doneTrips = 0
    for (const tripTime of time) {
        doneTrips += Math.floor(k / tripTime)
        if (doneTrips >= totalTrips) return true
    }
    return doneTrips >= totalTrips
}

var minimumTime = function (time, totalTrips) {
    // F F F F S S S S
    // First true
    return firstTrueBS(10e16, validationFunction, { time, totalTrips })
};