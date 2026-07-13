// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/base/Noise.hpp
// Header file of the noise spawner.

#pragma once

#include <random>
#include <pl/core/SignalData.hpp>

using namespace std;

class DigitalNoise
{
    mt19937 rng_;
    uint32_t seed_;
public:
    DigitalNoise();
    explicit DigitalNoise(uint32_t seed);

    uint32_t getSeed() const;
    uint32_t step();
};

class AnalogNoise
{
    mt19937 rng_;
    uint32_t seed_;
    SignalData status_ = SignalData(0, 0);
    normal_distribution<> dist_ = normal_distribution<>(0, 1.0);
public:
    AnalogNoise();
    explicit AnalogNoise(uint32_t seed);

    uint32_t getSeed() const;
    SignalData step();
};
