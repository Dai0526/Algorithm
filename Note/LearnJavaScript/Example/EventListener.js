
var addButton = document.getElementById("addTodoButton");
var todoList = document.getElementById('todoList');

addButton.onclick = add_todo_func;

function add_todo_func(){
    var li = document.createElement('li');
    var todoInfo = document.getElementById("todo").value;

    if(todoInfo == "" || todoInfo == null){
        alert("Add Item Failed: empty string");
        return;
    }

    li.innerHTML = todoInfo;
    todoList.appendChild(li);
    document.getElementById("todo").value = ""
}


// Random decorate html and button

var randButton = document.getElementById("randomButton");
randButton.onclick = random_color_count_Func;
var count = 0;

function random_color_count_Func() {
    ++count;
    var page = document.createElement('p');
    page.innerHTML = "Clicked " + count + " times!";

    var content = document.querySelector('body');
    content.appendChild(page)

    this.style.backgroundColor = randomColor();
}

function alert_func(argument) {
    alert(argument);
}

// random color generator 
var randomColor = function(){
    var rvalue = function() {
        return Math.round(Math.random()*255); 
    }
    return 'rgb(' + rvalue() + "," + rvalue() + "," + rvalue() + ")";
}

