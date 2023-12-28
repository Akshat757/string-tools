#include <bits/stdc++.h>

using namespace std;

int cmp(pair<string,int> a, pair<string,int> b){
    return a.second < b.second;
}

vector<pair<string,int>> wordCount(string filePath){
    map<string,int> counter;
    fstream inFile(filePath);
    string words;
    while(inFile>>words){
        counter[words]++;
    }
    inFile.close();
    vector<pair<string,int>> v(counter.begin(),counter.end());
    sort(v.begin(),v.end(),cmp);
    return v;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <file_path>" << endl;
        return 1;
    }
    string filePath = argv[1];

    vector<pair<string,int>> count = wordCount(filePath);
    
    int x,y,n=count.size();
    cout<<"do you want top 10 or 100 words or 1000(all): ";
    cin>>y;
    cout<<endl<<"do you want to get count in inc=1 or dec=0: ";
    cin >> x; 
    if(y==10){
        if(x){
            for(int i=0;i<10;i++){
                cout<< count[i].first << "  " << count[i].second <<endl;
            }
        }else{
            for(int i=n-1;i>=n-10;i--){
                cout<< count[i].first << "  " << count[i].second <<endl;
            }
        }
    }else if(x==100){
        if(x){
            for(int i=0;i<100;i++){
                cout<< count[i].first << "  " << count[i].second <<endl;
            }
        }else{
            for(int i=n-1;i>=n-100;i--){
                cout<< count[i].first << "  " << count[i].second <<endl;
            }
        }
    }
    else{
        if(x){
            for(int i=0;i<n;i++){
                cout<< count[i].first << "  " << count[i].second <<endl;
            }
        }else{
            for(int i=n-1;i>=0;i--){
                cout<< count[i].first << "  " << count[i].second <<endl;
            }
        }
    }
    return 0;
}