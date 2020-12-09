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

        /** Container Attributes */
        glm::vec2 container_top_left_corner_;
        glm::vec2 container_bottom_right_corner_;

        friend class Ball;

        friend class Level;

    public:

        Paddle(const glm::vec2 paddle_top_left_corner, const glm::vec2 &paddle_bottom_right_corner,
               const glm::vec2 &container_top_left_corner, const glm::vec2 &container_bottom_right_corner);

        /** Getter Methods */
        const glm::vec2 &GetPaddlePosition();

        /** Setter Methods */
        void SetPaddlePosition(const glm::vec2 &position);

        /**
         * Draws paddle in the cinder application
         */
        void Draw();
    };

} // namespace brickbreaker
