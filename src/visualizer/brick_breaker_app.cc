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
        ci::gl::color(ci::Color8u(255, 255, 255));
        ci::gl::Texture2dRef image = ci::gl::Texture::create(ci::loadImage("C:\\Users\\Omar\\Desktop\\Background.png"));
        ci::gl::draw(image, ci::Rectf(glm::vec2 {0, 0}, glm::vec2 {kWindowWidth, kWindowHeight}));

        // Draw Container
        /*
        ci::gl::color(container_color_);
        ci::gl::drawStrokedRect(ci::Rectf(container_top_left_corner_, container_bottom_right_corner_),
                                kContainerWallStroke);
                                */

        // Display Score Text
        /*
        ci::gl::drawStringCentered(
                "SCORE",
                glm::vec2(3450.0f, 550.0f), ci::Color("yellow"), ci::Font("Impact", 150.0f));
        */

        /*
        // Display Brick Types
        ci::gl::color(ci::Color8u(255, 255, 255));
        ci::gl::Texture2dRef steel_brick = ci::gl::Texture::create(ci::loadImage("C:\\Users\\Omar\\Desktop\\Steel_Brick.png"));
        ci::gl::draw(steel_brick, ci::Rectf(glm::vec2 {1000.0f, 1000.0f}, glm::vec2 {1200.0f, 1100.0f}));

        ci::gl::color(ci::Color8u(255, 255, 255));
        ci::gl::Texture2dRef solid_brick = ci::gl::Texture::create(ci::loadImage("C:\\Users\\Omar\\Desktop\\Solid_Brick.png"));
        ci::gl::draw(solid_brick, ci::Rectf(glm::vec2 {1500.0f, 1500.0f}, glm::vec2 {1700.0f, 1600.0f}));

        ci::gl::color(ci::Color8u(255, 255, 255));
        ci::gl::Texture2dRef normal_brick = ci::gl::Texture::create(ci::loadImage("C:\\Users\\Omar\\Desktop\\Normal_Brick.png"));
        ci::gl::draw(normal_brick, ci::Rectf(glm::vec2 {900.0f, 900.0f}, glm::vec2 {1100.0f, 1000.0f}));
         */

        ci::gl::color(ci::Color8u(255, 255, 255));
        ci::gl::Texture2dRef paddle = ci::gl::Texture::create(ci::loadImage("C:\\Users\\Omar\\Desktop\\Paddle.png"));
        ci::gl::draw(paddle, ci::Rectf(paddle_initial_position, glm::vec2 {paddle_initial_position.x + kPaddleWidth, paddle_initial_position.y + kPaddleHeight}));

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
            std::cout << "iteration bricks" << std::endl;

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
            float brick_spacing = 10.0f;

            // Section 1
            float x_1 = 800.0f;
            float y_1 = 975.0f;
            Brick brick_1 = Brick(kCrackedClay, kWeak, glm::vec2 {x_1, y_1},
                                 glm::vec2 {x_1 + kBrickWidth, y_1 + kBrickLength});
            bricks.push_back(brick_1);

            float x_2 = x_1 + kBrickWidth + brick_spacing;
            float y_2 = y_1;
            Brick brick_2 = Brick(kCrackedClay, kWeak, glm::vec2 {x_2, y_2},
                                  glm::vec2 {x_2 + kBrickWidth, y_2 + kBrickLength});
            bricks.push_back(brick_2);

            float x_3 = x_1;
            float y_3 = y_1 + kBrickLength + brick_spacing;
            Brick brick_3 = Brick(kCrackedClay, kWeak, glm::vec2 {x_3, y_3},
                                  glm::vec2 {x_3 + kBrickWidth, y_3 + kBrickLength});
            bricks.push_back(brick_3);

            float x_4 = x_3 + kBrickWidth + brick_spacing;
            float y_4 = y_3;
            Brick brick_4 = Brick(kCrackedClay, kWeak, glm::vec2 {x_4, y_4},
                                  glm::vec2 {x_4 + kBrickWidth, y_4 + kBrickLength});
            bricks.push_back(brick_4);

            // Add bricks to level 1
            Level level_1 = Level(1, bricks);

            return level_1;
        }

        Level level_default = Level(1, bricks);
        return level_default;
    }
}
}