// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /include/pl/ui/Node.hpp
// Header file of the tree node.

#pragma once

#include <string>
#include <imgui.h>

using namespace std;

enum class NodeType
{
    Folder,
    File,
};

ImGuiTreeNodeFlags getNodeStyle(const NodeType& node_type);
