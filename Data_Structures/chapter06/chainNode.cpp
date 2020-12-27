template <class T>
struct chainNode{
    T element;
    chainNode *next;

    chainNode(){}
    chainNode(const T& element)
        {this->element = element; next = nullptr;}
    chainNode(const T& element, chainNode<T>* next)
        {this->element = element; this -> next = next}
    
}