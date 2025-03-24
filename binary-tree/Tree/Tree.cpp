#include "Tree.h"
#include <algorithm>
#include <climits>

Tree::Tree() : root(nullptr) {}

Tree::Tree(int root_key) : root(new TreeNode(root_key)) {}

Tree::~Tree() {
    clear(root);
}

void Tree::clear(TreeNode* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}


bool Tree::add_node(int key) {
    if (search(key)) {
        return false;
    }
    root = insert_helper(root, key);
    return true;
}

TreeNode* Tree::insert_helper(TreeNode* node, int key) {
    if (!node) return new TreeNode(key);

    if (key < node->key) {
        node->left = insert_helper(node->left, key);
    } else {
        node->right = insert_helper(node->right, key);
    }
    return node;
}

void Tree::build_from_array(const std::vector<int>& keys) {
    for (int key : keys) add_node(key);
}

void Tree::build_optimal_tree(const std::vector<int>& keys) {
    clear(root);
    root = nullptr;

    std::set<int> unique_keys(keys.begin(), keys.end());
    std::vector<int> sorted_keys(unique_keys.begin(), unique_keys.end());

    root = build_balanced(sorted_keys, 0, sorted_keys.size() - 1);
}

TreeNode* Tree::build_balanced(std::vector<int>& sorted_keys, int start, int end) {
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2;
    TreeNode* node = new TreeNode(sorted_keys[mid]);
    node->left = build_balanced(sorted_keys, start, mid - 1);
    node->right = build_balanced(sorted_keys, mid + 1, end);
    return node;
}

bool Tree::search(int key) {
    return search_helper(root, key) != nullptr;
}

TreeNode* Tree::search_helper(TreeNode* node, int key) {
    if (!node || node->key == key) return node;

    return key < (node->key) ? search_helper(node->left, key) : search_helper(node->right, key);
}

int Tree::get_level(int key) {
    TreeNode* current = root;
    int level = 1;
    while (current) {

        if (current->key == key) return level;

        current = key < (current->key) ? current->left : current->right;
        level++;
    }
    return -1;
}

bool Tree::delete_node(int key) {
    if (!search(key)) return false;

    root = delete_helper(root, key);
    return true;
}

TreeNode* Tree::delete_helper(TreeNode* node, int key) {
    if (!node) return nullptr;

    if (key < node->key) {
        node->left = delete_helper(node->left, key);
    } else if (key > node->key) {
        node->right = delete_helper(node->right, key);
    } else {
        if (!node->left) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }
        TreeNode* temp = min_value_node(node->right);
        node->key = temp->key;
        node->right = delete_helper(node->right, temp->key);
    }
    return node;
}

TreeNode* Tree::min_value_node(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

std::vector<int> Tree::search_range(int low, int high) {
    std::vector<int> result;
    in_order_range(root, low, high, result);
    return result;
}

void Tree::in_order_range(TreeNode* node, int low, int high, std::vector<int>& result) {
    if (!node) return;
    in_order_range(node->left, low, high, result);
    if ((node->key) >= low && (node->key) <= high) {
        result.push_back(node->key);
    }
    in_order_range(node->right, low, high, result);
}

int Tree::max_level() {
    return calculate_max_level(root);
}

int Tree::calculate_max_level(TreeNode* node) {
    if (!node) return 0;
    return 1 + std::max(calculate_max_level(node->left), calculate_max_level(node->right));
}

double Tree::average_level() {
    int sum = 0, count = 0;
    calculate_level_sum(root, 1, sum, count);
    return count ? static_cast<double>(sum) / count : 0.0;
}

void Tree::calculate_level_sum(TreeNode* node, int current_level, int& sum, int& count) {
    if (!node) return;
    sum += current_level;
    count++;
    calculate_level_sum(node->left, current_level + 1, sum, count);
    calculate_level_sum(node->right, current_level + 1, sum, count);
}

std::vector<int> Tree::get_keys() {
    std::vector<int> result;
    in_order(root, result);
    return result;
}


void Tree::in_order(TreeNode* node, std::vector<int>& result) {
    if (!node) return;
    in_order(node->left, result);
    result.push_back(node->key);
    in_order(node->right, result);
}
