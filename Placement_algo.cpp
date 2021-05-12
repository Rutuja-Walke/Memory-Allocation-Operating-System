#include<bits/stdc++.h>
using namespace std;

// 5 4
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

void first_fit(int partitions, int processes){
    vector<int> part, p;
    cout<<"\nEnter partition Size:\n"; part = input(partitions);
    cout<<"\nEnter Process size:\n"; p = input(processes);

    cout<<endl;

    int e_frag=0;

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
}


void best_fit(int partitions, int processes){
    vector<int> part, p;
    cout<<"\nEnter partition Size:\n"; part = input(partitions);
    cout<<"\nEnter Process size:\n"; p = input(processes);
    cout<<endl;

    int e_frag=0;
    sort(part.begin(), part.end());    

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
}


void worst_fit(int partitions, int processes){
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
}


void next_fit(int partitions, int processes){
    vector<int> part, p;
    cout<<"\nEnter partition Size:\n";  part = input(partitions);
    cout<<"\nEnter Process size:\n";   p = input(processes);
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
}


int main()
{
    int partitions, processes;
    cout<<"\nEnter total number of partitions and processes:\n";
    cout<<"Partitions : ";
    cin >> partitions;
    cout<<"Processes : ";
    cin >> processes;

    cout<<"\nFIRST FIT:\n";
    first_fit(partitions, processes);
    cout<<endl<<endl;

    cout<<"_______________________________________________________________________\n\n";
    cout<<"BEST FIT:\n";
    best_fit(partitions, processes);
    cout<<endl<<endl;

    cout<<"_______________________________________________________________________\n\n";
    cout<<"WORST FIT:\n";
    worst_fit(partitions, processes);
    cout<<endl<<endl;

    cout<<"_______________________________________________________________________\n\n";
    cout<<"NEXT FIT:\n";
    next_fit(partitions, processes);
    
    return 0;
}