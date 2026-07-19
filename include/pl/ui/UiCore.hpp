// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/ui/UiCore.hpp
// Header file of the ui core for project.

#pragma once

#include <vector>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <pl/core/Environment.hpp>

using namespace std;

class UiEntry
{
    GLFWwindow* window_ = nullptr;
    float scale_ = 0;
    void setStyle(ImGuiIO& io) const;
public:
    int init();
    [[nodiscard]] int runGui(vector<Environment>& data) const;
};

