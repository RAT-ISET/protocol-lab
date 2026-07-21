// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/api/Actions.hpp
// Header file of the user actions runner.

#pragma once

enum class ActionType
{
    ProjectNew,
};

void handleActions(const ActionType& action);
