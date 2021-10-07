function lateFunc() {
    console.log('This was done asynchronously!');
}

console.log('This is the first log');
setTimeout(lateFunc, 5000);
console.log('This is the second log');