class Solution {
    int count = 0, ans = 0;

    public int kthSmallest(TreeNode root, int k) {
        inorder(root, k);
        return ans;
    }

    void inorder(TreeNode root, int k) {
        if (root == null) return;

        inorder(root.left, k);

        if (++count == k) {
            ans = root.val;
            return;
        }

        inorder(root.right, k);
    }
}