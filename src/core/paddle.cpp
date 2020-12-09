#include <core/paddle.h>

namespace brickbreaker {

    Paddle::Paddle(const glm::vec2 paddle_top_left_corner, const glm::vec2 &paddle_bottom_right_corner,
                   const glm::vec2 &container_top_left_corner, const glm::vec2 &container_bottom_right_corner) {
        paddle_top_left_corner_ = paddle_top_left_corner;
        paddle_bottom_right_corner_ = paddle_bottom_right_corner;
        container_top_left_corner_ = container_top_left_corner;
        container_bottom_right_corner_ = container_bottom_right_corner;
    }




} // namespace brickbreaker


