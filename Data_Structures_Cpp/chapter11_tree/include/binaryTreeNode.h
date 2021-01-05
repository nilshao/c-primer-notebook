#ifdef binaryTree_
#define binaryTree_

template<class T>
struct binaryTreeNode{
    T element;
    binaryTreeNode<T> *leftChild, *rightChild;

    binaryTreeNode(){leftChild = NULL; rightChild = NULL;}
    binaryTreeNode(const T& theElement){
        element = theElement;
        leftChild = NULL; 
        rightChild = NULL;
    }
    binaryTreeNode(const T& theElement, binaryTreeNode *theLeftChild, 
                                        binaryTreeNode *theRightChild){
        element = theElement;
        leftChild = theLeftChild; 
        rightChild = theRightChild;
    }

}

#endif