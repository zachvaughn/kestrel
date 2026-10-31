#include "kestrel/rigid_body.hpp"

namespace kestrel {
    RigidBodyDerivative compute_derivative(const RigidBodyState& state,
        const RigidBodyParams& params,
        const RigidBodyInputs& inputs) {
        RigidBodyDerivative derivative; // starts all zeros

        derivative.position_dot = state.velocity;
        derivative.velocity_dot = inputs.force / params.mass;

        return derivative;
        }
} // namespace kestrel