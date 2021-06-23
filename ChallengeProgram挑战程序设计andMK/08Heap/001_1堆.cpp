/*
//队列主要操作
// 入队 
// 出队(取出最高优先级数组)

//总共N个请求
//最差情况N^2
//堆 O nlogn


//二叉堆    是一颗完全二叉树
// 1.堆中某个节点的值总是不大于其父节点的值，堆总是一颗完全二叉树，(最大堆)
// 2.除了最后一个，

//                      62
//                 /          \   
//            41               30
//         /     \           /    \  
//      28         16      22      13
//     /  \      /
//   19   17    15   


// 最大堆，树形结构,完全二叉树
//堆中某个节点的值总是不大于其父节点的值
//堆中某个节点的值总是不大于其父节点的值
//堆中某个节点的值总是不大于其父节点的值


//                     62(1)
//                 /          \   
//            41(2)            30(3)
//         /      \           /    \  
//      28(4)      16(5)     22(6)  13(7)
//     /  \       /
//   19(8) 17(9) 15(10)  
// 每个左子节点编号是父节点的2倍 右节点是2倍+1
//  0   1   2   3   4   5   6   7   8   9   10
//  -  62  41  30  28  16  22  13  19  17   15
// parent(i) = i/2
// left-> 2*i
// right-> 2*i+1

*/
#include<iostream>
#include<algorithm>
#include<string>
#include<ctime>
#include<cmath>
#include<cassert>
using namespace std;
template<typename Item>
class MaxHeap{

private:
    Item* data;
    int count;

public:
    MaxHeap(int capacity){
        data = new Item[capacity +1];
        count = 0;
    }

    ~MaxHeap(){
        delete [] data;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }
};

int main(){
    MaxHeap<int> maxheap = MaxHeap<int>(100);
    cout<<maxheap.size()<<endl;

    return 0;
}

















