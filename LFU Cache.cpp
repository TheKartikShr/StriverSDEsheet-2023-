#include <bits/stdc++.h>
using namespace std; 

class LFUCache
{
public:
    unordered_map<int,int> mp;
    int n;
    LFUCache(int capacity)
    {
        // Write your code here.
        mp.clear();
        n=capacity;
    }

    int get(int key)
    {
        // Write your code here.
        if(mp.find(key)==mp.end())
        return -1;
        return mp[key];

    }

    void put(int key, int value)
    {
        // Write your code here.
        if(mp.find(key)!=mp.end())
        mp[key]=value;
        else if(n>mp.size())
        {
            mp[key]=value;
            
        }
        else
        {
            int mini=INT_MAX;
            int mikey=INT_MAX;
            for(auto x: mp)
            {
                if(x.second<mini)
                {
                    mini=x.second;
                    mikey=x.first;
                }
            }
            mp.erase(mikey);
            mp[key]=value;
        }
    }
};

int main(){
    LFUCache* temp = new LFUCache(3);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x == 1){
            int a, b;
            cin >> a >> b;
            temp -> put(a, b);
        }else{
            int a;
            cin >> a;
            cout << temp -> get(a) << " ";
        }
    }
    cout << endl;
}
