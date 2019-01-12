#J-Machine Learning Library
**Author: Jay Mody**

This project is a WIP ml library for multilayer perceptron networks in c++. This library for proof of concept and practice rather than implementation for actual programs. 

Matrices are stored as 2d std::vector objects. Matrix multiplication, printing, tranposes and all other operations were coded new.

**To Do:**
- find/create simple training data for classification
- neural-network class
- bias terms
- forward propogation
- loss
- optimization (back propogation gradient descent)


##Functionality
### Matrix Operations

Input a1
1 2 3
4 5 6

Input a2
1 2
3 4
5 6

Matmul algorithim
1(1) + 2(3) + 3(5) = 22
1(2) + 2(4) + 3(6) = 28
4(1) + 5(3) + 6(5) = 49
4(2) + 5(4) + 6(6) = 64

Output
22 28
39 64