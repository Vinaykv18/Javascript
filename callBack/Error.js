// Error = An Object that is created to represent a problem that occurs
//              Occur often with user input or establishing a connection

// try { } = Encloses code that might potentially cause an error
// catch { } = Catch and handle any thrown Errors from try { }
// finally { } = (optional) Always executes. Used mostly for clean up
//                    ex. close files, close connections, release resources

// In JavaScript, an error (or exception) is an issue that arises during the execution of a script, which stops the normal flow of the program. Error handling refers to the process of catching and managing these errors gracefully, so they do not crash the application or provide poor user experiences.

const prompt = require('prompt-sync')();
try{
    const dividend = Number(prompt("Enter a dividend: "));
    const divisor = Number(prompt("Enter a divisor: "));
    
    if(divisor == 0){
        throw new Error("You can't divide by zero!");
    }
    if(isNaN(dividend) || isNaN(divisor)){
        throw new Error("Values must be a number");
    }

    const result = dividend / divisor;
    console.log(result);
}
catch(error){
    console.error(error);
}
finally{
    console.log("This always executes");
}

console.log("You have reached the end!");



//Types of Errors
// 1:Syntax Errors: These occur when the code contains incorrect syntax, such as missing brackets or misspelled keywords.

// Example:

// javascript
// console.log("Hello World" // Missing closing parenthesis
// 2:Runtime Errors: These occur during the execution of the code. They are usually caused by incorrect logic or operations that cannot be performed.

// Example:

// javascript
// let a;
// console.log(a.length); // a is undefined, cannot read property 'length'
// 3:Logical Errors: These occur when the code runs without throwing any errors, but the output is not as expected. These are the hardest to debug.

// Example:

// javascript
// let a = 5;
// let b = 10;
// let sum = a - b; // Logical error, should be a + b
// console.log(sum);