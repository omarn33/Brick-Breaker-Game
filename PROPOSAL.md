# Final Project Proposal
## Game Selection
For my final project, I would like to model the **Brick Breaker** game that was implemented on Blackberry phones a decade ago.
Brick Breaker consists of a multi-level game where the user has to use a paddle to deflect a ball in order to destroy various bricks.
Each level starts off with a given number of bricks and the user must destroy these bricks by attempting to collide the bouncing ball with each brick.
With each passing level, the number of bricks as well as the strength of bricks increase, making it more difficult for the user to complete each level.
The user starts the game with three lives and if the user misses the ball with the paddle, a life is lost. The game ends when the user passes all the levels
or the user runs out of lives.

## Background
My first experience with coding was in an 8th grade technology class where I learned how to use the Scratch programming language to create visual animations
and games. My final project for this technology class was to model the Brick Breaker game that I used to play as a child on
Blackberry phones. I was able to determine the physics for bouncing the ball off the containing wall but I was not able to bounce the ball
off any bricks given the lack of mathematical concepts I had known at time. Almost a decade later, I would decide to major in the field of Computer Science
and having taken CS 126, I have learned a lot about programming and Object-Oriented Design. My choice to select **Brick Breaker** for my CS 126 Final Project
was to illustrate how far I have come -- from my early days of programming to where I am now -- and would ultimately show what I have learned throughout my years of programming.

## Timeline
### Week 1:
* Create individual classes for various parts of the game:
    - Ball
    - BallPhysics
    - Paddle
    - GameEngine
    - UI 
* Handle the physics involved with the game:
    - Ball collisions with the wall
    - Ball collisions with the paddle
    - Ball collisions with the bricks
    - Extra: Ball collision with other balls (if multiple ball feature is implemented)

### Week 2:
* Handle the GUI portion of the game:
    - Displaying the Game Window
    - Adjusting Game for Window Size
    - Displaying Instructions
    - Displaying Respective Levels
    - Displaying User Lives Remaining
    - Displaying Win Screen
    - Displaying Lose Screen
    - Displaying Game Features (ball, paddle, bricks, etc.)
    
### Week 3:
* Handle testing of the game:
    - Verify all testable features function properly
    - Verify ball collision physics with the wall, paddle, and bricks
    - Test Edge Cases (ex: ball colliding with brick and wall simultaneously)
* Implement Extra Features:
    - JSON file parsing for game diversity
    - SQL database for player high scores
    - Potential Power-Up Features (for a given length of game time):
        - Paddle lasers to destroy bricks
        - Paddle length extension for extra reach
        - Multiple balls to increase brick collision frequency
        - Extra life boosts (increment lives by one)
        - Slow ball velocity for easier paddle deflection
        
       
        
        

