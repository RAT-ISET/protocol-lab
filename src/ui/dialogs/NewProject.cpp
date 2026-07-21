// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /src/ui/dialogs/NewProject.cpp
// Dialogs for create project.

#include <pl/ui/dialogs/NewProject.hpp>

NewProjectDialog::NewProjectDialog()= default;

void NewProjectDialog::render()
{
    ImGui::OpenPopup("New Project");
    if (ImGui::BeginPopupModal("New Project", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
    {
        ImGui::InputText("Project Name", &project_name_);
        ImGui::InputText("Project Path", &project_path_);
        ImGui::SameLine();
        if (ImGui::Button("Browse"))
        {
            UniquePath path;
            if (const auto result = PickFolder(path); result == NFD_OKAY)
            {
                project_path_ = path.get();
            }
        } else if (ImGui::Button("Apply"))
        {
            can_close_ = true;
            project_full_path_ = project_path_ + "/" + project_name_;
        } else if (ImGui::SameLine(); ImGui::Button("Cancel"))
            can_close_ = true;
        ImGui::EndPopup();
    }
}

bool NewProjectDialog::canClose()
{
    return can_close_;
}

string NewProjectDialog::getPath()
{
    return std::move(project_full_path_.value());
}
