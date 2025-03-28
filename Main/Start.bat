@echo off
REM Biên dịch file Config.cpp thành Config.exe
g++ Config.cpp -o Config.exe

REM Kiểm tra lỗi biên dịch
IF ERRORLEVEL 1 (
    echo Biên dịch thất bại!
    pause
    exit /b
)

REM Chạy chương trình
echo Đang chạy chương trình...
Config.exe

pause
