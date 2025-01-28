// Define constants and variables
const gameBoard = document.querySelector("#gameBoard");
const ctx = gameBoard.getContext("2d");
const scoreText = document.querySelector("#scoreText");
const resetBtn = document.querySelector("#resetBtn");
const pauseBtn = document.querySelector("#pauseBtn"); // New: Pause button
const gameWidth = gameBoard.width;
const gameHeight = gameBoard.height;
const boardBackground = "white";
const snakeColor = "lightgreen";
const snakeBorder = "black";
const foodColor = "red";
const unitSize = 25; // Size of each snake segment and food

let running = false;
let paused = false; // New: Flag to track if the game is paused
let xVelocity = unitSize; // Initial velocity in X direction
let yVelocity = 0; // Initial velocity in Y direction
let foodX;
let foodY;
let score = 0;
let snake = [
    { x: unitSize * 4, y: 0 },
    { x: unitSize * 3, y: 0 },
    { x: unitSize * 2, y: 0 },
    { x: unitSize, y: 0 },
    { x: 0, y: 0 }
];

let level = 1; // Starting level
const levels = [
    { speed: 75, obstacles: false }, // Level 1 configuration
    { speed: 60, obstacles: true },  // Level 2 configuration (example)
    // Add more levels as needed
];

let obstacles = []; // Array to hold obstacle positions

// Event listeners
window.addEventListener("keydown", changeDirection);
resetBtn.addEventListener("click", resetGame);
pauseBtn.addEventListener("click", togglePause); // New: Pause button click event

// Initialize game
gameStart();

// Game functions

function gameStart() {
    running = true;
    paused = false; // New: Ensure game starts as unpaused
    scoreText.textContent = score;
    createFood();
    drawFood();
    nextTick();
}

function nextTick() {
    if (running && !paused) { // Check if game is running and not paused
        setTimeout(() => {
            clearBoard();
            drawFood();
            moveSnake();
            drawSnake();
            if (levels[level - 1].obstacles) {
                drawObstacles();
            }
            checkGameOver();
            nextTick();
        }, levels[level - 1].speed); // Adjust speed based on current level
    } else {
        if (!running) {
            displayGameOver();
        } // Game over display handled separately
        // Continue to nextTick if paused
    }
}

function clearBoard() {
    ctx.fillStyle = boardBackground;
    ctx.fillRect(0, 0, gameWidth, gameHeight);
}

function createFood() {
    function randomFood(min, max) {
        return Math.round((Math.random() * (max - min) + min) / unitSize) * unitSize;
    }
    foodX = randomFood(0, gameWidth - unitSize);
    foodY = randomFood(0, gameHeight - unitSize);
}

function drawFood() {
    ctx.fillStyle = foodColor;
    ctx.fillRect(foodX, foodY, unitSize, unitSize);
}

function moveSnake() {
    const head = { x: snake[0].x + xVelocity, y: snake[0].y + yVelocity };

    snake.unshift(head);

    if (snake[0].x === foodX && snake[0].y === foodY) {
        score++;
        scoreText.textContent = score;
        createFood();
        if (score % 5 === 0) { // Add a power-up (example)
            // Implement power-up logic here
        }
    } else {
        snake.pop();
    }
}

function drawSnake() {
    ctx.fillStyle = snakeColor;
    ctx.strokeStyle = snakeBorder;
    snake.forEach(snakePart => {
        ctx.fillRect(snakePart.x, snakePart.y, unitSize, unitSize);
        ctx.strokeRect(snakePart.x, snakePart.y, unitSize, unitSize);
    });
}

function drawObstacles() {
    ctx.fillStyle = "gray";
    obstacles.forEach(obstacle => {
        ctx.fillRect(obstacle.x, obstacle.y, unitSize, unitSize);
    });
}

function changeDirection(event) {
    const keyPressed = event.keyCode;
    const LEFT = 37;
    const UP = 38;
    const RIGHT = 39;
    const DOWN = 40;

    const goingUp = (yVelocity === -unitSize);
    const goingDown = (yVelocity === unitSize);
    const goingRight = (xVelocity === unitSize);
    const goingLeft = (xVelocity === -unitSize);

    switch (true) {
        case (keyPressed === LEFT && !goingRight):
            xVelocity = -unitSize;
            yVelocity = 0;
            break;
        case (keyPressed === UP && !goingDown):
            xVelocity = 0;
            yVelocity = -unitSize;
            break;
        case (keyPressed === RIGHT && !goingLeft):
            xVelocity = unitSize;
            yVelocity = 0;
            break;
        case (keyPressed === DOWN && !goingUp):
            xVelocity = 0;
            yVelocity = unitSize;
            break;
    }
}

function togglePause() {
    paused = !paused; // Toggle pause flag
    if (paused) {
        pauseBtn.textContent = "Resume";
    } else {
        pauseBtn.textContent = "Pause";
        nextTick(); // Resume the game loop if unpaused
    }
}

function checkGameOver() {
    if (snake[0].x < 0 || snake[0].x >= gameWidth || snake[0].y < 0 || snake[0].y >= gameHeight) {
        running = false;
    }

    for (let i = 1; i < snake.length; i++) {
        if (snake[i].x === snake[0].x && snake[i].y === snake[0].y) {
            running = false;
            break;
        }
    }
}

function displayGameOver() {
    ctx.font = "50px MV Boli";
    ctx.fillStyle = "black";
    ctx.textAlign = "center";
    ctx.fillText("GAME OVER!", gameWidth / 2, gameHeight / 2);
}

function resetGame() {
    score = 0;
    xVelocity = unitSize;
    yVelocity = 0;
    snake = [
        { x: unitSize * 4, y: 0 },
        { x: unitSize * 3, y: 0 },
        { x: unitSize * 2, y: 0 },
        { x: unitSize, y: 0 },
        { x: 0, y: 0 }
    ];
    gameStart();
}
