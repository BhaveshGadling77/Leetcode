/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let len = fn.length
    // console.log(fn(arr[0]))
    if (len == 1) {
        return arr.map((x) => fn(x))
    } 
    let ans = []
    for (let i = 0; i < arr.length; i++) {
        ans.push(fn(arr[i], i))
    }
    return ans
};