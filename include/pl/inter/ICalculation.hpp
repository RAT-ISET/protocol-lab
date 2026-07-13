// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/inter/ICalculation.hpp
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

template<class Out, class In, size_t InputCount>
class ICalculation : public ICalculationBase
{
public:
    ~ICalculation() override = default;
    virtual size_t addTask(const array<In, InputCount>& inputs) = 0;
    virtual Out getResult(size_t index) = 0;
    virtual vector<Out>& getResults() = 0;
    virtual void clear() = 0;
};

template<class Out, class TaskType>
class IMultiCalculation : public ICalculationBase
{
public:
    ~IMultiCalculation() override = default;
    virtual size_t addMultiTask(TaskType task) = 0;
    virtual vector<Out>& getMultiResult(size_t index) = 0;
    virtual void clear() = 0;
};
