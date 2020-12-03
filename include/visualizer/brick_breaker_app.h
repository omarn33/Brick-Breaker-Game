
#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "ideal_gas_simulator.h"
#include <core/ball.h>

namespace brickbreaker {

namespace visualizer {

/** Allows a user to play the Brick Breaker game  */
class BrickBreakerApp : public ci::app::App {

private:
    /** Window Screen Margins */
    const float kWindowWidth = 4000.0f;
    const float kWindowHeight = 2000.0f;
    const float kMargin = 300.0f;

    /** Wall Margins */
    glm::vec2 container_top_left_corner_ = {700.0f, 100.0f};
    glm::vec2 container_bottom_right_corner_ = {3000.0f, 2055.55f};
    const float kContainerWallStroke = 50.0f;
    const ci::Color container_color_ =  ci::Color("yellow");

    /** Ball Attributes */
    float const kBallRadius = 35.0f;
    const ci::Color8u kBallColor = ci::Color8u(105, 105, 105);
    glm::vec2 ball_initial_position_ = {1000.0f, 1000.0f};
    glm::vec2 ball_initial_velocity_ = {-5.0f, -5.0f};
    Ball ball_;

public:
    BrickBreakerApp();

    void draw() override;

    void update() override;

    void keyDown(ci::app::KeyEvent event) override;

    //void mouseDown(ci::app::MouseEvent event) override;

    //void mouseDrag(ci::app::MouseEvent event) override;

};

}  // namespace visualizer

}  // namespace brickbreaker
