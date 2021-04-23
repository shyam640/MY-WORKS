// In simple console log is something like if we wish to show something in console window
// You will get to know more about it below
// For now just assume this as when we want to see some javacode on our webpage we just use console window.

// I have putted all code in single file I would recommend to try each line in console
// A line gap means that block of code is finished and that whole block need to be executed completely .

// Tip : In console window do not press 'Enter' to go to next line use 'shift+Enter' .

// In js u can use semicolon at end of line or do not use as u wish .....but it is recommended to use it to make it 
//look correct

// ######################################    Topic 1 : Doing some Basics      ###################################################################

console.log("Hello World !"); // Writing first console log
console.log(4 + 34); // This performs addition similarly u can do more operations and do not forget BODMAS
console.log(34); // Displaying integer
console.log(true); // displaying boolean
console.log([34, 2, 1, 2]); // Displaying array
console.log({ harry: "this", marks: 34 }); //Displaying text in same format
console.table({ harry: "this", marks: 34 }); // Displaying text in form of a table
console.warn("This is a warning"); // Displaying a warning
// console.clear();                                      // for clearing the console
console.timeEnd("Your Code took "); // It will give time taken to execute javascriipt
// console.assert(566<189, 'Age>189 is not possible');               // Boolean check for condition
console.error("This is an error"); // This will display an error

// ######################################    Topic 2 : Variables in JS      #####################################################################

// Three type of variable declaration : var , let , const
// In js you don't need to define type of variable it will automatically detect.
var Name = `@its_shyam640`; // String variable

// One more thing when declaring string then it is recommended to use backcomma (` `) why??   because it considers string passed to be string even it consist of mix of char and int .
/* var help = 'shyam640';       // this will show error while printing to console window    ( I would recommend to try it)
   var help = `shyam640`        // this will be printed as a string
*/

var temp; // Undefined variable
var number = 8817719155; // Integer Variable
// temp = ' if value is assigned then something is prited on console else undefined will be printed';
console.log(Name, temp, number);

/*    Rules to define Variables :-
      1. Cannot start with numbers
      2. can start with $ and _ but try avoiding it
      3. Are case sensitive (means A and a are two different variables for it)
*/

/* Most asked question : Why it is recommended to use let or const instead of var ?? 
      Answer is :           When u define variable with var , if u use the same variable another place it will be reused while defining it with    let or const will result into an error . 
*/

var _city = "Gwalior";
console.log(_city);

const owner_name = "Shyam Sundar Vashishtha";
console.log(owner_name);

const fruit = "Apple";

{
  let city = "Joura";
  city = "Kolkata";
  console.log(city); // Kolkata is printed here
}
console.log(city); // Same here Kolkata is printed as it is overided

const arr = [12, 23, 13, 46, 7]; // Defining array
// arr.push(67);                                // push function is to push element at end of array
console.log(arr); // Display array

/* Different types of text-writting styles (Note : Names written below are in their respective way)
   1. camelCase
   2. Kebab-case
   3. snake_case
   4. PascalCase
*/

// ##############################   Topic 3 : Different Datatypes    ########################################################################

/* Types of Data Types in JS
      1. Primitive DataType
            a. Stack    b. String(Harry) , Numbers(56) , Boolean(true/false) , Null() , Undefined , Symbol
      2. Reference DataType
            a. Heap     b. Arrays , Object , literals , funtion , Dates
*/

// Primitive Datatypes

// Defining Strinng
let _name = "its_shyam640";
console.log("My Username is " + _name);
console.log("My Username is " + typeof _name); // typeof tells about the type of variable.

// Defining Numbers
let _number = 8817719155;
console.log("My number is " + _number);
console.log("My number is " + typeof _number);

// Defining Boolean
let knowDriving = true;
console.log("Do I know Driving " + knowDriving);
console.log("Do I know Driving " + typeof knowDriving);

// Defining  Null
let nullVar = null;
console.log("Datatype defined is " + nullVar);
console.log("Datatype defined is " + typeof nullVar);

// Defining Undefined
let unDef = undefined;
console.log("Datatype defined is " + unDef);
console.log("Datatype defined is " + typeof unDef);

// Reference Datatype

// Defining Array
let myarr = [1, 2, 3, 4, false, "string"];
console.log("Datatype defined is " + myarr);
console.log("Datatype defined is " + typeof myarr);

// Object Literals
let stMarks = {
  shyam: 89,
  anshul: 99,
  shivam: 55,
};
console.log(stMarks);
console.log(typeof stMarks);

// Defining functions
function findname() {
  console.log("This function worked.");
}
console.log(findname);
console.log(typeof findname);

// Defining date
let date = new Date();
console.log(date);
console.log(typeof date);

//  ################################    Topic 4 : Type conversion and type coercion    #############################################################

// Type conversion
let intVar = 35;
console.log(intVar);
let strCnvrsn;
strCnvrsn = String(34); // Integer converted to string
console.log(strCnvrsn, typeof strCnvrsn); // typeof gives type of variable

let date = String(new Date()); // Date gives the current date and time
console.log(date.toString()); // Another method to convert integer to string using toString() function
console.log(date, typeof date);

let arr = String([1, 2, 3, 4, 5]);
console.log(arr, length, typeof arr);

let stri = Number("3434");
console.log(stri, typeof stri);

stri = Number("343d4");
console.log(stri, typeof stri); // This is going to give error as it is mixture of int and char.

stri = Number(false);
console.log(stri, typeof stri); // Boolean values containg corresponding 0 and 1 in integer so here 0 is printed

stri = Number([1, 2, 3, 4, 5, 6]);
console.log(stri, typeof stri);

let FloatNum = parseFloat("253.634");
console.log(FloatNum, typeof FloatNum); // Another method of conversion using parse funtion
console.log(FloatNum.toFixed(2)); // toFixed() is used to set precision

let int_Num = parseInt("4366");
console.log(int_Num, typeof int_Num); // Output : 4366 int

// Type coercion
let str1 = "436";
let int1 = 45;
console.log(str1 + int1); // Output : 43645
str1 = Number("436");
console.log(str1 + int1); // Output : 481

// ###################################  Topic : Js Errors and Error Handling ( Try , Catch and Finally )    ################################################

/* 
   Basic Errors : Syntax Error , Runtime Error and Logical Error
      a. Try-catch
      b. Try-finally
      c. Try-catch-finally
      
      // let arr = [2,5,1]                       // const arr = [2,5,1]                                           const arr = [2,5,1]
      try{                                        try{                                                            try{                                             
          // Some text                                // some text                                                   // Some text                                                  
      }                                           }                                                               }                                           
      catch(e){                                   finally{                                                        catch(e){     arr = [2,1];                                                   
         console.log(e.message);                      console.log("Error !"); OR console.log(e.message);              console.log(e.message)                                                                                             
      }                                           }                                                               }
                                                                                                                  finally{
                                                                                                                     arr.Sort();
                                                                                                                  }  
      //Error : arr not defined                  // Error : Error !                                              // Error : arr defined constant 
      
      Try -> this keyword is used to check for error in a block of code and it is paired with atleast one catch/clause or finally keyword .
      catch -> this keyword throws an error written inside it or by default error. 
      finally -> using this keyword is optional and this is always used after a try or catch keyword . It is used to throw an error or do some operations
      
==> Throwing an exception : 
         Throw keyword throws an error to console window . Their are two ways to throw an error :
         a. Throw value
         b. Throw custom error

         Throw value => 
         Ex:    function throwString(){                   function throwFalse(){                      function throwNumber(){
                  throw "This is error";                    throw false;                                    throw -1;
               }                                         }                                            }

               try{
                  throwString();  OR  throwFalse();  OR  throwNumber();
               }
               catch(e){
                  conosole.log(e);
               }

         Throw custom Error =>
         Ex:    function throwMyError(){
                  throw new Error("This is error");
                }
                try{
                   throwMyError();
                }
                catch(e){
                   console.log(e.message);
                }

         e => Above many times i used 'e' , It is just like something storing something . sometimes it stores error ,sometimes click events and more.
*/

// ###########################  Topic 5 : String properties and Methods & Template Literals in Javascript     ###############################

// Printing an string
console.log("This is its_shyam640");
const name2 = "Shyam";
const greeting = "Hello ";
console.log(greeting + name2); // Here space b/w strings will be there as after hello i gave space but to give space by ourself add' 'in b/w

// concatinating of string
// Method 1
let html;
html = "<h1>this is a heading</h1>" + "<p>This is a paragraph</p>";

// Method 2
html = html.concat("this is a heading", "this is a paragraph");
console.log(html);

// Sting inbuilt functions
console.log(html.length); // function gives the length of string
console.log(html.toUpperCase()); // function converts string to uppercase
console.log(html.toLowerCase()); // function converts string to uppercase
console.log(html[1]); // Gives character at index 1
console.log(html.indexOf("<")); // Gives first index of char. <
console.log(html.lastIndexOf("<")); // Givers last index of char. >
console.log(html.charAt(3)); // gives character at 3 position
console.log(html.endsWith("dsfsdfd")); // gives string ending with passed string
console.log(html.includes(" fg")); // Gives the string that includes characters fg
console.log(html.substring(1, 6)); // Gives sub string from 1 to 6
console.log(html.slice(-4)); // Gives last 4 characters of string
console.log(html.split(">")); // Splits the string after >
console.log(html.replace("this", "it")); // replaces the string 'this' with 'it'

// Declaring String in another way
let g1 = "piyu";
let g2 = "shivam";
let g3 = "shyam";
let myhtml = `Hello ${g3} <h1>This is something more</h1><p>${g3} likes ${g1}</p><h3>He has friends like ${g2} and ${g1}</h3>`;

document.body.innerHTML = myhtml; // This is used to display my javascript code in html body

/* More String Funtions : 
            String.charAt()   String.concat()   String.includes()    String.endsWith()    String.indexOf()     String.lastIndexOf()    String.match()
            String.normalize()   String.repeat()   String.replace()     String.search()   String.slice()    String.split()    String.startsWith()
            String.substr()   String.substring()   String.toLowerCase()    String.toUpperCase()    String.trim()
      */

// ##############################   Topic 6 : Arrays and Objects In JS     ###################################################################

const Students = ["Shyam", "Ayushi", "Shivam", "Piyu", "Nikhil"];
const FruitTheyLike = ["Mango", "Grapes", "Apple", "Pineapple"];
const mixedArray = ["str", 89, [3, 5]];

const arr = new Array(64, 636, 22, "Banana");
console.log(arr);
console.log(mixed);
console.log(fruit[0]);

let value = FruitTheyLike.indexOf(22);
console.log(value); // Gives position where 22 is present.

// Mutating or modifying arrays
Students.push("Krishna"); // Pushes element at last
Students.unshift(5264); // Pushes element at starting
Students.pop(); // Pops element from end
Students.shift(); // pops element from starting
Students.splice(2, 3); // this function removes element from 2 to 3 i.e. 1 element
Students.reverse(); // This function reverse array
let moreFruits = ["BlackGrapes", "Kiwi"];
FruitTheyLike = FruitTheyLike.concat(moreFruits);
console.log(FruitTheyLike);

// Creating objects (You will learn more about objects below)
let myobj = {
  firstName: "Shyam",
  middleName: "Sundar",
  lastName: "Vashishtha",
  isActive: true,
  number: [8, 8, 1, 7, 7, 1, 9, 1, 5, 5],
};
console.log(myobj); // Displayed same as above written
console.log(myobj["firstName"]);
console.log(myobj.firstName);

// #############################   Topic 6 : Condition Operators and If Else statements and switch statements ######################################
const age = 65;
// If Else statements
if (age < 18) console.log("You are not allowed to Vote");
else if (age === 65)
  // Here triple equal to means datatype and value both are same
  console.log("Your age is 65 .  You are allowed to vote");
else console.log("You are allowed to vote");

// More If Else conditions
age = "65";
if (age !== 65)
  // It means value is same but datatype is not same
  console.log("Value is same but type is not same");

if (age > 50 && age < 80) console.log("Your age is between 50 to 80");
else if (age < 50 || age > 80)
  console.log("You are either below 50 or above 80");

// Switch statement
switch (age) {
  case 18:
    console.log("You are 18");
    break;
  case 65:
    console.log("Your age is 65");
    break;
  default:
    break;
}

// For , while , Do while loops
let z = 1;
z++;
z += 1;
console.log(z);

// for loop
for (let i = 0; i < 100; i++) console.log(i);

// while loop
let k = 0;
while (k < 10) {
  console.log(k);
  k++;
}

// do while loop
do {
  // Do not forget about the break and continue statement
  console.log(k + 1);
  k += 1;
} while (k < 10);

// array displaying
let arr = [2, 4, 1, 6, 4, 6];
// Method 1 to display array
arr.forEach(function (element) {
  console.log(element);
  console.log(element, index, arr);
});
// Method 2 to display array
for (let i = 0; i < arr.length(); i++) console.log(arr[i]);

// Tip :  always try using object way which is cool and also will help you in most of the programming languages
let object = {
  obName: "Vashi",
  age: 18,
  type: "Programmer",
  os: "Windows",
};
for (let key in boject) console.log(`${key} of objects is ${object[key]}`);

// #################################      Topic 7 : functions in JS    ######################################################################

// Method 1 to define function
function something(name3, name4) {
  console.log(
    `${name3} and ${name4} Lorem ipsum dolor sit amet consectetur adipisicing elit. voluptatibus voluptatem, rem iste delectus quisquam quasi vero? Illo consectetur quia debitis fugiat.`
  );
  return 4;
}
let name3 = "shivam";
let name4 = "piyu";
let val3 = something(name3, name4);

// Method 2 to define function
const obj = {
  name: "its_shyam640",
  game: function () {
    return "Coding";
  },
};
console.log(obj.game());

// ############################      Topic 8 :  Manipulating website using JS and DOM      ##################################################

// DOM -> Document Oject Model
let a = window;
console.log(a);

alert("This is working");
// or u can write
// window.alert('This is working');

let z = prompt("This will create a prompt window to store value in variable z");
// or u can write
// window.prompt('this is also correct');
console.log(z);

// I have used same varible to save time but you have to use different variable if u do these operations in single file .
// These are some old js codes which might not be used now because we now have more advanced css , Bootstrap and SASS .
// I would recommend u to try these once in your browser .

let b = innerWidth;
console.log(b);

b = window.outerHeight; // similarly many more things are there so try using these
console.log(b);

b = scrollY;
console.log(b);

b = scrollX;
console.log(b);

b = location;
console.log(b);

b = location.toString();
console.log(b);

b = window.history; // This gives the history of your page
console.log(b);

// In console if u type
history(-1); // this will take you one step back .... Inshort it behaves like back and forward button in your webpage .

let t = document;
console.log(t); // this will show all tag in console
//t = document.all;
// console.log(t);
t = document.body;
console.log(t); // This will give body tag
console.log(document.head); // This will give head tag

let y = document;
// y.forEach(function(element){              // This will give an error as it is not a array
//    console.log(element);
// })
Array.from(y).forEach(function (element) {
  // Converting y to array then printing
  console.log(element);
});

let p = document.links;
console.log(p);

// Topic 9 : DOM Selectors
/* Element Selectors: 
      a. Single Element Selector
      b. Multi Element Selector
*/

let element = document.getElementById("heading"); // Selects element by id
console.log(element);
let element1 = document.getElementsByTagName("h1"); // selects element by tag name
console.log(element1);
let element2 = document.getElementsByClassName("heading"); // selects element by class name
console.log(element2);
let element3 = document.getElementsByName("somename"); // select element by name
console.log(element3);

element = element.className;
console.log(element);

element = element.childNodes;
console.log(element);

element = element.parentNode;
console.log(element);

element.style.color = "red"; // This will change color of text with id heading to red in html document
console.log(element);

element.innerText = "this is some text";
console.log(element.innerText);
element.innerHTML = "<h1>In this we can use tags</h1>";
console.log(element.innerHTML);

let selet = document.querySelector("#heading"); // query selector is used to select tag,class,heading
console.log(selet);

selet = document.querySelector(".child");
console.log(selet);

selet = document.querySelector("div");
console.log(selet);

selet.style.color = "orange"; // this will change color of 1st div to orange
console.log(selet);

//######################     Topic 9 : DOM Manipulation and Traversing Nodes , Parent and Child nodes     ########################################

let c = document.querySelector(".class1");
console.log(c);
console.log(c.childNodes); // This will print all the child nodes of class .class1
console.log(c.children); // This will Print children of class .class1 means leaving some childs like comment etc.

let vrblName = c.childNodes[0].nodeName; // This will give node name of 0th child node
let vrbltype = c.childNodes[0].nodeType; //This will give node type of 0th child node
console.log(vrblName);
console.log(vrbltype);

/*   Node Types
      1 -> Element
      2 -> Attribute
      3 -> Text Node
      8 -> comment
      9 -> document
      10 -> docType
*/

// Tip : Try all these manipulations over a website .

console.log(class1.firstChild);
console.log(class1.firstElementChild);
console.log(class1.lastElementChild);
console.log(class1.lastElementChild);
console.log(class1.firstElementChild.nextElementSibling);
console.log(class1.firstElementChild.nextElementSibling.nextElementSibling);

// creating an element using js
// Remember all the functions discussed below.

let elm = document.createElement("li"); // creating a tag or element
let text = document.createTextNode("This is some text"); // creating text
elm.appendChild(text); // Adding text to tag li created using elm

elm.className = "objCls"; // This adds name to class of element created by elm i.e. li
elm.id = "objId"; // This adds id to class of element created by elm i.e. li
elm.setAttribute("title", "objTtl"); // This will add title to li
elm.innerText = "This tag is created using js"; // This will add text to li but if we use <b> tag here it will not bold the text
elm.innerHTML = "<b>The tag is bolded</b>"; // This will add bolded text to li

let ul = document.querySelector(".class2"); // Selecting tag with class name class2
ul.appendChild(elm); // This will add li tag to tag with class name class 2
console.log(ul);
console.log(elm);

// Replacing element
let elm2 = document.createElement("h4"); // creating element
elm2.id = "elem2"; // Adding id to element h4
elm2.className = "elem2"; // Adding class name to element h4
let textNode = document.createTextNode("This need to be replaced"); // Adding text to element
elm2.appendChild(textNode); // This will add text to tag created by elm2
elm.replaceChild(elm2); // This will replace element elm to elm2

let newul = document.getElementById("myid");
newul.replaceChild(elm, document.getElementById("rplctext"));
newul.removeChild(document.getElementById("rmvtext"));

let pr = elm2.hasAttribute("href");
console.log(pr); // This will return false as elm2 has no 'href' attribute

elm2.removeAttribute("id");
elm2.setAttribute("title", "elm2Title");
console.log(elm2);

// ########################################      Topic 10 : Event and Event Objects      ######################################################

document.getElementById("evntBtn").addEventListener("click", function (e) {
  // addEvenetListner is to fire some cases
  // You can understand it more by changing click to mouseover and open console window simultaneously to check something cool.
  console.log(e.target); // This will show if u have clicked at place with id evntBtn
  console.log(e.target.className); // This will give the class name of the clicked id evntBtn
  console.log(Array.from(e.target.classList)); // This will give the class list of the clicked id evntBtn

  let xpos = e.offsetX; // This will give x coordinate of the clicked position of element with id evntBtn
  let ypos = e.offsetY; // This will give the y coordinate of the clicked position of element with id evntBtn
  console.log(xpos, ypos);

  let clntX = e.clientX; // This will give x coordinate of the clicked position of element with id evntBtn from client side
  let clmtY = e.clientY; // This will give x coordinate of the clicked position of element with id evntBtn  from client side
  console.log(clntX, clntY);
});

let btn = document.getElementById("newBtn");
btn.addEventListener("click", func1);
btn.addEventListener("dblclick", func2);
btn.addEventListener("mousedowm", func3);

function func1(e) {
  e.preventDefault();
}

function func2(e) {
  console.log("This is a double click");
}

function func3(e) {
  console.log("This is a mouse dowm");
}

// More Events are mouseenter and mouseleave and mousemove

// Let me tell u something really cool thing
document.getElementById("fullBody").addEventListener("mousemove", function (e) {
  console.log(e.offsetX, e.offsetY);
  document.body.style.backgroundColor = `rgb(${e.offsetX},${e.offsetY},73)`; // This will change color of html page on mouse move
});

// This is used when we make games using js.

// ###################################    Topic 11 : Local Storage and Session Storage    ########################################################

// You might have seen a option Application while pressing ctrl+shift+I over any website there are options of local and session storage.

localStorage.setItem("Name5", "its_shyam640"); // adding key = Name5 and value = its_shyam640 to local storage
localStorage.setItem("Name6", "piyu");
// localStorage.clear();                                          // To clear local storage
localStorage.removeItem("Name6");

let arry = ["This", "is", "an", "array"];
localStorage.setItem("myarry", arry);
localStorage.getItem("myarry"); // When u type this line in browser's console window u will get arry in string form
localStorage.setItem("myarry", JSON.stringify(arry)); // This changes string array to an simple array
localStorage.getItem("myarray"); // When u type this line in browser's console window u will get arry in array form

// Local Storage remains over the browser forever until u clear it manually even if you close the browser window but Session Storage is cleared by
// default as soon as you leave a browser .

//#############################    Topic 12 : Object Literals , constructors and Object oriented js    #########################################

// creating an object
let car = {
  name: "kwid",
  topSpeed: "110",
  run: function () {
    console.log("car is running");
  },
};

// creating an object function
function GeneralCar(givenName, GivenSpeed) {
  this.name = givenName;
  this.topSpeed = GivenSpeed;
  this.run = function () {
    console.log(`${this.name} is running`);
  };
}

car1 = new GeneralCar("SUV200", 180);
car2 = new GeneralCar("swift", 120);
car3 = new GeneralCar("cruize", 200);
console.log(car1);

// Creating objects is useful when doing repeated work

// Creating object using literals
let obj = {
  name: "its_shyam640",
  type: "student",
  work: "coder",
};

// creating Object Prototype
function Obj(givenName) {
  this.name = givenName;
}

Obj.prototype.getname = function () {
  return this.name;
};

let obj2 = new Obj("Prince");
console.log(obj2);

// Object Prototype is nothing much . It is something like object which is created before and we just adds our work by creating object prototype to
// avoid object changing

//#####################################    Topic 13 : Prototypes ,Inheritance and Object oriented js    ###########################################

// Creating a Prototype
const proto = {
  slogan: function () {
    return `This is some text`;
  },
  changeName: function (newName) {
    this.name = newName;
  },
};

// Creating object method 1
const objPrto = Object.create(proto);
objPrto.name = "shyam";
objPrto.role = "Programmer";
// objPrto.changeName('its_shyam640');
console.log(objPrto);

// Creating object method 2
const objPrto1 = Object.create(proto, {
  name: { value: "piyu", writable: true }, // writable:true is used bcoz if we change name using changeName it is not changed if we do not use writable
  role: { value: "Coder" },
});
objPrto1.changeName("its_shyam640");
console.log(objPrto);

// creating object function
function Employee(newNAME, salary, experience) {
  this.name = newNAME;
  this.salary = salary;
  this.experience = experience;
}

// creating object function prototype
Employee.prototype.slogan = function () {
  return `This is something new ${this.name}`;
};

// function
let NewObj = new Employee("its_shyam640", 70000, 1);
console.log(NewObj);

// creating constructor function
function Programmer(AgainName, AgainSalary, AgainExperience, Language) {
  Employee.call(this, newName, salary, experience);
  this.Language = Language;
}

// This method of prototype is not used now because after the arival of ES6
Programmer.prototype = Object.create(Employee.prototype);

Programmer.prototype.constructor = Programmer;

let ayushi = new Programmer("Ayushi", 2, 0, "C++");
console.log(ayushi);

//#####################################    Topic 14 : ES6 and classes and Inheritance    #######################################

// Creating object using class
class Employee {
  constructor(givenName, givenExperience, givenDivision) {
    this.name = givenName;
    this.experience = givenExperience;
    this.division = givenDivision;
  }
  somText() {
    return `This is ${this.name} and I'm a coder with ${this.experience}`;
  }
  joiningYear() {
    return 2021 - this.experience;
  }
  static add(a, b) {
    return a + b;
  }
}

clsObj = new Employee("its_shyam640", 1, "cs"); // creating object
console.log(clsObj);
console.log(clsObj.joiningYear());
console.log(Employee.add(33, 5)); // Calling static functions is done directly we don't need object

// showing Inheritance to create new object
class Programmers extends Employee {
  constructor(giveName, givenExperience, givenDivision, github) {
    super(givenName, givenExperience, givenDivision);
    this.Language = lang;
    this.github = github;
  }
  favouriteLanguage() {
    if (this.Language == "python") return "Python";
    else return "C++";
  }
  static multiply(a, b) {
    return a * b;
  }
}

pihu = new Programmers("pihu", 1, "cs", "C++", "pihu520");
console.log(pihu);
console.log(pihu.favouriteLanguage());
console.log(Programmers.multiply(35, 2));

//#####################################    Topic 14 : Synchronous and Asynchronous     #######################################

// Synchronous -> This means single thing to be happened at single time . In other words , when we ask server for packets of data
//               then in this method firstly first packet is brought then other packets one by one .
// Time taken in this method is equal to sum of time taken to bring each packet .

// Asynchronous -> This means performing several tasks at the same time . In other words , when we ask server for packets of data
//               then in this method it creates several copies or objects to get different packets at the same time .
// Time taken in this method is equal to the maximum time taken to bring most traffic data .

for (let index = 1; index < 4004; index++) {
  const elmnt = index;
  console.log(index);
}
console.log("this work is done with Synchronous way");
// OUTPUT -> first loop will run then last log is printed .

setTimeout(() => {
  for (let index = 1; index < 4004; index++) {
    const elmnt = index;
    console.log(index);
  }
}, 100);
console.log("this work is done with Asynchronous way");
// OUTPUT -> First last log is printed then loop runs as time alloted is 100ms only for loop .

//#####################################    Topic 14 : AJAX - Asynchronous javascript and XML    ###############################

// Ajax helps in fetching data asynchronously without intefering with the current page. Now JSON is used more then XML.

// GET METHOD
const btn1 = document.getElementById("ajax-button");
btn1.addEventListener("click", ajaxFunction);

function ajaxFunction() {
  console.log("this line is printed");
  const xhr = new XMLHttpRequest();

  xhr.open("GET", "AjaxFile.txt", true); // true because process should be running in background did not stop

  // What action to be done when processing the request (optional)
  xhr.onprogress = function () {
    console.log("work is under progress !");
  };

  // This shows when the progress has changed
  //    0  =>   UNSENT            =>   Client has been created open is not called yet
  //    1  =>   OPENED             =>   open has been called
  //   2  =>   HEADERS_RECIEVED   =>   sent has been called and header and status are received
  //   3  =>   LOADING            =>   Downloading; responseText hold partial data
  //   4  =>   DONE               =>   The operation is complete

  xhr.onreadystatechange = function () {
    console.log("This function is no longer used !");
  };

  // What action to be done when loading the request
  // onload is nothing but just similar to request code 4 (DONE)
  xhr.onload = function () {
    console.log(this.responseText);
  };
  xhr.send();

  console.log(
    "This text will be shown before while other things are processing"
  );
  // This is why we wrote 'true' while getting the request.
}

// POST METHOD
const btn2 = document.getElementById("ajax-button");
btn2.addEventListener("click", POSTshowFunction);

function POSTshowFunction() {
  console.log("this line is printed");
  const xhr = new XMLHttpRequest();

  xhr.open("POST", "https://jsonplaceholder.typicode.com/todos/3", true);
  // xhr.getResponseHeader('Content-type','application/x-www-form-urlencoded');        // This is also a method
  xhr.getResponseHeader("Content-type", "application/json");

  // What action to be done when processing the request (optional)
  xhr.onprogress = function () {
    console.log("work is under progress !");
  };

  xhr.onreadystatechange = function () {
    console.log("This function is no longer used !");
  };

  // What action to be done when loading the request
  // onload is nothing but just similar to request code 4 (DONE)
  xhr.onload = function () {
    let obj = JSON.parse(this.responseText);
    console.log(obj);
  };

  params = `{
      "userId": 3,
      "id": 3,
      "title": "This is sent",
      "completed": false
    }`;

  xhr.send(params);

  console.log(
    "This text will be shown before while other things are processing"
  );
  // This is why we wrote 'true' while getting the request.
}

// Learn about the http status code . You can see my blog where i had explained all
// https://startblogwith.blogspot.com/2021/03/http-response-codes.html

const btn3 = document.getElementById("show-button");
btn3.addEventListener("click", popFunction);

function popFunction() {
  console.log("this line is printed");
  const xhr = new XMLHttpRequest();

  xhr.open("GET", "http://dummy.restapiexample.com/api/v1/employees", true); // true because process should be running in background did not stop

  xhr.onload = function () {
    if (this.status === 200) {
      let obj = JSON.parse(this.responseText);
      console.log(obj);
      let list = document.getElementById("list");
      let str = "";
      for (key in obj) {
        str += `<li>${obj[key].employee_name}</li>`;
      }
      list.innerHTML = str;
    } else {
      console.error("SOME ERROR OCCURED !");
    }
  };
  xhr.send();

  console.log("This is fething through get method");
}

//#####################################    Topic 15 : Callbacks in javascript       ##################################

// Callback are nothing just a way calling a function inside function
const Msg = [
  { name: "Its_shyam640", message: "I love coding !" },
  { name: "anonymous", message: "I love who code" },
];

function saySomething(message, callback) {
  setTimeout(function () {
    Msg.push(message);
    console.log("message is pushed");
    callback();
  }, 3000);
}

function whoIsSaying() {
  setTimeout(function () {
    let str = "";
    saySomething.forEach(function (message) {
      str += `<li>${message}</li>`;
    });
    document.getElementById("msg-list").innerHTML = str;
    console.log("Message has been written");
  }, 1000);
}

// Now calling functions
let newMsg = { name: "SecondAnonymous", message: "I don't like coding" };
saySomething(newMsg, whoIsSaying);

//##############################    Topic 16 : Promise ,Promise.then(),promise.catch()       #########################

function tempfunc() {
  return new Promise(function (resolve, reject) {
    setTimeout(() => {
      const error = 404; // Here if we will get some error from server
      if (error != 404) {
        console.log("You Promise is done successfully !");
        console.log("Shyam : Thanks for solving");
        resolve();
      } else {
        console.log("Your promise is not fulfilled !");
        reject("This is the reason of error");
      }
    }, 2000);
  });
}
// Calling tempfunction
tempfunc()
  .then(function () {
    console.log("This is message when we have fulfilled promise");
  })
  .catch(function (error) {
    console.log(
      "This is message when we do not complete promise and its reason is : " +
        error
    );
  });

// Why do we need promise ?
// Promise is subsitute of callbacks

//##############################    Topic 17 : Arrow functions in Javascript      ##################################

// Creating a normal function
const func = function () {
  console.log("This is simple method to call function !");
};
func();

// Creating a arrow function
const func = () => {
  console.log("This is second method of calling function !");
};
console.log(func());

// writing arrow function in another way
const func = () =>
  "This statement is returned ! we do not need braces in one line return function . ";
console.log(func());

// if single argument is passed to function then we can write it as :
const func = (greeting) => "Good morning " + greeting;
console.log(func("Sir"));

// if more then one argument is passed to function then we can write it as :
const func = (greeting, salutation) => "Good morning " + greeting + salutation; // if bracket not used then we
console.log(func("Mr.", "Sir")); // will get an error



//##############################    Topic 18 : Fetch API  in JavaScript     ######################################

let firstBtn = document.getElementById('sample-btn');
let secondBtn = document.getElementById('fetch-btn');

// Sample code to understand fetching of data
// function getData(){
//    url = "fetchAPIfile.txt";
//    fetch(url).then((response)=>{
//       console.log("This fetch method promises to give data");
//       return response.text();
//    }).then((data)=>{
//       console.log("This method of double promise and fetch data is asynchronous");
//       console.log(data);
//    });
// }

// // How actually it works see below code :
function getData(){
   url = "https://api.github.com/users";                       // Actual url to get understand fetching
   fetch(url).then((response)=>{
      console.log("This fetch method promises to give data");
      // return response.text();
      return response.json();                     // returning in json format to see it clearly
   }).then((data)=>{
      console.log("This method of double promise and fetch data is asynchronous");
      console.log(data);
   });
}
getData();


// Doing post call to get to know about fetching more :
function getData(){
   url = "https://jsonplaceholder.typicode.com/posts";     // dummy url taken from google to get understand post fetching
   data = `{"name":"its_shyam640","salary":"35299","age":"18"}`         // Sample data to post
   params = {                                                              // Params is nothing just Parameters
            method: 'post',
            headers: {
               'Content-type':'application/json'               // This need to be defined 
            },
            // body: JSON.stringyfy(data)                         // To convert some data to json
            body: data                             // Here we have data in json format so no stringyfy
   }
   
   // Using arrow function to write below method in just one line
   fetch(url,params).then(response => response.json()).then(data => console.log(data));

   // This is expanded above method to understand :
   // fetch(url,params).then((response)=>{
   //    return response.json();                     // returning in json format to see it clearly
   // }).then((data)=>{
   //    console.log(data);
   // });
}
getData();


//##############################    Topic 18 : Async and await in JavaScript     ##################################
// These are used to avoid using double then 

async function temp(){
   console.log("This line is inside function");
   const response = await fetch("https://api.github.com/users");
   console.log("Before response");
   const users = await response.json();
   console.log("users fetched and ready to print");
   return users;
}
console.log("Before calling function");
let a = temp();
console.log("After calling function");
console.log(a);
a.then(data => console.log(data));
console.log("This is end line which is printed before");

// OUTPUT of above

// Before calling function                                first cosole printed
// This line is inside function                    // then it goes inside function and prints functions first console
// After calling                             // Then it sees await so it comes out of func. and then prints second console
// Promise {<pending>}                       // a.then... calls a promise but it is awaited so printed this line
// This is end line which is printed before     // Then prints third console
// Before response                              // Now outside work is finish now goes inside func. and prints console
// users fetched and ready to print                // again sees await so prints last console in func and then prints users
// (30) [{…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}, {…}]


//##############################    Topic 18 : Try,catch and throw in JavaScript     ##################################

// When to use throw?
// If you want some data in integer form and you get it in string form from api so we need to throw an error . 
// when to use try catch finally?
// when we did some mistake in code then we can use try catch or if we something to be executed when we don't know if
// its true or false then also we use try catch 

let a = false;
if(!a){
   throw new Error("This program will not execute further");
}else{
   console.log(a);
}

try{
   console.log("This line is printed");
   skjfsdjs                                               // called something which is not in js error will come
   functiontemp();
}catch(error){
   console.log("This is my custom designed error");
   // console.log(error);
   // console.log(error.name);
   // console.log(error.message);
}finally{
   console.log("If error comes or not this line is printed for sure");
}


//##############################    Topic 18 : Usage of Objects in JavaScript     ##################################

const sometempJSON = `{
   "users": [
     {
       "id": 0,
       "name": "Adam Carter",
       "work": "Unilogic",
       "email": "adam.carter@unilogic.com",
       "dob": "1978",
       "address": "83 Warner Street",
       "city": "Boston",
       "optedin": true
     },
     {
       "id": 2,
       "name": "Leanne Brier",
       "work": "Connic",
       "email": "leanne.brier@connic.org",
       "dob": "1987",
       "address": "9 Coleman Avenue",
       "city": "Toronto",
       "optedin": false
     },
     {
       "id": 3,
       "name": "Leanne Brier",
       "work": "Connic",
       "email": "leanne.brier@connic.org",
       "dob": "1987",
       "address": "9 Coleman Avenue",
       "city": "Toronto",
       "optedin": false
     },
     {
       "id": 4,
       "name": "Leanne Brier",
       "work": "Connic",
       "email": "leanne.brier@connic.org",
       "dob": "1987",
       "address": "9 Coleman Avenue",
       "city": "Toronto",
       "optedin": false
     },
     {
       "id": 5,
       "name": "Leanne Brier",
       "work": "Connic",
       "email": "leanne.brier@connic.org",
       "dob": "1987",
       "address": "9 Coleman Avenue",
       "city": "Toronto",
       "optedin": false
     },
     {
       "id": 6,
       "name": "Leanne Brier",
       "work": "Connic",
       "email": "leanne.brier@connic.org",
       "dob": "1987",
       "address": "9 Coleman Avenue",
       "city": "Toronto",
       "optedin": false
     },
     {
       "id": 7,
       "name": "Leanne Brier",
       "work": "Connic",
       "email": "leanne.brier@connic.org",
       "dob": "1987",
       "address": "9 Coleman Avenue",
       "city": "Toronto",
       "optedin": false
     },
     {
       "id": 8,
       "name": "Leanne Brier",
       "work": "Connic",
       "email": "leanne.brier@connic.org",
       "dob": "1987",
       "address": "9 Coleman Avenue",
       "city": "Toronto",
       "optedin": false
     }
   ],
   "images": [
     "img0.png",
     "img1.png",
     "img2.png"
   ],
   "coordinates": {
     "x": 35.12,
     "y": -21.49
   },
   "price": "$59,395"
 }`;

 const obj = JSON.parse(sometempJSON);
 let printbtn = document.getElementById('print-data-btn');
printbtn.addEventListener('click',()=>{
      let results = sometempJSON['images'];
      let html="";
      results.forEach(element => {
         html+=`<li class="list-group-item list-group-item-action list-group-item-info">${element.users}</li>`;
      });
      let mylist = document.getElementById('data-list');
      mylist.innerHTML = html;
 });

//##############################    Topic 18 : Usage of Objects in JavaScript     ##################################















