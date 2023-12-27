#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <map>

struct TreeNode 
{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* createTree(const std::vector<std::string>& values) 
{
    if (values.empty() || values[0] == "null")
    {
        return nullptr;
    }

    TreeNode* root = new TreeNode(stoi(values[0]));
    std::queue<TreeNode*> q;
    q.push(root);

    size_t i = 1;
    while (i < values.size() && !q.empty())
    {
        TreeNode* current = q.front();
        q.pop();

        if (values[i] != "null")
        {
            current->left = new TreeNode(stoi(values[i]));
            q.push(current->left);
        }
        i++;

        if (i < values.size() && values[i] != "null")
        {
            current->right = new TreeNode(stoi(values[i]));
            q.push(current->right);
        }
        i++;
    }
    return root;
}


std::vector<std::vector<int>> vertTraversal(TreeNode* root)
{
    std::vector<std::vector<int>> result;

    if (!root) 
    {
        return result;
    }

    std::map<int, std::vector<int>> columns;
    std::queue<std::pair<TreeNode*, int>> q;

    q.push({ root, 0 });

    while (!q.empty())
    {
        auto [node, col] = q.front();
        q.pop();

        columns[col].push_back(node->value);

        if (node->left)
        {
            q.push({ node->left, col - 1 });
        }

        if (node->right)
        {
            q.push({ node->right, col + 1 });
        }
    }

     for (const auto& col : columns)
     {
        result.push_back(col.second);
     }

    return result;
}

int main() 
{
    std::string input = "[8,4,10,2,6,9,11,1,3,5,7,null,null,null,12]";

    std::vector<std::string> values;
    std::stringstream ss(input.substr(1, input.size() - 2));
    std::string token;

    while (getline(ss, token, ',')) 
    {
        values.push_back(token);
    }

    TreeNode* tree = createTree(values);

    std::vector<std::vector<int>> result = vertTraversal(tree);

    for (const auto& col : result)
    {
        for (int val : col)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}