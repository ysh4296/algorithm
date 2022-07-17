/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string Answer;

int n, m;
vector<int> XA, XB, YA, YB;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		// left right middle

		cin >> n >> m;
        char Xstart, Ystart;
        int curAlphabet = 's';
        int alphabetStack = 0;
        int numberXA = 0, numberXB = 0, numberYA = 0 , numberYB = 0;
        string X,Y;
        cin >> X;
        cin >> Y;
        for (int i = 0; i < n; i++) {
            char value = X.at(i);
            if (curAlphabet == value) {
                alphabetStack++;
            }
            else {
                if (curAlphabet == 'a') {
                    XA.push_back(alphabetStack);
                    numberXA += alphabetStack;
                    alphabetStack = 1;
                    curAlphabet = 'b';
                }
                else if (curAlphabet == 'b') {
                    XB.push_back(alphabetStack);
                    numberXB += alphabetStack;
                    alphabetStack = 1;
                    curAlphabet = 'a';
                }
                else if (curAlphabet == 's'){
                    // init
                    alphabetStack++;
                    curAlphabet = value; Xstart = value;
                }
            }
        }
        if (curAlphabet == 'a') {
            XA.push_back(alphabetStack);
            numberXA += alphabetStack;
        }
        else if (curAlphabet == 'b') {
            XB.push_back(alphabetStack);
            numberXB += alphabetStack;
        }
        curAlphabet = 's';
        alphabetStack = 0;
        for (int i = 0; i < m; i++) {
            char value = Y.at(i);
            if (curAlphabet == value) {
                alphabetStack++;
            }
            else {
                if (curAlphabet == 'a') {
                    YA.push_back(alphabetStack);
                    numberYA += alphabetStack;
                    alphabetStack = 1;
                    curAlphabet = 'b';
                }
                else if (curAlphabet == 'b') {
                    YB.push_back(alphabetStack);
                    numberYB += alphabetStack;
                    alphabetStack = 1; 
                    curAlphabet = 'a';
                }
                else {
                    // init
                    alphabetStack++;
                    curAlphabet = value; Ystart = value;
                }
            }
        }
        if (curAlphabet == 'a') {
            numberYA += alphabetStack;
            YA.push_back(alphabetStack);
        }
        else if (curAlphabet == 'b') {
            numberYB += alphabetStack;
            YB.push_back(alphabetStack);
        }
        // print 

        bool correct = false;
        if (Ystart == 'a') {
            int AErase = 0;
            for (int i = 0; i < (int)XA.size(); i++) {
                int curA = XA[i];
                AErase += curA;
                if (numberXA - AErase + curA < YA[0] || AErase < YA[0]) {
                    continue; // can't seach
                }
                // can start with this A
                // cout << "start A" << endl;
                int pi = 0;
                if (Xstart == 'b') {
                    pi++;
                }
                int BErase = 0;
                if (YB.size() == 0) {
                    correct = true;
                    break;
                }
                if (YB.size() == 1) {
                    correct = true;
                    break;
                }
                if (XB[i + pi] < YB[0]) {
                    continue; // can't start with B
                }
                // cout << "start B" << endl;
                int j = 1; 
                for (int count = 0; count <= i + pi; count++) BErase += XB[count];
                for (; j < YA.size() - 1 || j <  YB.size() - 1; j++) {
                    if (j < YA.size() - 1) {
                        if (YA[j] != XA[j + i]) {
                            break;
                        }
                        AErase += XA[j + i];
                    }
                    if (j < YB.size() - 1) {
                        if (YB[j] != XB[j + i]) {
                            break;
                        }
                        BErase += XB[j + 1];
                    }
                }
                // cout << "long until done" << endl;
                if (YB.size() == YA.size()) {
                    if (j == 1) {
                        correct = true;
                        break;
                    }
                    if (YA[j-1] <= XA[j + i - 1] && YB[j-1] <= numberXB - BErase) {
                        correct = true;
                        break;
                    }
                }
                else { // YB.size() < YA.size()
                    if (YA[j] <= numberXA - AErase && YB[j-1] <= XB[j + i - 1]) {
                        correct = true;
                        break;
                    }
                }
            }
        }
        else {
            int BErase = 0;
            for (int i = 0; i < (int)XB.size(); i++) {
                int curB = XB[i];
                BErase += curB;
                if (numberXB - BErase < YB[0] || BErase < YB[0]) {
                    break; // can't seach
                }
                // can start with this A
                int pi = 0;
                if (Xstart == 'a') {
                    pi++;
                }
                int AErase = 0; 
                if (YA.size() == 0) {
                    correct = true;
                    break;
                }
                if (YA.size() == 1) {
                    correct = true;
                    break;
                }
                if (XA[i + pi] < YA[0]) {
                    continue; // can't start with B
                }
                int j = 1;
                for (int count = 0; count <= i + pi; count++) AErase += XA[count];
                for (; j < YB.size() - 1 || j < YA.size() - 1; j++) {
                    if (j < YB.size() - 1) {
                        if (YB[j] != XB[j + i]) {
                            break;
                        }
                        BErase += XB[j + i];
                    }
                    if (j < YA.size() - 1) {
                        if (YA[j] != XA[j + i]) {
                            break;
                        }
                        AErase += XA[j + 1];
                    }
                }
                if (YA.size() == YB.size()) {
                    if (j == 1) {
                        correct = true;
                        break;
                    }
                    if (YB[j-1] <= XB[j + i-1] && YA[j-1] <= numberXA - AErase) {
                        correct = true;
                        break;
                    }
                }
                else { // YA.size() < YB.size()
                    if (YB[j] <= numberXB - BErase && YA[j - 1] <= XA[j + i - 1]) {
                        correct = true;
                        break;
                    }
                }
            }
        }
		Answer = correct == true?"YES":"NO";
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
        XA.clear();
        XB.clear();
        YA.clear();
        YB.clear();
	}

	return 0;//Your program should return 0 on normal termination.
}
