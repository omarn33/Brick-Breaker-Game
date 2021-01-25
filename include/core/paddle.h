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
    float length_;

    /** Container Attributes */
    glm::vec2 container_top_left_corner_;
    glm::vec2 container_bottom_right_corner_;
    float container_stroke_width_;

    friend class Ball;

public:
    /**
     * Constructs a Paddle with the given attributes
     * @param paddle_top_left_corner glm::vec2 representing the coordinate of the top left corner of the paddle
     * @param paddle_bottom_right_corner glm::vec2 representing the coordinate of the bottom right corner of the paddle
     * @param container_top_left_corner glm::vec2 representing the coordinate of the top left corner of the container
     * @param container_bottom_right_corner glm::vec2 representing the coordinate of the bottom right corner of the container
     * @param container_stroke_width float representing the width of the container walls
     */
    Paddle(const glm::vec2 paddle_top_left_corner, const glm::vec2 &paddle_bottom_right_corner,
           const glm::vec2 &container_top_left_corner, const glm::vec2 &container_bottom_right_corner,
           float container_stroke_width);

    /** Getter Methods */
    const glm::vec2 &GetPaddlePosition();

    /** Setter Methods */
    void SetPaddlePosition(const glm::vec2 &position);

    /**
     * Draws the Paddle in the cinder application
     */
    void Draw();
};

} // namespace brickbreaker
