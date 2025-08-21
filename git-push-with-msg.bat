@echo off
setlocal enabledelayedexpansion
title Git Push with Message

git rev-parse --is-inside-work-tree >nul 2>&1 || (
    echo [ERROR] 当前目录不是一个 Git 仓库
    pause
    exit /b 1
)

:: 输入 commit message
set /p msg=请输入 commit message（留空则使用默认）: 
if "%msg%"=="" set "msg=auto-commit %date:~0,4%-%date:~5,2%-%date:~8,2% %time:~0,2%:%time:~3,2%:%time:~6,2%"

echo.
echo ===== 开始执行 =====
git add -A
git commit -m "%msg%"
git push

echo.
echo ===== 完成！ =====
pause