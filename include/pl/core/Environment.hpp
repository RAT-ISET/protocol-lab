// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/core/Environment.hpp
// Header file of the software environment.

#pragma once

#include <vector>
#include <pl/inter/IModule.hpp>
#include <pl/core/Workspace.hpp>

using namespace std;

class Environment
{
    vector<IModule> modules_;
    vector<Workspace> workspaces_;
};
