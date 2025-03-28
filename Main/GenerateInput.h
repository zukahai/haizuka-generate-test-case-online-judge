#include <bits/stdc++.h>
#include "../libraries/FunctionRadom.h"

#define int long long
#define randomSubtask() random(subtasks, currentTest, totalTests)
#define randomVectorSubtask() randomVector(subtasks, currentTest, totalTests)
using namespace std;

vector<Subtask> subtasks = {
    {percent: 50, lenN: 4, lenAi: 5},
    {percent: 50, lenN: 8, lenAi: 9},
};


void generateInput(int currentTest, int totalTests , string target_file = "input.txt")
{
    ofstream cout(target_file);
    srand(time(0) + currentTest); // Sinh số ngẫu nhiên theo thời gian thực
    // Cout ra những đầu vào cần thiết ở phía dưới
    
    if (currentTest == totalTests) {
        cout << 100000000;
        return;
    }


    int n = randomSubtask();
    cout << n;
	
}

    
