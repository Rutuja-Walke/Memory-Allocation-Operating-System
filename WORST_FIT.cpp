#include<bits/stdc++.h>
using namespace std;

// partitions = 100 500 200 300 600
// processes = 212 417 112 426

vector<int> input(int size)
{
    vector<int> v;
    for(int i=0; i<size; i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    return v;
}

int main()
{
    int partitions, processes;
    cout<<"Enter total number of partitions and processes:\n";
    cin >> partitions >> processes;

    vector<int> part, p;
    cout<<"\nEnter partition Size:\n"; part = input(partitions);
    cout<<"\nEnter Process size:\n"; p = input(processes);
    cout<<endl;

    int e_frag=0;
    sort(part.begin(), part.end(), greater<int>());    

    int j=0;
    for(int i=0; i<partitions; i++){
        
        if(j == processes) break;

        if(p[j] <= part[i]){
            cout<<"Process of size "<<p[j]<<" Kb fits in "<<part[i]<<" Kb\n";
            e_frag += (part[i] - p[j]);
            part[i] = 0;
            j++;
            i=0;
        }
    }

    cout<<endl;
    cout<<"Total External Fragmentation: "<<e_frag;
    
    return 0;
}