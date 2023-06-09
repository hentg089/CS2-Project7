/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2023
 *
 *  Header file for a node in the pointer-based implementation of the
 *  ADT binary tree.
 *
 *  Adapted from page 478 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 29 Mar 2023
 *
 *  @version 7.0 */

#ifndef BINARY_NODE_
#define BINARY_NODE_

#include <memory>

/** @class BinaryNode BinaryNode.h "BinaryNode.h"
 *
 *  Specification of the nested node type for a linked-chain based ADT
 *  binary tree. */



template <typename ItemType>
class BinaryNodeTree<ItemType>::BinaryNode {
public:
   using BinaryNodePtr = std::shared_ptr<BinaryNode>;

   ItemType item;

   BinaryNodePtr leftChildPtr;
   BinaryNodePtr rightChildPtr;
    /**conostruct bin node
     * @param anItem that is in the node
     * @param leftPtr the left ptr
     * @param rightPtr the right ptr
     */
   explicit BinaryNode(const ItemType& anItem,
                       BinaryNodePtr leftPtr = nullptr,
                       BinaryNodePtr rightPtr = nullptr);

#ifdef DTOR_TEST
   ~BinaryNode();
#else
   ~BinaryNode() = default;
#endif
};

#include "BinaryNode.cpp"

#endif
