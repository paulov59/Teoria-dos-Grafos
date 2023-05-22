#ifndef UTILS_H
#define UTILS_H
using namespace std;

struct Argument {
  bool help = false;
  ostream* output = &cout;
  const char* input = NULL;
  bool solution = false;
  int initial = -1;
  int final = -1;
};

bool get_arguments(int argc, char** argv, Argument* args);
void help_arguments(string top_text, bool start = true, bool end = true);

#endif