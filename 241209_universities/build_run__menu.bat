@echo off
chcp 1251 > log
del log

set CPP_FILES="menu_fragments.cpp functiones.cpp main.cpp"
set EXE=universities_list.exe
set CHARSET="-finput-charset=utf-8 -fexec-charset=windows-1251"

if exist %EXE% del %EXE%

g++ "%CHARSET%" "%CPP_FILES%" -o %EXE%

%EXE%
