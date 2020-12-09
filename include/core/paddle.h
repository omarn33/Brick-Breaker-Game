#pragma once

#include "cinder/gl/gl.h"
#include "../../../../include/glm/glm.hpp"
#include "../../../../include/cinder/Color.h"
#include <vector>

namespace brickbreaker {
    class Paddle {
    private:
        /** Paddle Attributes */
        glm::vec2 paddle_top_left_corner_;
        glm::vec2 paddle_bottom_right_corner_;
        float paddle_sensitivity_;

        /** Container Attributes */
        glm::vec2 container_top_left_corner_;
        glm::vec2 container_bottom_right_corner_;
        float container_stroke_width_;

        friend class Ball;

    public:

        Paddle(const glm::vec2 paddle_top_left_corner, const glm::vec2 &paddle_bottom_right_corner, float paddle_sensitivity,
               const glm::vec2 &container_top_left_corner, const glm::vec2 &container_bottom_right_corner, float container_stroke_width);

        /** Getter Methods */
        const glm::vec2 &GetPaddlePosition();

        /** Setter Methods */
        void SetPaddlePosition(const glm::vec2 &position);

        void MovePaddleRight();

        void MovePaddleLeft();

        /**
         * Draws paddle in the cinder application
         */
        void Draw();
    };

} // namespace brickbreaker
