//sort() = method used to sort elements of an array in place.
//               Sorts elements as strings in lexicographic order, not alphabetical
//               lexicographic = (alphabet + numbers + symbols) as strings

// ---------- EXAMPLE 1 ----------
// const numbers = [1, 10, 2, 9, 3, 8, 4, 7, 5, 6];

// numbers.sort((a, b) => a - b); //FORWARD
// numbers.sort((a, b) => b - a); //REVERSE

// console.log(numbers);

// // ---------- EXAMPLE 2 ----------
// const people = [{name: "Spongebob", age: 30, gpa: 3.0},
//                             {name: "Patrick", age: 37, gpa: 1.5},
//                             {name: "Squidward", age: 51, gpa: 2.5},
//                             {name: "Sandy", age: 27, gpa: 4.0}]

// people.sort((a, b) => a.age - b.age); //FORWARD
// people.sort((a, b) => b.age - a.age); //REVERSE

// people.sort((a, b) => a.gpa - b.gpa); //FORWARD
// people.sort((a, b) => b.gpa - a.gpa); //REVERSE

// people.sort((a, b) => a.name.localeCompare(b.name)); //FORWARD
// people.sort((a, b) => b.name.localeCompare(a.name)); //REVERSE

// console.log(people);



//-----------------------------------------------------------------------
const numbers = [1, 10, 2, 9, 3, 8, 4, 7, 5, 6];
numbers.sort();
console.log(numbers); // Output: [1, 10, 2, 3, 4, 5, 6, 7, 8, 9]
//---------------------------------------------------------------------
const num = [1, 10, 2, 9, 3, 8, 4, 7, 5, 6];
num.sort((a, b) => a - b); // Ascending order
console.log(num); // Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
//---------------------------------------------------------------------------
const nu = [1, 10, 2, 9, 3, 8, 4, 7, 5, 6];
nu.sort((a, b) => b - a); // Descending order
console.log(nu); // Output: [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
//-------------------------------------------------------------------------
const fruitss = ['banana', 'apple', 'mango', 'cherry'];
fruitss.sort();
console.log(fruitss); // Output: ['apple', 'banana', 'cherry', 'mango']
//---------------------------------------------------------------
const fruits = ['Banana', 'apple', 'mango', 'cherry'];
fruits.sort();
console.log(fruits); // Output: ['apple', 'banana', 'cherry', 'mango']
//----------------------------------------------------------------------
const fruis = ['Banana', 'apple', 'mango', 'cherry'];
fruis.sort((a, b) => a.toLowerCase().localeCompare(b.toLowerCase()));
console.log(fruis); // Output: ['Apple', 'banana', 'cherry', 'mango']
