#include <iostream>
#include <cstdlib>
#include <functional>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
priority_queue<int,vector<int>,less<int>> max_heap;
priority_queue<int,vector<int>,greater<int>> min_heap;

int main()
{
    int n;
    //cin >> N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        //cin >> n;
        scanf("%d",&n);
        if(max_heap.size()==min_heap.size()){
            max_heap.push(n);
        }else{
            min_heap.push(n);
        }

        if(!max_heap.empty() && !min_heap.empty() && max_heap.top()>min_heap.top()){
            int tmp=max_heap.top(); max_heap.pop();
            max_heap.push(min_heap.top()); min_heap.pop();
            min_heap.push(tmp);
        }
        //cout << max_heap.top() << endl;
        printf("%d\n",max_heap.top());
    }
    return 0;
}
