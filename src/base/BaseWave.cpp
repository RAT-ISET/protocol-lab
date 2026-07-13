// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /src/base/BaseWave.cpp
// Base RF wave class.

#include <pl/base/BaseWave.hpp>
#include <pl/base/BaseWaveCalculation.hpp>
#include <pl/core/SignalData.hpp>
#include <pl/inter/ICalculation.hpp>
#include <pl/core/Calculator.hpp>
#include <numbers>
#include <vector>

BaseWaveStatus::BaseWaveStatus(const SignalData& phase, const SignalData& omega)
    : omega_(omega)
{
    values_.push_back(phase);
}

void BaseWaveStatus::update(vector<BaseWaveStatus*>& source, const SignalDataBuffer& values)
{
    for (size_t i = 0; i < source.size(); i++)
        source[i].values_.push_back
            (SignalData(values.Is[i], values.Qs[i]));
}

void BaseWave::init()
{
    // TODO(base): Initialize the BaseWave Module.
}

BaseWave::BaseWave(const double frequency, const double amplitude, const double phase)
    : frequency_(frequency)
    , amplitude_(amplitude)
    , status_(BaseWaveStatus(
        SignalData(phase),
        SignalData(2 * numbers::pi * frequency)
    )){}

SignalData& BaseWave::getValue(const size_t time)
{
    return status_.values_[time];
}
