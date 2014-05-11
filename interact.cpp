#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]){
  if(argc < 2)return 0;
  ostringstream cmd;
  const char* sep = ";";
  bool fromstr = false;
  istringstream instr(argv[1]);
  cmd << "expect -c 'spawn ssh ";
  string line;
  int n = 0;
  while (getline(instr, line)){
    if(n++ == 0){
      cmd << line << sep 
      << "set prompt \">|:|#|\\\\\\$\"" << sep;
    }else{
      cmd << "interact -o -nobuffer -re $prompt return" << sep 
      << "send \"" << line << "\\r\"" << sep;
    }
  }
  cmd << "interact;'";
  const char* cmds = cmd.str().c_str();
  system(cmds);
  return 0;
}
