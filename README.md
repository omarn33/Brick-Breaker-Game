# Instructions
## Game Set-Up
In order to set-up Brick Breaker, the following must be installed on your personal device:
* CLion (or another C++ IDEA)
* Cinder (C++ visual application)
* Microsoft Visual Studio Code 2015 Build Tools

You can play the game by running the cinder_app_main.cc located within the apps folder. Another application window
should pop-up which should display the home screen for the Brick Breaker game.

## How to Play
Brick Breaker is composed of the following objects:
* Paddle
* Bricks
* Ball
* Boxed Container

The objective of the game is to destroy all the bricks within a given level by deflecting a ball with the use of a 
moveable paddle.The paddle will be in your control and left/right mouse movements will allow you to control the 
horizontal position of the paddle. If you miss the ball, the ball will collide with the ground and you will lose a
life. At the beginning of each game players are given 3 lives and completing all 4 levels without losing your lives will
result in you winning the game. However, losing all 3 of your lives will result in you losing the game. 

### Brick Types
There are four types of bricks within the game:
* Steel Brick
* Solid Brick
* Normal Brick
* Weak Brick

The Steel Brick is unbreakable. Therefore, no matter how many times the ball strikes the Steel Brick, it will not erode 
or weaken. The next strongest brick is the Solid Brick. The Solid Brick requires 3 hits in order to completely destroy.
Hitting the Solid Brick once will result in it eroding into the Normal Brick. The Normal Brick has a few cracks and
requires 2 hits in order to destroy. Hitting this brick once will alter its state into the Weak Brick. The Weak Brick is
the weakest brick in the game and contains noticeable cracks on its exterior. Hitting this brick once will destroy it.
In summary:
* Steel Brick: Unbreakable
* Solid Brick: 3 Hits to destroy
* Normal Brick: 2 Hits to destroy
* Weak Brick: 1 Hit to destroy

## Score
In addition to keeping track of your lives, the game will also display your score. Everytime the ball strikes a brick,
your score increases by 10 points. At the end of the game, your score will be displayed and can be compared to your 
highest every game score.

## Strategy
Lastly, its important to deflect the ball with a certain direction in mind rather than aimless deflection. Every time
the ball strikes the paddle, the ball gains speed, therefore making it more difficult to deflect with every bounce. Use
your paddle wisely and difficult levels will become a lot easier. Let the ball do all the work!