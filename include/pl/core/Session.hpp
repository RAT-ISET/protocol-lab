// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/core/Session.hpp
// Header file of the software session.

#pragma once

#include <pl/ui/UiCore.hpp>
#include <pl/core/Workspace.hpp>

class Session
{
    UiEntry* ui_;
    vector<Workspace> workspaces_;
    bool have_ui_;
public:
    explicit Session(UiEntry* ui);
    Session();
    int run();
};
