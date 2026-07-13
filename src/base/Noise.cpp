// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /src/base/Noise.cpp
// Noise spawner.

#include <pl/base/Noise.hpp>

DigitalNoise::DigitalNoise()
{
    seed_ = random_device().operator()();
    rng_ = mt19937(seed_);
}

DigitalNoise::DigitalNoise(uint32_t seed) : seed_(seed)
{
    rng_ = mt19937(seed_);
}

uint32_t DigitalNoise::getSeed() const
{
    return seed_;
}

uint32_t DigitalNoise::step()
{
    return rng_();
}

AnalogNoise::AnalogNoise()
{
    seed_ = random_device().operator()();
    rng_ = mt19937(seed_);
}

AnalogNoise::AnalogNoise(uint32_t seed) : seed_(seed)
{
    rng_ = mt19937(seed_);
}

uint32_t AnalogNoise::getSeed() const
{
    return seed_;
}

SignalData AnalogNoise::step()
{
    status_.I += distribution(rng_);
    status_.Q += distribution(rng_);
    return status_;
}
