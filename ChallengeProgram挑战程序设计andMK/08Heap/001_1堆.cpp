/*
队列主要操作
 入队 
 出队(取出最高优先级数组)

总共N个请求
最差情况N^2
堆 O nlogn


二叉堆    是一颗完全二叉树
 1.堆中某个节点的值总是不大于其父节点的值，堆总是一颗完全二叉树，(最大堆)
 2.除了最后一个，

                      62
                 /          \   
            41               30
         /     \           /    \  
      28         16      22      13
     /  \      /
   19   17    15   


 最大堆，树形结构,完全二叉树
堆中某个节点的值总是不大于其父节点的值
堆中某个节点的值总是不大于其父节点的值
堆中某个节点的值总是不大于其父节点的值


                     62(1)
                 /          \   
            41(2)            30(3)
         /      \           /    \  
      28(4)      16(5)     22(6)  13(7)
     /  \       /
   19(8) 17(9) 15(10)  
 每个左子节点编号是父节点的2倍 右节点是2倍+1
  0   1   2   3   4   5   6   7   8   9   10
  -  62  41  30  28  16  22  13  19  17   15
 parent(i) = i/2
 left-> 2*i
 right-> 2*i+1

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
    int capacity;
    //串位
    void shiftUp(int k){
        
        while ( k>1 &&data[k/2]<data[k]){
            swap(data[k/2],data[k]);
            k/=2;
        } 
    }

    //打印所需要的函数
    void putNumberInLine( int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width+1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if( num >= 10 ) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        }
        else{
            if( isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine( string &line, int index_cur_level, int cur_tree_width){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width+1) + sub_sub_tree_width;
        assert( offset_left + 1 < line.size() );
        int offset_right = index_cur_level * (cur_tree_width+1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert( offset_right < line.size() );

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }

public:

    // 打印堆
    void testPrint(){

        // 我们的testPrint只能打印100个元素以内的堆的树状信息
        if( size() >= 100 ){
            cout<<"This print function can only work for less than 100 int";
            return;
        }

        // 我们的testPrint只能处理整数信息
        if( typeid(Item) != typeid(int) ){
            cout <<"This print function can only work for int item";
            return;
        }

        cout<<"The max heap size is: "<<size()<<endl;
        cout<<"Data in the max heap: ";
        for( int i = 1 ; i <= size() ; i ++ ){
            // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
            assert( data[i] >= 0 && data[i] < 100 );
            cout<<data[i]<<" ";
        }
        cout<<endl;
        cout<<endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while( n > 0 ) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level-1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for( int level = 0 ; level < max_level ; level ++ ){
            string line1 = string(max_level_number*3-1, ' ');

            int cur_level_number = min(count-int(pow(2,level))+1,int(pow(2,level)));
            bool isLeft = true;
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index ++ , index_cur_level ++ ){
                putNumberInLine( data[index] , line1 , index_cur_level , cur_tree_max_level_number*3-1 , isLeft );
                isLeft = !isLeft;
            }
            cout<<line1<<endl;

            if( level == max_level - 1 )
                break;

            string line2 = string(max_level_number*3-1, ' ');
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index_cur_level ++ )
                putBranchInLine( line2 , index_cur_level , cur_tree_max_level_number*3-1 );
            cout<<line2<<endl;

            cur_tree_max_level_number /= 2;
        }
    }

    MaxHeap(int capacity){
        data = new Item[capacity +1];
        count = 0;
        this->capacity = capacity;
    }

    ~MaxHeap(){
        delete [] data;
    }

    // 获取当前堆大小
    int size(){
        return count;
    }

    //判断是否为空
    bool isEmpty(){
        return count == 0;
    }

    //添加新的元素
    void insert(Item item){
        assert(count+1<capacity);

        data[count+1] = item;
        count++;
        shiftUp(count);
    }
};

int main(){
    MaxHeap<int> maxheap = MaxHeap<int>(100);
    cout<<maxheap.size()<<endl;
    srand(time(NULL));
    for(int i = 0;i<15;i++)
        maxheap.insert(rand()%100);
    maxheap.testPrint();
    return 0;
}

















