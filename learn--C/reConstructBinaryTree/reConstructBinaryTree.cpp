#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	if (pre.size() == 0) {
		return NULL;
	}

	vector<int> left_pre, right_pre, left_vin, right_vin;

	TreeNode *head = new TreeNode(pre[0]);
	int root = 0;

	for (int i = 0; i < vin.size();i++) {
		if (vin[i] == pre[0]) {
			root = i;
			break;
		}
	}

	for (int i = 0;i < root;i++) {
		left_pre.push_back(pre[i + 1]);
		left_vin.push_back(vin[i]);
	}

	for (int i = root + 1;i < vin.size();i++) {
		right_pre.push_back(pre[i]);
		right_vin.push_back(vin[i]);
	}

	head->left = reConstructBinaryTree(left_pre, left_vin);
	head->right = reConstructBinaryTree(right_pre, right_vin);

	return head;

}

