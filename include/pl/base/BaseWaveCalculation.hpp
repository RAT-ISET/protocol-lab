// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/base/BaseWaveCalculation.hpp
// Header file of the base RF wave calculation.

#pragma once

#include <cmath>
#include <vector>
#include <array>
#include <pl/inter/ISignal.hpp>
#include <pl/inter/ICalculation.hpp>
#include <pl/base/BaseWave.hpp>

using namespace std;

struct BaseWaveCalculationTask : ICalculationTask<BaseWaveStatus>
{
    vector<BaseWaveStatus*> source_;
    array<SignalDataBuffer, 2> data_;
    size_t step_count_;
    explicit BaseWaveCalculationTask(const size_t step_count) : step_count_(step_count) {}
    void addEntry(BaseWaveStatus& in) override;
    void run() override;
    void step();
};

class BaseWaveCalculation : public ICalculation<BaseWaveCalculationTask>
{
    array<vector<SignalData>, 2> inputs_;
    vector<SignalData> outputs_;
public:
    void run() override;
    void addTask(BaseWaveCalculationTask task) override;
    void clear() override;
};

inline auto base_wave_calculation = BaseWaveCalculation();
