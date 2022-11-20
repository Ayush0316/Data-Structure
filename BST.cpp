// Name : Ayush Kansal
// Sid: 21105049
// Branch: ECE





#include<iostream>
using namespace std;

template <typename t>
class Binary_tree_node{
    public:
        t data;
        Binary_tree_node<t>* left;
        Binary_tree_node<t>* right;

        Binary_tree_node(t data){
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~Binary_tree_node(){
            delete(left);
            delete(right);
        }
};

class BST{
    Binary_tree_node<int>* root;

    Binary_tree_node<int>* insert_helper(int data, Binary_tree_node<int>* node){
        if (node == NULL){
            Binary_tree_node<int>* tmp = new Binary_tree_node<int>(data);
            return tmp;
        }

        if (node->data > data){
            node->left = insert_helper(data, node->left);
        }
        else{
            node->right = insert_helper(data, node->right);
        }
        return node;
    }

    int minimum(Binary_tree_node<int>* nood){
        if (nood == NULL){
            return -1;
        }

        while(nood->left != NULL){
            nood = nood->left;
        }

        return nood->data;
    }

    Binary_tree_node<int>* deletedata_helper(int data, Binary_tree_node<int>* node){
        if (node == NULL){
            return NULL;
        }

        if (node->data == data){
            if ((node->left == NULL)&&(node->right == NULL)){
                delete node;
                return NULL;
            }
            else if ((node->left == NULL)&& (node->right != NULL)){
                Binary_tree_node<int>* tmp = node->right;
                node->right = NULL;
                delete node;
                return tmp;
            }
            else if ((node->left != NULL)&& (node->right == NULL)){
                Binary_tree_node<int>* tmp = node->left;
                node->left = NULL;
                delete node;
                return tmp;
            }
            else{
                int min = minimum(node->right);
                node->data = min;
                node->right = deletedata_helper(min,node->right);
                return node;
            }
        }
        else if (node->data > data){
            node->left = deletedata_helper(data, node->left);
        }
        else{
            node->right = deletedata_helper(data, node->right);
        }
        return node;
    }

    public:
        BST(){
            root = NULL;
        }

        ~BST(){
            delete root;
        }

        void insert(int* data, int size){
            for(int i = 0; i < size; i++){
                this->root = insert_helper(data[i], root);
            }
        }

        void deletedata(int data){
            this->root = deletedata_helper(data, root);
        }

    private:
        void print_helper(Binary_tree_node<int>* nood){
            if(nood == NULL){
                return;
            }

            cout << nood->data << ":";
            if (nood->left){
                cout << " L" << nood->left->data;
            }
            if (nood->right){
                cout << " R" << nood->right->data;
            }
            cout << endl;

            print_helper(nood->left);
            print_helper(nood->right);
        }
    
    public:
        void print(){
            print_helper(root);
        }
};

void print_Arr(int* arr, int size){
    for(int i = 0; i< size; i++){
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}

void delete_data_from_arr(int data, int* arr, int size){
    int i = 0;
    for(; i<size; i++){
        if (arr[i] == data){
            break;
        }
    }
    for(; i<size; i++){
        arr[i] = arr[i+1];
    }
    return;
}

int main(){
    int input_arr[] = {12,43,1,4,2,18,76,23,11};
    cout << "Initial array taken to create BST"<< endl;
    print_Arr(input_arr,9);
    
    BST asg;
    asg.insert(input_arr,9);
    
    cout << "BST created from the array taken." << endl;
    cout << "Output format:" << endl;
    cout << "node_Data: L(data_at_left_node) R(data_at_right_node)" << endl;
    asg.print();
    cout << endl;

    delete_data_from_arr(76,input_arr,9);
    cout << "Arr after deleting 76 from it." << endl;
    print_Arr(input_arr,8);

    asg.deletedata(76);
    cout << "BST after deleting 76 from it." << endl;
    asg.print();
    cout << endl;

    cout << "Time complexity analysis:" << endl << endl;
    cout << "To delete data from the arr we have to traverse the whole arr once. Therefore the time complexity is O(n)" << endl << endl;
    cout << "To delete data from the BST we have to traverse as much as the height of the BST therefore time complexity is O(h). In ideal case the height of the BST is considered to be log(n) so time complexity can be O(logn)" << endl << endl;
    return 0;
}


// *********Ans 4***********//
// Time complexity analysis:
// To delete data from the arr we have to traverse the whole arr once. Therefore the time complexity is O(n)
// To delete data from the BST we have to traverse as much as the height of the BST therefore time complexity is O(h). In ideal case the height of the BST is considered to be log(n) so time complexity can be O(logn)