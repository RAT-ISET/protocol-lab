// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /src/core/Calculator.cpp
// Data calculator.

#include <pl/core/Calculator.hpp>

void Calculator::run() const
{
    for (ICalculationBase* item : calculation_list_) item->run();
}

void Calculator::registerCalculation(ICalculationBase* calculation)
{
    calculation_list_.push_back(calculation);
}
