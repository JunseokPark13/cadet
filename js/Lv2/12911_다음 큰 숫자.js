function solution(n) {
    const getCountofOne = (str) => {
        return str.toString(2).length - (str.toString(2)).replace(/1/g, "").length
    }

    let countofOne = getCountofOne(n);

    while (1){
        if(countofOne == getCountofOne(++n))
            break;
    }

    return n;
}   // 2021-06-17

// https://programmers.co.kr/learn/courses/30/lessons/12911

console.log("solution : ", solution(78));
console.log("answer  : ", 83)
console.log("\n");

console.log("solution : ", solution(15));
console.log("answer  : ", 23)
console.log("\n");