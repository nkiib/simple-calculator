@echo off
if "%1"=="" (
    g++ -o tlsc -std=c++17 main.cpp --exec-charset=cp932 --input-charset=utf-8
) else (
    g++ -o %1 -std=c++17 main.cpp --exec-charset=cp932 --input-charset=utf-8
)
