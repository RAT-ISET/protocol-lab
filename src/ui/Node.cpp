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
    case NodeType::Workspace:
        return ImGuiTreeNodeFlags_Bullet;
    case NodeType::Environment:
        return ImGuiTreeNodeFlags_Bullet;
    case NodeType::Folder:
        return ImGuiTreeNodeFlags_OpenOnArrow;
    case NodeType::Signal:
        return ImGuiTreeNodeFlags_OpenOnArrow;
    case NodeType::Working:
        return ImGuiTreeNodeFlags_Framed;
    }
    return ImGuiTreeNodeFlags_None;
}
