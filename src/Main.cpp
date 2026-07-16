// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /src/Main.cpp
// Main of ProtocolLab.

#include <pl/ui/UiCore.hpp>
#include <pl/core/Session.hpp>

int main(const int argc, char* argv[])
{
    auto ui = UiEntry();
    auto session = Session(&ui);
    session.run();
}
