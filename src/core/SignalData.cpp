// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /src/core/SignalData.cpp
// Make and use data for signal.

#include <cmath>
#include <pl/core/SignalData.hpp>

SignalData::SignalData(const double value)
{
    double value_sin, value_cos;
    sincos(value, &value_sin, &value_cos);
    I = value_cos;
    Q = value_sin;
}

SignalData::SignalData(const double i_input, const double q_input)
{
    I = i_input;
    Q = q_input;
}

SignalData SignalData::operator*(const SignalData& value) const
{
    return SignalData(I * value.I - Q * value.Q, I * value.Q + Q * value.I);
}
