
#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "ideal_gas_simulator.h"
#include <core/ball.h>
#include <core/level.h>
#include <core/paddle.h>

namespace brickbreaker {

namespace visualizer {

/** Allows a user to play the Brick Breaker game  */
class BrickBreakerApp : public ci::app::App {

private:
    /** Window Screen Margins */
    const float kHeightToWidthRatio = 1.3125;
    const float kWindowHeight = 1950.0f;
    const float kWindowWidth = kWindowHeight * kHeightToWidthRatio;
    const float kMargin = 300.0f;

    /** Wall Margins */
    const float kContainerWallStroke = 70.0f;
    glm::vec2 container_top_left_corner_ = {100.0f, 185.0f};
    glm::vec2 container_bottom_right_corner_ = {1775.0f, kWindowHeight + (kContainerWallStroke/2)};
    const ci::Color container_color_ =  ci::Color("yellow");

    /** Paddle Attributes */
    float const kPaddleHeight = 80.0f;
    float const kPaddleWidth = 310.0f;
    float const kPaddleSensitivity = 100.0f;
    glm::vec2 paddle_initial_position = {782.5, kWindowHeight - kPaddleHeight};
    Paddle paddle_;

    /** Ball Attributes */
    float const kBallRadius = 25.0f;
    const ci::Color8u kBallColor = ci::Color8u(105, 105, 105);
    glm::vec2 ball_initial_position_ = {paddle_initial_position.x + (kPaddleWidth / 2), paddle_initial_position.y - kBallRadius};
    glm::vec2 ball_initial_velocity_ = {-25.0f, -30.0f};
    Ball ball_;

    /** Brick Attributes */
    float const kBrickLength = 100.0f;
    float const kBrickWidth = 200.0f;

    /** Game Attributes */
    Level current_level_;
    const size_t kNumberOfLevels = 2;
    const size_t kScorePerBrickHit = 10;
    size_t score_;
    size_t ammo_;
    int lives_;
    size_t high_score_;

    /** Game Conditions */
    bool new_game_;
    bool resume_game_;
    bool ball_in_motion_;
    bool generate_new_level_;
    bool has_game_ended_;

public:
    BrickBreakerApp();

    void draw() override;

    void update() override;

    void keyDown(ci::app::KeyEvent event) override;

    void mouseMove(ci::app::MouseEvent event) override;

    //void mouseDrag(ci::app::MouseEvent event) override;

    Level GetLevel(int level);

    void DrawDefaultStage();

};

}  // namespace visualizer

}  // namespace brickbreaker
