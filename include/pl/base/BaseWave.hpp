// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/base/BaseWave.hpp
// Header file of the base RF wave class.

#pragma once

#include <cmath>
#include <cstdlib>
#include <vector>
#include <array>
#include <pl/inter/ISignal.hpp>
#include <pl/inter/IModule.hpp>
#include <pl/inter/ICalculation.hpp>

using namespace std;

class BaseWaveStatus
{
    SignalData value_;
    const SignalData omega_;
public:
    BaseWaveStatus(double phase, double omega);
    void step() const;
    void step(size_t step);
    void calibrate();
};

class BaseWave : public IGetSignal, public IModule
{
    double frequency_;
    double amplitude_;
    BaseWaveStatus status_;
public:
    void init() override;
    BaseWave(double frequency, double amplitude, double phase);
    SignalData getValue(double time) override;
};
