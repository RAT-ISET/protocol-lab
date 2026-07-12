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
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

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
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    float scale_x, scale_y;
    glfwGetWindowContentScale(window, &scale_x, &scale_y);
    const float scale = scale_x * 1.5f;
    io.FontGlobalScale = scale;
    ImGuiStyle& style = ImGui::GetStyle();
    style.ScaleAllSizes(scale);

    style.Colors[ImGuiCol_DockingPreview] =
        ImVec4(0.5f,0.5f,0.5f,0.7f);

    style.Colors[ImGuiCol_Header] =
        ImVec4(0.35f,0.35f,0.35f,1);

    style.Colors[ImGuiCol_HeaderHovered] =
        ImVec4(0.45f,0.45f,0.45f,1);

    style.Colors[ImGuiCol_HeaderActive] =
        ImVec4(0.55f,0.55f,0.55f,1);

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();

        ImGui::NewFrame();
        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                ImGui::MenuItem("New");
                ImGui::MenuItem("Open");
                ImGui::MenuItem("Save");
                ImGui::MenuItem("Close");
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }

        ImGui::DockSpaceOverViewport();
        ImGui::Begin("Hello, world!");
        ImGui::Text("ISET Protocol Lab");
        ImGui::End();

        ImGui::Render();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();

            glfwMakeContextCurrent(backup_current_context);
        }

        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);

    glfwTerminate();

    return 0;
}
