#include <iostream>
#include <string>
#include "Tree/Tree.h"
#include "styles/styles.h"

int main() {
    Tree tree1;
    std::cout << std::endl;
    Style::printHint("Adding nodes to tree1: ");
    std::cout << "   5, 3, 7, 2, 4, 6, 8" << std::endl;
    tree1.add_node(5);
    tree1.add_node(3);
    tree1.add_node(7);
    tree1.add_node(2);
    tree1.add_node(4);
    tree1.add_node(6);
    tree1.add_node(8);

    std::cout << std::endl;
    Style::printSuccess("Keys in tree1 (in order): ");
    std::cout << "   ";
    for (int key : tree1.get_keys()) {
        std::cout << key << " ";
    }

    Style::printResult("\nSearch for 4: " + std::string((tree1.search(4) ? "Found" : "Not found")));
    Style::printResult("\nLevel of 4: " + std::to_string(tree1.get_level(4)));
    Style::printResult("\nMax Level: " + std::to_string(tree1.max_level()));
    Style::printResult("\nAverage Level: " + std::to_string(static_cast<int>(tree1.average_level())) + "\n");

    std::cout << std::endl;
    Style::printHint("Deleting node 3..");

    tree1.delete_node(3);

    Style::printSuccess("Keys after deletion: ");
    std::cout << "   ";
    for (int key : tree1.get_keys()) {
        std::cout << key << " ";
    }

    Style::printResult("\nRange search [4,7]: ");
    for (int key : tree1.search_range(4, 7)) {
        std::cout << key << " ";
    }

    std::cout << std::endl;
    Style::printSeparator("fancy");
    std::cout << std::endl;
    std::vector<int> arr = {10, 5, 15, 3, 7, 12, 20};

    Tree tree2;
    tree2.build_from_array(arr);
    std::cout << std::endl;
    Style::printHint("Tree2 keys: ");
    std::cout << "   ";
    for (int key : tree2.get_keys()) {
        std::cout << key << " ";
    }

    std::cout<< std::endl;

    Tree tree3;
    tree3.build_optimal_tree(arr);
    Style::printSuccess("Tree3 (optimal) keys: ");
    std::cout << "   ";
    for (int key : tree3.get_keys()) {
        std::cout << key << " ";
    }
    std::cout << std::endl;
    Style::printSeparator("double");
    std::cout << std::endl;

    Style::printHint("Comparison");
    Style::printResult(
        "Tree2 max level: " +
        std::to_string(tree2.max_level()) +
        ", average: " +
        std::to_string(static_cast<int>(tree2.average_level()))
    );
    std::cout << std::endl;
    Style::printResult(
        "Tree3 max level: " +
        std::to_string(tree3.max_level()) +
        ", average: " +
        std::to_string(static_cast<int>(tree3.average_level()))
    );
    std::cout << std::endl << std::endl;
    return 0;
}
