all:
    g++ -I src/include -L src/lib -o window window.cpp -lmingw32 -lSDL2main -lSDL2