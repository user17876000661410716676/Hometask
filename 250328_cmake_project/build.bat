echo off

set BUILD_TYPE=Ninja
set BUILD_SUFFIX=ninja

chcp 65001

set BUILD_FOLDER=build_%BUILD_SUFFIX%
set PROJECT_FOLDER=project

if not exist %BUILD_FOLDER% mkdir %BUILD_FOLDER%
cd %BUILD_FOLDER% 

cmake -G %BUILD_TYPE% ..\%PROJECT_FOLDER%
cmake --build .

copy ..\%PROJECT_FOLDER%\universities_list\build_run_menu.bat .\build_run_menu

copy ..\run_tests.bat