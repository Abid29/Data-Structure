#include <iostream>
using namespace std;

struct node
{
    int val;
    struct node *l, *r;
};

struct node *newnode(int data)
{
    struct node *nd = (struct node *)malloc(sizeof(struct node));
    nd->val = data;
    nd->l = nd->r = NULL;
    return nd;
}

struct node *insert(node *root, int data)
{
    if (root == NULL)
        return newnode(data);
    else if (root->val > data)
    {
        root->l = insert(root->l, data);
    }
    else
    {
        root->r = insert(root->r, data);
    }
    return root;
}

struct node *mnval(struct node *root)
{
    while (root->l != NULL)
    {
        root = root->l;
    }
    return root;
}

struct node *del(struct node *root, int data)
{
    if (root->val > data)
    {
        root->l = del(root->l, data);
    }
    else if (root->val < data)
    {
        root->r = del(root->r, data);
    }
    else
    {
        if (root->l == NULL)
            return root->r;
        if (root->r == NULL)
            return root->l;
        struct node *tmp = mnval(root->r);
        root->val = tmp->val;
        root->r = del(root->r, tmp->val);
        return root;
    }
}

void inorder(struct node *root)
{
    if (root->l != NULL)
        inorder(root->l);
    cout << root->val << ' ';
    if (root->r != NULL)
        inorder(root->r);
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 77);
    inorder(root);
    cout << endl;
    root = del(root, 4);
    root = insert(root, 5);
    inorder(root);
    cout << endl;
    root = insert(root, 8);
    inorder(root);
}