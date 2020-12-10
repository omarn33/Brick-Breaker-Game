#include <visualizer/brick_breaker_app.h>
#include <iostream>

namespace brickbreaker {

    namespace visualizer {
        BrickBreakerApp::BrickBreakerApp() : paddle_(paddle_initial_position,
                                                     glm::vec2{paddle_initial_position.x + kPaddleWidth,
                                                               paddle_initial_position.y + kPaddleHeight},
                                                     kPaddleSensitivity, container_top_left_corner_,
                                                     container_bottom_right_corner_, kContainerWallStroke),
                                             ball_(kBallRadius, ball_initial_position_,
                                                   ball_initial_velocity_,
                                                   container_top_left_corner_, container_bottom_right_corner_, kContainerWallStroke),
                                             current_level_(4, std::vector<Brick>{}, 0) {
            ci::app::setWindowSize((int) kWindowWidth, (int) kWindowHeight);
            score_ = 0;
            ammo_ = 0;
            lives_ = 3;
            high_score_ = 0;
            generate_new_level_ = true;
            new_game_ = true;
            resume_game_ = false;
            ball_in_motion_ = false;
            has_game_ended_ = false;
        }

        void BrickBreakerApp::draw() {

            if(new_game_) {
                // Draw introduction screen
                ci::Color8u background_color(0, 0, 0);

                // Clear the background color
                ci::gl::clear(background_color);

                ci::gl::drawStringCentered(
                        "BrickBreaker",
                        glm::vec2(kWindowWidth / 2, kWindowHeight / 4), ci::Color("white"), ci::Font("Century", 300.0f));

                ci::gl::drawStringCentered(
                        "Press [S] to Start Game",
                        glm::vec2(kWindowWidth / 2, kWindowHeight / 2), ci::Color("white"), ci::Font("Arial", 150.0f));
            }
            else if(!resume_game_) {
                // Stop ball
                ball_in_motion_ = false;

                // Determine current level
                if (generate_new_level_) {
                    current_level_ = GetLevel(current_level_.GetLevelNumber());
                    generate_new_level_ = false;
                } else {
                    current_level_.Draw();
                }

                DrawDefaultStage();
            }
            else if (has_game_ended_){
                if(lives_ == 0) {
                    // Set ball position to the paddle position
                    ball_.SetPosition(glm::vec2 {paddle_.GetPaddlePosition().x + (kPaddleWidth/2), paddle_.GetPaddlePosition().y - kBallRadius});

                    // Set new high score
                    high_score_ = score_;

                    // Draw background
                    ci::gl::color(ci::Color8u(255, 255, 255));
                    ci::gl::Texture2dRef image = ci::gl::Texture::create(
                            ci::loadImage("C:\\Users\\Omar\\Desktop\\Background.png"));
                    ci::gl::draw(image, ci::Rectf(glm::vec2{0, 0}, glm::vec2{kWindowWidth, kWindowHeight}));


                    // Draw Scoreboard
                    ci::gl::drawStringCentered(
                            std::to_string(score_),
                            glm::vec2(2250.0f, 425.0f), ci::Color("Black"), ci::Font("Impact", 200.0f));

                    ci::gl::drawStringCentered(
                            std::to_string(ammo_),
                            glm::vec2(2250.0f, 425.0f + 425.0f), ci::Color("Black"), ci::Font("Impact", 200.0f));

                    ci::gl::drawStringCentered(
                            std::to_string(lives_),
                            glm::vec2(2250.0f, 425.0f + 425.0f + 425.0f), ci::Color("Black"), ci::Font("Impact", 200.0f));

                    ci::gl::drawStringCentered(
                            std::to_string(high_score_),
                            glm::vec2(2250.0f, 425.0f + 425.0f + 425.0f + 425.0f), ci::Color("Black"),
                            ci::Font("Impact", 200.0f));

                    // Draw level
                    current_level_.Draw();

                    // Draw the paddle
                    paddle_.Draw();

                    // Draw the ball
                    ball_.Draw();

                    // Display Win Screen

                    // Draw pop-up message
                    ci::gl::color(ci::Color8u(160, 160, 160));
                    float x_1 = 400.0f;
                    float y_1 = 500.0f;
                    double length = 700.0f;
                    double width = 1100.0f;

                    // Draw message
                    ci::gl::drawStringCentered(
                            "GAME OVER!",
                            glm::vec2(x_1 + (width/2), y_1 + (length/10)), ci::Color("red"), ci::Font("Impact", 250.0f));

                    // Draw message
                    ci::gl::drawStringCentered(
                            "You Lose",
                            glm::vec2(x_1 + (width/2), y_1 + (length/2)), ci::Color("yellow"), ci::Font("Impact", 200.0f));

                    // Draw message
                    ci::gl::drawStringCentered(
                            "Score: " + std::to_string(score_),
                            glm::vec2(x_1 + (width/2), y_1 + (length * 4/5)), ci::Color("yellow"), ci::Font("Impact", 150.0f));

                } else {
                    // Set ball position to the paddle position
                    ball_.SetPosition(glm::vec2 {paddle_.GetPaddlePosition().x + (kPaddleWidth/2), paddle_.GetPaddlePosition().y - kBallRadius});

                    // Set new high score
                    high_score_ = score_;

                    // Draw background
                    ci::gl::color(ci::Color8u(255, 255, 255));
                    ci::gl::Texture2dRef image = ci::gl::Texture::create(
                            ci::loadImage("C:\\Users\\Omar\\Desktop\\Background.png"));
                    ci::gl::draw(image, ci::Rectf(glm::vec2{0, 0}, glm::vec2{kWindowWidth, kWindowHeight}));


                    // Draw Scoreboard
                    ci::gl::drawStringCentered(
                            std::to_string(score_),
                            glm::vec2(2250.0f, 425.0f), ci::Color("Black"), ci::Font("Impact", 200.0f));

                    ci::gl::drawStringCentered(
                            std::to_string(ammo_),
                            glm::vec2(2250.0f, 425.0f + 425.0f), ci::Color("Black"), ci::Font("Impact", 200.0f));

                    ci::gl::drawStringCentered(
                            std::to_string(lives_),
                            glm::vec2(2250.0f, 425.0f + 425.0f + 425.0f), ci::Color("Black"), ci::Font("Impact", 200.0f));

                    ci::gl::drawStringCentered(
                            std::to_string(high_score_),
                            glm::vec2(2250.0f, 425.0f + 425.0f + 425.0f + 425.0f), ci::Color("Black"),
                            ci::Font("Impact", 200.0f));

                    // Draw level
                    current_level_.Draw();

                    // Draw the paddle
                    paddle_.Draw();

                    // Draw the ball
                    ball_.Draw();

                    // Display Win Screen

                    // Draw pop-up message
                    ci::gl::color(ci::Color8u(160, 160, 160));
                    float x_1 = 400.0f;
                    float y_1 = 500.0f;
                    double length = 700.0f;
                    double width = 1100.0f;

                    // Draw message
                    ci::gl::drawStringCentered(
                            "Congratulations!",
                            glm::vec2(x_1 + (width/2), y_1 + (length/10)), ci::Color("yellow"), ci::Font("Impact", 250.0f));

                    // Draw message
                    ci::gl::drawStringCentered(
                            "You Win",
                            glm::vec2(x_1 + (width/2), y_1 + (length/2)), ci::Color("yellow"), ci::Font("Impact", 200.0f));

                    // Draw message
                    ci::gl::drawStringCentered(
                            "Score: " + std::to_string(score_),
                            glm::vec2(x_1 + (width/2), y_1 + (length * 4/5)), ci::Color("yellow"), ci::Font("Impact", 150.0f));
                }
            }
            else {

                ci::gl::clear();

                // Draw background
                ci::gl::color(ci::Color8u(255, 255, 255));
                ci::gl::Texture2dRef image = ci::gl::Texture::create(
                        ci::loadImage("C:\\Users\\Omar\\Desktop\\Background.png"));
                ci::gl::draw(image, ci::Rectf(glm::vec2{0, 0}, glm::vec2{kWindowWidth, kWindowHeight}));

                // Draw Scoreboard
                ci::gl::drawStringCentered(
                        std::to_string(score_),
                        glm::vec2(2250.0f, 425.0f), ci::Color("Black"), ci::Font("Impact", 200.0f));

                ci::gl::drawStringCentered(
                        std::to_string(ammo_),
                        glm::vec2(2250.0f, 425.0f + 425.0f), ci::Color("Black"), ci::Font("Impact", 200.0f));

                ci::gl::drawStringCentered(
                        std::to_string(lives_),
                        glm::vec2(2250.0f, 425.0f + 425.0f + 425.0f), ci::Color("Black"), ci::Font("Impact", 200.0f));

                ci::gl::drawStringCentered(
                        std::to_string(high_score_),
                        glm::vec2(2250.0f, 425.0f + 425.0f + 425.0f + 425.0f), ci::Color("Black"),
                        ci::Font("Impact", 200.0f));

                if(!ball_in_motion_) {
                    ball_.SetVelocity(ball_initial_velocity_);
                    ball_in_motion_ = true;
                }

                // Draw level
                current_level_.Draw();

                // Draw the paddle
                paddle_.Draw();

                // Draw the ball
                ball_.Draw();
            }
        }

        void BrickBreakerApp::update() {

            if(!has_game_ended_) {
                // Determine if the level ended
                if (current_level_.GetNumberDestroyableOfBricks() == 0 && resume_game_) {
                    // Determine if the player won
                    if (current_level_.GetLevelNumber() == kNumberOfLevels) {
                        has_game_ended_ = true;
                    } else {
                        resume_game_ = false;
                        generate_new_level_ = true;
                        current_level_.SetLevelNumber(current_level_.GetLevelNumber() + 1);
                    }
                }


                // Update ball velocity if the ball collided with the wall
                std::vector<bool> wall_collision_directions = ball_.HasCollidedWithWall();
                if (wall_collision_directions.at(0) || wall_collision_directions.at(1)) {
                    ball_.CalculateVelocityAfterWallCollision(wall_collision_directions);
                }

                // Determine if the ball collided with the floor
                if (ball_.HasCollidedWithFloor()) {
                    // Decrease lives by 1
                    lives_ -= 1;

                    // Determine if the player lost
                    if(lives_ == 0) {
                        has_game_ended_ = true;
                    }
                    else {
                        resume_game_ = false;
                    }
                }

                // Determine if the ball collided with any bricks
                for (int brick = 0; brick < current_level_.GetBricks().size(); ++brick) {
                    std::vector<bool> brick_collision_directions = ball_.HasCollidedWithBrick(
                            current_level_.GetBricks().at(brick));
                    //std::cout << "iteration bricks" << std::endl;

                    if (brick_collision_directions.at(0) || brick_collision_directions.at(1)) {
                        // Update score
                        score_ += kScorePerBrickHit;

                        // Calculate ball velocity after collision
                        ball_.CalculateVelocityAfterBrickCollision(brick_collision_directions);

                        // Erode Brick
                        current_level_.ErodeBrick(brick);
                    }
                }

                // Determine if the ball collided with the paddle
                if (ball_.HasCollidedWithPaddle(paddle_)) {
                    ball_.CalculateVelocityAfterPaddleCollision();
                }

                // Update ball position
                ball_.CalculatePositionAfterCollision();
            }
        }

        void BrickBreakerApp::keyDown(ci::app::KeyEvent event) {
            switch (event.getCode()) {
                case ci::app::KeyEvent::KEY_LEFT:
                    // Move the paddle to the left
                    //paddle_.MovePaddleLeft();
                    break;

                case ci::app::KeyEvent::KEY_RIGHT:
                    // Move the paddle to the right
                    //paddle_.MovePaddleRight();
                    break;

                case ci::app::KeyEvent::KEY_s:
                    // Start Game
                    new_game_ = false;
                    break;

                case ci::app::KeyEvent::KEY_SPACE:
                    // Resume game
                    resume_game_ = true;
                    break;
            }
        }

        void BrickBreakerApp::mouseMove(ci::app::MouseEvent event) {
            if((event.getPos().x - (kPaddleWidth/2) >= container_top_left_corner_.x + (kContainerWallStroke/2)) &&
                event.getPos().x + (kPaddleWidth/2) <= container_bottom_right_corner_.x - (kContainerWallStroke/2))
            {
                paddle_.SetPaddlePosition(glm::vec2 {event.getPos().x - (kPaddleWidth/2), paddle_.GetPaddlePosition().y});
            }
        }

        Level BrickBreakerApp::GetLevel(int level) {
            // Initialize a vector to store bricks
            std::vector<Brick> bricks;
            float brick_spacing = 10.0f;

            // Generate appropriate levels
            if (level == 1) {
                // Add bricks for Level 1

                // Section 1
                float x_1 = 750.0f;
                float y_1 = 800.0f;
                Brick brick_1 = Brick(kSolidClay, kWeak, glm::vec2{x_1, y_1},
                                      glm::vec2{x_1 + kBrickWidth, y_1 + kBrickLength});
                bricks.push_back(brick_1);

                float x_2 = x_1 + kBrickWidth + brick_spacing;
                float y_2 = y_1;
                Brick brick_2 = Brick(kSolidClay, kWeak, glm::vec2{x_2, y_2},
                                      glm::vec2{x_2 + kBrickWidth, y_2 + kBrickLength});
                bricks.push_back(brick_2);

                float x_3 = x_1;
                float y_3 = y_1 + kBrickLength + brick_spacing;
                Brick brick_3 = Brick(kSolidClay, kWeak, glm::vec2{x_3, y_3},
                                      glm::vec2{x_3 + kBrickWidth, y_3 + kBrickLength});
                bricks.push_back(brick_3);

                float x_4 = x_3 + kBrickWidth + brick_spacing;
                float y_4 = y_3;
                Brick brick_4 = Brick(kSolidClay, kWeak, glm::vec2{x_4, y_4},
                                      glm::vec2{x_4 + kBrickWidth, y_4 + kBrickLength});
                bricks.push_back(brick_4);

                // Add bricks to level 1
                Level level_1 = Level(1, bricks, 0);

                return level_1;
            }
            else if(level == 2) {
                // Add bricks for Level 2

                // Section 1
                float x_1 = 135.0f;
                float y_1 = 250.0f;
                Brick brick_1 = Brick(kSolidClay, kStrong, glm::vec2{x_1, y_1},
                                      glm::vec2{x_1 + kBrickWidth, y_1 + kBrickLength});
                bricks.push_back(brick_1);

                float x_2 = x_1 + kBrickWidth + brick_spacing;
                float y_2 = y_1;
                Brick brick_2 = Brick(kSolidClay, kStrong, glm::vec2{x_2, y_2},
                                      glm::vec2{x_2 + kBrickWidth, y_2 + kBrickLength});
                bricks.push_back(brick_2);

                float x_3 = x_2 + kBrickWidth + brick_spacing;
                float y_3 = y_1;
                Brick brick_3 = Brick(kSolidClay, kStrong, glm::vec2{x_3, y_3},
                                      glm::vec2{x_3 + kBrickWidth, y_3 + kBrickLength});
                bricks.push_back(brick_3);

                float x_4 = x_3 + kBrickWidth + brick_spacing;
                float y_4 = y_1;
                Brick brick_4 = Brick(kSolidClay, kStrong, glm::vec2{x_4, y_4},
                                      glm::vec2{x_4 + kBrickWidth, y_4 + kBrickLength});
                bricks.push_back(brick_4);

                float x_5 = x_4 + kBrickWidth + brick_spacing;
                float y_5 = y_1;
                Brick brick_5 = Brick(kSolidClay, kStrong, glm::vec2{x_5, y_5},
                                      glm::vec2{x_5 + kBrickWidth, y_5 + kBrickLength});
                bricks.push_back(brick_5);

                float x_6 = x_5 + kBrickWidth + brick_spacing;
                float y_6 = y_1;
                Brick brick_6 = Brick(kSolidClay, kStrong, glm::vec2{x_6, y_6},
                                      glm::vec2{x_6 + kBrickWidth, y_6 + kBrickLength});
                bricks.push_back(brick_6);

                float x_7 = x_6 + kBrickWidth + brick_spacing;
                float y_7 = y_1;
                Brick brick_7 = Brick(kSolidClay, kStrong, glm::vec2{x_7, y_7},
                                      glm::vec2{x_7 + kBrickWidth, y_7 + kBrickLength});
                bricks.push_back(brick_7);

                // Section 2
                float x_8 = 555.0f;
                float y_8 = 750.0f;
                Brick brick_8 = Brick(kCrackedClay, kWeak, glm::vec2{x_8, y_8},
                                      glm::vec2{x_8 + kBrickWidth, y_8 + kBrickLength});
                bricks.push_back(brick_8);

                float x_9 = x_8 + kBrickWidth + brick_spacing;
                float y_9 = y_8;
                Brick brick_9 = Brick(kCrackedClay, kWeak, glm::vec2{x_9, y_9},
                                      glm::vec2{x_9 + kBrickWidth, y_9 + kBrickLength});
                bricks.push_back(brick_9);

                float x_10 = x_9 + kBrickWidth + brick_spacing;
                float y_10 = y_9;
                Brick brick_10 = Brick(kCrackedClay, kWeak, glm::vec2{x_10, y_10},
                                      glm::vec2{x_10 + kBrickWidth, y_10 + kBrickLength});
                bricks.push_back(brick_10);

                float x_11 = x_10 + kBrickWidth + brick_spacing;
                float y_11 = y_10;
                Brick brick_11 = Brick(kCrackedClay, kWeak, glm::vec2{x_11, y_11},
                                       glm::vec2{x_11 + kBrickWidth, y_11 + kBrickLength});
                bricks.push_back(brick_11);

                float x_12 = x_11 + kBrickWidth + brick_spacing;
                float y_12 = y_11;
                Brick brick_12 = Brick(kCrackedClay, kWeak, glm::vec2{x_12, y_12},
                                       glm::vec2{x_12 + kBrickWidth, y_12 + kBrickLength});
                bricks.push_back(brick_12);

                // Add bricks to level 2
                Level level_2 = Level(2, bricks, 0);

                return level_2;
            } else if(level == 3) {
                // Add bricks for Level 3

                float x_1 = 837.5f;
                float y_1 = 335.0f;
                Brick brick_1 = Brick(kSteel, kUnbreakable, glm::vec2{x_1, y_1},
                                      glm::vec2{x_1 + kBrickWidth, y_1 + kBrickLength});
                bricks.push_back(brick_1);

                float x_2 = x_1;
                float y_2 = y_1 + kBrickLength;
                Brick brick_2 = Brick(kSteel, kUnbreakable, glm::vec2{x_2, y_2},
                                      glm::vec2{x_2 + kBrickWidth, y_2 + kBrickLength});
                bricks.push_back(brick_2);

                float x_3 = x_1;
                float y_3 = y_2 + kBrickLength;
                Brick brick_3 = Brick(kSteel, kUnbreakable, glm::vec2{x_3, y_3},
                                      glm::vec2{x_3 + kBrickWidth, y_3 + kBrickLength});
                bricks.push_back(brick_3);

                float x_4 = x_1;
                float y_4 = y_3 + kBrickLength;
                Brick brick_4 = Brick(kSteel, kUnbreakable, glm::vec2{x_4, y_4},
                                      glm::vec2{x_4 + kBrickWidth, y_4 + kBrickLength});
                bricks.push_back(brick_4);

                float x_5 = x_1;
                float y_5 = y_4 + kBrickLength;
                Brick brick_5 = Brick(kSteel, kUnbreakable, glm::vec2{x_5, y_5},
                                      glm::vec2{x_5 + kBrickWidth, y_5 + kBrickLength});
                bricks.push_back(brick_5);

                float x_6 = x_1;
                float y_6 = y_5 + kBrickLength;
                Brick brick_6 = Brick(kSteel, kUnbreakable, glm::vec2{x_6, y_6},
                                      glm::vec2{x_6 + kBrickWidth, y_6 + kBrickLength});
                bricks.push_back(brick_6);

                float x_7 = x_1;
                float y_7 = y_6 + kBrickLength;
                Brick brick_7 = Brick(kSteel, kUnbreakable, glm::vec2{x_7, y_7},
                                      glm::vec2{x_7 + kBrickWidth, y_7 + kBrickLength});
                bricks.push_back(brick_7);

                float x_8 = x_1;
                float y_8 = y_7 + kBrickLength;
                Brick brick_8 = Brick(kSteel, kUnbreakable, glm::vec2{x_8, y_8},
                                      glm::vec2{x_8 + kBrickWidth, y_8 + kBrickLength});
                bricks.push_back(brick_8);

                float x_9 = x_1;
                float y_9 = y_8 + kBrickLength;
                Brick brick_9 = Brick(kSteel, kUnbreakable, glm::vec2{x_9, y_9},
                                      glm::vec2{x_9 + kBrickWidth, y_9 + kBrickLength});
                bricks.push_back(brick_9);

                // Section 2
                float x_10 = x_5 - kBrickWidth;
                float y_10 = y_5;
                Brick brick_10 = Brick(kSteel, kUnbreakable, glm::vec2{x_10, y_10},
                                      glm::vec2{x_10 + kBrickWidth, y_10 + kBrickLength});
                bricks.push_back(brick_10);

                float x_11 = x_10 - kBrickWidth;
                float y_11 = y_5;
                Brick brick_11 = Brick(kSteel, kUnbreakable, glm::vec2{x_11, y_11},
                                       glm::vec2{x_11 + kBrickWidth, y_11 + kBrickLength});
                bricks.push_back(brick_11);

                float x_12 = x_11 - kBrickWidth;
                float y_12 = y_5;
                Brick brick_12 = Brick(kSteel, kUnbreakable, glm::vec2{x_12, y_12},
                                       glm::vec2{x_12 + kBrickWidth, y_12 + kBrickLength});
                bricks.push_back(brick_12);

                // Section 3
                float x_13 = x_5 + kBrickWidth;
                float y_13 = y_5;
                Brick brick_13 = Brick(kSteel, kUnbreakable, glm::vec2{x_13, y_13},
                                       glm::vec2{x_13 + kBrickWidth, y_13 + kBrickLength});
                bricks.push_back(brick_13);

                float x_14 = x_13 + kBrickWidth;
                float y_14 = y_5;
                Brick brick_14 = Brick(kSteel, kUnbreakable, glm::vec2{x_14, y_14},
                                       glm::vec2{x_14 + kBrickWidth, y_14 + kBrickLength});
                bricks.push_back(brick_14);

                float x_15 = x_14 + kBrickWidth;
                float y_15 = y_5;
                Brick brick_15 = Brick(kSteel, kUnbreakable, glm::vec2{x_15, y_15},
                                       glm::vec2{x_15 + kBrickWidth, y_15 + kBrickLength});
                bricks.push_back(brick_15);

                // Section 4
                float x_16 = x_4 + kBrickWidth;
                float y_16 = y_4;
                Brick brick_16 = Brick(kSolidClay, kStrong, glm::vec2{x_16, y_16},
                                       glm::vec2{x_16 + kBrickWidth, y_16 + kBrickLength});
                bricks.push_back(brick_16);

                // Section 5
                float x_17 = x_4 - kBrickWidth;
                float y_17 = y_4;
                Brick brick_17 = Brick(kSolidClay, kStrong, glm::vec2{x_17, y_17},
                                       glm::vec2{x_17 + kBrickWidth, y_17 + kBrickLength});
                bricks.push_back(brick_17);

                // Add bricks to level 2
                Level level_3 = Level(3, bricks, 15);

                return level_3;
            } else if(level == 4) {
                // Add bricks for Level 4

                float x_1 = 937.5f;
                float y_1 = 882.5f;
                Brick brick_1 = Brick(kCrackedClay, kWeak, glm::vec2{x_1, y_1},
                                      glm::vec2{x_1 + kBrickWidth, y_1 + kBrickLength});
                bricks.push_back(brick_1);

                // Add bricks to Level 4
                Level level_4 = Level(4, bricks, 0);

                return level_4;
            }

            Level level_default = Level(0, bricks, 0);
            return level_default;
        }


        void BrickBreakerApp::DrawDefaultStage() {
            // Set paddle setting to default position
            //paddle_.SetPaddlePosition(paddle_initial_position);

            // Set ball position to the paddle position
            ball_.SetPosition(glm::vec2 {paddle_.GetPaddlePosition().x + (kPaddleWidth/2), paddle_.GetPaddlePosition().y - kBallRadius});

            // Draw background
            ci::gl::color(ci::Color8u(255, 255, 255));
            ci::gl::Texture2dRef image = ci::gl::Texture::create(
                    ci::loadImage("C:\\Users\\Omar\\Desktop\\Background.png"));
            ci::gl::draw(image, ci::Rectf(glm::vec2{0, 0}, glm::vec2{kWindowWidth, kWindowHeight}));

            // Draw Scoreboard
            ci::gl::drawStringCentered(
                    std::to_string(score_),
                    glm::vec2(2250.0f, 425.0f), ci::Color("Black"), ci::Font("Impact", 200.0f));

            ci::gl::drawStringCentered(
                    std::to_string(ammo_),
                    glm::vec2(2250.0f, 425.0f + 425.0f), ci::Color("Black"), ci::Font("Impact", 200.0f));

            ci::gl::drawStringCentered(
                    std::to_string(lives_),
                    glm::vec2(2250.0f, 425.0f + 425.0f + 425.0f), ci::Color("Black"), ci::Font("Impact", 200.0f));

            ci::gl::drawStringCentered(
                    std::to_string(high_score_),
                    glm::vec2(2250.0f, 425.0f + 425.0f + 425.0f + 425.0f), ci::Color("Black"),
                    ci::Font("Impact", 200.0f));

            // Draw level
            current_level_.Draw();

            // Draw the paddle
            paddle_.Draw();

            // Draw the ball
            ball_.Draw();

            // Draw pop-up message
            ci::gl::color(ci::Color8u(160, 160, 160));

            float x_1 = 400.0f;
            float y_1 = 500.0f;
            double length = 700.0f;
            double width = 1100.0f;

            glm::vec2 message_top_corner_ = {x_1, y_1};
            glm::vec2 message_bottom_corner_ = {x_1 + width, y_1 + length};
            ci::gl::drawSolidRect(ci::Rectf(message_top_corner_, message_bottom_corner_));

            // Draw message
            ci::gl::drawStringCentered(
                    "Level " + std::to_string(current_level_.GetLevelNumber()),
                    glm::vec2(x_1 + (width/2), y_1 + (length/10)), ci::Color("yellow"), ci::Font("Impact", 250.0f));

            // Draw message
            ci::gl::drawStringCentered(
                    "Lives: " + std::to_string(lives_),
                    glm::vec2(x_1 + (width/2), y_1 + (length/2)), ci::Color("yellow"), ci::Font("Impact", 150.0f));

            // Draw message
            ci::gl::drawStringCentered(
                    "Press [Space] to Continue",
                    glm::vec2(x_1 + (width/2), y_1 + (length * 3/4)), ci::Color("yellow"), ci::Font("Impact", 120.0f));

        }
    }
}