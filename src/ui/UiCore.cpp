// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /src/ui/UiCore.cpp
// Ui core for project.

#include <cstdio>
#include <pl/ui/UiCore.hpp>
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

int UiEntry::init()
{
    printf("1");
    if (!glfwInit()) return -1;
    window_ = glfwCreateWindow(640, 480, "ISET Protocol Lab", nullptr, nullptr);
    if (!window_)
    {
        glfwTerminate();
        return -1;
    }
    return 0;
}


int UiEntry::runGui() const
{
    glfwMakeContextCurrent(window_);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    float scale_x, scale_y;
    glfwGetWindowContentScale(window_, &scale_x, &scale_y);
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

    ImGui_ImplGlfw_InitForOpenGL(window_, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    while (!glfwWindowShouldClose(window_))
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
        ImGui::Begin("Project");
        ImGui::Text("ISET Protocol Lab");
        ImGui::End();
        ImGui::Begin("Viewport");
        ImGui::Text("ISET Protocol Lab");
        ImGui::End();
        ImGui::Begin("Properties");
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

        glfwSwapBuffers(window_);
    }

    glfwDestroyWindow(window_);

    glfwTerminate();

    return 0;
}
