#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
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

    /** Wall Margins */
    const float kContainerWallStroke = 70.0f;
    glm::vec2 container_top_left_corner_ = {100.0f, 185.0f};
    glm::vec2 container_bottom_right_corner_ = {1775.0f, kWindowHeight + (kContainerWallStroke / 2)};
    const ci::Color container_color_ = ci::Color("yellow");

    /** Paddle Attributes */
    float const kPaddleHeight = 80.0f;
    float const kPaddleWidth = 310.0f;
    glm::vec2 paddle_initial_position = {container_top_left_corner_.x +
                                         ((container_top_left_corner_.x - container_bottom_right_corner_.x)/2)
                                         - (kPaddleWidth/2),
                                         kWindowHeight - kPaddleHeight};
    Paddle paddle_;

    /** Ball Attributes */
    float const kBallRadius = 25.0f;
    glm::vec2 ball_initial_position_ = {paddle_initial_position.x + (kPaddleWidth / 2),
                                        paddle_initial_position.y - kBallRadius};
    glm::vec2 ball_initial_velocity_ = {-25.0f, -30.0f};
    Ball ball_;

    /** Brick Attributes */
    float const kBrickLength = 100.0f;
    float const kBrickWidth = 200.0f;

    /** Scoreboard Dimensions */
    float const kScoreboardTextX = 2250.0f;
    float const kScoreboardTextY = 425.0f;
    float const kScoreboardSpacing = 425.0f;

    /** Game Attributes */
    const size_t kNumberOfLevels = 4;
    const size_t kScorePerBrickHit = 10;
    Level current_level_;
    size_t score_;
    size_t ammo_;
    size_t lives_;
    size_t high_score_;

    /** Game Conditions */
    bool new_game_;
    bool resume_game_;
    bool ball_in_motion_;
    bool generate_new_level_;
    bool has_game_ended_;

public:
    /**
     * Constructs the Brick Breaker Game
     */
    BrickBreakerApp();

    /** Cinder Functions */
    void draw() override;

    void update() override;

    void keyDown(ci::app::KeyEvent event) override;

    void mouseMove(ci::app::MouseEvent event) override;

    /**
     * Generates respective level with corresponding bricks
     * @param level size_t representing the level number
     * @return
     */
    Level GenerateLevel(size_t level);

    /**
     * Displays the game scoreboard
     */
    void DisplayScoreboard();

    /**
     * Displays paddle, ball, and pop up message in default positions
     */
    void DrawDefaultStage();

    /**
     * Displays pop up message with 'You Win' text and resets ball/paddle to default positions
     */
    void DisplayWinScreen();

    /**
     * Displays pop up message with 'Game Over' text and resets ball/paddle to default positions
     */
    void DisplayGameOverScreen();
};

}  // namespace visualizer

}  // namespace brickbreaker
