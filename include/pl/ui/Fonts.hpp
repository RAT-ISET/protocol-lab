// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/ui/Fonts.hpp
// Include and define the font.

#pragma once
#include <imgui.h>
#include <string_view>

using namespace std;

constexpr string_view UI_FONT_PATH = "assets/fonts/SourceSerif4-Regular.ttf";
constexpr string_view TITLE_FONT_PATH = "assets/fonts/IBMPlexSans-Light.ttf";
constexpr string_view MONO_FONT_PATH = "assets/fonts/IntelOneMono-Regular.ttf";

namespace Font
{
    inline ImFont* UI{};
    inline ImFont* Title{};
    inline ImFont* Mono{};
}
