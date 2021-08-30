var images = [
    ".\\img\\1.jpg",
    ".\\img\\2.jpg",
    ".\\img\\3.jpg",
    ".\\img\\4.jpg",
    ".\\img\\5.jpg",
  ];

var currentIndex = 0; 

var incrementIndex = function(){
    console.log(currentIndex);
    currentIndex = currentIndex +  1;
    if(currentIndex > images.length - 1){
        currentIndex = 0;
    }

    return currentIndex;
}

var decrementIndex = function(){
    console.log(currentIndex);
    currentIndex = currentIndex - 1;
    if(currentIndex < 0){
        currentIndex = images.length - 1;
    }
    return currentIndex;
}

var img = document.querySelector('img');
var next = document.getElementById('next-button');
var prev = document.getElementById('prev-button');

next.onclick = function(){
    img.setAttribute('src', images[incrementIndex(currentIndex)]);
}

prev.onclick = function(){
    img.setAttribute('src', images[decrementIndex(currentIndex)]);
}