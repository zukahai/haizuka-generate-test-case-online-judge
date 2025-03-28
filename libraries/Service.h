#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

// Chuyển đổi số thành chuỗi độ dài cố định (ít nhất 4 ký tự)
string toFixedLengthString(long long number) {
    if (number == 0) return "0000";
    if (number < 0) return "-" + toFixedLengthString(-number);
    string result = "";
    for (int i = 1; i <= 4; i++) {
        result = char((number % 10) + '0') + result;
        number /= 10;
    }
    return result;
}

// Tạo thư mục cho từng bộ kiểm thử
void createTestFolder(const string& taskName, int testIndex) {
    string folderCommand = "mkdir " + taskName + "\\Test" + toFixedLengthString(testIndex);
    system(folderCommand.c_str());
}

// Tạo thư mục chính cho bài toán
void initializeTaskFolder(const string& taskName) {
    string folderCommand = "mkdir " + taskName;
    system(folderCommand.c_str());
}

// Biên dịch chương trình
void compileSolution() {
    system("g++ solution.cpp -o solution.exe");
}

// Chuẩn bị thư mục và biên dịch chương trình
void setupEnvironment(const string& taskName, int startIndex, int totalTests) {
    initializeTaskFolder(taskName);
    for (int i = startIndex; i <= totalTests; i++) {
        createTestFolder(taskName, i);
    }
    compileSolution();
}

// Sao chép nội dung từ file nguồn sang file đích
void copyFileContents(const string& sourcePath, const string& destinationPath) {
    ifstream sourceFile(sourcePath);
    ofstream destinationFile(destinationPath);
    string line;
    while (getline(sourceFile, line)) {
        destinationFile << line << '\n';
    }
}
