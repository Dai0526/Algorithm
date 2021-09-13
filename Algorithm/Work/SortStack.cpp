
#include <stack>
#include <iostream>

using namespace std;

void printStack(stack<int> stk){
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

stack<int> sortStack(stack<int> stk){
    stack<int> temp;

    while(!stk.empty()){
        int n = stk.top();
        stk.pop();
        while(!temp.empty() && temp.top() > n){
            stk.push(temp.top());
            temp.pop();
        }
        temp.push(n);
    }

    while(!temp.empty()){
        stk.push(temp.top());
        temp.pop();
    }

    return stk;
}

    int main(int argc, char* argv[]){
        
        stack<int> stk;
        stk.push(1);
        stk.push(7);
        stk.push(2);
        stk.push(9);
        stk.push(5);
        stk.push(3);

        printStack(stk);
        stack<int> ans = sortStack(stk);
        printStack(ans);
        return 0;
    }

