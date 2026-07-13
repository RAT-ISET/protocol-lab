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

void BaseWaveCalculationTask::addEntry(BaseWaveStatus& in)
{
    source_.push_back(&in);
    data_[0].pushBack(in.values_.back());
    data_[1].pushBack(in.omega_);
}

void BaseWaveCalculationTask::run()
{
    for (size_t i = 0; i < step_count_; i++)
        step();
}

void BaseWaveCalculationTask::step()
{
    data_[0] *= data_[1];
    BaseWaveStatus::update(source_, data_[0]);
}

void BaseWaveCalculation::run()
{
    for (BaseWaveCalculationTask& task : tasks_)
        task.run();
}

void BaseWaveCalculation::addTask(const BaseWaveCalculationTask task)
{
    tasks_.push_back(task);
}

void BaseWaveCalculation::clear()
{
    tasks_.clear();
}
