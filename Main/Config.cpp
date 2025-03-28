#include <bits/stdc++.h>
#include "../libraries/Service.h"
#include "GenerateInput.h"
#include <ctime> // Cho hàm time()
using namespace std;


// Hàm chuyển số thành chuỗi dạng "0001", "0002", ...
string formatNumber(int num) {
    ostringstream oss;
    oss << setw(4) << setfill('0') << num;
    return oss.str();
}

// Tạo các bộ kiểm thử và chạy chương trình
void create_tests(const string& problemName, int start, int testnum) {
    initializeTaskFolder(problemName); // Tạo thư mục cho bài toán
    compileSolution(); // Biên dịch chương trình

    for (int i = start; i <= testnum; ++i) {
        string test_dir = problemName + "/Test" + formatNumber(i);
        createTestFolder(problemName, i); // Tạo thư mục cho bộ test

        cout << "Generating Test #" << i << "...\n";

        // Tạo input
        generateInput(i, testnum, "input.txt");
        copyFileContents("input.txt", test_dir + "/" + problemName + ".inp");

        // Chạy solution.exe
#ifdef _WIN32
        if (system("solution.exe") == 0) { // Windows
#else
        if (system("./solution.exe") == 0) { // Linux/macOS
#endif
            copyFileContents("output.txt", test_dir + "/" + problemName + ".out");
            cout << "Test #" << i << " completed.\n";
        } else {
            cerr << "Error running solution.exe on Test #" << i << "\n";
        }
    }
}

main() {
    srand(time(NULL)); // Khởi tạo bộ sinh số ngẫu nhiên

    string problemName = "UocSoSieuDoiXung";
    int start = 1, testnum = 50;

    create_tests(problemName, start, testnum);

    cout << "All tests generated successfully!\n";
    return 0;
}
