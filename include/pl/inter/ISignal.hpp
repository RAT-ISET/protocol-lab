// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/inter/ISignal.hpp
// Interface of signal.

#pragma once

#include <pl/core/SignalData.hpp>

class IGetSignal
{
public:
    virtual ~IGetSignal() = default;
    virtual SignalData& getValue(size_t time) = 0;
};
