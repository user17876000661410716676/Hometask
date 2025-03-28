@echo off
chcp 65001 > log
del log

set CPP_FILES="functions.cpp menu_fragments.cpp main.cpp"
set EXE=universities_list.exe
set CHARSET="-finput-charset=utf-8 -fexec-charset=utf-8"

if exist %EXE% del %EXE%

g++ "%CHARSET%" "%CPP_FILES%" -o %EXE%

%EXE%
