function solution(n, t, m, p) {
    var answer = '';

    let num = 0;
    let nstr = '';
    while (1){
        nstr += num.toString(n);
        if (nstr.length >= t * m)
            break;
        num++;
    }

    let pos = 1;
    for(let i = 0; i < nstr.length; i++){
        if (pos++ == p){
            answer += nstr[i];
        }   
        if ((i + 1) % m == 0)
            pos = 1;
        if (answer.length == t)
            break;
    }

    return answer.toUpperCase();
}   // 2021-06-17

// https://programmers.co.kr/learn/courses/30/lessons/17687

console.log("solution : ", solution(2, 4, 2, 1));
console.log("answer   : ", "0111")
console.log("\n");

console.log("solution : ", solution(16, 16, 2, 1));
console.log("answer   : ", "02468ACE11111111")
console.log("\n");

console.log("solution : ", solution(16, 16, 2, 2));
console.log("answer   : ", "13579BDF01234567")
console.log("\n");



