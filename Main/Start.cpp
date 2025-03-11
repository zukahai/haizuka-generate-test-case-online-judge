#include <bits/stdc++.h>
#include "GenerateInput.h"
#include <ctime> // Cho hàm time()
using namespace std;

// Hàm tạo thư mục (Windows/Linux)
void create_directory(const string& path) {
#ifdef _WIN32
    system(("mkdir " + path).c_str()); // Windows
#else
    system(("mkdir -p " + path).c_str()); // Linux/macOS
#endif
}

// Hàm chuyển số thành chuỗi dạng "0001", "0002", ...
string format_number(int num) {
    ostringstream oss;
    oss << setw(4) << setfill('0') << num;
    return oss.str();
}

// Hàm sao chép file từ source -> destination
void copy_file(const string& source, const string& destination) {
    ifstream src(source, ios::binary);
    ofstream dest(destination, ios::binary);
    dest << src.rdbuf();
}

// Biên dịch chương trình `solution.cpp`
void compile_solution() {
    cout << "Compiling solution.cpp...\n";
    if (system("g++ -std=c++14 solution.cpp -o solution.exe") != 0) {
        cerr << "Compilation failed!\n";
        exit(1);
    }
    cout << "Compilation successful.\n";
}

// Tạo các bộ kiểm thử và chạy chương trình
void create_tests(const string& prob_name, int start, int testnum) {
    create_directory(prob_name);
    compile_solution(); // Biên dịch chương trình

    for (int i = start; i <= testnum; ++i) {
        string test_dir = prob_name + "/Test" + format_number(i);
        create_directory(test_dir);

        cout << "Generating Test #" << i << "...\n";

        // Tạo input
        generateInput(i, testnum, "input.txt");
        copy_file("input.txt", test_dir + "/" + prob_name + ".inp");

        // Chạy solution.exe
#ifdef _WIN32
        if (system("solution.exe") == 0) { // Windows
#else
        if (system("./solution.exe") == 0) { // Linux/macOS
#endif
            copy_file("output.txt", test_dir + "/" + prob_name + ".out");
            cout << "Test #" << i << " completed.\n";
        } else {
            cerr << "Error running solution.exe on Test #" << i << "\n";
        }
    }
}

main() {
    srand(time(0)); // Sinh số ngẫu nhiên theo thời gian thực

    string prob_name = "testcase";
    int start = 1, testnum = 10;

    create_tests(prob_name, start, testnum);

    cout << "All tests generated successfully!\n";
    return 0;
}
