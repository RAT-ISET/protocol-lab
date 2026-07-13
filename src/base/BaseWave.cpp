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

void BaseWaveCalculation::run()
{
    outputs_ = SignalDataBuffer(inputs_[0]) * SignalDataBuffer(inputs_[1]);
}

size_t BaseWaveCalculation::addTask(const array<SignalData, 2>& inputs)
{
    inputs_[0].push_back(inputs[0]);
    inputs_[1].push_back(inputs[1]);
    return inputs_[0].size() - 1;
}

SignalData BaseWaveCalculation::getResult(const size_t index)
{
    return outputs_[index];
}

vector<SignalData>& BaseWaveCalculation::getResults()
{
    return outputs_;
}

void BaseWaveCalculation::clear()
{
    inputs_[0].clear();
    inputs_[1].clear();
    outputs_.clear();
}

BaseWave::BaseWave(const double frequency, const double amplitude, const double phase)
    : frequency_(frequency)
    , amplitude_(amplitude)
    , status_(BaseWaveStatus(phase, 2 * numbers::pi * frequency)) {}

void BaseWave::init()
{
    CALCULATOR.registerCalculation(&base_wave_calculation);
}
