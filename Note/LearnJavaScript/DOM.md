# Document Object Model
The structure of HTML markup provides a **hierarchy** of elements, similar to any programming language providing a syntax tree and a semantic tree.

* query the metadata of a document
* allows access to a certain part of the document (the HTML markup).

## Accessing DOM element

### Work with Element Nodes
Each element on your HTML page has an associated **element node** in the Document Object Model, or DOM. The DOM can be accessed using Javascript through the `document` **object**.

document behaves like any other Javascript object, and has many different properties and methods that are useful in accessing nodes in the DOM.

### `document.querySelector()`  

`document.querySelector()` is a function that takes an element selector as an argument. These selectors are the same as those used to apply CSS styles to HTML elements.

`document.querySelector()` will return the first element it finds with the selector provided. If no element is found using that particular selector, the function will return as `null`.

#### Modifying HTML elements
##### `obj.innerHTML` 
It can change the display content of the obj.
```
var h1 = document.querySelector('h1');
h1.innerHTML = "We just modified HTML using Javascript!";
```

##### `Element.id`
Get id attribtue of the html node.

##### `Element.outerHTML`
Element.outerHTML returns a string-like value that contains both the content of the HTML element and its opening/closing tags.

##### more properties
https://developer.mozilla.org/en-US/docs/Web/API/Element

### `document.getElementById(id)`
```
var mainHeading = document.getElementById('mainHeading');

mainHeading.innerHTML = "Access an element with an id attribute using <code>document.getElementById()</code>";
```

### Multiple element nodes
### `document.querySelectorAll(selector)`

```
var todoItems = document.querySelectorAll('#todos > li');

for(var i = 0; i < todoItems.length; i++) {
  todoItems[i].innerHTML = "Todo Item #" + (i+1);
}
```

### `document.getElementsByTagName`
```
var headings = document.getElementsByTagName('h1');
var paragraphs = document.getElementsByTagName('p');

for(var i = 0; i < headings.length; i++){
  headings[i].style.color = "green";
}

for(var i = 0; i < paragraphs.length; i++){
  paragraphs[i].style.color = "blue";
}

```

## Add/Remove Element
### `document.createElement(element)`
Create an DOM object. 

### `Element.appendChild(element_node)`
Add the object to html DOM tree

```
<html>
 <head>
   <title>Creating New Elements</title>
 </head>
 <body>
	
 </body>
</html>

// Create
var h1 = document.createElement('h1');
h1.innerHTML = "A new HTML element!";

// Add previous item
var content = document.querySelector('#content');
content.appendChild(h1);

```

### `Element.removeChild(element_node)`
```
<html>
 <head>
   <title>Removing HTML Elements</title>
 </head>
 <body>
   <div id="content">
     <h1>Removing an HTML Element</h1>
     <p>This element will be removed.</p>
   </div>
 </body>
</html>

var content = document.querySelector('#content');
var contentParagraph = document.querySelector('#content > p');

var oldElement = content.removeChild(contentParagraph);
console.log(oldElement.innerHTML);

```

## Modifying Element Attribtues

### `Element.getAttributeNames()`
```
 </head>
 <body>
   <h1 id="logo">Learn DOM Manipulation with Javascript</h1>
   <label for="question">What do you want to learn about the DOM?</label>
   <input type="text" name="question" id="question" placeholder="Insert Question Here">
 </body>
</html>

var h1 = document.querySelector('h1');
var input = document.querySelector('input[type=text]');

console.log("input attributes:", input.getAttributeNames());

// print
[
    0 : 'type'
    1 : 'name'
    2 : 'id'
    3 : 'placeholder'

]
]

```

### `Element.getAttribute(name)`

```
 </head>
 <body>
   <h1 id="logo">Learn DOM Manipulation with Javascript</h1>
   <label for="question">What do you want to learn about the DOM?</label>
   <input type="text" name="question" id="question" placeholder="Insert Question Here">
 </body>
</html>

var h1 = document.querySelector('h1');
var input = document.querySelector('input[type=text]');

console.log("input type:", input.getAttribute('type'));

// print 
text
```
 
### `Element.setAttribute(name, value)` and `Element.removeAttribute(name)`
You can change the value of an attribute using the setAttribute() function. Additionally, you can remove attributes using the removeAttribute() function.


## Event Listeners

```
<html>
 <head>
   <title>First Javascript Code</title>
 </head>
 <body>
   <button type="button">Click Me!</button>
 </body>
</html>

var button = document.querySelector('button');

button.onclick = function() {
  alert("Hello, World!");
}

```

* the variable button stores an element node object that represents the HTML button
* since button is an object, we can define properties on it
* the onclick property acts as an **event listener**: onclick is defined as a * function, and that function will execute whenever a **click event** occurs on the `<button>` element.

### Modifying elements using `this`

Since the button variable is an object, we can use the this keyword from within the object’s methods to access its properties:

```
// random color generator 
var randomColor = function(){
  var rvalue = function() {
  	return Math.round(Math.random()*255); 
  }

 	return 'rgb(' + rvalue() + "," + rvalue() + "," + rvalue() + ")";
}

// get button element from DOM
var button = document.querySelector('button');

// create event listener to change background color on button click
button.onclick = function(){
	this.style.backgroundColor = randomColor();
}
```
### More event listeners

* Mouse Events: Events that occur with a user’s mouse
    * ondblclick: occurs when an element is double clicked
    * onmouseenter: occurs when the mouse pointer moves onto an element
    * onmouseleave: occurs when the mouse pointer moves away from an element

* Keyboard Events: Events related to keypresses on the user’s keyboard
    * onkeypress: occurs when a key is pressed on the user’s keyboard
    * onkeydown: occurs when a user is pressing down on a key
    * onkeyup: occurs when a user releases a key press

*  Form Events: Events related to interactions with form elements, such as `<input>`
    * onfocus: occurs when focus is placed on an `<input>` field
    * onchange: occurs when an `<input>`'s value is changed (useful for radio or checkbox type inputs)
    * oninput: occurs when a user provides input to an element (useful for text type inputs or `<textarea>` elements)


## Modifying CSS

### `Element.style`
For example:  
* Element.style.textAlign
* Element.style.border
* Fulllist here https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Properties_Reference


```
<html>
 <head>
   <title>Modifying CSS with Element.style</title>
 </head>
 <body>
   <h1>This element should have a border.</h1>
 </body>
</html>

var h1 = document.querySelector('h1');
h1.style.border = "3px dashed black";
```

### Programmatically styling with classese using `Element.classList`
```
<html>
 <head>
   <title>Applying Multiple Styles</title>
 </head>
 <body>
   <h1>Highlight this element on a click</h1>
 </body>
</html>

var h1 = document.querySelector('h1');

h1.onclick = function(){
  this.style.color = 'white';
  this.style.backgroundColor = 'blue';
}

```

However, a better way to add multiple styles would be to create a class with those CSS properties and then add the class to the HTML element. We can use `Element.classList` to:

* check the class values associated with an element
* add/remove classes toggle class values
* check whether a certain class is associated with an element
* replace one class with another class

```
// HTML 
<html>
 <head>
   <title>Applying Multiple Styles</title>
 </head>
 <body>
   <h1>Highlight this element on a click</h1>
 </body>
</html>

// CSS
.highlight {
  color: white;
  background-color: blue;
}


// JS to apply css style class to an node or type
var h1 = document.querySelector('h1');

h1.onclick = function(){
  this.classList.add('highlight');
}

// JS to remove css style class to an node or type
var h1 = document.querySelector('h1');

h1.onclick = function(){
  this.classList.toggle('highlight');
}

```