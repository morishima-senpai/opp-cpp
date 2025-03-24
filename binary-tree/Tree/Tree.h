#include <vector>
#include <set>

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

class Tree {
private:
    TreeNode* root;

    TreeNode* insert_helper(TreeNode* node, int key);
    TreeNode* search_helper(TreeNode* node, int key);
    TreeNode* delete_helper(TreeNode* node, int key);
    TreeNode* min_value_node(TreeNode* node);
    void in_order(TreeNode* node, std::vector<int>& result);
    void in_order_range(TreeNode* node, int low, int high, std::vector<int>& result);
    int calculate_max_level(TreeNode* node);
    void calculate_level_sum(TreeNode* node, int current_level, int& sum, int& count);
    void clear(TreeNode* node);
    TreeNode* build_balanced(std::vector<int>& sorted_keys, int start, int end);

public:
    Tree();
    explicit Tree(int root_key);
    ~Tree();

    bool add_node(int key);
    void build_from_array(const std::vector<int>& keys);
    void build_optimal_tree(const std::vector<int>& keys);
    bool search(int key);
    int get_level(int key);
    bool delete_node(int key);
    std::vector<int> search_range(int low, int high);
    int max_level();
    double average_level();
    std::vector<int> get_keys();
};