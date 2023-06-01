//Mark Hentges 5814125

/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2023
 *
 *  Implementation file for a pointer-based implementation of the ADT binary
 *  tree.
 *
 *  Adapted from pages 482-491 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 29 Mar 2023
 *
 *  @version 7.0 */

#include <algorithm> // For std::max
#include <iostream>
#include <memory>
#include <new>

#include "PrecondViolatedExcep.h"
#include "NotFoundException.h"

//////////////////////////////////////////////////////////////
//      Protected Utility Methods Section
//////////////////////////////////////////////////////////////

template <typename ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(BinaryNodePtr subTreePtr) const {

   if (subTreePtr) {
      return 1 + std::max(getHeightHelper(subTreePtr->leftChildPtr),
                          getHeightHelper(subTreePtr->rightChildPtr) );
   }

   return 0;
}

template <typename ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(BinaryNodePtr subTreePtr) const {

   if (subTreePtr) {
      return 1 +
         getNumberOfNodesHelper(subTreePtr->leftChildPtr) +
         getNumberOfNodesHelper(subTreePtr->rightChildPtr);
   }

   return 0;
}

template <typename ItemType>
auto BinaryNodeTree<ItemType>::balancedAdd(BinaryNodePtr subTreePtr,
                                           BinaryNodePtr newNodePtr) {

   if (!subTreePtr) {
      return newNodePtr;
   }

   if (getHeightHelper(subTreePtr->leftChildPtr) >
       getHeightHelper(subTreePtr->rightChildPtr) ) {
      subTreePtr->rightChildPtr = balancedAdd(subTreePtr->rightChildPtr,
                                              newNodePtr);
   }
   else {
      subTreePtr->leftChildPtr = balancedAdd(subTreePtr->leftChildPtr,
                                             newNodePtr);
   }

   return subTreePtr;
}

template <typename ItemType>
auto BinaryNodeTree<ItemType>::moveValuesUpTree(BinaryNodePtr subTreePtr) {

   if (isLeaf(subTreePtr) ) {
      subTreePtr = nullptr;
      return subTreePtr;
   }

   if (getHeightHelper(subTreePtr->leftChildPtr) >
       getHeightHelper(subTreePtr->rightChildPtr) ) {
      subTreePtr->item = subTreePtr->leftChildPtr->item;
      subTreePtr->leftChildPtr = moveValuesUpTree(subTreePtr->leftChildPtr);
   }
   else {
      subTreePtr->item = subTreePtr->rightChildPtr->item;
      subTreePtr->rightChildPtr = moveValuesUpTree(subTreePtr->rightChildPtr);
   }

   return subTreePtr;
}

/** Depth-first search of tree for item.
 *
 *  @param subTreePtr The tree to search.
 *
 *  @param target The target item to find.
 *
 *  @param success Communicate to client whether we found the target.
 *
 *  @return A pointer to the node containing the target. */
template <typename ItemType>
auto BinaryNodeTree<ItemType>::removeValue(BinaryNodePtr subTreePtr,
                                           const ItemType& target,
                                           bool& success) {

   if (!subTreePtr) {
      return BinaryNodePtr(); // A nullptr with type 'BinaryNodePtr'.
   }

   if (subTreePtr->item == target) {
      success = true;
      return moveValuesUpTree(subTreePtr);
   }

   subTreePtr->leftChildPtr = removeValue(subTreePtr->leftChildPtr,
                                          target,
                                          success);
   if (!success) {
      subTreePtr->rightChildPtr = removeValue(subTreePtr->rightChildPtr,
                                              target,
                                              success);
   }

   return subTreePtr;
}

template <typename ItemType>
auto BinaryNodeTree<ItemType>::findNode(BinaryNodePtr subTreePtr,
                                        const ItemType& target) const {

   BinaryNodePtr returnPtr;

   if (!subTreePtr) {
      return returnPtr;
   }

   if (subTreePtr->item == target) {
      return subTreePtr;
   }

   returnPtr = findNode(subTreePtr->leftChildPtr,
                        target);
   if (!returnPtr) {
      returnPtr = findNode(subTreePtr->rightChildPtr,
                           target);
   }

   return returnPtr;
}

template <typename ItemType>
auto BinaryNodeTree<ItemType>::copyTree(const BinaryNodePtr& subTreePtr) const {

   if (!subTreePtr) {
      return BinaryNodePtr();
   }

   // Copy tree nodes using a preorder traversal
   return std::make_shared<BinaryNode>(subTreePtr->item,
                                       copyTree(subTreePtr->leftChildPtr),
                                       copyTree(subTreePtr->rightChildPtr) );
}

//////////////////////////////////////////////////////////////
//      Protected Tree Traversal Sub-Section
//////////////////////////////////////////////////////////////

template <typename ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&),
                                        BinaryNodePtr subTreePtr) {

   if (subTreePtr) {
      visit(subTreePtr->item);

      preorder(visit, subTreePtr->leftChildPtr);
      preorder(visit, subTreePtr->rightChildPtr);
   }
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&),
                                       BinaryNodePtr subTreePtr) {

   if (subTreePtr) {
      inorder(visit, subTreePtr->leftChildPtr);

      visit(subTreePtr->item);

      inorder(visit, subTreePtr->rightChildPtr);
   }
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&),
                                         BinaryNodePtr subTreePtr) {

   if (subTreePtr) {
      postorder(visit, subTreePtr->leftChildPtr);
      postorder(visit, subTreePtr->rightChildPtr);

      visit(subTreePtr->item);
   }
}

//////////////////////////////////////////////////////////////
//      Protected Node Access Sub-Section
//////////////////////////////////////////////////////////////

template <typename ItemType>
bool BinaryNodeTree<ItemType>::isLeaf(BinaryNodePtr nodePtr) const {

   return !nodePtr->leftChildPtr && !nodePtr->rightChildPtr;
}

template <typename ItemType>
auto BinaryNodeTree<ItemType>::getRootPtr() const {

   return rootPtr;
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::setRootPtr(BinaryNodePtr newRootPtr) {

   rootPtr = newRootPtr;
}

//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
//      Constructor and Destructor Section
//////////////////////////////////////////////////////////////

template <typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
   : rootPtr(std::make_shared<BinaryNode>(rootItem) ) {
}

template <typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem,
                                         const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                                         const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr)
   : rootPtr(std::make_shared<BinaryNode>(rootItem,
                                          copyTree(leftTreePtr->rootPtr),
                                          copyTree(rightTreePtr->rootPtr)) ) {
}

template <typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr) {

   try {
      rootPtr = copyTree(treePtr.rootPtr);
   }
   catch (const std::bad_alloc&) {
      clear();
      throw;
   }
}

//////////////////////////////////////////////////////////////
//      Public BinaryTreeInterface Methods Section
//////////////////////////////////////////////////////////////

template <typename ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const {

   return !rootPtr;
}

template <typename ItemType>
int BinaryNodeTree<ItemType>::getHeight() const {

   return getHeightHelper(rootPtr);
}

template <typename ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const {

   return getNumberOfNodesHelper(rootPtr);
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::clear() {

   rootPtr.reset();
}

template <typename ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const {

   if (!isEmpty() ) {
      return rootPtr->item;
   }

   std::string message("BinaryNodeTree::getRootData: called ");
   message += "on an empty tree.";

   throw PrecondViolatedExcep(message);
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newItem) {

   if (isEmpty() ) {
      try {
         rootPtr = std::make_shared<BinaryNode>(newItem);
      }
      catch (const std::bad_alloc&) {
         // What should we do with this? Return something? Throw a
         // different type of exception? Crash?
      }
   }
   else {
      rootPtr->item = newItem;
   }
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData) {

   try {
      rootPtr = balancedAdd(rootPtr,
                            std::make_shared<BinaryNode>(newData) );
   }
   catch (const std::bad_alloc&) {
      return false;
   }

   return true;
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType& target) {

   bool isSuccessful(false);

   rootPtr = removeValue(rootPtr, target, isSuccessful);

   return isSuccessful;
}

template <typename ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType& anEntry) const {

   auto binaryNodePtr(findNode(rootPtr, anEntry) );

   if (binaryNodePtr) {
      return binaryNodePtr->item;
   }

   std::string message("BinaryNodeTree::getEntry: Entry ");
   message += "not found in this tree.";

   throw NotFoundException(message);
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::contains(const ItemType& anEntry) const {

   return findNode(rootPtr, anEntry) != nullptr;
}

//////////////////////////////////////////////////////////////
//      Public Traversals Section
//////////////////////////////////////////////////////////////

template <typename ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&) ) {

   preorder(visit, rootPtr);
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&) ) {

   inorder(visit, rootPtr);
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&) ) {

   postorder(visit, rootPtr);
}

//////////////////////////////////////////////////////////////
//      Overloaded Operator
//////////////////////////////////////////////////////////////

template <typename ItemType>
BinaryNodeTree<ItemType>&
BinaryNodeTree<ItemType>::operator=(const BinaryNodeTree<ItemType>& rhs) {

   auto oldTreePtr(rootPtr);

   if (this != &rhs) {
      try {
         rootPtr = copyTree(rhs.rootPtr);
      }
      catch (const std::bad_alloc&) {
         rootPtr = oldTreePtr;
         throw;
      }
   }

   return *this;
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::displayThisTree() const {
    displayThisTreeHelper(rootPtr, 0);
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::displayThisTreeHelper(BinaryNodePtr n, int val) const {
    if(n == nullptr) return;
    displayThisTreeHelper(n->rightChildPtr, val + 1);
    for(int i = 0; i < val*2; ++i){
        std::cout << " ";
    }
    std::cout << n->item << std::endl;
    displayThisTreeHelper(n->leftChildPtr, val + 1);
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::flip() {
    flipHelper(rootPtr);
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::flipHelper(BinaryNodePtr n) {
    if(n == nullptr || isLeaf(n)) return;
    std::swap(n->rightChildPtr,n->leftChildPtr);
    flipHelper(n->leftChildPtr);
    flipHelper(n->rightChildPtr);
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::containsBinarySearchTree() {
    return containsBinarySearchTreeHelper(rootPtr);
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::containsBinarySearchTreeHelper(BinaryNodePtr n) {
    if(isLeaf(n)) return true;
    if(n->leftChildPtr == nullptr) return n->item < n->rightChildPtr->item;
    if(n->rightChildPtr == nullptr) return n->item > n->leftChildPtr->item;
    if(n->item > n->leftChildPtr->item && n->item < n->rightChildPtr->item){
        return containsBinarySearchTreeHelper(n->leftChildPtr) &&
                containsBinarySearchTreeHelper(n->rightChildPtr);
    }else{
        return false;
    }
}

template <typename ItemType>
ItemType BinaryNodeTree<ItemType>::maximumValue() {
    std::string message("BinaryNodeTree::getRootData: called ");
    message += "on an empty tree.";
    if(rootPtr == nullptr){
        throw PrecondViolatedExcep(message);
    }

    return maximumValueHelper(rootPtr);
}

template <typename ItemType>
ItemType BinaryNodeTree<ItemType>::maximumValueHelper(BinaryNodePtr n) {
    if(isLeaf(n)) return n->item;
    if(n->leftChildPtr == nullptr) return std::max(n->item, n->rightChildPtr->item);
    if(n->rightChildPtr == nullptr) return std::max(n->item, n->leftChildPtr->item);
    return std::max(n->item,
                    std::max(maximumValueHelper(n->leftChildPtr), maximumValueHelper(n->rightChildPtr)));
}


template <typename ItemType>
ItemType BinaryNodeTree<ItemType>::minimumValue() {
    std::string message("BinaryNodeTree::getRootData: called ");
    message += "on an empty tree.";
    if(rootPtr == nullptr){
        throw PrecondViolatedExcep(message);
    }

    return minimumValueHelper(rootPtr);
}

template <typename ItemType>
ItemType BinaryNodeTree<ItemType>::minimumValueHelper(BinaryNodePtr n) {
    if(isLeaf(n)) return n->item;
    if(n->leftChildPtr == nullptr) return std::min(n->item, n->rightChildPtr->item);
    if(n->rightChildPtr == nullptr) return std::min(n->item, n->leftChildPtr->item);
    return std::min(n->item,
                    std::min(minimumValueHelper(n->leftChildPtr), minimumValueHelper(n->rightChildPtr)));
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::rootToLeafPaths() {
    std::cout << "All root to leaf paths: " << std::endl;
    std::list<ItemType> nodeValues;
    rootToLeafPathsHelper(rootPtr, nodeValues);
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::rootToLeafPathsHelper(BinaryNodePtr n, std::list<ItemType>& nodeValues) {
    nodeValues.push_back(n->item);
    if(isLeaf(n)) {
        printPath(nodeValues);
    }else{
        if(n->leftChildPtr != nullptr){
            rootToLeafPathsHelper(n->leftChildPtr, nodeValues);
        }
        if(n->rightChildPtr != nullptr){
            rootToLeafPathsHelper(n->rightChildPtr, nodeValues);
        }
    }
    nodeValues.pop_back();
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::printPath(std::list<ItemType> &nodeValues) {
    std::cout << "\t";
    for(ItemType& i : nodeValues){
        std::cout  << i << " ";
    }
    std::cout << std::endl;
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::doesSomePathHaveSum(int num) {
    return doesSomePathHaveSumHelper(rootPtr, 0, num);
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::doesSomePathHaveSumHelper(BinaryNodePtr n, int sum, int num) {
    if(n != nullptr){
        sum += n->item;
        if(isLeaf(n)){
            return sum == num;
        }else{
            return doesSomePathHaveSumHelper(n->leftChildPtr, sum, num) || \
            doesSomePathHaveSumHelper(n->rightChildPtr, sum, num);
        }
    }
    return false;
}
