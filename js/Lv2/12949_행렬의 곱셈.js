function solution(arr1, arr2){
    var answer;
    let arr1_len = arr1.length;
    let arr2_len = arr2[0].length;
    let mid = arr1[0].length;

    answer = new Array(arr1_len);
    for(let i = 0; i < answer.length; i++){
        answer[i] = [];
    }

    for(let i = 0; i < arr1_len; i++){
        for(let j = 0; j < arr2_len; j++){
            let sum = 0;
            for(let k = 0; k < mid; k++){
                sum += arr1[i][k] * arr2[k][j];
            }
            answer[i][j] = sum;
        }
    }

    return answer;
}   // 2021-06-17
// https://programmers.co.kr/learn/courses/30/lessons/12949

console.log("solution : ", solution([[1, 4], [3, 2], [4, 1]], [[3, 3], [3, 3]]));
console.log("anaswer  : ", [[15, 15], [15, 15], [15, 15]])

console.log("solution : ", solution([[2, 3, 2], [4, 2, 4], [3, 1, 4]], [[5, 4, 3], [2, 4, 1], [3, 1, 1]]));
console.log("anaswer  : ", [[22, 22, 11], [36, 28, 18], [29, 20, 14]])