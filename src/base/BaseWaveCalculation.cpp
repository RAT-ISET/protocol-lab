// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /src/base/BaseWaveCalculation.cpp
// Base RF wave calculation.

#include <pl/base/BaseWaveCalculation.hpp>
#include <pl/core/SignalData.hpp>
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

void BaseWaveMultiCalculationData::calculate()
{
    vector<SignalData> caches = inputs_[0];
    for (size_t count = 0; count < step_count_; count++)
    {
        for (size_t index = 0; index < caches.size(); index++)
    }
}

void BaseWaveMultiCalculation::run()
{

}
