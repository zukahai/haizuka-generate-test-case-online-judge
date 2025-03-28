@echo off
REM Biên dịch file TGenerator.cpp thành TGenerator.exe
g++ TGenerator.cpp -o TGenerator.exe

REM Kiểm tra lỗi biên dịch
IF ERRORLEVEL 1 (
    echo Biên dịch thất bại!
    pause
    exit /b
)

REM Chạy chương trình
echo Đã tạo thử input...
TGenerator.exe

pause
