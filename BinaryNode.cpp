//Mark Hentges 5814125

//
// Created by markh on 4/16/2023.
//


template <typename ItemType>
BinaryNodeTree<ItemType>::BinaryNode::BinaryNode(const ItemType &anItem, BinaryNodePtr leftPtr,
                                                 BinaryNodePtr rightPtr)
                                                 : item(anItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr){

}

#ifdef DTOR_TEST

#include <iostream>

template <typename ItemType>
BinaryNodeTree<ItemType>::BinaryNode::~BinaryNode() {
    std::cout << "BinaryNode destructor called on: \n\titem: "
              << item
              << std::endl;
}
#endif