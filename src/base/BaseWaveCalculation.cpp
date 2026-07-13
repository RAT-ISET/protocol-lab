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
#include <bits/ios_base.h>

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

void BaseWaveCalculationTask::addEntry(BaseWaveStatus& input_value)
{
    inputs_.push_back(&input_value);
}

void BaseWaveCalculationTask::calculate()
{
    for (BaseWaveStatus* input : inputs_)
    {
        input->calculate();
    }
}

void BaseWaveMultiCalculation::run()
{
    for (BaseWaveCalculationTask task : tasks_) task.calculate();
}

size_t BaseWaveMultiCalculation::addMultiTask(const BaseWaveCalculationTask task)
{
    tasks_.push_back(task);
    return tasks_.size() - 1;
}

vector<SignalData>& BaseWaveMultiCalculation::getMultiResult(size_t index)
{
    return *tasks_[index].outputs_;
}

void BaseWaveMultiCalculation::clear()
{
    tasks_.clear();
}
