#include "graminit.h"
#include "CharStream.hpp"
#include <iostream>
#include "llvm/ADT/STLExtras.h"

std::unique_ptr<CharStream> cs;

static int gettok(){

    static int lastChar = ' ';

    while (isspace(lastChar)) {
        cs->next();
        lastChar = cs->getCurrent();
    }

    if (lastChar == '#'){
        cout << "read a comment\n";
        do {
            cs->next();
            lastChar = cs->getCurrent();
        } while (lastChar != EOF && lastChar != '\n' && lastChar != '\r');
    }

    if (lastChar == EOF) {
        return eof_tok;
    }

    int thisChar = lastChar;
    cs->next();
    lastChar = cs->getCurrent();
    return thisChar;
}

static int CurTok;
static int getNextToken() {
    return CurTok = gettok();
}

int main(int argc, char **argv){
    bool help = false;
    string helpMsg = "Options: --help\n";
    string helpFlag("--help");

    // checking for flags
    for (int i = 0; i < argc; i++){
        char* arg = argv[i];
        if (arg == helpFlag){
            help = true;
        }
    }

    if (help){
        std::cout << helpMsg;
        exit(1);
    }

    char* filename = argv[argc - 1];

    // Create character stream
    cs = llvm::make_unique<CharStream>(filename);
    cout << "Created character stream\n";
    getNextToken();

    return 0;
}
