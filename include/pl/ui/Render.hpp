// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/ui/Render.hpp
// Header file of the ui render method.

#pragma once

#include <vector>
#include <pl/core/Environment.hpp>
#include <pl/core/Workspace.hpp>

using namespace std;

void renderMenu();
void renderEnvironment(vector<Environment>& environments);
void renderWorkspace(vector<Workspace>& workspaces);
