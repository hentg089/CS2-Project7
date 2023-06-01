//Mark Hentges 5814125

#include <iostream>

#include "BinaryNodeTree.h"

int main() {
    std::cout << "tree 1: " << std::endl;
    BinaryNodeTree<int> t1;
    t1.add(10);
    t1.add(8);
    t1.add(16);
    t1.add(2);
    t1.add(1);

    t1.displayThisTree();

    std::cout << "tree 1 flipped:" << std::endl;
    t1.flip();
    t1.displayThisTree();

    std::cout << "does this binary tree contain a BST?" << std::endl;

    if(t1.containsBinarySearchTree()){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }

    std::cout << "Min value of this binary tree: " << t1.minimumValue() << std::endl;
    std::cout << "Max value of this binary tree: " << t1.maximumValue() << std::endl;

    t1.rootToLeafPaths();

    std::cout << "does this tree contain the sum " << 9 << " in any of its paths?" << std::endl;
    if(t1.doesSomePathHaveSum(9)){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }
    std::cout << "does this tree contain the sum " << 27 << " in any of its paths?" << std::endl;
    if(t1.doesSomePathHaveSum(27)){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }
    std::cout << "does this tree contain the sum " << 20 << " in any of its paths?" << std::endl;
    if(t1.doesSomePathHaveSum(20)){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }
    std::cout << "does this tree contain the sum " << 51 << " in any of its paths?" << std::endl;
    if(t1.doesSomePathHaveSum(51)){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }


    //next tree

    std::cout << "tree 2: " << std::endl;
    BinaryNodeTree<int> t2;
    t2.add(12);


    t2.displayThisTree();

    std::cout << "tree 2 flipped:" << std::endl;
    t2.flip();
    t2.displayThisTree();

    std::cout << "does this binary tree contain a BST?" << std::endl;

    if(t2.containsBinarySearchTree()){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }

    std::cout << "Min value of this binary tree: " << t2.minimumValue() << std::endl;
    std::cout << "Max value of this binary tree: " << t2.maximumValue() << std::endl;

    t2.rootToLeafPaths();

    std::cout << "does this tree contain the sum " << 12 << " in any of its paths?" << std::endl;
    if(t2.doesSomePathHaveSum(12)){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }
    std::cout << "does this tree contain the sum " << 27 << " in any of its paths?" << std::endl;
    if(t2.doesSomePathHaveSum(27)){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }
    std::cout << "does this tree contain the sum " << 20 << " in any of its paths?" << std::endl;
    if(t2.doesSomePathHaveSum(20)){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }
    std::cout << "does this tree contain the sum " << 51 << " in any of its paths?" << std::endl;
    if(t2.doesSomePathHaveSum(51)){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }

    //next tree

    std::cout << "tree 3: " << std::endl;
    BinaryNodeTree<int> t3;
    t3.add(109);
    t3.add(1);
    t3.add(-9);
    t3.add(0);
    t3.add(87);
    t3.add(900);
    t3.add(1098);
    t3.add(1893);
    t3.add(-9432);
    t3.add(89);
    t3.add(43);
    t3.add(80);
    t3.add(19);
    t3.add(5);
    t3.add(109000);


    t3.displayThisTree();

    std::cout << "tree 3 flipped:" << std::endl;
    t3.flip();
    t3.displayThisTree();

    std::cout << "does this binary tree contain a BST?" << std::endl;

    if(t3.containsBinarySearchTree()){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }

    std::cout << "Min value of this binary tree: " << t3.minimumValue() << std::endl;
    std::cout << "Max value of this binary tree: " << t3.maximumValue() << std::endl;

    t3.rootToLeafPaths();

    std::cout << "does this tree contain the sum " << 9 << " in any of its paths?" << std::endl;
    if(t3.doesSomePathHaveSum(9)){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }
    std::cout << "does this tree contain the sum " << 0 << " in any of its paths?" << std::endl;
    if(t3.doesSomePathHaveSum(0)){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }
    std::cout << "does this tree contain the sum " << 153 << " in any of its paths?" << std::endl;
    if(t3.doesSomePathHaveSum(153)){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }
    std::cout << "does this tree contain the sum " << 99755 << " in any of its paths?" << std::endl;
    if(t3.doesSomePathHaveSum(99755)){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }

    //next tree

    std::cout << "tree 4: " << std::endl;
    BinaryNodeTree<int> t4;
    t4.add(10);
    t4.add(5);
    t4.add(15);
    t4.add(4);
    t4.add(13);
    t4.add(6);
    t4.add(3);
    t4.add(16);








    t4.displayThisTree();

    std::cout << "tree 4 flipped:" << std::endl;
    t4.flip();
    t4.displayThisTree();

    std::cout << "does this binary tree contain a BST?" << std::endl;
    t4.flip();
    if(t4.containsBinarySearchTree()){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }

    std::cout << "Min value of this binary tree: " << t4.minimumValue() << std::endl;
    std::cout << "Max value of this binary tree: " << t4.maximumValue() << std::endl;

    t4.rootToLeafPaths();

    std::cout << "does this tree contain the sum " << 12 << " in any of its paths?" << std::endl;
    if(t4.doesSomePathHaveSum(12)){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }
    std::cout << "does this tree contain the sum " << 27 << " in any of its paths?" << std::endl;
    if(t4.doesSomePathHaveSum(27)){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }
    std::cout << "does this tree contain the sum " << 20 << " in any of its paths?" << std::endl;
    if(t4.doesSomePathHaveSum(20)){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }
    std::cout << "does this tree contain the sum " << 51 << " in any of its paths?" << std::endl;
    if(t4.doesSomePathHaveSum(51)){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }

    //new tree

    std::cout << "tree 5: " << std::endl;
    BinaryNodeTree<std::string> t5;
    t5.add("hi");
    t5.add("a");
    t5.add("z");
    t5.add("x");
    t5.add("poag");
    t5.add("j");
    t5.add("u");
    t5.add("vvvc");




    t5.displayThisTree();

    std::cout << "tree 5 flipped:" << std::endl;
    t5.flip();
    t5.displayThisTree();

    std::cout << "does this binary tree contain a BST?" << std::endl;

    if(t5.containsBinarySearchTree()){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }

    std::cout << "Min value of this binary tree: " << t5.minimumValue() << std::endl;
    std::cout << "Max value of this binary tree: " << t5.maximumValue() << std::endl;

    t5.rootToLeafPaths();

    //new tree

    std::cout << "tree 6: " << std::endl;
    BinaryNodeTree<std::string> t6;
    t6.add("p");
    t6.add("g");
    t6.add("u");
    t6.add("z");

    t6.displayThisTree();

    std::cout << "tree 5 flipped:" << std::endl;
    t6.flip();
    t6.displayThisTree();

    std::cout << "does this binary tree contain a BST?" << std::endl;

    if(t6.containsBinarySearchTree()){
        std::cout << "yes" << std::endl;
    }else{
        std::cout << "no" << std::endl;
    }

    std::cout << "Min value of this binary tree: " << t6.minimumValue() << std::endl;
    std::cout << "Max value of this binary tree: " << t6.maximumValue() << std::endl;

    t6.rootToLeafPaths();




    return 0;
}
