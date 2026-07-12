// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/inter/ICalculation.cpp
// Interface of calculate process.

#pragma once

#include <vector>

using namespace std;

class ICalculationBase
{
public:
    virtual ~ICalculationBase();
    virtual void run();
};

template<class Out, class In>
class ICalculation : ICalculationBase
{
public:
    ~ICalculation() override = default;
    virtual void addTask(In ins...);
    virtual Out getResult(size_t index);
    virtual vector<Out> getResults();
};
