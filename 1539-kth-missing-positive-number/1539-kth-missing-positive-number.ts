function findKthPositive(arr: number[], k: number): number {
    const missing: number[] = []
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
}
