// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/ui/dialogs/NewProject.hpp
// Header file of the project create dialog.

#pragma once

#include <optional>
#include <nfd.hpp>
#include <imgui.h>
#include <misc/cpp/imgui_stdlib.h>
#include <pl/ui/inter/IRender.hpp>

using namespace NFD;
using namespace std;

class NewProjectDialog : public IRender
{
    bool can_close_ = false;
    string project_name_;
    string project_path_;
    optional<string> project_full_path_;
public:
    NewProjectDialog();
    void render() override;
    bool canClose() override;
    string getPath();
};
