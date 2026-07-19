// ==============================================================
// Copyright (c) 2026 Team ISET
// Licensed under the MIT.
// https://github.com/RAT-ISET/protocol-lab
// ==============================================================
// Path /src/ui/Node.cpp
// Tree node.

#include <pl/ui/Node.hpp>
#include <imgui.h>

ImGuiTreeNodeFlags getNodeStyle(const NodeType& node_type)
{
    switch (node_type)
    {
        case NodeType::Folder:
            return ImGuiTreeNodeFlags_OpenOnArrow;
        case NodeType::File:
            return ImGuiTreeNodeFlags_OpenOnArrow;
    }
    return ImGuiTreeNodeFlags_None;
}
