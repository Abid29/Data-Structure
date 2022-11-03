#include<iostream>
using namespace std;

//tree node including left and right child's pointer and data
struct node{
    node(int value) : val(value), l(NULL), r(NULL){}
    int val;
    node *l,*r;
};

//class BST
class BST{
    private:
    node *root;
    void insert(node *treenode,int data);
    bool isbalanced(node *treenode);
    int getheight(node *treenode);
    void deleteBST(node *treenode);
    void inorder(node *treenode);
    void preorder(node *treenode);
    void postorder(node *treenode);

    public:
    //constructor
    BST(){
        root = NULL;
    }
    //destructor
    ~BST(){
        deleteBST(root);
    }
    void insert(int data){    insert(root,data);}
    bool isbalanced(){    return isbalanced(root);}
    int getheight(){    return getheight(root);};
    void deleteBST(){    deleteBST(root);}
    void inorder() {    inorder(root);}
    void preorder(){    preorder(root);}
    void postorder(){   postorder(root);}
    node *getmaxnode();
    node *getminnode();
};

void BST :: insert(node *treenode, int data){
    if(!treenode){
        treenode=new node(data);
        root = treenode; return;
    }
    if(treenode->val>data){
        if(!treenode->l){
            treenode->l = new node(data);
        }
        else{
            insert(treenode->l,data);
        }
    }
    else{
        if(!treenode->r){
            treenode->r = new node(data);
        }
        else{
            insert(treenode->r,data);
        }
    }
}

int BST :: getheight(node *treenode){
    if(!treenode) return 0;
    int lf = 0, rt = 0;
    lf = getheight(treenode->l),rt = getheight(treenode->r);
    if(lf>rt) return 1+lf;
    else      return 1+rt;
}

bool BST :: isbalanced(node *treenode){
    if(!treenode) return true;
    bool ans=1;
    ans&=abs(getheight(treenode->l)-getheight(treenode->r))<2;
    ans&=isbalanced(treenode->l);
    ans&=isbalanced(treenode->r);
    return ans;
}

node *BST :: getmaxnode(){
    if(!root) return NULL;
    node *treenode = root;
    while(treenode->r) treenode = treenode->r;
    return treenode;
}

node *BST :: getminnode(){
    if(!root) return NULL;
    node *treenode = root;
    while(treenode->l) treenode = treenode->l;
    return treenode;
}

void BST :: deleteBST(node *treenode){
    if(!treenode) return;
    deleteBST(treenode->l),deleteBST(treenode->r);
    delete(treenode);
}

void BST :: inorder(node *treenode){
    if(!treenode) return;
    inorder(treenode->l);
    cout<<treenode->val<<"  ";
    inorder(treenode->r);
}

void BST :: preorder(node *treenode){
    if(!treenode) return;
    cout<<treenode->val<<"  ";
    preorder(treenode->l);
    preorder(treenode->r);
}

void BST :: postorder(node *treenode){
    if(!treenode) return;
    postorder(treenode->l);
    postorder(treenode->r);
    cout<<treenode->val<<"  ";
}

int main(){
    BST myBST;
    myBST.insert(5);
    myBST.insert(10);
    myBST.insert(3);

    myBST.insert(51);
    myBST.insert(110);
    myBST.insert(13);
    
    int h = myBST.getheight();
    cout << "the height of this BSt is : " << h << endl;
    node * mx = myBST.getmaxnode();
    cout << "max value: " << mx->val << endl;

    node * mi = myBST.getminnode();
    cout << "min value: " << mi->val << endl;
    bool isbal = myBST.isbalanced();
    if (isbal)
            cout << "BST is balanced! " << endl;
    else
            cout << "BST is not balanced! " << endl;

    cout << " in-order traverse is : " << endl;
    myBST.inorder();cout << endl;
    cout << " pre-order traverse is : " << endl;
    myBST.preorder();cout << endl;
    cout << " post-order traverse is : " << endl;
    myBST.postorder();cout << endl;
}