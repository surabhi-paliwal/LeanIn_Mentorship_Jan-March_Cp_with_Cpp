class Solution {
public:
    int maxDepth(Node* root) {
        if(root==NULL) return 0;
        
        int childDepth = 0;
        for(Node* child : root->children){
            childDepth = max(childDepth, maxDepth(child));
        }
        return 1+childDepth;
    }
};
