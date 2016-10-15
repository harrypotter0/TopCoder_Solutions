#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;


class EllysThreeRivers {
public:

    int walk;
    vector<int> width;
    vector<int> swim;

    double calc(int idx, double rem)
    {
        if(idx>=3)
        {
            return rem/walk;
        }

        double ans = numeric_limits<double>::max();
        double left = 0.0;
        double right = rem;

        for(int i=0;i<=100;i++)
        {
            double m1 = left + (right - left)/3.0;
            double m2 = right - (right - left)/3.0;

            double a1 = calc(idx+1, rem-m1) + sqrt((m1*m1)+(width[idx]*width[idx]))/swim[idx];
            ans = min(ans, a1);
            double a2 = calc(idx+1, rem-m2) + sqrt((m2*m2)+(width[idx]*width[idx]))/swim[idx];
            ans = min(ans, a2);

            if(a1<a2)
                right = m2;
            else
                left = m1;
        }
        return ans;
    }
	double getMin(int length, int _walk, vector <int> _width, vector <int> _swim) {
        walk = _walk;
        width = _width;
        swim = _swim;
        return calc(0, length);
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, vector <int> p3, bool hasAnswer, double p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}";
	cout << "]" << endl;
	EllysThreeRivers *obj;
	double answer;
	obj = new EllysThreeRivers();
	clock_t startTime = clock();
	answer = obj->getMin(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = fabs(p4 - answer) <= 1e-9 * max(1.0, fabs(p4));
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	int p1;
	vector <int> p2;
	vector <int> p3;
	double p4;
	
	{
	// ----- test 0 -----
	p0 = 10;
	p1 = 8;
	int t2[] = {5,2,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {5,2,7};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 3.2063518370413364;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 1000;
	p1 = 100;
	int t2[] = {91,911,85};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {28,97,19};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 21.549321613601297;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 666;
	p1 = 4;
	int t2[] = {777,888,999};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {11,12,13};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 228.26633673141083;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 6;
	p1 = 100;
	int t2[] = {2,3,4};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {77,88,99};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 0.12049782476139667;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 873;
	p1 = 54;
	int t2[] = {444,588,263};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {67,97,26};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 26.365540023205206;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
