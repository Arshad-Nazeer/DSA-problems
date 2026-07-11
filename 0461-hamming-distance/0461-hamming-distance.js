/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function(x, y) {
    x=x^y;
    let count=0;
    for(let i=0; i<32; i++){
        count+=x&1;
        x=x>>1;
    }
    return count;
};