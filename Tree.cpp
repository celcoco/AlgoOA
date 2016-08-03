//
// Created by Allen Chen on 8/3/16.
//

#include "Tree.h"
using namespace std;
int TreeLen(TreeNode* node){
    if(node == NULL){
        return 0;
    }else{
        int LeftLen = TreeLen(node->left);
        int RigtLen = TreeLen(node->right);

        if(LeftLen > RigtLen){
            return LeftLen+1;
        }else{
            return RigtLen+1;
        }
    }
}
int TreeLenMini(TreeNode* node){
    if(node == NULL){
        return 0;
    }else{
        int LeftLen = TreeLenMini(node->left);
        int RigtLen = TreeLenMini(node->right);

        if(LeftLen > RigtLen){
            return RigtLen+1;
        }else{
            return LeftLen+1;
        }
    }
}
void TreeInsert(TreeNode*& node,int data){
    if(node == NULL){
        TreeNode* tmp = new TreeNode(data);
        node = tmp;
        return;
    }else{
        int LeftLen = TreeLenMini(node->left);
        int RigtLen = TreeLenMini(node->right);
        if(LeftLen > RigtLen+1 || LeftLen < RigtLen){
            cout<<"ERROR: LeftLen="<<LeftLen<<",RigtLen="<<RigtLen<<endl;
            return;
        }else{
            if(LeftLen == RigtLen){
                TreeInsert(node->left,data);
                /*
                if(node->right != NULL && node->left->right != NULL) {
                    node->right->left = node->left->right;
                }*/
            }else{
                TreeInsert(node->right,data);
                node->left->ParalRigt = node->right;
                if(node->ParalRigt != NULL){
                    node->ParalRigt->left = node->right;
                }
            }
        };
        return;
    }
}
void TreeDele(TreeNode*& node){
    if(node == NULL){
        return;
    }else{
        TreeDele(node->left);
        TreeDele(node->right);
        delete(node);
        if(node->left!=NULL){
            node->left = NULL;
        }
        if(node->right!=NULL){
            node->right = NULL;
        }
        if(node->ParalRigt!=NULL)
        {
            node->ParalRigt->left = NULL;
            node->ParalRigt = NULL;
        }
        node = NULL;
    }
}
void RecPrint(TreeNode* node){
    cout<<node->val<<"   ";
    if(node->ParalRigt != NULL){
        RecPrint(node->ParalRigt);
    }
}
void RecPrint2(TreeNode* node){
    if(node->left != NULL){
        cout<<"/ ";
    }else{
        cout<<"  ";
    }
    if(node->right != NULL){
        cout<<"\\ ";
    }else{
        cout<<"  ";
    }
    if(node->ParalRigt != NULL){
        RecPrint2(node->ParalRigt);
    }
}
void TreePrint(TreeNode* node){
    if(node != NULL){
        int MaxLen = TreeLen(node);
        int i = 0;
        while(i<2*(MaxLen-1)){
            cout<<" ";
            i++;
        }
        RecPrint(node);
        cout<<endl;
        i=0;
        while(i<2*(MaxLen-1)-1){
            cout<<" ";
            i++;
        }
        RecPrint2(node);
        cout<<endl;
        TreePrint(node->left);
    }
}

int TreeMiniDist(TreeNode* node){
    if(node == NULL){
        return 0;
    }else{
        int LeftDist = TreeMiniDist(node->left);
        int RigtDist = TreeMiniDist(node->right);
        int MiniDist = LeftDist;
        if(RigtDist < MiniDist){
            MiniDist = RigtDist;
        }
        return MiniDist+node->val;
    }
}