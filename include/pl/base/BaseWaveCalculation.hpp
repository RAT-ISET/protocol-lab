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

using namespace std;

class BaseWaveCalculation : public ICalculation<SignalData, SignalData, 2>
{
    array<vector<SignalData>, 2> inputs_;
    vector<SignalData> outputs_;
public:
    void run() override;
    size_t addTask(const array<SignalData, 2>& inputs) override;
    SignalData getResult(size_t index) override;
    vector<SignalData>& getResults() override;
    void clear() override;
};

inline auto base_wave_calculation = BaseWaveCalculation();

struct BaseWaveMultiCalculationData
{
    array<vector<SignalData>, 2> inputs_;
    vector<SignalData> outputs_;
    size_t step_count_;
    explicit BaseWaveMultiCalculationData(const size_t step_count) : step_count_(step_count) {}
    void calculate();
};

class BaseWaveMultiCalculation : public IMultiCalculation<SignalData, BaseWaveMultiCalculationData>
{
    vector<BaseWaveMultiCalculationData> tasks_;
public:
    void run() override;
    size_t addMultiTask(BaseWaveMultiCalculationData task) override;
    vector<SignalData>& getMultiResult(size_t index) override;
    void clear() override;
};

inline auto base_wave_multi_calculation = BaseWaveMultiCalculation();
