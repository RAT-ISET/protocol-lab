// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/core/Session.hpp
// Header file of the software session.

#pragma once

#include <optional>
#include <string>
#include <pl/ui/UiCore.hpp>
#include <pl/core/Environment.hpp>

class Session
{
    UiEntry* ui_;
    vector<Environment> environments_;
    optional<string> path_;
    bool have_ui_;
public:
    explicit Session(UiEntry* ui);
    Session();
    int run();
    optional<string>& getPath();
};
