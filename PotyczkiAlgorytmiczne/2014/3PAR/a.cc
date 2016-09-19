#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct car {
    //pom
    int id;
    int oldx;
    int oldy;
    //pom
    int x;
    int y;
    int gap;
    int before;
    int after;
};

bool comp(const car &lhs, const car &rhs) {
    if (lhs.x!=rhs.x) {
        return lhs.x < rhs.x;
    }
    else {
        return lhs.y < rhs.y;
    }
}

bool bComp(const car &lhs, const car &rhs) {
    return lhs.before < rhs.before;
}

bool iComp(const car &lhs, const car &rhs) {
    return lhs.id < rhs.id;
}


int main() {
    int i,j,k,t,n,w,x1,x2,y1,y2,h;
    car c;
    bool ok;
    vector<car> cars;
    cin >> t;
    for (i=0; i<t; i++) {
        cars.clear();
        ok=true;
        cin >> n >> w;
        for (j=0; j<n; j++) {
            cin >> x1 >> y1 >> x2 >> y2;
            c.id=j;
            c.oldx=c.x=(x1<x2)?x1:x2;
            c.oldy=c.y=(y1<y2)?y1:y2;
            h=(y2>y1)?y2-y1:y1-y2;
            c.gap=w-h;
            cars.push_back(c);
        }
        sort(cars.begin(),cars.end(),comp);
        for (j=0; j<n; j++) {
            cars[j].before=j;
        }
        sort(cars.begin(),cars.end(),iComp);
        for (j=0; j<n; j++) {
            cin >> x1 >> y1 >> x2 >> y2;
            cars[j].x=(x1<x2)?x1:x2;
            cars[j].y=(y1<y2)?y1:y2;
        }
        sort(cars.begin(),cars.end(),comp);
        for (j=0; j<n; j++) {
            cars[j].after=j;
        }
        sort(cars.begin(),cars.end(),bComp);
        
        j=1;
        while (j<n && ok) {
            h=w-cars[j].gap;
            k=j-1;
            while (k>=0 && ok) {
                /*if (cars[k].after<cars[j].after && w-cars[k].gap>=h) {
                    break;
                }
                else {
                    ok=(cars[k].gap>=h);
                }*/
                if (cars[k].after<cars[j].after) {
                    if (w-cars[k].gap>=h) {
                        break;
                    }
                }
                else {
                    ok=(cars[k].gap>=h);
                }
                k--;
            }
            j++;
        }
        
        if (ok) {
            cout << "TAK\n";
        }
        else {
            cout << "NIE\n";
        }
    }
    return 0;
}

/*if (!ok) {
 cout << "id,oldx,oldy,x,y,h:\n";
 cout << "auto:\n";
 cout << cars[j].id << ", " << cars[j].oldx << ", " << cars[j].oldy << ", " << cars[j].x << ", " << cars[j].y << ", " << w-cars[j].gap << endl;
 cout << "nie miesci sie pod autem:\n";
 cout << cars[k].id << ", " << cars[k].oldx << ", " << cars[k].oldy << ", " << cars[k].x << ", " << cars[k].y << ", " << w-cars[k].gap << endl;
 }*/