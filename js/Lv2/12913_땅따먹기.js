function solution(land) {
    const getMaxExceptPos = (ary, pos) => {
        let max = 0;
        for(let i = 0; i < ary.length; i++){
            if (i != pos && ary[i] > max){
                max = ary[i];
            }
        }
        return max;
    }

    let maxNum = Math.max(...land[0]);
    let maxpos = land[0].indexOf(maxNum);
    let maxNum2 = getMaxExceptPos(land[0], maxpos); 
    
    for(let i = 1; i < land.length; i++){
        for(let j = 0; j < 4; j++){
            if (j == maxpos) land[i][j] += maxNum2;
            else land[i][j] += maxNum;
        }
        maxNum = Math.max(...land[i]);
        maxpos = land[i].indexOf(maxNum);
        maxNum2 = getMaxExceptPos(land[i], maxpos); 
    }

    return Math.max(...land[land.length - 1]);
}   // 2021-06-17

// https://programmers.co.kr/learn/courses/30/lessons/12924

console.log("solution : ", solution([[1,2,3,5],[5,6,7,8],[4,3,2,1]]));
console.log("answer  : ", 16)
console.log("\n");
