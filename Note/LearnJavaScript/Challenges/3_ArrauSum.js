const arrays = [[1, 4], [11], [3, 5, 7]];

function findSum(arry){
    var sum = 0;
    for(const subArry of arry){
        sum += subArry.reduce((acc, value) => acc + value, 0);
    }
    return sum;
}

console.log(findSum(arrays));