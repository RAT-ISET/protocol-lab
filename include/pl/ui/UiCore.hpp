// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/ui/UiCore.hpp
// Header file of the ui core for project.

#pragma once

#include <GLFW/glfw3.h>

class UiEntry
{
    GLFWwindow* window_ = nullptr;
    float scale_ = 0;
public:
    int init();
    [[nodiscard]] int runGui() const;
};

