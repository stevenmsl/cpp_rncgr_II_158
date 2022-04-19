#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol158;

/*
File file("abc");
Solution sol;
// Assume buf is allocated and guaranteed to have enough space for storing all characters from the file.
sol.read(buf, 1); // After calling your read method, buf should contain "a". We read a total of 1 character from the file, so return 1.
sol.read(buf, 2); // Now buf should contain "bc". We read a total of 2 characters from the file, so return 2.
sol.read(buf, 1); // We have reached the end of file, no more characters can be read. So return 0.
*/

void test1()
{
  cout << "test 1" << endl;
  char *buf = new char[3]; // just make sure the buf is big enough
  auto file = File("abc");
  cout << "Expect to see 1 -> " << to_string(file.read(buf, 1)) << endl;
  cout << "Expect to see a -> " << buf << endl;
  cout << "Expect to see 2 -> " << to_string(file.read(buf, 2)) << endl;
  cout << "Expect to see bc -> " << buf << endl;
  cout << "Expect to see 0 -> " << to_string(file.read(buf, 1)) << endl;
  cout << "Expect to see nothing ->" << buf << endl;
}

/*
File file("abc");
Solution sol;
sol.read(buf, 4); // After calling your read method, buf should contain "abc". We read a total of 3 characters from the file, so return 3.
sol.read(buf, 1); // We have reached the end of file, no more characters can be read. So return 0.
*/

void test2()
{
  cout << "test 2" << endl;
  char *buf = new char[3]; // just make sure the buf is big enough
  auto file = File("abc");
  cout << "Expect to see 3 -> " << to_string(file.read(buf, 4)) << endl;
  cout << "Expect to see abc -> " << buf << endl;
  cout << "Expect to see 0 -> " << to_string(file.read(buf, 1)) << endl;
  cout << "Expect to see nothing -> " << buf << endl;
}

/* test read4
File file("abcdefghijk"); // File is "abcdefghijk", initially file pointer (fp) points to 'a'
char[] buf = new char[4]; // Create buffer with enough space to store characters
read4(buf); // read4 returns 4. Now buf = "abcd", fp points to 'e'
read4(buf); // read4 returns 4. Now buf = "efgh", fp points to 'i'
read4(buf); // read4 returns 3. Now buf = "ijk", fp points to end of file
*/
void testRead4()
{
  auto file = File("abcdefghijk");
  char buffer[5];
  cout << "Expect to see 4" << endl;
  cout << to_string(file.read4(buffer)) << endl;
  cout << "Expect to see abcd" << endl;
  cout << buffer << endl;
  cout << "Expect to see 4" << endl;
  cout << to_string(file.read4(buffer)) << endl;
  cout << "Expect to see efgh" << endl;
  cout << buffer << endl;
  cout << "Expect to see 3" << endl;
  cout << to_string(file.read4(buffer)) << endl;
  cout << "Expect to see ijk" << endl;
  cout << buffer << endl;
}

main()
{
  test1();
  test2();
  // testRead4();
  return 0;
}