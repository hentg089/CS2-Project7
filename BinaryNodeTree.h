//Mark Hentges 5814125

/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2023
 *
 *  Header file for a pointer-based implementation of the ADT binary
 *  tree.
 *
 *  Adapted from pages 480-482 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 29 Mar 2023
 *
 *  @version 7.0 */

#ifndef BINARY_NODE_TREE_
#define BINARY_NODE_TREE_

#include <memory>

#include <list>

#include "BinaryTreeInterface.h"


/** @class BinaryNodeTree BinaryNodeTree.h "BinaryNodeTree.h"
 *
 *  Specification of a link-based ADT binary tree. */
template <typename ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType> {
protected:
   class BinaryNode;

   using BinaryNodePtr = std::shared_ptr<BinaryNode>;

private:
   BinaryNodePtr rootPtr;

protected:
   //------------------------------------------------------------
   // Protected Utility Methods Section:
   // Recursive helper methods for the public methods.
   //------------------------------------------------------------

   int getHeightHelper(BinaryNodePtr subTreePtr) const;

   int getNumberOfNodesHelper(BinaryNodePtr subTreePtr) const;

   // Recursively adds a new node to the tree in a left/right fashion to
   // keep the tree balanced.
   auto balancedAdd(BinaryNodePtr subTreePtr,
                    BinaryNodePtr newNodePtr);

   // Removes the target value from the tree by calling moveValuesUpTree
   // to overwrite value with value from child.
   auto removeValue(BinaryNodePtr subTreePtr,
                    const ItemType& target,
                    bool& success);

   // Copies values up the tree to overwrite value in current node until
   // a leaf is reached; the leaf is then removed, since its value is
   // stored in the parent.
   auto moveValuesUpTree(BinaryNodePtr subTreePtr);

   // Recursively searches for target value in the tree by using a
   // preorder traversal.
   auto findNode(BinaryNodePtr treePtr,
                 const ItemType& target) const;

   // Copies the tree rooted at treePtr and returns a pointer to
   // the copy.
   auto copyTree(const BinaryNodePtr& treePtr) const;

   // Recursive traversal helper methods:
   void preorder(void visit(ItemType&),
                 BinaryNodePtr treePtr);
   void inorder(void visit(ItemType&),
                BinaryNodePtr treePtr);
   void postorder(void visit(ItemType&),
                  BinaryNodePtr treePtr);

   // Tools for manipulating BinaryNodes:

   bool isLeaf(const BinaryNodePtr nodePtr) const;

   auto getRootPtr() const;
   void setRootPtr(BinaryNodePtr newRootPtr);
public:
   //------------------------------------------------------------
   // Constructor and Destructor Section.
   //------------------------------------------------------------
   BinaryNodeTree() = default;

   explicit BinaryNodeTree(const ItemType& rootItem);

   BinaryNodeTree(const ItemType& rootItem,
                  const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                  const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr);

   BinaryNodeTree(const BinaryNodeTree<ItemType>& tree);

   ~BinaryNodeTree() override = default;

   //------------------------------------------------------------
   // Public BinaryTreeInterface Methods Section.
   //------------------------------------------------------------
   bool isEmpty() const override;

   int getHeight() const override;

   int getNumberOfNodes() const override;

   ItemType getRootData() const override;

   void setRootData(const ItemType& newData) override;

   bool add(const ItemType& newData) override;

   bool remove(const ItemType& data) override;

   void clear() override;

   ItemType getEntry(const ItemType& anEntry) const override;

   bool contains(const ItemType& anEntry) const override;

   //------------------------------------------------------------
   // Public Traversals Section.
   //------------------------------------------------------------
   void preorderTraverse(void visit(ItemType&) ) override;
   void inorderTraverse(void visit(ItemType&) ) override;
   void postorderTraverse(void visit(ItemType&) ) override;

   //------------------------------------------------------------
   // Overloaded Operator Section.
   //------------------------------------------------------------
   BinaryNodeTree& operator=(const BinaryNodeTree& rhs);

   /**displays 90 degree rotated tree
    *@pre none
    * @post none
    */
   void displayThisTree() const;

   /**flips tree
    * @pre none
    * @post the entire tree should be flipped
    */
   void flip();

   /**checks to see if a BST
    *@pre none
    * @post none
    * @return whether or not its a BST
    */
   bool containsBinarySearchTree();

   /**returns the max item value node
    * @pre none
    * @post none
    * @return
    */
   ItemType maximumValue();

   /**returns the min item value node
    * @pre noe
    * @post none
    * @return the min value
    */
   ItemType minimumValue();

   /**prints out all root to leaf paths
    * @pre none
    * @post none
    */
   void rootToLeafPaths();

   /**checks to see if any fo the paths sum to a node
    * @pre none
    * @post none
    * @param num that we are chekcing
    * @return fi there was a path where the sum was equal
    */
   bool doesSomePathHaveSum(int num);
private:
    /**helper for display tree
     * @pre none
     * @post none
     * @param n the root pointer of the tree
     * @param val how many spaces well add before printing
     */
    void displayThisTreeHelper(BinaryNodePtr n, int val = 0) const;

    /**helper for the flip func
     * @pre none
     * @post flip tree
     * @param n root of tree
     */
    void flipHelper(BinaryNodePtr n);

    /**contains bst helper
     * @pre none
     * @post none
     * @param n root ptr
     * @return bool if it does or does not
     */
    bool containsBinarySearchTreeHelper(BinaryNodePtr n);

    /**finds the maximum value
     * @pre none
     * @post none
     * @param n the root pointer
     * @return the max value
     */
    ItemType maximumValueHelper(BinaryNodePtr n);

    /**finds the minimum value
     * @pre none
     * @post none
     * @param n root pointer
     * @return the min value
     */
    ItemType minimumValueHelper(BinaryNodePtr n);

    /**leaf paths helper
     * @pre none
     * @post none
     * @param n root ptr
     * @param nodeValues list of nodeValues
     */
    void rootToLeafPathsHelper(BinaryNodePtr n, std::list<ItemType>& nodeValues);

    /**prints the path
     * @pre none
     * @post none
     * @param nodeValues list of nodes in a path
     */
    void printPath(std::list<ItemType>& nodeValues);

    /**doesSomePathHaveSum helper
     * @pre none
     * @post none
     * @param n root ptr
     * @param sum the current sum
     * @param num the num we are comparing to
     * @return if the path exists or not
     */
    bool doesSomePathHaveSumHelper(BinaryNodePtr n, int sum, int num);
};

#include "BinaryNode.h"

#include "BinaryNodeTree.cpp"

#endif
