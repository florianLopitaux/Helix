@echo off
:: clean old compiled file
IF EXIST ".\lib\libHelix.a" del /f ".\lib\libHelix.a"

:: build object files
g++ -c .\helix\src\exceptions\*.cpp -std=c++17 -I .\include\ -L .\lib\ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
g++ -c .\helix\src\mathutils\*.cpp -std=c++17 -I .\include\ -L .\lib\ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
g++ -c .\helix\src\graphics.cpp -std=c++17 -I .\include\ -L .\lib\ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
g++ -c .\helix\src\*.cpp -std=c++17 -I .\include\ -L .\lib\ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

:: build library
ar -cqs .\lib\libHelix.a .\*.o

:: clean object files
del /f ".\*.o"
