// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/ui/dialogs/NewProjectHave.hpp
// Header file of the project create dialog when have old project.

#pragma once

#include <nfd.hpp>
#include <vector>
#include <pl/ui/inter/IRender.hpp>

using namespace NFD;
using namespace std;

class NewProjectHaveDialog : public IRender
{
    bool can_close_ = false;
    bool status_{};
    string new_path_;
public:
    explicit NewProjectHaveDialog(string new_path);
    void render() override;
    bool canClose() override;
    [[nodiscard]] bool getStatus() const;
    void close(vector<IRender*>& renders) override;
};
