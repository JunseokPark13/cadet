function solution(n) {
    var answer = 1;
    
    for(let i = 1 ; i < n ; i++){
        let sum = 0;
        for(let j = i; j < n; j++){
            sum += j;
            if (sum == n) answer++;
            if (sum + j + 1 > n) break;
        }
    }

    return answer;
}   // 2021-06-17

// https://programmers.co.kr/learn/courses/30/lessons/12924

console.log("solution : ", solution(15));
console.log("answer  : ", 4)
console.log("\n");