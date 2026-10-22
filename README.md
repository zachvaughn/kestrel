# Kestrel

A 6-DOF quadcopter simulator with EKF state estimation, written in C++20. Simulates a quadcopter with noisy sensors.

## Conventions

| Item | Convention |
|------|------------|
| World frame | NED (x north, y east, z down) |
| Body frame | FRD (x forward, y right, z down) |
| Gravity | +9.81 m/s² along world z |
| Altitude | −z |
| Attitude | Unit quaternion, body → world, Hamilton convention |
| Angular velocity | Body frame |
| Units | SI, angles in radians |

## Building

Requires CMake and a C++20 compiler.

```
cmake -B build
cmake --build build
```

## License

MIT