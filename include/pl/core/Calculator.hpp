// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/core/Calculator.hpp
// Header file of the data calculator.

#pragma once

#include <vector>
#include <pl/inter/ICalculation.hpp>

using namespace std;

class Calculator
{
    vector<ICalculationBase*> calculation_list_{};
public:
    Calculator() = default;
    void run() const;
    void registerCalculation(ICalculationBase* calculation);
};

inline auto CALCULATOR = Calculator();
