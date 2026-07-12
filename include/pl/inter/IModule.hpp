// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/inter/IModule.hpp
// Interface of module.

#pragma once

class IModule
{
public:
    virtual ~IModule() = default;
    virtual void init();
};
