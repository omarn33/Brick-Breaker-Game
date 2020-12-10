#include <core/paddle.h>
#include <cinder/app/AppBase.h>

namespace brickbreaker {

Paddle::Paddle(const glm::vec2 paddle_top_left_corner, const glm::vec2 &paddle_bottom_right_corner,
               const glm::vec2 &container_top_left_corner,
               const glm::vec2 &container_bottom_right_corner, float container_stroke_width) {
    paddle_top_left_corner_ = paddle_top_left_corner;
    paddle_bottom_right_corner_ = paddle_bottom_right_corner;
    length_ = paddle_bottom_right_corner_.x - paddle_top_left_corner_.x;

    container_top_left_corner_ = container_top_left_corner;
    container_bottom_right_corner_ = container_bottom_right_corner;
    container_stroke_width_ = container_stroke_width;
}

/** Getter Methods */
const glm::vec2 &Paddle::GetPaddlePosition() {
    return paddle_top_left_corner_;
}

/** Setter Methods */
void Paddle::SetPaddlePosition(const glm::vec2 &position) {
    paddle_top_left_corner_ = position;
    paddle_bottom_right_corner_.x = paddle_top_left_corner_.x + length_;
}

void Paddle::Draw() {
    // Draw Paddle
    ci::gl::color(ci::Color8u(255, 255, 255));
    ci::gl::Texture2dRef paddle = ci::gl::Texture::create(ci::loadImage(
            ci::app::loadAsset("Paddle.png")));
    ci::gl::draw(paddle, ci::Rectf(paddle_top_left_corner_, paddle_bottom_right_corner_));
}

} // namespace brickbreaker


