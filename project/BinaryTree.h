#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <queue>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val);
};

Node* Tree(const std::vector<std::string>& values);
std::vector<std::vector<int>> vertTraversal(Node* root);