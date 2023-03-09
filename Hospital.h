#pragma once
#include<iostream> 
#include<string>
#include<iomanip>
#include"TNode.h"
using namespace std;

class Hospital
{
public:
    int size;
    TNode* root;
    Hospital()
    {
        //default constructor 
    }
    Hospital(const Hospital& h)
    {
        this->root = h.root;
        this->size = h.size;
    }

    // RR(Y rotates to the right)
    TNode* RR_Rotate(TNode* k2)
    {
        TNode* k1 = k2->lchild;
        k2->lchild = k1->rchild;
        k1->rchild = k2;
        return k1;
    }

    // LL(Y rotates to the left)
    TNode* LL_Rotate(TNode* k2)
    {
        TNode* k1 = k2->rchild;
        k2->rchild = k1->lchild;
        k1->lchild = k2;
        return k1;
    }

    TNode* Splay(int key, TNode* root)
    {
        // If root is null or it's present return as it is  
        if (root == NULL || root->key == key)
            return root;


        if (root->key > key) //key is present in left subtree 
        {

            if (root->lchild == NULL) return root; //key is not present 


            if (root->lchild->key > key)  //left - left (Zig-Zig)
            {

                root->lchild->lchild = Splay(key, root->lchild->lchild);

                // Do first rotation for root,  
                // second rotation is done after else  
                root = RR_Rotate(root);
            }
            else if (root->lchild->key < key) // Zig-Zag (Left Right)  
            {
                // First recursively bring  
                // the key as root of left-right  
                root->lchild->rchild = Splay(key, root->lchild->rchild);

                // Do first rotation for root->left  
                if (root->lchild->rchild != NULL)
                    root->lchild = LL_Rotate(root->lchild);
            }

            // Do second rotation for root  
            return (root->lchild == NULL) ? root : RR_Rotate(root);
        }
        else // Key lies in right subtree  
        {
            // Key is not in tree, we are done  
            if (root->rchild == NULL) return root;

            // Zig-Zag (Right Left)  
            if (root->rchild->key > key)
            {
                // Bring the key as root of right-left  
                root->rchild->lchild = Splay(key, root->rchild->lchild);

                // Do first rotation for root->right  
                if (root->rchild->lchild != NULL)
                    root->rchild = RR_Rotate(root->rchild);
            }
            else if (root->rchild->key < key)// Zag-Zag (Right Right)  
            {
                // Bring the key as root of  
                // right-right and do first rotation  
                root->rchild->rchild = Splay(key, root->rchild->rchild);
                root = LL_Rotate(root);
            }

            // Do second rotation for root  
            return (root->rchild == NULL) ? root : LL_Rotate(root);
        }
    }

    TNode* New_Node(int key, patientRecord h)
    {
        TNode* p_node = new TNode;
        if (!p_node)
        {
            fprintf(stderr, "Out of memory!\n");
            exit(1);
        }
        p_node->key = key;
        p_node->val.pname = h.pname;
        p_node->val.pID = h.pID;
        p_node->val.pDate = h.pDate;
        p_node->val.pDiagnosis = h.pDiagnosis;
        p_node->val.pStatus = h.pStatus;
        p_node->lchild = p_node->rchild = NULL;
        return p_node;
    }

    TNode* Insert(int key, patientRecord h, TNode* root)
    {
        static TNode* p_node = NULL;
        if (!p_node)
            p_node = New_Node(key, h);
        else
            p_node->key = key;
        if (!root)
        {
            root = p_node;
            p_node = NULL;
            return root;
        }
        root = Splay(key, root);
        /* This is BST that, all keys <= root->key is in root->lchild, all keys >
        root->key is in root->rchild. */
        if (key < root->key)
        {
            p_node->lchild = root->lchild;
            p_node->rchild = root;
            root->lchild = NULL;
            root = p_node;
        }
        else if (key > root->key)
        {
            p_node->rchild = root->rchild;
            p_node->lchild = root;
            root->rchild = NULL;
            root = p_node;
        }
        else
            return root;
        p_node = NULL;
        return root;
        size++;
    }

    TNode* Delete(int key, TNode* root)
    {
        TNode* temp;
        if (!root)
            return NULL;
        root = Splay(key, root);
        if (key != root->key) {
            cout << "\n" << key << " is not present in the tree";
            return root;
        }
        else
        {
            if (!root->lchild)
            {
                temp = root;
                root = root->rchild;
            }
            else
            {
                temp = root;
                /*Note: Since key == root->key,
                so after Splay(key, root->lchild),
                the tree we get will have no right child tree.*/
                root = Splay(key, root->lchild);
                root->rchild = temp->rchild;
            }
            free(temp);
            return root;
            size--;
        }
    }

    TNode* Search(int key, TNode* root)
    {
        return Splay(key, root);
    }

    void InOrder(TNode* root)
    {
        if (root)
        {
            InOrder(root->lchild);
            cout << "key: " << root->key;
            if (root->lchild)
                cout << " | left child: " << root->lchild->key << "\n";
            if (root->rchild)
                cout << " | right child: " << root->rchild->key << "\n";
            cout << "\n";
            InOrder(root->rchild);
        }
    }
    void PreOrder(TNode* root) {
        if (root) {
            cout << setw(15) << root->key << setw(15) << root->val.pname << setw(15) << root->val.pDate << setw(15) << root->val.pDiagnosis << setw(15) << root->val.pStatus << "\n";
            cout << "\n";
            PreOrder(root->lchild);
            PreOrder(root->rchild);
        }
    }
    void Output(TNode* root)
    {
        //output a specific patient
        cout << "\nName:";
        cout << root->val.pname;
        cout << "\nDate: ";
        cout << root->val.pDate;
        cout << "\nDiagnosis:";
        cout << root->val.pDiagnosis;
        cout << "\nStatus:";
        cout << root->val.pStatus;
    }
    void Edit(int id,TNode*root)
    {
        //edit the patients details
        root = Search(id, root);
        
        string s = "";
      
            cout << "Enter New name: ";
            cin >> s;
            root->val.pname = s;
            cout << "Enter New Date: ";
            cin >> s;
            root->val.pDate = s;
       
            cout << "Enter New Disease: ";
            cin >> s;
            root->val.pDiagnosis = s;
        
            cout << "Enter New Status: ";
            cin >> s;
            root->val.pStatus = s;
    }


    int Median()
    {
        int med;
        if (size % 2 == 0)
        {
            med = size / 2;

        }
        else
            med = (size / 2) + 1;
        return med;
    }
    void Child(TNode* node, bool left, TNode* child)
    {
        if (left)
        {
            node->lchild = child;
        }
        else
            node->rchild = child;
    }
    TNode* splitTree(TNode* root, int k)
    {
        TNode* temp = root;
        TNode* parent = nullptr;
        TNode* parent2 = nullptr;
        bool left = root != nullptr && k < this->root->val.pID;
        while (root != nullptr)
        {
            while (root != nullptr && k < this->root->val.pID)
            {
                parent = root;
                root = left ? root->lchild : root->rchild;
            }
            Child(parent, left, nullptr);
            left != left;
            if (temp == NULL)
            {
                root = temp;

            }
            else if (parent2 == nullptr)
            {
                Child(parent, left, root);
            }
            parent2 = parent;
            parent = nullptr;
        }
        return temp;
    }
    Hospital split()
    {
        int median = Median();
        Hospital temp;
        temp.root = splitTree(root, median);
        root = root->rchild;
        temp.size = size - median;
        size = median;
        return temp; 
    }
};

   
        
       