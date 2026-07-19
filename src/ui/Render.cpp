// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /src/ui/Render.cpp
// Ui render method.

#include <pl/ui/Render.hpp>
#include <pl/ui/UiCore.hpp>
#include <pl/ui/Fonts.hpp>

void renderMenu()
{
    ImGui::PushFont(Font::Title);
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
        if (ImGui::BeginMenu("Edit"))
        {
            ImGui::MenuItem("Undo");
            ImGui::MenuItem("Redo");
            ImGui::MenuItem("Find");
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

void renderWorkspace(vector<Workspace>& workspaces)
{
    return;
}
