function solution(s) {
    var answer = 0;
    
    let ary = s.split(" ").map((val) => parseInt(val)).sort((a, b) => a - b);
    answer = ary[0] + " " + ary[ary.length - 1];

    return answer;
}   // 2021-06-17

// https://programmers.co.kr/learn/courses/30/lessons/12939

console.log("solution : ", solution("1 2 3 4"));
console.log("anaswer  : ", "1 4")
console.log("\n");

console.log("solution : ", solution("-1 -2 -3 -4"));
console.log("anaswer  : ", "-4 -1")
console.log("\n");

console.log("solution : ", solution("-1 -1"));
console.log("anaswer  : ","-1 -1")
console.log("\n");