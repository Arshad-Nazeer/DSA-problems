/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function(x, y) {
    x=x^y;
    let count=0;
    while(x){
        count+=x&1;
        x=x>>1;
    }
    return count;
};