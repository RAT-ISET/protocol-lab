// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/core/SignalData.hpp
// Header file of the signal data maker and user.

#pragma once

using namespace std;

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
    explicit SignalDataBuffer(const vector<SignalData>& signal_datas);
    inline vector<SignalData> operator*(const SignalDataBuffer& value) const;
};
