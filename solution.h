
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;
namespace sol158
{
    class File
    {
    private:
        const char *buffer;
        int curIndx, N;

        /* buffer for the read method */
        char chunk[5];
        /* where we are at currently */
        int chunkIndx = 0;
        /* the total chars read from read4 the last time */
        int chunkSize = 0;

    public:
        File(string input) : buffer(input.c_str()), curIndx(0), N(input.size()){};
        int read4(char *buf);
        int read(char *buf, int n);
    };
}
#endif