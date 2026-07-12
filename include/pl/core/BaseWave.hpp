// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/core/BaseWave.hpp
// Header file of the base RF wave class.

#pragma once

#include <cmath>
#include <pl/inter/ISignal.hpp>
#include <cstdlib>

using namespace std;

class BaseWaveStatus
{
    SignalData value_;
    const SignalData omega_;
public:
    BaseWaveStatus(double phase, double omega);
    void step();
    void step(size_t step);
    void calibrate();
};

class BaseWave : public IGetSignal
{
    double frequency_;
    double amplitude_;
    BaseWaveStatus status_;
public:
    BaseWave(double frequency, double amplitude, double phase);

    SignalData getValue(double time) override;
};
