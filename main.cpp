class SolutionEight{
public:
	vector<int> result;
	int prev=0;
	int counter=0;
	int maxi=0;
	void inorder(TreeNode* root){
		if(!root) return;
		inorder(root->left);
		if(prev==root->val) counter++;
		else counter=1;
		if(counter==maxi) result.push_back(root->val);
		else if(counter>maxi){
			maxi=max(maxi,counter);
			result={root->val};
		}
		prev=root->val;
		inorder(root->right);
	}
	vector<int> findMode(TreeNode* root){
		inorder(root);
		return result;
	}
};