#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long big;

void getOK(big ** tab,big n,vector<big> &ok,bool height=false){
    int a,b,i,min,max;
    if (height) {
        a=2;b=3;
    }
    else {
        a=0;b=1;
    }
    min=tab[0][a];
    max=tab[0][b];
    for (i=1; i<n; i++) {
        if (tab[i][a]<min) {
            min=tab[i][a];
        }
        if (tab[i][b]>max) {
            max=tab[i][b];
        }
    }
    for (i=0; i<n; i++) {
        if (tab[i][a]<=min && max<=tab[i][b]) {
            ok.push_back(i);
        }
    }
}

bool common(vector<big> &okW,vector<big> &okH) {
    bool found=false;
    big i,j,n,m;
    i=j=0;
    n=okW.size(); m=okH.size();
    if (n>0 && m>0) {
        while (!found && i<n) {
            j=0;
            while (!found && j<m) {
                found=(okW.at(i)==okH.at(j));
                j++;
            }
            i++;
        }
    }
    return found;
}

void show(vector<big> v) {
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << ", ";
    }
    cout << endl;
}

void showtab(big ** v,big n) {
    for (int i=0; i<n; i++) {
        cout << v[i][0] << ", ";
        cout << v[i][1] << ", ";
        cout << v[i][2] << ", ";
        cout << v[i][3];
        cout << endl;
    }
    cout << endl;
}

int main() {
    int i,t;
    big j,n;
    big **tab;
    vector<big> okW,okH;
    cin >> t;
    for (i=0; i<t; i++) {
        cin >> n;
        okW.clear();
        okH.clear();
        tab=new big * [n];
        for (j=0; j<n; j++) {
            tab[j]=new big [4];
            cin >> tab[j][0];
            cin >> tab[j][1];
            cin >> tab[j][2];
            cin >> tab[j][3];
        }
        getOK(tab,n,okW);
        getOK(tab,n,okH,true);
        if (common(okW,okH)) {
            cout << "TAK\n";
        }
        else {
            cout << "NIE\n";
        }
        for (j=0; j<n; j++) {
            delete [] tab[j];
        }
        delete [] tab;
    }
    return 0;
}