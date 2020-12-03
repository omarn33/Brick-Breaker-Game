#include <visualizer/brick_breaker_app.h>
#include <iostream>

namespace brickbreaker {

namespace visualizer {
    BrickBreakerApp::BrickBreakerApp() : ball_(kBallRadius, kBallColor, ball_initial_position_, ball_initial_velocity_,
                                               container_top_left_corner_, container_bottom_right_corner_),
                                         current_level_(1, std::vector<Brick> {}) {
        ci::app::setWindowSize((int) kWindowWidth, (int) kWindowHeight);
    }

    void BrickBreakerApp::draw() {
        // Draw background
        ci::Color8u background_color(128, 128, 128);

        // Clear the background color
        ci::gl::clear(background_color);

        // Draw Container
        ci::gl::color(container_color_);
        ci::gl::drawStrokedRect(ci::Rectf(container_top_left_corner_,
                                          container_bottom_right_corner_), kContainerWallStroke);

        // Draw Inside Container
        ci::gl::color(ci::Color8u(150, 150, 150));
        ci::gl::drawSolidRect(ci::Rectf(container_top_left_corner_ + (kContainerWallStroke / 2),
                                        container_bottom_right_corner_ - (kContainerWallStroke / 2)));

        // Draw Scoreboard
        ci::gl::color(ci::Color8u(140, 140, 140));
        glm::vec2 scoreboard_top_left_corner = {3200.0f, 500.0f};
        glm::vec2 scoreboard_container_bottom_right_corner = {3700.0f, 1700.0f};
        ci::gl::drawSolidRect(ci::Rectf(scoreboard_top_left_corner, scoreboard_container_bottom_right_corner));

        // Display Score Text
        ci::gl::drawStringCentered(
                "SCORE",
                glm::vec2(3450.0f, 550.0f), ci::Color("yellow"), ci::Font("Impact", 150.0f));

        // Draw texture rectangles
        ci::gl::color(ci::Color8u(150, 150, 150));
        ci::gl::drawSolidRect(ci::Rectf(glm::vec2 {0.0f, 0.0f}, glm::vec2 {500.0f, 700.0f}));

        ci::gl::color(ci::Color8u(140, 140, 140));
        ci::gl::drawSolidRect(ci::Rectf(glm::vec2 {30.0, 250.0}, glm::vec2 {650.0f, 950.0f}));

        ci::gl::color(ci::Color8u(160, 160, 160));
        ci::gl::drawSolidRect(ci::Rectf(glm::vec2 {330.0, 650.0}, glm::vec2 {450.0f, 1050.0f}));

        // Draw Ball
        ball_.Draw();

        // Draw Level
        current_level_ = GetLevel(current_level_.GetLevelNumber());
        current_level_.Draw();
    }

    void BrickBreakerApp::update() {
        // Update ball velocity if the ball collided with the wall
        std::vector<bool> wall_collision_directions = ball_.HasCollidedWithWall();
        if(wall_collision_directions.at(0) || wall_collision_directions.at(1)) {
            ball_.CalculateVelocityAfterWallCollision(wall_collision_directions);
        }

        // Determine if the ball collided with any bricks
        for(int brick = 0; brick < current_level_.GetBricks().size(); ++brick) {
            std::vector<bool> brick_collision_directions = ball_.HasCollidedWithBrick(
                    current_level_.GetBricks().at(brick));
            if(brick_collision_directions.at(0) || brick_collision_directions.at(1)) {
                ball_.CalculateVelocityAfterBrickCollision(brick_collision_directions);
            }
        }

        // Update ball position
        ball_.CalculatePositionAfterCollision();
    }

    void BrickBreakerApp::keyDown(ci::app::KeyEvent event) {
        switch (event.getCode()) {
            case ci::app::KeyEvent::KEY_DELETE:
                // Delete all particles
                //simulator_.ClearParticles();
                break;

            case ci::app::KeyEvent::KEY_r:
                // Add a red particle
                //simulator_.AddParticle(ci::Color("red"));
                break;

            case ci::app::KeyEvent::KEY_b:
                // Add a blue particle
                //simulator_.AddParticle(ci::Color("blue"));
                break;

            case ci::app::KeyEvent::KEY_g:
                // Add a green particle
                //simulator_.AddParticle(ci::Color("green"));
                break;
        }
    }

    Level BrickBreakerApp::GetLevel(int level) {
        // Initialize a vector to store bricks
        std::vector<Brick> bricks;

        // Generate appropriate levels
        if(level == 1) {
            // Add bricks for Level 1
            float x_1 = 1850.0f;
            float y_1 = 1050.0f;
            Brick brick_1 = Brick(kCrackedClay, kWeak, glm::vec2 {x_1, y_1},
                                 glm::vec2 {x_1 + kBrickWidth, y_1 + kBrickLength});
            bricks.push_back(brick_1);

            float x_2 = 2060.0f;
            float y_2 = 1050.0f;
            Brick brick_2 = Brick(kCrackedClay, kWeak, glm::vec2 {x_2, y_2},
                                  glm::vec2 {x_2 + kBrickWidth, y_2 + kBrickLength});
            bricks.push_back(brick_2);

            float x_3 = 2270.0f;
            float y_3 = 1050.0f;
            Brick brick_3 = Brick(kCrackedClay, kWeak, glm::vec2 {x_3, y_3},
                                  glm::vec2 {x_3 + kBrickWidth, y_3 + kBrickLength});
            bricks.push_back(brick_3);

            float x_4 = 1640.0f;
            float y_4 = 1050.0f;
            Brick brick_4 = Brick(kCrackedClay, kWeak, glm::vec2 {x_4, y_4},
                                  glm::vec2 {x_4 + kBrickWidth, y_4 + kBrickLength});
            bricks.push_back(brick_4);

            float x_5 = 1430.0f;
            float y_5 = 1050.0f;
            Brick brick_5 = Brick(kCrackedClay, kWeak, glm::vec2 {x_5, y_5},
                                  glm::vec2 {x_5 + kBrickWidth, y_5 + kBrickLength});
            bricks.push_back(brick_5);

            float x_6 = 1220.0f;
            float y_6 = 1050.0f;
            Brick brick_6 = Brick(kCrackedClay, kWeak, glm::vec2 {x_6, y_6},
                                  glm::vec2 {x_6 + kBrickWidth, y_6 + kBrickLength});
            bricks.push_back(brick_6);

            float x_7 = 1430.0f;
            float y_7 = 940.0f;
            Brick brick_7 = Brick(kCrackedClay, kWeak, glm::vec2 {x_7, y_7},
                                  glm::vec2 {x_7 + kBrickWidth, y_7 + kBrickLength});
            bricks.push_back(brick_7);

            float x_8 = 1640.0f;
            float y_8 = 940.0f;
            Brick brick_8 = Brick(kCrackedClay, kWeak, glm::vec2 {x_8, y_8},
                                  glm::vec2 {x_8 + kBrickWidth, y_8 + kBrickLength});
            bricks.push_back(brick_8);

            float x_9 = 1850.0f;
            float y_9 = 940.0f;
            Brick brick_9 = Brick(kCrackedClay, kWeak, glm::vec2 {x_9, y_9},
                                  glm::vec2 {x_9 + kBrickWidth, y_9 + kBrickLength});
            bricks.push_back(brick_9);

            float x_10 = 2060.0f;
            float y_10 = 940.0f;
            Brick brick_10 = Brick(kCrackedClay, kWeak, glm::vec2 {x_10, y_10},
                                  glm::vec2 {x_10 + kBrickWidth, y_10 + kBrickLength});
            bricks.push_back(brick_10);

            float x_11 = 1640.0f;
            float y_11 = 830.0f;
            Brick brick_11 = Brick(kCrackedClay, kWeak, glm::vec2 {x_11, y_11},
                                   glm::vec2 {x_11 + kBrickWidth, y_11 + kBrickLength});
            bricks.push_back(brick_11);

            float x_12 = 1850.0f;
            float y_12 = 830.0f;
            Brick brick_12 = Brick(kCrackedClay, kWeak, glm::vec2 {x_12, y_12},
                                   glm::vec2 {x_12 + kBrickWidth, y_12 + kBrickLength});
            bricks.push_back(brick_12);

            // Add bricks to level 1
            Level level_1 = Level(1, bricks);

            return level_1;
        }

        Level level_default = Level(1, bricks);
        return level_default;
    }
}
}