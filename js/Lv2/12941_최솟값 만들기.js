function solution(A, B) {
    var answer = 0;
    
    A.sort((a, b) => a - b);
    B.sort((a, b) => b - a);

    for(let i = 0; i < A.length; i++){
        answer += A[i] * B[i];
    }

    return answer;
}   // 2021-06-17

// https://programmers.co.kr/learn/courses/30/lessons/12941

console.log("solution : ", solution([1, 4, 2], [5, 4, 4]));
console.log("anaswer  : ", 29)
console.log("\n");

console.log("solution : ", solution([1, 2], [3, 4]));
console.log("anaswer  : ", 10)
console.log("\n");