function varExample() {
  console.log(x); // undefined (due to hoisting)
  var x = 10;
  console.log(x); // 10

  if (true) {
    var y = 20;
    console.log(y); // 20
  }

  console.log(y); // 20 (y is accessible outside the if block)
}

varExample();

// var Scope: Function-scoped or globally-scoped if declared outside a function.

// Hoisting: Variables declared with var are hoisted to the top of their scope and can be used before they are declared.

// Re-declaration: Allowed within the same scope.
//----------------------------------------------------------

// let  Scope: Block-scoped (limited to the block, statement, or expression they are declared in).

// Hoisting: Variables declared with let are hoisted, but not initialized; accessing them before declaration results in a ReferenceError.

// Re-declaration: Not allowed within the same scope.

//  const Scope: Block-scoped (like let).

// Hoisting: Variables declared with const are hoisted, but not initialized; accessing them before declaration results in a ReferenceError.

// Re-declaration: Not allowed within the same scope.

// Assignment: Must be initialized at the time of declaration and cannot be reassigned.


//---------------------------


function letExample() {
  // console.log(a); // ReferenceError: a is not defined
  let a = 10;
  console.log(a); // 10

  if (true) {
    let b = 20;
    console.log(b); // 20
  }

  //console.log(b); // ReferenceError: b is not defined (b is not accessible outside the if block)
}

letExample();
console.log('\n')
//-----------------------------------
function constExample() {
  const c = 10;
  console.log(c); // 10

  // c = 20; // TypeError: Assignment to constant variable.

  if (true) {
    const d = 20;
    console.log(d); // 20
  }

  // console.log(d); // ReferenceError: d is not defined (d is not accessible outside the if block)
}

constExample();


