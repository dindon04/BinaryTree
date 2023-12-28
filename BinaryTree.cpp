#include "BinaryTree.h"


Node::Node(int val) : value(val), left(nullptr), right(nullptr) {}

Node* Tree(const std::vector<std::string>& values) {
    if (values.empty() || values[0] == "null") {
        return nullptr;
    }

    int rootValue = std::stoi(values[0]);

    if (rootValue < -100 || rootValue > 100) {
        std::cout << "Invalid root value: " << rootValue << std::endl;
        return nullptr;
    }

    Node* root = new Node(rootValue);
    std::queue<Node*> q;
    q.push(root);

    size_t i = 1;
    while (i < values.size() && !q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (values[i] != "null") {
            int leftValue = std::stoi(values[i]);
            if (leftValue >= -100 && leftValue <= 100) {
                curr->left = new Node(leftValue);
                q.push(curr->left);
            }
            else {
                std::cout << "Invalid left child value: " << leftValue << std::endl;
                delete root; 
                return nullptr;
            }
        }
        i++;

        if (i < values.size() && values[i] != "null") {
            int rightValue = std::stoi(values[i]);
            if (rightValue >= -100 && rightValue <= 100) {
                curr->right = new Node(rightValue);
                q.push(curr->right);
            }
            else {
                std::cout << "Invalid right child value: " << rightValue << std::endl;
                delete root;  
                return nullptr;
            }
        }
        i++;
    }

    return root;
}


std::vector<std::vector<int>> vertTraversal(Node* root) {
    std::vector<std::vector<int>> result;

    if (!root) {
        return result;
    }

    std::map<int, std::vector<int>> columns;
    std::queue<std::pair<Node*, int>> q;

    q.push({ root, 0 });

    while (!q.empty()) {
        auto [node, col] = q.front();
        q.pop();

        columns[col].push_back(node->value);

        if (node->left) {
            q.push({ node->left, col - 1 });
        }

        if (node->right) {
            q.push({ node->right, col + 1 });
        }
    }

    for (const auto& col : columns) {
        result.push_back(col.second);
    }
    return result;
}
