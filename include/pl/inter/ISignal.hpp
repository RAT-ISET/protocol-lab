// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/inter/ISignal.cpp
// Interface of signal.

#pragma once

struct SignalData
{
    double I;
    double Q;
};

class IGetSignal
{
public:
    virtual ~IGetSignal() = default;
    virtual SignalData getValue(double time) = 0;
};
