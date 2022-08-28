g++ .\src_templates\animatedSprite_template.cpp .\src\*.cpp .\src\graphics\*.cpp .\src\utils\*.cpp -o .\bin\animatedSprite_template -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
cd .\bin
.\animatedSprite_template.exe
cd ..
