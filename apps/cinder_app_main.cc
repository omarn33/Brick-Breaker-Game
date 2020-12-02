#include <visualizer/brick_breaker_app.h>

using brickbreaker::visualizer::BrickBreakerApp;

void prepareSettings(BrickBreakerApp::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(BrickBreakerApp, ci::app::RendererGl, prepareSettings);
