function solution(n) {
    var answer = 0;
    let mod = 1234567;
    if (n == 1 || n == 2) {
        return 1;
    }

    let a = 1;
    let b = 1;
    let sum = 0;

    for (let i = 2; i < n; i++) {
        sum = ((a % mod) + (b % mod)) % mod;
        a = b % mod;
        b = sum % mod;
    }

    answer = sum;
    return answer;
}   // 2021-06-17
// https://programmers.co.kr/learn/courses/30/lessons/12945

console.log("solution : ", solution(3));
console.log("anaswer  : ", 2)
console.log("\n");

console.log("solution : ", solution(5));
console.log("anaswer  : ", 5)
console.log("\n");

console.log("solution : ", solution(10));
console.log("anaswer  : ", 55)
console.log("\n");