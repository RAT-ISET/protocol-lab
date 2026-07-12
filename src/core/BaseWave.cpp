// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /src/core/BaseWave.cpp
// Base RF wave class.

#include <pl/core/BaseWave.hpp>
#include <pl/core/SignalData.hpp>
#include <numbers>

BaseWaveStatus::BaseWaveStatus
(const double phase, const double omega)
    : value_(phase)
    , omega_(omega) {}

BaseWave::BaseWave(const double frequency, const double amplitude, const double phase)
    : frequency_(frequency)
    , amplitude_(amplitude)
    , status_(BaseWaveStatus(phase, 2 * numbers::pi * frequency)) {}
