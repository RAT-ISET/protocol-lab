// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/core/SignalData.hpp
// Header file of the signal data maker and user.

#pragma once

using namespace std;

#include <vector>

struct SignalData
{
    double I;
    double Q;

    explicit SignalData(double value);
    explicit SignalData(double i_input, double q_input);
    inline SignalData operator*(const SignalData& value) const;
};

struct SignalDataBuffer
{
    vector<double> Is;
    vector<double> Qs;

    inline void replace(size_t index, const SignalData& data);
    inline void pushBack(const SignalData& value);
    [[nodiscard]] inline vector<SignalData> multiData(const SignalDataBuffer& value) const;
    inline SignalDataBuffer operator*(const SignalDataBuffer& value) const;
    inline void operator*=(const SignalDataBuffer& value);

    SignalDataBuffer() = default;
    explicit SignalDataBuffer(const vector<SignalData>& signal_data);
};
