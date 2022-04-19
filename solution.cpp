#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <set>
#include <cstring>
using namespace sol158;
using namespace std;

/*takeaways
  - the main difference between this and question 157
    is that here the read method needs to remember
    where it is at (index) and a its own buffer
    to store the chars read from the read4 method
  - in terms of implementation, copy one char at
    a time will make the logic way simpler than
    using the strncpy for copying

*/
int File::read(char *buf, int n)
{
  auto read = 0;
  while (read < n)
  {
    /* chucnk is empty; needs to read in more */
    if (chunkIndx == chunkSize)
    {
      chunkSize = read4(chunk);
      /* reset index and exit if there are no more chars
         to read
      */
      chunkIndx = 0;
      if (chunkSize == 0)
        break;
    }
    buf[read++] = chunk[chunkIndx++];
  }

  buf[read] = '\000';

  return read;
}

int File::read4(char *buf)
{
  if (curIndx >= N)
  {
    buf[0] = '\000';
    return 0;
  }
  auto chars = curIndx + 4 <= N ? 4 : N - curIndx;
  strncpy(buf, buffer + curIndx, chars);
  curIndx += chars;
  buf[chars] = '\000';
  return chars;
}