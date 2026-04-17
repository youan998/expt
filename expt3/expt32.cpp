#include <iostream>
#include "mystack.h" 
#include <vector>
using namespace std;
int totalcount = 0;
      
void generateSequences(int n, int current_num, stack<int>& s, vector<int>& path) {
    if (path.size()==n)
    {
        totalcount++;
        return;
    }
    if(current_num<=n)
    {
        s.push(current_num);
        generateSequences(n, current_num + 1, s, path);
        int temp;
        s.pop(temp);
    }
    if(!s.isEmpty())
    {
        int x;
        s.pop(x);
        path.push_back(x);
        generateSequences(n, current_num, s, path);
        path.pop_back();      
        s.push(x);   
    }
}           
int main() {
    stack<int> s(100);  
    vector<int> path;   
    int n ;
    cin >> n;
    cout<<"输入n的值为："<<n<<endl;
    generateSequences(n, 1, s, path);   
    cout << "总的出栈序列数: " << totalcount << endl;               
}