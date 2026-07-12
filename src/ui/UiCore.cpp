// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /src/ui/UiCore.cpp
// Ui core for project.

#include <pl/ui/UiCore.hpp>
#include <GLFW/glfw3.h>
#include <imgui.h>

int runGui()
{
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(640, 480, "ISET Protocol Lab", nullptr, nullptr);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);

    glfwTerminate();

    return 0;
}
