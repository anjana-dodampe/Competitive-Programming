#include <bits/stdc++.h>

using namespace std;

class Node
{
  public:
    char data;
    int column;
    Node *left;
    Node *right;
};

int searchIn(string arr, int strt, int end, char value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
}

int preIndex = 0;
Node *buildTree(string in, string pre, int inStrt, int inEnd)
{

    if (inStrt > inEnd || pre[preIndex] == 0)
        return NULL;

    /* Pick current Node from Preorder traversal using preIndex 
	and increment preIndex */
    Node *tNode = new Node();
    tNode->data = pre[preIndex++];

    /* If this Node has no children then return */
    if (inStrt == inEnd)
        return tNode;

    /* Else find the index of this Node in Inorder traversal */
    int inIndex = searchIn(in, inStrt, inEnd, tNode->data);

    /* Using index in Inorder traversal, construct left and 
	right subtress */
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

    return tNode;
}

Node *findLeftMostNode(Node *root)
{
    for (; root; root = root->left)
        if (root->left == NULL)
            break;
    return root;
}

Node *findRightMostNode(Node *root)
{
    for (; root; root = root->right)
        if (root->right == NULL)
            break;
    return root;
}

/* This funtcion is here just to test buildTree() */
void findColumns(Node *node)
{
    if (node == NULL)
        return;

    findColumns(node->left);
    if (node->left != NULL)
    {
        Node *left = findRightMostNode(node->left);
        node->column = left->column + 1;
        // cout << "Left not null: " << left->column << endl;
    }
    if (node->right != NULL)
    {
        Node *right = findLeftMostNode(node->right);
        if (right != NULL)
        {
            right->column = node->column + 1;
            // cout << "Right not null: " << right->column << endl;
        }
    }
    // cout << node->data << " " << node->column << " ";

    findColumns(node->right);
}

void printInorder(Node *node)
{
    if (node == NULL)
        return;

    printInorder(node->left);

    // cout << "!" << node->data << "!" << node->column << " ";

    printInorder(node->right);
}

int height(Node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

bool isFirst = true;
int column = 0;
/* Print nodes at a given level */
void printGivenLevel(Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        int space = 0;
        if (isFirst)
        {
            column = root->column;
            space = column;
            isFirst = false;
        }
        else
        {
            space = root->column - column - 1;
            column = root->column;
        }
        // cout << root->column << " " << column << endl;
        cout << string(max(space, 0), ' ') << root->data;
        // printf("%c ", root->data);
    }
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void printLevelOrder(Node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
    {
        isFirst = true;
        column = 0;
        printGivenLevel(root, i);
        cout << endl;
    }
}

/* Driver program to test above functions */
int main()
{
    string in, pre;

    vector<pair<string, string>> tasks;
    while (cin.good())
    {
        cin >> in >> pre;
        tasks.push_back({in, pre});
    }
    // cout << in << "|" << endl;
    // cout << pre << "|" << endl;

    // char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    // char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    // int len = sizeof(in) / sizeof(in[0]);

    for (auto t : tasks)
    {
        preIndex = 0;
        Node *root = buildTree(t.first, t.second, 0, t.second.size());

        findColumns(root);

        printLevelOrder(root);
        root = NULL;
    }
}