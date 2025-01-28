// callback = a function that is passed as an argument
//                    to another function.

//                    used to handle asynchronous operations:
//                    1. Reading a file
//                    2. Network requests
//                    3. Interacting with databases

//                    "Hey, when you're done, call this next."
// callback function
// In JavaScript, a callback function is a function that is passed as an argument to another function and is executed after some operation has been completed. Callback functions are a fundamental concept in asynchronous programming in JavaScript, allowing you to run code after an asynchronous task has finished.

//--------------------------------------------------------------------------
hello(goodbye);

function hello(callback){
    console.log("Hello!");
    callback();
}

function goodbye(){
    console.log("Goodbye!");
}
////-----------------------------------------------------------------------

function fetchData(callback) {
  console.log("Fetching data...");

  // Simulate a delay with setTimeout
  setTimeout(() => {
    console.log("Data fetched!");
    callback("Here is your data.");
  }, 2000); // 2-second delay
}

function processData(data) {
  console.log(`Processing: ${data}`);
}
// Call fetchData and pass processData as the callback function
fetchData(processData);


//---------------------------------------------------------------------------------
// Callback Example with Event Listeners
// Callbacks are also commonly used with event listeners:


const button = document.getElementById('myButton');

button.addEventListener('click', () => {
  console.log('Button clicked!');
});
// In this example, the anonymous function passed to addEventListener is the callback function that executes when the button is clicked.

//-----------------------------------------------------------------