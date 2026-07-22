// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/ui/inter/IRender.hpp
// Interface of the render item.

#pragma once

#include <vector>

using namespace std;

class IRender
{
public:
    virtual ~IRender() = default;
    virtual void render() = 0;
    virtual bool canClose() = 0;
    virtual void close(vector<IRender*>& renders) = 0;
};
