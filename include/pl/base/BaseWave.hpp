// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/base/BaseWave.hpp
// Header file of the base RF wave class.

#pragma once

#include <vector>
#include <pl/inter/ISignal.hpp>
#include <pl/inter/IModule.hpp>

using namespace std;

struct BaseWaveStatus
{
    SignalDataBuffer values_{};
    const SignalData omega_;
    BaseWaveStatus(double phase, double omega);
    inline void iteration();
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
