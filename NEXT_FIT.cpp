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

    int e_frag=0, j=0;

    for(int i=0; i<processes;i++ ){

        int tmp = p[i];
        int k=0, flag=0, size;

        while(k<partitions){
            if(part[j%partitions] >= tmp){
                flag = 1;
                size = part[j%partitions];
                e_frag += (part[j%partitions] - tmp);
                part[j%partitions] = 0;
                break;
            }
            j++;
            k++;
        }

        if(flag == 1) cout<<"Process of size "<<tmp<<" Kb fits in "<<size<<" Kb\n";
        else cout<<"Process of size "<<tmp<<" Kb cannot be allocated"<<endl;

    }
       
    cout<<endl;
    cout<<"Total External Fragmentation: "<<e_frag;
    
    return 0;
}