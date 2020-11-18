#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "ideal_gas_simulator.h"

namespace idealgas {

namespace visualizer {

    /** Allows a user to add ideal gas particles to a container and view collisions  */
    class IdealGasApp : public ci::app::App {

    private:
        /** Window Screen Margins */
        const float kWindowWidth = 3000.0f;
        const float kWindowHeight = 2000.0f;
        const float kMargin = 300.0f;
        const float kHistogramMargin = 175.0f;
        const float kHistogramSideLength = 433.0f;

        IdealGasSimulator simulator_;

    public:
        IdealGasApp();

        void draw() override;

        void update() override;

        void keyDown(ci::app::KeyEvent event) override;

        //void mouseDown(ci::app::MouseEvent event) override;

        //void mouseDrag(ci::app::MouseEvent event) override;

    };

}  // namespace visualizer

}  // namespace idealgas
