/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let len = fn.length;
    if (len == 1) {
        let out = arr.filter((x) => fn(x))
        return out
    } 
    let ans =[]
    for (let i = 0; i < arr.length; i++) {
        fn(arr[i], i) ? ans.push(arr[i]) : false;
    }
    return ans
};