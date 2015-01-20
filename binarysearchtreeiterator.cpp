/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if (root != NULL)
		{
			build_tree(root);
		}
		it = tree.begin();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (it != tree.end())
		{
			return true;
		}
		return false;
    }

    /** @return the next smallest number */
    int next() {
        if (it != tree.end())
		{
		    int tmp = *it;
		    it++;
			return tmp;
		}
		return 0;
    }
private:
	vector<int> tree;
	vector<int>::iterator it;
	bool build_tree(TreeNode *root)
	{
		if (root == NULL)
		{
			return false;
		}
		build_tree(root->left);
		tree.push_back(root->val);
		build_tree(root->right);
		return true;
	}
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
