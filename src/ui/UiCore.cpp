// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /src/ui/UiCore.cpp
// Ui core for project.

#include <cstdio>
#include <pl/ui/UiCore.hpp>
#include <pl/ui/Fonts.hpp>
#include <pl/ui/Render.hpp>
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include "pl/core/Environment.hpp"

int UiEntry::init()
{
    if (!glfwInit()) return -1;
    window_ = glfwCreateWindow(1920, 1080, "ISET Protocol Lab", nullptr, nullptr);
    float scale_x, scale_y;
    glfwGetWindowContentScale(window_, &scale_x, &scale_y);
    scale_ = scale_x * 1.5f;
    if (!window_)
    {
        glfwTerminate();
        return -1;
    }
    return 0;
}

int UiEntry::runGui(vector<Environment>& data) const
{
    glfwMakeContextCurrent(window_);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    setStyle(io);

    io.FontGlobalScale = scale_;

    ImGui_ImplGlfw_InitForOpenGL(window_, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    while (!glfwWindowShouldClose(window_))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();

        ImGui::NewFrame();
        renderMenu();

        ImGui::DockSpaceOverViewport();
        ImGui::Begin("Project");
        ImGui::PopFont();
        renderEnvironment(data);
        ImGui::End();
        ImGui::PushFont(Font::Title);
        ImGui::Begin("Viewport");
        ImGui::PopFont();
        ImGui::Text("ISET Protocol Lab");
        ImGui::End();
        ImGui::PushFont(Font::Title);
        ImGui::Begin("Properties");
        ImGui::PopFont();
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

void UiEntry::setStyle(ImGuiIO& io) const
{
    ImGuiStyle& style = ImGui::GetStyle();
    style.ScaleAllSizes(scale_);

    Font::UI = io.Fonts->AddFontFromFileTTF(UI_FONT_PATH.data(), 12.0f);
    Font::Title = io.Fonts->AddFontFromFileTTF(TITLE_FONT_PATH.data(), 14.0f);
    Font::Mono = io.Fonts->AddFontFromFileTTF(MONO_FONT_PATH.data(), 12.0f);
    io.FontDefault = Font::UI;

    style.TabBarBorderSize = 0.0f;
    style.TabRounding = 0.0f;
    style.WindowRounding = 0.0f;
    style.DockingSeparatorSize = 1.0f;

    style.Colors[ImGuiCol_MenuBarBg] =
        ImVec4(0.15f,0.15f,0.15f,1);
    style.Colors[ImGuiCol_DockingPreview] =
        ImVec4(0.5f,0.5f,0.5f,0.2f);
    style.Colors[ImGuiCol_WindowBg] =
        ImVec4(0.2f,0.2f,0.2f,1);
    style.Colors[ImGuiCol_Tab] =
        ImVec4(0,0,0,0);
    style.Colors[ImGuiCol_TabHovered] =
        ImVec4(0.1f,0.1f,0.1f,0.2f);
    style.Colors[ImGuiCol_TabActive] =
        ImVec4(0.1f,0.55f,0.52f,1);
    style.Colors[ImGuiCol_TabSelected] =
        ImVec4(1,1,1,0.2f);
    style.Colors[ImGuiCol_TabSelectedOverline] =
        ImVec4(0.1f,0.55f,0.52f,1);
    style.Colors[ImGuiCol_TitleBg] =
        ImVec4(0.3f,0.3f,0.3f,1);
    style.Colors[ImGuiCol_TitleBgActive] =
        ImVec4(0.1f,0.55f,0.52f,1);
    style.Colors[ImGuiCol_TabDimmed] =
        ImVec4(0.3f,0.3f,0.3f,1);
    style.Colors[ImGuiCol_TabDimmedSelected] =
        ImVec4(0.2f,0.2f,0.2f,0.2f);
    style.Colors[ImGuiCol_TabDimmedSelectedOverline] =
        ImVec4(0.2f,0.2f,0.2f,0.2f);
}
