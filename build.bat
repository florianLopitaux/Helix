g++ .\template.cpp .\src\*.cpp .\src\graphics\*.cpp .\src\utils\*.cpp -o .\bin\template -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
cd .\bin
.\template.exe
cd ..