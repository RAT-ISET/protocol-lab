// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /src/core/SignalData.cpp
// Make and use data for signal.

#include <cmath>
#include <vector>
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

SignalDataBuffer::SignalDataBuffer(const vector<SignalData>& signal_data)
{
    Is.reserve(signal_data.size());
    Qs.reserve(signal_data.size());
    for (const SignalData& item : signal_data)
    {
        Is.push_back(item.I);
        Qs.push_back(item.Q);
    }
}

void SignalDataBuffer::pushBack(const SignalData& value)
{
    Is.push_back(value.I);
    Qs.push_back(value.Q);
}

void SignalDataBuffer::replace(const size_t index, const SignalData& data)
{
    Is[index] = data.I;
    Qs[index] = data.Q;
}

void SignalDataBuffer::operator*=(const SignalDataBuffer& value)
{
    for (size_t i = 0; i < Is.size(); i++)
        replace(i, SignalData(
        Is[i] * value.Is[i] - Qs[i] * value.Qs[i],
        Is[i] * value.Qs[i] + Qs[i] * value.Is[i]
        ));
}
