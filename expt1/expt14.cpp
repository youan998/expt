#include <iostream>
#include <vector>
#include "seqlist.h"
using namespace std; 
void insertlist(list &L, vector<int> value){
    L.size = 0; // 确保在插入前清空顺序表               
    for (int i = 0; i < value.size(); i++) {
        L.insert(value[i]); 
    }
}    
void deletelement(list &L) {
    if (L.size <= 1) {
        cout << "删除重复元素后的表: ";
        L.display();
        return; // 只有 0 或 1 个元素，必定不重复，直接返回
    }
    int slow = 0; // 慢指针停在第一个元素
    for (int fast = 1; fast < L.size; fast++) { // 快指针从第二个元素开始探路
        // 如果快指针找到了和慢指针不一样的新鲜数字
        if (L.data[fast] != L.data[slow]) {
            slow++; // 慢指针前进一步，腾出新位置
            L.data[slow] = L.data[fast]; // 把新数字赋值过去
        }
    }
    L.size = slow + 1; 
    cout << "删除重复元素后的表: ";
    L.display();
}         
int main(){
    list L;
    vector<int> values1= {1,2,3,4,5,6,7,8,9};
    cout<<"第一次测试:"<<endl;
    insertlist(L, values1);
    deletelement(L);
    cout<<"第二次测试:"<<endl;
    vector<int> values2= {1,1,2,2,2,3,4,5,5,5,6,6,7,7,8,8,9};
    insertlist(L, values2); 
    deletelement(L);
    cout<<"第三次测试:"<<endl;
    vector<int> values3= {1,2,3,4,5,5,6,7,8,8,9,9,9,9,9};
    insertlist(L, values3);
    deletelement(L);
}