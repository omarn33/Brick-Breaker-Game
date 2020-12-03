#include <core/level.h>

namespace brickbreaker {

Level::Level(const std::vector<Brick> &bricks) {
    bricks_ = bricks;
}

void Level::Draw() {
    // Display all bricks within the level
    for(int brick = 0; brick < bricks_.size(); ++brick) {
        bricks_.at(brick).Draw();
    }
}
}  // namespace brickbreaker
