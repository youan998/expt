#include <iostream>
#include "linkedList.h"
#include <vector>
using namespace std;
void deleteElement(linkedList& list) {
    if (list.head == nullptr) return;

    Node* slow = list.head;
    // 外层循环：slow 依次遍历每一个节点
    while (slow != nullptr) {
        Node* fast = slow; 
        // 内层循环：fast 负责排查 slow 后面的所有节点
        while (fast->next != nullptr) { // 【关键修正3】确保 fast->next 不为空，安全防范段错误
            if (fast->next->data == slow->data) {
                // 发现重复，断开并删除 fast 的下一个节点
                Node* temp = fast->next; 
                fast->next = fast->next->next; 
                delete temp;
            } else {
                fast = fast->next; // 没有重复，fast 往后走
            }
        }
        slow = slow->next; // 换下一个数字继续排雷
    }
}         
void add(linkedList& list1, linkedList& list2) {
    if (list1.head == nullptr) {
        list1.head = list2.head;
        list2.head = nullptr; //断开 list2，防止后续被重复析构释放内存
        list1.displaylist();
        return;
    }
    Node* i = list1.head;
    while (i->next != nullptr) {  
        i = i->next;
    }
    i->next = list2.head;
    list2.head = nullptr; //断开 list2，防止后续被重复析构释放内存                      
    deleteElement(list1); // 删除合并后链表中的重复元素                 
    list1.displaylist(); // 输出合并后的链表                    
}
int main() {
    linkedList list1, list2;
    vector<int> values1= {1,3,6,10,15,16,17,18,19,20};
    vector<int> values2= {1,2,3,4,5,6,7,8,9,10,18,20,30};
    for (int value : values1) {
        list1.insert(value);
    }                       
    for (int value : values2) {
        list2.insert(value);
    }               
    cout<<"第一次实验："<<endl;     
    add(list1, list2);  
    list1.head=nullptr;
    list2.head=nullptr;    
    values1= {1,3,6,10,15,16,17,18,19,20};
    values2= {2,4,5,7,8,9,12,22};
    for (int value : values1) {
        list1.insert(value);
    }                   
    for (int value : values2) {
        list2.insert(value);
    }
    cout<<"第二次实验："<<endl;         
    add(list1, list2);      
    list1.head=nullptr;         
    list2.head=nullptr; 
    values1= {};        
    values2= {1,2,3,4,5,6,7,8,9,10};
    for (int value : values1) {
        list1.insert(value);
    }
    for (int value : values2) {
        list2.insert(value);
    }
    cout<<"第三次实验："<<endl;             
    add(list1, list2);                  
    return 0;   
}