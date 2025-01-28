// synchronous  = Executes line by line consecutively in a sequential manner 
//                             Code that waits for an operation to complete.

// asynchronous = Allows multiple operations to be performed concurrently without waiting
//                              Doesn't block the execution flow and allows the program to continue
//                             (I/O operations, network requests, fetching data)
//                             Handled with: Callbacks, Promises, Async/Await

// ASYNCHRONOUS
// Define an async function
async function fetchData() {
  try {
    // Pause execution until the fetch completes
    let response = await fetch('https://api.example.com/data');
    let data = await response.json();
    console.log(data);
  } catch (error) {
    console.error('Error:', error);
  }
}

// Call the async function
fetchData();
// async function fetchData() defines an asynchronous function.

// Inside fetchData, await fetch('https://api.example.com/data') waits for the fetch call to complete and get a response.

// Then, await response.json() waits for the response to be converted to JSON.

// If any errors occur, they are caught by the catch block.

//-----------------------------------------------------



