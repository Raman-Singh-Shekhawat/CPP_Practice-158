/*176. Code: Construct BST from a Sorted Array: Given a sorted integer array A of size n, which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.
Note: If array size is even, take first mid as root.*/

/**********************************************************

    Following is the Binary Tree Node class structure

    template <typename T>
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

BinaryTreeNode<int> *helper(int *input, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    BinaryTreeNode<int> *leftSubTree = helper(input, start, mid - 1);
    BinaryTreeNode<int> *rightSubTree = helper(input, mid + 1, end);

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);
    root->left = leftSubTree;
    root->right = rightSubTree;

    return root;
}

BinaryTreeNode<int> *constructTree(int *input, int n)
{
    if (n == 0)
    {
        return NULL;
    }
    return helper(input, 0, n - 1);
}