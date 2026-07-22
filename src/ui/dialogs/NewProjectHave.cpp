// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /src/ui/dialogs/NewProjectHave.cpp
// Dialogs for create project when have old project.

#include <pl/ui/dialogs/NewProjectHave.hpp>
#include <utility>
#include <imgui.h>

NewProjectHaveDialog::NewProjectHaveDialog(string new_path) : new_path_(std::move(new_path)) {}

void NewProjectHaveDialog::render()
{
    ImGui::OpenPopup("New Project Location");
    if (ImGui::BeginPopupModal("New Project Location", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
    {
        if (ImGui::Button("This Window"))
        {
            status_ = true;
            can_close_ = true;
        }
        else if (ImGui::SameLine(); ImGui::Button("New Window"))
        {
            status_ = false;
            can_close_ = true;
        }
        ImGui::EndPopup();
    }
}

bool NewProjectHaveDialog::canClose()
{
    return can_close_;
}

bool NewProjectHaveDialog::getStatus() const
{
    return status_;
}

void NewProjectHaveDialog::close(vector<IRender*>& renders) {}
