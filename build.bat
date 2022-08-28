g++ .\src_templates\basic_template.cpp .\src\*.cpp .\src\graphics\*.cpp .\src\utils\*.cpp -o .\bin\basic_template -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
cd .\bin
.\basic_template.exe
cd ..
