// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /src/core/BaseWave.cpp
// Base RF wave class.

#include <pl/core/BaseWave.hpp>
#include <numbers>

BaseWaveStatus BaseWaveStatus::buildBaseWaveStatus(double phase, double omega)
{
    double omega_sin, omega_cos;
    sincos(omega, &omega_sin, &omega_cos);
    return {phase, omega_sin, omega_cos};
}

BaseWaveStatus::BaseWaveStatus
(const double phase, const double omega_sin, const double omega_cos)
    : phase_(phase)
    , omega_sin_(omega_sin)
    , omega_cos_(omega_cos)
{
    sincos(phase, &value_sin_, &value_cos_);
}

BaseWave::BaseWave(const double frequency, const double amplitude, const double phase)
    : frequency_(frequency)
    , amplitude_(amplitude)
    , status_(BaseWaveStatus::buildBaseWaveStatus(phase, 2 * numbers::pi * frequency)) {}
