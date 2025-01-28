// .filter() = creates a new array by filtering out
//                 elements with a callback

// 00:00:00 example 1
// 00:02:13 example 2
// 00:04:01 example 3

// ---------- EXAMPLE 1 ----------
let numbers = [1, 2, 3, 4, 5, 6, 7];
let evenNums = numbers.filter(isEven);
let oddNums = numbers.filter(isOdd);

console.log(oddNums);

function isEven(element){
    return element % 2 === 0;
}

function isOdd(element){
    return element % 2 !== 0;
}