#include <core/particle.h>
#include <core/particle_physics.h>
#include <visualizer/ideal_gas_simulator.h>


#include <iostream>

using namespace idealgas;
using namespace visualizer;

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main(int argc, char* argv[]) {

    glm::vec2 top_left(0.0, 0.0);
    glm::vec2 bottom_right(100.0, 100.0);

    glm::vec2 position1(20.0, 20.0);
    glm::vec2 velocity1(0.1, 0.0);

    glm::vec2 position2(21.4, 21.4);
    glm::vec2 velocity2(-0.1, 0.0);

    Particle particle1(1.0f, 1.0, "white", position1, velocity1);
    Particle particle2(1.0f, 1.0, "white", position2, velocity2);

    ParticlePhysics physics(top_left, bottom_right);

    if(physics.HasParticleCollidedWithParticle(particle1, particle2))
    {
        cout << "Particles collided!" << endl;
        physics.CalculateVelocityAfterParticleCollision(particle1, particle2);

        cout << "Particle 1 Velocity: (" << particle1.GetVelocity().x << ", " << particle1.GetVelocity().y << ")" << endl;
        cout << "Particle 2 Velocity: (" << particle2.GetVelocity().x << ", " << particle2.GetVelocity().y << ")" << endl;

        cout << endl;

        physics.CalculatePositionAfterCollision(particle1);
        physics.CalculatePositionAfterCollision(particle2);
    }
    else
    {
        cout << "Particles did not collide!" << endl;
    }

    cout << "Particle 1 Position: (" << particle1.GetPosition().x << ", " << particle1.GetPosition().y << ")" << endl;
    cout << "Particle 2 Position: (" << particle2.GetPosition().x << ", " << particle2.GetPosition().y << ")" << endl;

  return 0;
}
