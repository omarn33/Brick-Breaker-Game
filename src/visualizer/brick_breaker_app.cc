#include <visualizer/brick_breaker_app.h>
#include <iostream>

namespace brickbreaker {

namespace visualizer {
    BrickBreakerApp::BrickBreakerApp() : ball_(kBallRadius, kBallColor, ball_initial_position_, ball_initial_velocity_,
                                               container_top_left_corner_, container_bottom_right_corner_) {
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
        glm::vec2 inner_container_top_left_corner = {725.0f, 225.0f};
        glm::vec2 inner_container_bottom_right_corner = {2975.0f, 2055.55f};
        ci::gl::drawSolidRect(ci::Rectf(inner_container_top_left_corner, inner_container_bottom_right_corner));

        // Draw Scoreboard
        ci::gl::color(ci::Color8u(140, 140, 140));
        glm::vec2 scoreboard_top_left_corner = {3200.0f, 500.0f};
        glm::vec2 scoreboard_container_bottom_right_corner = {3700.0f, 1700.0f};
        ci::gl::drawSolidRect(ci::Rectf(scoreboard_top_left_corner, scoreboard_container_bottom_right_corner));

        // Display Score Text
        ci::gl::drawStringCentered(
                "SCORE",
                glm::vec2(3450.0f, 550.0f), ci::Color("yellow"), ci::Font("Arial", 150.0f));

        // Draw texture rectangles
        ci::gl::color(ci::Color8u(150, 150, 150));
        ci::gl::drawSolidRect(ci::Rectf(glm::vec2 {0.0f, 0.0f}, glm::vec2 {500.0f, 700.0f}));

        ci::gl::color(ci::Color8u(140, 140, 140));
        ci::gl::drawSolidRect(ci::Rectf(glm::vec2 {30.0, 250.0}, glm::vec2 {650.0f, 950.0f}));

        ci::gl::color(ci::Color8u(160, 160, 160));
        ci::gl::drawSolidRect(ci::Rectf(glm::vec2 {330.0, 650.0}, glm::vec2 {450.0f, 1050.0f}));

        // Draw Brick
        // width: 200.0f
        // height: 100.0f
        ci::gl::color(ci::Color8u(128, 0, 0));
        ci::gl::drawSolidRect(ci::Rectf(glm::vec2 {0.0f, 0.0f}, glm::vec2 {200.0f, 100.00f}));

        // Draw Ball
        ball_.Draw();
    }

    void BrickBreakerApp::update() {
        // Update ball velocity if the ball collided with the wall
        std::vector<bool> collision_directions = ball_.HasCollidedWithWall();
        std::cout << "Collision Direction: " << collision_directions.at(0) << ", " << collision_directions.at(1) << std::endl;
        ball_.CalculateVelocityAfterWallCollision(collision_directions);

        std::cout << "Velocity: " << ball_.GetVelocity().x << ", " << ball_.GetVelocity().y << std::endl;


        std::cout << "Initial Position: " << ball_.GetPosition().x << ", " << ball_.GetPosition().y << std::endl;
        // Update ball position
        ball_.CalculatePositionAfterCollision();

        std::cout << "Final Position: " << ball_.GetPosition().x << ", " << ball_.GetPosition().y << std::endl;

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
}
}