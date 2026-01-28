#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cfloat>

using namespace std;

struct Point {
    int x, y;
};

bool compareX(Point a, Point b) {
    return a.x < b.x;
}

bool compareY(Point a, Point b) {
    return a.y < b.y;
}

float dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

float bruteForce(vector<Point> &P, int n) {
    float min_dist = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min_dist)
                min_dist = dist(P[i], P[j]);
    return min_dist;
}

float stripClosest(vector<Point> &strip, float d) {
    float min_dist = d;
    sort(strip.begin(), strip.end(), compareY);

    for (size_t i = 0; i < strip.size(); ++i)
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < min_dist; ++j)
            if (dist(strip[i], strip[j]) < min_dist)
                min_dist = dist(strip[i], strip[j]);

    return min_dist;
}

float closestUtil(vector<Point> &P, int n) {
    if (n <= 3)
        return bruteForce(P, n);

    int mid = n / 2;
    Point midPoint = P[mid];

    vector<Point> Pl, Pr;
    for(int i=0; i<mid; i++) Pl.push_back(P[i]);
    for(int i=mid; i<n; i++) Pr.push_back(P[i]);
    
    // Recursive calls usually operate on sorted X array without copying, 
    // but copying is simpler for clarity here. For rigorous O(N log N) pre-sort Y.
    // This implementation is O(N (log N)^2).
    
    float dl = closestUtil(Pl, mid);
    float dr = closestUtil(Pr, n - mid);

    float d = min(dl, dr);

    vector<Point> strip;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip.push_back(P[i]);

    return min(d, stripClosest(strip, d));
}

float closest(vector<Point> &P, int n) {
    sort(P.begin(), P.end(), compareX);
    return closestUtil(P, n);
}

int main() {
    vector<Point> P = {
        {9,3}, {2,6}, {15,3}, {5,1}, {1,2}, {12,4}, {7,2}, {4,7}, 
        {16,5}, {3,3}, {10,5}, {6,4}, {14,6}, {8,6}, {11,1}, {13,2}
    };
    int n = P.size();
    
    // Using default scientific output or fixed?
    // "Print ... minimum Euclidean distance". 
    cout << "Minimum distance: " << closest(P, n) << endl;
    return 0;
}
