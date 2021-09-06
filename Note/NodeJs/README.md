# NodeJs

## Why Node.js?

1. Node.js works great for **data-intensive** applications.
2. Same programming language for front-end and back-end developers.
3. Lightweight and consumes fewer resources.

## What is Node.js
* **Open-source**: Node.js has a healthy community of collaborators who work on keeping Node.js feature-rich and up-to-date.
* **Cross-platform**: Node.js applications can be run on Windows, macOS, or Linux.
* **Runtime environment**: Node.js is built on Google Chrome’s V8 engine and provides everything you need to run JavaScript outside the browser.

## Concurrency and Event Loop
Node.js provides us with several APIs that allow us to make asynchronous call.

### Event Loop
The event loop is initialized when Node.js runs. It can perform otherwise blocking operations in a non-blocking manner. The event loop can be further broken down into phases, but that is beyond the scope of this course.

### Event Queue
The event queue stores incoming events in an orderly fashion. It then passes those events one-by-one to the event loop.

### API pool
The API pool consists of all the APIs that Node.js provides to execute blocking events asynchronously.

```Javascript
function lateFunc() {
    console.log('This was done asynchronously!');
}

console.log('This is the first log');

setTimeout(lateFunc, 5000);

console.log('This is the second log');
```

The CallStack is as follow
| Step | Event Queue | API pool | note |
| ---| ---| ---|---|
| 0 | log("first")... |  all idle | put log call to queue|
| 1 | empty           | all idle   | execute log call|
| 2 | setTimeout()... | all idel   | load setTimeout to queue|
| 3 | empty | assign 1 api to do setTimeout   | |
| 4 | log("second")... | api 1, other idel| add log second to queue |
| 5 | empty | api 1, other idel| api 1 execute while second logged|
| 6 | log(This was..) | all idel| put log to queue|
| 7 | empty | all idel| pring this was...|
