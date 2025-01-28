const gameBoard = document.querySelector("#gameBoard");
const ctx = gameBoard.getContext("2d");
//ctx: This is the context object for the canvas element, obtained using gameBoard.getContext("2d").

const scoreText = document.querySelector("#scoreText");
const resetBtn = document.querySelector("#resetBtn");
const gameWidth = gameBoard.width;
const gameHeight = gameBoard.height;
const boardBackground = "white";
const snakeColor = "lightgreen";
const snakeBorder = "black";
const foodColor = "red";
const unitSize = 25;
let running = false;
let xVelocity = unitSize;//snake will move hori initially
let yVelocity = 0;
let foodX;
let foodY;
let score = 0;
let snake = [
  //Initially, the snake consists of 5 segments positioned horizontally
    {x:unitSize * 4, y:0},//The head of the snake, positioned at (100, 0).
    {x:unitSize * 3, y:0},
    {x:unitSize * 2, y:0},
    {x:unitSize, y:0}, //The fourth segment, positioned at (25, 0).
    {x:0, y:0}
];

window.addEventListener("keydown", changeDirection);
resetBtn.addEventListener("click", resetGame);

gameStart();

function gameStart(){
    running= true;
    scoreText.textContent = score;
    createFood();
    drawFood();
    nextTick();
};

function nextTick(){
    if(running){
        setTimeout(()=>{
            clearBoard();
            drawFood();
            moveSnake();
            drawSnake();
            checkGameOver();
            nextTick();
        }, 75);
    }
    else{
        displayGameOver();
    }
};

function clearBoard(){
    ctx.fillStyle = boardBackground;
    ctx.fillRect(0, 0, gameWidth, gameHeight);
    //x: The x-coordinate of the upper-left corner of the rectangle, set to 0 to start from the left edge.
 ///y: The y-coordinate of the upper-left corner of the rectangle, set to 0 to start from the top edge.
};


// this will create a food at random side within box
function createFood(){
  // his will crteate randnum that shoud ddiv by 25 within a canvas 
    function randomFood(min, max){
        const randNum = Math.round((Math.random() * (max - min) + min) / unitSize) * unitSize;//rounded to the nearest multiple of unitSize
        return randNum;
    }
    foodX = randomFood(0, gameWidth - unitSize);//foodX: Calls randomFood with min as 0 and max as gameWidth - unitSize to ensure the food's x-coordinate is within the game board's width and aligns with the grid.
    foodY = randomFood(0, gameWidth - unitSize);
};


function drawFood(){
    ctx.fillStyle = foodColor;
    ctx.fillRect(foodX, foodY, unitSize, unitSize);
    //fillStyle: This property of the context object sets the color, gradient, or pattern to use inside shapes. Here, it's set to foodColor.
};


function moveSnake(){
  //head: This is a new object representing the new position of the snake's head.

    const head = {x: snake[0].x + xVelocity,
                  y: snake[0].y + yVelocity};
                  //snake[0]: This is the current head of the snake (the first element in the snake array).
                  //x: snake[0].x + xVelocity: The new x-coordinate is calculated by adding the current x-coordinate of the head and the x-velocity. This determines how far the snake moves horizontally.
    
    snake.unshift(head);
    //unshift: This method adds the new head object to the beginning of the snake array. This effectively moves the snake forward by adding a new head in the direction of movement.
    //if food is eaten
    if(snake[0].x == foodX && snake[0].y == foodY){
        score+=1;
        scoreText.textContent = score;
        createFood();
    }
    else{
        snake.pop();
    }     
};



// this will draw a snake that will as ---- like this initally
function drawSnake(){
    ctx.fillStyle = snakeColor;
    ctx.strokeStyle = snakeBorder;
    //strokeStyle: This property of the context object sets the color, gradient, or pattern to use for the outlines (strokes) of shapes. Here, it's set to snakeBorder.
//snakeBorder is a constant defined elsewhere in the code:
    snake.forEach(snakePart => {
        ctx.fillRect(snakePart.x, snakePart.y, unitSize, unitSize);
        ctx.strokeRect(snakePart.x, snakePart.y, unitSize, unitSize);
    })
};


//The purpose of the changeDirection function is to change the direction of the snake's movement based on the arrow key pressed by the player. The function ensures that the snake cannot reverse direction directly to avoid immediate self-collision
function changeDirection(event){
    // key code of mouse
    const keyPressed = event.keyCode;
    const LEFT = 37;
    const UP = 38;
    const RIGHT = 39;
    const DOWN = 40;
    // change the direction when up r d k mouse keyboard 

    const goingUp = (yVelocity == -unitSize);
    //These boolean variables check the current direction of the snake by comparing the xVelocity and yVelocity with unitSize.
    //goingUp: True if the snake is currently moving up.
    const goingDown = (yVelocity == unitSize);
    const goingRight = (xVelocity == unitSize);
    const goingLeft = (xVelocity == -unitSize);

    switch(true){
      //If the left arrow key is pressed and the snake is not currently moving right (!goingRight), change the direction to left by setting xVelocity to -unitSize and yVelocity to 0.
        case(keyPressed == LEFT && !goingRight):
            xVelocity = -unitSize;
            yVelocity = 0;
            break;
      //If the up arrow key is pressed and the snake is not currently moving down (!goingDown), change the direction to up by setting xVelocity to 0 and yVelocity to -unitSize.
        case(keyPressed == UP && !goingDown):
            xVelocity = 0;
            yVelocity = -unitSize;
            break;
        case(keyPressed == RIGHT && !goingLeft):
            xVelocity = unitSize;
            yVelocity = 0;
            break;
        case(keyPressed == DOWN && !goingUp):
            xVelocity = 0;
            yVelocity = unitSize;
            break;
    }


};

function checkGameOver(){
    switch(true){
      //snake[0].x < 0: Checks if the snake's head has moved beyond the left boundary of the game board.
        case (snake[0].x < 0):
            running = false;
            break;
      //snake[0].x >= gameWidth: Checks if the snake's head has moved beyond the right boundary of the game board.
        case (snake[0].x >= gameWidth):
            running = false;
            break;
      //snake[0].y < 0: Checks if the snake's head has moved beyond the top boundary of the game board.
        case (snake[0].y < 0):
            running = false;
            break;
        case (snake[0].y >= gameHeight):
                running = false;
                break;
    }
    //Check for Self-Collision:
    //: Checks if any segment of the snake (other than the head) has the same coordinates as the head.
    for(let i = 1; i < snake.length; i+=1){
        if(snake[i].x == snake[0].x && snake[i].y == snake[0].y){
            running = false;
        }
    }
};


function displayGameOver(){
    ctx.font = "50px MV Boli";
    ctx.fillStyle = "black";
    ctx.textAlign = "center";
    ctx.fillText("GAME OVER!", gameWidth / 2, gameHeight / 2);
    running = false;
};


function resetGame(){
    score = 0;
    xVelocity = unitSize;
    yVelocity = 0;
    snake = [
        {x:unitSize * 4, y:0},
        {x:unitSize * 3, y:0},
        {x:unitSize * 2, y:0},
        {x:unitSize, y:0},
        {x:0, y:0}
    ];
    gameStart();
};