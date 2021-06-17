function solution(files) {
    var answer = [];
    for(let name of files){
        // console.log(name);
        // console.log(name.match(/[^0-9]+$/));
        let div = {
            head : name.substr(0, name.match(/[0-9]/).index),
            number : parseInt(name.match(/[0-9]+/)[0]),
            tail : name.match(/[^0-9]+$/)[0]
        }

        console.log(div);
    }

    return answer;
}   // 2021-06-17

// https://programmers.co.kr/learn/courses/30/lessons/17686

console.log("solution : ", solution(["img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"]));
console.log("answer   : ", ["img1.png", "IMG01.GIF", "img02.png", "img2.JPG", "img10.png", "img12.png"])
console.log("\n");

console.log("solution : ", solution(["F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"]));
console.log("answer   : ", ["A-10 Thunderbolt II", "B-50 Superfortress", "F-5 Freedom Fighter", "F-14 Tomcat"])
console.log("\n");




