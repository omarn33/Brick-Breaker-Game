
#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "ideal_gas_simulator.h"

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
