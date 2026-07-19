// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /src/core/Session.cpp
// Software session.

#include <pl/core/Session.hpp>

Session::Session(UiEntry* ui)
    : ui_(ui)
    , have_ui_(true) {}

Session::Session()
    : ui_(nullptr)
    , have_ui_(false) {}

int Session::run()
{
    if (have_ui_)
    {
        if (const int out = ui_->init(); out != 0) return out;
        return ui_->runGui(workspaces_);
    }
    // TODO(server): run only server
    return 0;
}
