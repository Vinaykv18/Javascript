// Helper function to generate an empty Sudoku grid (9x9)
function generateEmptyBoard() {
  return Array.from({ length: 9 }, () => Array(9).fill('.'));
}

// Function to check if a value is valid in the current row, column, and 3x3 subgrid
function isValid(board, row, col, c) {
  for (let i = 0; i < 9; i++) {
    if (board[i][col] === c) return false;
    if (board[row][i] === c) return false;
    if (board[3 * Math.floor(row / 3) + Math.floor(i / 3)][3 * Math.floor(col / 3) + i % 3] === c) return false;
  }
  return true;
}

// Helper function to solve the board
function solve(board) {
  for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
      if (board[i][j] === '.') {
        for (let c = '1'; c <= '9'; c++) {
          if (isValid(board, i, j, c)) {
            board[i][j] = c;
            if (solve(board)) return true;
            else board[i][j] = '.'; // Backtrack
          }
        }
        return false;
      }
    }
  }
  return true;
}

// Function to remove random cells to make it unsolved
function removeCells(board, difficulty = 40) {
  for (let i = 0; i < difficulty; i++) {
    const row = Math.floor(Math.random() * 9);
    const col = Math.floor(Math.random() * 9);
    board[row][col] = '.';
  }
}

// Function to generate a random valid Sudoku puzzle
function generateRandomPuzzle() {
  const board = generateEmptyBoard();
  
  // Fill the diagonal 3x3 subgrids first (simplifies solving the puzzle)
  for (let i = 0; i < 9; i += 3) {
    fillDiagonalSubgrid(board, i, i);
  }

  // Solve the board to get a complete Sudoku puzzle
  solve(board);

  // Remove random cells to make it unsolved based on difficulty
  removeCells(board);

  // Render the unsolved board to the grid
  renderBoard(board);
}

// Function to fill a 3x3 diagonal subgrid
function fillDiagonalSubgrid(board, rowStart, colStart) {
  const numbers = shuffleArray(['1', '2', '3', '4', '5', '6', '7', '8', '9']);
  let idx = 0;
  for (let i = 0; i < 3; i++) {
    for (let j = 0; j < 3; j++) {
      board[rowStart + i][colStart + j] = numbers[idx++];
    }
  }
}

// Helper function to shuffle an array
function shuffleArray(array) {
  for (let i = array.length - 1; i > 0; i--) {
    const j = Math.floor(Math.random() * (i + 1));
    [array[i], array[j]] = [array[j], array[i]];
  }
  return array;
}

// Function to render the board (either solved or unsolved) in the grid
function renderBoard(board) {
  const grid = document.getElementById('sudoku-grid');
  grid.innerHTML = ''; // Clear previous board

  for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
      const input = document.createElement('input');
      input.type = 'text';
      input.maxLength = 1;

      if (board[i][j] !== '.') {
        input.value = board[i][j];
        input.disabled = true; // Disable pre-filled values
      }

      grid.appendChild(input);
    }
  }
}

// Function to solve the current Sudoku puzzle
function solveSudoku() {
  const inputs = document.querySelectorAll('input');
  const currentBoard = [];

  // Get the current board state from the input fields
  for (let i = 0; i < 9; i++) {
    currentBoard.push([]);
    for (let j = 0; j < 9; j++) {
      const val = inputs[i * 9 + j].value;
      currentBoard[i].push(val === '' ? '.' : val);
    }
  }

  if (solve(currentBoard)) {
    // Update the grid with the solved values
    for (let i = 0; i < 9; i++) {
      for (let j = 0; j < 9; j++) {
        inputs[i * 9 + j].value = currentBoard[i][j];
      }
    }
  } else {
    alert('No solution exists!');
  }
}

// Function to reset the Sudoku board
function resetBoard() {
  generateRandomPuzzle(); // Regenerate a new puzzle
}

// Generate an initial puzzle on page load
window.onload = generateRandomPuzzle;


































// Let's go through each function in the Sudoku code, with a clear structure of Purpose, How it works, and What it does to give you five detailed explanations for each function.

// 1. generateEmptyBoard()
// Purpose: To create an empty 9x9 Sudoku board.
// How it works: Uses Array.from() to create an array of length 9. Each element of the array is a new array of length 9, initialized with the value '.', representing an empty cell.
// What it does: Returns a 2D array (9x9) with each cell filled with '.' to represent an empty Sudoku board.
// Key Functionality: Generates a blank board for either solving or displaying.
// Code Efficiency: Simple and concise, using Array.from() and Array.fill() to generate the board efficiently.


// 2. isValid(board, row, col, c)
// Purpose: To check if placing the number c in the cell at position (row, col) is a valid move based on Sudoku rules.
// How it works:
// Iterates through the row and column to ensure c is not already present.
// Checks the 3x3 subgrid by calculating its starting position and verifying that c isn't duplicated in that subgrid.
// What it does: Returns true if placing c is valid, otherwise false.
// Key Functionality: Ensures Sudoku rules (no duplicates in rows, columns, or subgrids) are followed when placing a number.
// Code Efficiency: Minimizes unnecessary checks by combining row, column, and subgrid checks in a single loop.


// 3. solve(board)
// Purpose: To solve the Sudoku puzzle using the backtracking algorithm.
// How it works:
// Iterates over every cell of the board.
// For each empty cell ('.'), tries placing numbers '1' to '9'.
// If placing a number is valid (checked by isValid()), it recursively attempts to solve the rest of the puzzle.
// If a solution cannot be found, it backtracks by removing the last placed number and tries a different one.
// What it does: Recursively solves the board and returns true if a solution is found, otherwise false (no solution).
// Key Functionality: Uses recursion and backtracking to explore all possible configurations and only returns a valid, fully solved puzzle.
// Code Efficiency: Efficiently attempts to solve the puzzle, but may have performance bottlenecks for very difficult or large puzzles (backtracking is computationally intensive).


// 4. removeCells(board, difficulty = 40)
// Purpose: To remove a specified number of cells from a completed Sudoku puzzle to create a playable puzzle with missing numbers.
// How it works:
// Loops difficulty times (default is 40), each time selecting a random row and column.
// Sets the cell at (row, col) to '.', which represents an empty spot in the Sudoku puzzle.
// What it does: Modifies the board by removing difficulty cells to create an unsolved puzzle for the user to solve.
// Key Functionality: Adds difficulty to the game by clearing cells on a solved puzzle, thus creating an incomplete one.
// Code Efficiency: Relies on random cell removal, so the distribution of empty cells may vary (but performs efficiently for typical difficulty levels).


// 5. generateRandomPuzzle()
// Purpose: To generate a random, playable Sudoku puzzle.
// How it works:
// First, generates an empty board.
// Fills the diagonal 3x3 subgrids to simplify solving the puzzle later (since the subgrids are independent).
// Uses solve() to generate a completely filled valid Sudoku puzzle.
// Calls removeCells() to remove cells and create an unsolved puzzle.
// Finally, renders the puzzle on the webpage using renderBoard().
// What it does: Creates a random Sudoku puzzle and displays it on the page.
// Key Functionality: Ensures that a valid puzzle is generated, and removes cells to create the challenge for the user.
// Code Efficiency: Optimizes puzzle generation by solving first and then clearing cells, rather than trying to generate an incomplete puzzle directly.


// 6. fillDiagonalSubgrid(board, rowStart, colStart)
// Purpose: To fill the 3x3 diagonal subgrids of the Sudoku board.
// How it works:
// First, creates an array of the numbers '1' to '9' and shuffles them using shuffleArray().
// Fills the 3x3 subgrid starting at (rowStart, colStart) with the shuffled numbers.
// What it does: Randomly fills a 3x3 subgrid on the board with numbers from '1' to '9'.
// Key Functionality: Ensures that the diagonal subgrids are filled with valid numbers, simplifying the process of solving the puzzle.
// Code Efficiency: This method simplifies solving since diagonal grids are independent, reducing complexity when generating the puzzle.


// 7. shuffleArray(array)
// Purpose: To shuffle the elements of an array in a random order.
// How it works:
// Uses the Fisher-Yates algorithm to shuffle the array in place.
// Swaps each element with a randomly selected one.
// What it does: Returns a shuffled version of the input array.
// Key Functionality: Ensures randomness in number placement (used for filling diagonal subgrids).
// Code Efficiency: The Fisher-Yates shuffle is an efficient algorithm with O(n) time complexity.


// 8. renderBoard(board)
// Purpose: To display the Sudoku board on the webpage.
// How it works:
// Gets the HTML element representing the Sudoku grid.
// Clears any previous content inside the grid.
// Loops through the 9x9 board, creating an input field for each cell.
// If the cell contains a number, it sets the input field to that value and disables editing.
// Appends each input field to the grid.
// What it does: Dynamically generates the HTML to display the Sudoku board on the webpage.
// Key Functionality: Creates an interactive UI where users can see the puzzle and fill in missing numbers.
// Code Efficiency: Efficiently creates the input fields for the grid but may need optimization for larger grids or additional features (e.g., event handling).


// 9. solveSudoku()
// Purpose: To solve the current Sudoku puzzle displayed on the webpage.
// How it works:
// Reads the current state of the board from the input fields on the page.
// Calls solve() to solve the puzzle.
// Updates the input fields with the solved values.
// Alerts the user if no solution exists.
// What it does: Attempts to solve the Sudoku puzzle and updates the grid with the solution.
// Key Functionality: Provides users with a way to auto-solve the puzzle.
// Code Efficiency: May be inefficient for puzzles that are unsolvable due to user errors, as backtracking is expensive in such cases.


// 10. resetBoard()
// Purpose: To reset the Sudoku board and generate a new random puzzle.
// How it works: Simply calls generateRandomPuzzle() to regenerate the board.
// What it does: Resets the current puzzle by generating a new one.
// Key Functionality: Allows users to start over with a fresh, random puzzle.
// Code Efficiency: Since it relies on the already efficient generateRandomPuzzle(), this function performs well.


// 11. window.onload = generateRandomPuzzle;
// Purpose: To generate a random Sudoku puzzle when the page is loaded.
// How it works: Sets the generateRandomPuzzle() function to be called when the window finishes loading.
// What it does: Automatically generates and displays a new puzzle as soon as the page is ready.
// Key Functionality: Ensures that a puzzle is shown when the user first visits the webpage.
// Code Efficiency: Simple and effective in initializing the page with a puzzle.
// Summary of Key Features
// Puzzle Generation: Functions like generateRandomPuzzle(), solve(), and removeCells() handle generating and solving the puzzle.
// User Interface: Functions like renderBoard() and solveSudoku() interact with the webpage, allowing users to view and interact with the puzzle.
// Randomness: shuffleArray() ensures that the puzzle has random configurations.
// Validation: isValid() ensures that numbers follow Sudoku rules (no duplicates in rows, columns, or subgrids).