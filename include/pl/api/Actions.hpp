// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/api/Actions.hpp
// Header file of the user actions runner.

#pragma once

#include <utility>
#include <vector>
#include <pl/ui/dialogs/NewProject.hpp>
#include <pl/ui/dialogs/NewProjectHave.hpp>
#include <pl/core/Session.hpp>

namespace actions
{
    inline void NewProject(optional<string>& session_path, vector<IRender*>& renders)
    {
        renders.push_back(new NewProjectDialog(session_path));
    }
    inline void NewProjectOver(optional<string>& session_path, vector<IRender*>& renders, const string& path)
    {
        if (session_path.has_value())
        {
            renders.push_back(new NewProjectHaveDialog(path));
        }
        else
            session_path = path;
    }
}
