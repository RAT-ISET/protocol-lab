// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/core/BaseWave.hpp
// Header file of the base RF wave class.

#pragma once
#include <pl/inter/ISignal.hpp>

class BaseWave : public IGetSignal
{
    double frequency_;
    double amplitude_;
    double phase_;
public:
    BaseWave(const double frequency, const double amplitude, const double phase)
        : frequency_(frequency)
        , amplitude_(amplitude)
        , phase_(phase) {}

    SignalData getValue(double time) override;
};
