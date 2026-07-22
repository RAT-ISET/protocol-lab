// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /src/ui/Render.cpp
// Ui render method.

#include <pl/ui/Render.hpp>
#include <pl/ui/Fonts.hpp>
#include <pl/ui/Node.hpp>
#include <pl/ui/dialogs/NewProject.hpp>
#include <pl/api/Actions.hpp>

void renderMenu(vector<IRender*>& renders, optional<string>& session_path)
{
    ImGui::PushFont(Font::Title);
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("New"))
                actions::NewProject(session_path, renders);
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

void renderEnvironment(vector<Environment>& environments)
{
    if (ImGui::TreeNodeEx("Folder", getNodeStyle(NodeType::Folder)))
    {
        ImGui::TreePop();
    }
}

void renderWorkspace(vector<Workspace>& workspaces)
{
    if (ImGui::TreeNodeEx("Folder", getNodeStyle(NodeType::Folder)))
    {
        ImGui::TreePop();
    }
}
