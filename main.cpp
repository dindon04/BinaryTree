#include "BinaryTree.cpp"
#include <gtest/gtest.h>
#include <fstream>

TEST(BinaryTreeTest, ValidInput) {
    std::vector<std::string> values1 = { "3", "9", "8", "4", "0", "1", "7" };
    Node* tree1 = Tree(values1);

    ASSERT_TRUE(tree1);

    delete tree1;
}

TEST(BinaryTreeTest, InvalidInput) 
{
    std::vector<std::string> invalidValues = { "200", "-150", "105", "invalid", "null" };
    Node* invalidTree = Tree(invalidValues);

    ASSERT_EQ(nullptr, invalidTree);

    ASSERT_EQ(nullptr, invalidTree->left);
    ASSERT_EQ(nullptr, invalidTree->right);

    delete invalidTree;
}



TEST(BinaryTreeTest, VerticalTraversal) 
{
    std::vector<std::string> values = { "3", "9", "8", "4", "0", "1", "7" };
    Node* tree = Tree(values);

    ASSERT_TRUE(tree);

    std::vector<std::vector<int>> expected = { {4}, {9}, {3, 0, 1}, {8}, {7} };

    std::vector<std::vector<int>> result = vertTraversal(tree);

    ASSERT_EQ(expected, result);

    delete tree;
}

TEST(BinaryTreeTest, VerticalTraversal3) 
{
    std::vector<std::string> values3 = { "3", "9", "8", "4", "0", "1", "7", "null", "null", "null", "2", "5"};
    Node* tree3 = Tree(values3);

    ASSERT_TRUE(tree3);

    std::vector<std::vector<int>> expected3 = { {4}, {9,5}, {3, 0, 1}, {8,2}, {7} };

    std::vector<std::vector<int>> result3 = vertTraversal(tree3);

    ASSERT_EQ(expected3, result3);

    delete tree3;
}


int main(int argc, char** argv)
{
    const char* in = "input.txt";
    const char* out = "output.txt";

    std::ifstream inputFile(in);
    if (!inputFile.is_open()) {
		std::cerr << "Unable to open input file: " << in << std::endl;
        return 1;
    }

    std::string inputLine;
    std::getline(inputFile, inputLine);

    std::vector<std::string> values;
    std::stringstream s(inputLine);
    std::string token;
    while (getline(s, token, ',')) {
        values.push_back(token);
    }

    Node* tree = Tree(values);
    inputFile.close();
    std::vector<std::vector<int>> result = vertTraversal(tree);

    std::ofstream outputFile(out);
    if (!outputFile.is_open()) {
        return 1;
    }

    for (const auto& col : result) {
        for (int val : col) {
            outputFile << val << " ";
        }
        outputFile << "\n";
    }

    outputFile.close();

   
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
