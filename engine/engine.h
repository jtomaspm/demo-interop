#ifndef ENGINE_H
#define ENGINE_H

int start_engine();

int test(){
    static int t = 0;
    return t++;
}

#endif