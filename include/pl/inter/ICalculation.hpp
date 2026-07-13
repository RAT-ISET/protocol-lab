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

template<class TaskType>
class ICalculation : public ICalculationBase
{
public:
    ~ICalculation() override = default;
    virtual void addTask(TaskType task) = 0;
    virtual void clear() = 0;
};

template<class In>
struct ICalculationTask
{
    virtual ~ICalculationTask() = default;
    virtual void addEntry(In& in) = 0;
    virtual void run() = 0;
};
