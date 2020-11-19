#include <visualizer/brick_breaker_app.h>
#include <iostream>

namespace idealgas {

namespace visualizer {
    IdealGasApp::IdealGasApp() :
    simulator_(IdealGasSimulator(glm::vec2(kWindowWidth * (1 / 3.0), kMargin),
                                                              glm::vec2(kWindowWidth - kMargin,
                                                                        kWindowHeight - kMargin))) {
        ci::app::setWindowSize((int) kWindowWidth, (int) kWindowHeight);
    }

    void IdealGasApp::draw() {
        // Draw background
        ci::Color8u background_color(0, 0, 0);

        // Clear the background color
        ci::gl::clear(background_color);

        // Display instructions
        ci::gl::drawStringCentered(
                "Press [ R ] , [ B ] , [ G ] to add a particle. Press [ Delete ] to remove all particles.",
                glm::vec2(1850.0f, kMargin / 2), ci::Color("white"), ci::Font("Arial", 60.0f));

        // Display Ideal Gas Simulator
        simulator_.Draw();
    }

    void IdealGasApp::update() {
        // Update Ideal Gas Simulator
        simulator_.Update();
    }

    void IdealGasApp::keyDown(ci::app::KeyEvent event) {
        switch (event.getCode()) {
            case ci::app::KeyEvent::KEY_DELETE:
                // Delete all particles
                simulator_.ClearParticles();
                break;

            case ci::app::KeyEvent::KEY_r:
                // Add a red particle
                simulator_.AddParticle(ci::Color("red"));
                break;

            case ci::app::KeyEvent::KEY_b:
                // Add a blue particle
                simulator_.AddParticle(ci::Color("blue"));
                break;

            case ci::app::KeyEvent::KEY_g:
                // Add a green particle
                simulator_.AddParticle(ci::Color("green"));
                break;
        }
    }
}
}