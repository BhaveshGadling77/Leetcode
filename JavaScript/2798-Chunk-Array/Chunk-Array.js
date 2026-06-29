/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let ans = []
    for (let i = 0; i < arr.length; i++) {
        let chunkarr = arr.slice(i, size + i);
        ans.push(chunkarr);
        i += size - 1;
    }
    return ans;
};
