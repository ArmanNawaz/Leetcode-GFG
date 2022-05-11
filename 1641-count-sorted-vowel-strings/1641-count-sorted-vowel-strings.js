/**
 * @param {number} n
 * @return {number}
 */

function recurse(n, idx) {
    if(idx >= 5 || n == 0) {
        if(n == 0)
            return 1;
        return 0;
    }
    
    return recurse(n - 1, idx) + recurse(n, idx + 1);
}

var countVowelStrings = function(n) {
    return recurse(n, 0);
};