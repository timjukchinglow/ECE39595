#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <memory>
#include "Line.h"
#include "InstructionBuffer.h"
#include "Start.h"
#include "Exit.h"
#include "Pushi.h"
#include "Printtos.h"
#include "Add.h"
#include "Prints.h"
#include "SymbolTable.h"
#include "Jump.h"
#include "Gosub.h"
#include "Gosublabel.h"
#include "SymbolTable.h"
#include "Label.h"
#include "Popscal.h"
#include "Pushscal.h"
#include "Returns.h"
#include "Data.h"
// #include "Stmt.h"
//#include "Instruction.h"
using namespace std;

string split(string str, char del){
   string temp = "";
   int finish = 0;
   
   for(int i=0; i<(int)str.size(); i++){
      if(str[i] != del && finish == 0){
         temp += str[i];
      }
      else{
         finish = 1;
      }
   }
   return temp;
}

template <typename T>
void remove(std::vector<T>& v, size_t pc) {
    v.erase(v.begin() + pc);
}

int split_num(string str, char del){
   string val;
   int start = 0;
   int ret_val = 0;
   
   for(int i=0; i<(int)str.size(); i++){
      if (start == 1) {
         if (str[i] != ' '){
            val += str[i];
         }
      }
      if(str[i] == del){
         start = 1;
      }
   }
   if (val.size() > 0){
      ret_val = stoi(val);
   }
   return ret_val;
}


int main(int argc, char* argv[]) {
   
   if(argc == 1){
      cout << "Please use\n\n$vm sourcefile\n";
      exit(0);
   }
   string sourcefile = argv[1];
   ifstream inFile(sourcefile);
   

   string str;
   string blah;
   string delim = " ";
   string inst, symb, value;

   vector<Line> allLines;

   std::map<std::string, std::string> op_codes = {
      {"jump", "OP_JUMP"},
      {"jumpzero", "OP_JUMPZERO"},
      {"jumpnzero", "OP_JUMPNZERO"},
      {"gosub", "OP_GOSUB"},
      {"return", "OP_RETURN"},
      {"gosublabel", "OP_ENTER_SUBROUTINE"},
      {"exitsublabel", "OP_EXIT_SUBROUTINE"},
      {"start", "OP_START_PROGRAM"},
      {"exit", "OP_EXIT_PROGRAM"},
      {"pushscal", "OP_PUSHSCALAR"},
      {"pusharr", "OP_PUSHARRAY"},
      {"pushi", "OP_PUSHI"},
      {"popscal", "OP_POPSCALAR"},
      {"poparr", "OP_POPARRAY"},
      {"pop", "OP_POP"},
      {"dup", "OP_DUP"},
      {"swap", "OP_SWAP"},
      {"add", "OP_ADD"},
      {"negate", "OP_NEGATE"},
      {"mul", "OP_MUL"},
      {"div", "OP_DIV"},
      {"prints", "OP_PRINTS"},
      {"printtos", "OP_PRINTTOS"}
   };
   std::vector<std::unique_ptr<Stmt>> instr;
   std::vector<int> runtime;
   std::vector<int> return_addr;
   std::vector<string> str_buff;
   std::vector<std::unique_ptr<Data>> data;
   int pc = 0;
   string temp_str;
   int temp_val;
   char space = ' ';
   int start_control = 0;
   while(getline(inFile, str)){
      temp_str = split(str, space);
      temp_val = split_num(str, space);
      // cout << temp_str << " " << temp_val << endl;
      if (temp_str == "Start") {
         start_control = 1;
      }
      if (start_control == 0) {
         str_buff.push_back((temp_str));
      }
      else {
         instr.push_back(std::move(std::unique_ptr<Stmt>(new Stmt(temp_str, temp_val))));
      }
   }
   sourcefile.pop_back();
   sourcefile.pop_back();
   sourcefile.pop_back();
   sourcefile.pop_back();
   sourcefile.pop_back();

   // START VM
   int finished = 0;
   int start = 0;
   int val1(0);
   int val2(0);
   int str_buff_size = 0;
   int ind = 0;
   int control = 0;
   int z = 0;
   while (finished == 0) {
      control += 1;
      if (start > 0) {
         ind = pc;
      }
      else {
         ind = pc;
      }
      auto &stmt = instr[ind];
      auto curr = stmt->getOpCode();
      int val = stmt->val;


      if (z < 300) {
         cout << curr << " " << stmt->val  << " " << ind << endl;
      }
      z++;



      // cout << ind << endl;
      // cout << "b4" << endl;
      // if (control < 14) {
      //       for (int k : runtime){
      //       cout << "Run " << curr << " " << k << " " << control << endl;
      //    }
      // }

      if (curr == "Start") {
         start = 1;
         str_buff_size = str_buff.size();
         int j = 0;
         while (j < val){
            data.push_back(std::move(std::unique_ptr<Data>(new Data())));
            j += 1;
         }
         // data.push_back(std::move(std::unique_ptr<Data>(new Data())));
         // for (string j : str_buff) {
         //    cout << j << endl;
         // }
      }
      // Check for String
      // if (start != 1) {
      //    str_buff.push_back((curr)); // Change the Prints stmt class value to address in str_buff stack
      // }

      if (curr == "PushI") {
         runtime.push_back(val);
      }

      if (curr == "Add") {
         if (!runtime.empty()) {
            int run_size = runtime.size();
            int val1 = runtime[run_size - 1];
            int val2 = runtime[run_size - 2];
            val1 += val2;
            runtime.pop_back();
            runtime.pop_back();
            runtime.push_back(val1);
         }
      }
      if  (curr == "Prints") {
         cout << str_buff[val] << endl;
         // for (string k : str_buff) {
         //    cout << k << endl;
         // }
         // remove(str_buff, val);
      }

      if (curr == "PrintTOS") {
         int run_size = runtime.size();
         int val1 = runtime[run_size - 1];
         runtime.pop_back();
         cout << val1 << endl;
      }
      if (curr == "Div") {
         int run_size = runtime.size();
         int val1 = runtime[run_size - 1];
         int val2 = runtime[run_size - 2];
         val1 /= val2;
         runtime.pop_back();
         runtime.pop_back();
         runtime.push_back(val1);
      }
      if (curr == "Dup") {
         runtime.push_back(runtime[runtime.size() - 1]);
      }
      if (curr == "Mul") {
         int run_size = runtime.size();
         int val1 = runtime[run_size - 1];
         int val2 = runtime[run_size - 2];
         val1 *= val2;
         runtime.pop_back();
         runtime.pop_back();
         runtime.push_back(val1);
      }
      if (curr == "Negate") {
         int run_size = runtime.size();
         int val1 = runtime[run_size - 1];
         val1 *= -1;
         runtime.pop_back();
         runtime.push_back(val1);
      }
      if (curr == "Pop") {
         runtime.pop_back();
      }
      if (curr == "Swap") {
         int run_size = runtime.size();
         int val1 = runtime[run_size - 1];
         int val2 = runtime[run_size - 2];
         runtime.pop_back();
         runtime.pop_back();
         runtime.push_back(val1);
         runtime.push_back(val2);

      }
      if (curr == "Jump") {
         pc = val - 1;
      }
      if (curr == "GoSubLabel") {
         int j = 0;
         while (j < val){
            data.push_back(std::move(std::unique_ptr<Data>(new Data())));
            j += 1;
         }
         data.push_back(std::move(std::unique_ptr<Data>(new Data())));
      }
      if (curr == "PopScalar") {
         // for (int j : runtime) {
         //    cout << j << endl;
         // }
         // cout << "size " << data.size() << endl;
         int run_size = runtime.size();
         // data_buff[val].second = to_string(runtime[run_size-1]);
         data[val]->vars.push_back(to_string(runtime[run_size-1]));
         runtime.pop_back();
      }
      if (curr == "PushScalar") {
         string temp_str = data[val]->vars[0];
         runtime.push_back(stoi(temp_str));
      }
      if (curr == "JumpZero") {
         int run_size = runtime.size();
         int temp = runtime[run_size-1];
         // cout << "b4" << endl;
         // for (int k : runtime){
         //    cout << "In JumpNZero " << k << " " << run_size << endl;
         // }
         runtime.erase(runtime.end() - 1);
         if (temp == 0) {
            pc = val - 1;
         }
      }
      if (curr == "JumpNZero") {
         int run_size = runtime.size();
         int temp = runtime[run_size-1];
         // cout << "b4" << endl;
         runtime.pop_back();
         if (temp != 0) {
            pc = val - 1;
         }
      }
      if (curr == "PopArray") {
         int run_size = runtime.size();
         int e = runtime[run_size-1];
         e += val;
         runtime.pop_back();
         int index = 0;
         // cout << index << " " << e << endl;
         while (index < e) {
            if (data[val]->vars.size() < e) {
               data[val]->vars.push_back("0");
            }
            index += 1;
         }
         run_size = runtime.size();
         data[val]->vars.push_back(to_string(runtime[run_size-1]));
         runtime.pop_back();
         // for (string k : data[val]->vars) {
         //    cout << "In array " << k << endl;
         // }
      }
      if (curr == "PushArray") {
         int run_size = runtime.size();
         int e = runtime[run_size-1];
         e += val;
         runtime.pop_back();
         runtime.push_back(stoi(data[val]->vars[e]));
      }
      if (curr == "GoSub") {
         return_addr.push_back(pc+1);
         pc = val;
      }
      else {
         pc += 1;
      }
      if (curr == "Return") {
         int return_size = return_addr.size();
         pc = return_addr[return_size-1];
         // cout << return_addr[return_size-1] << " " << pc << endl;
      }
      if (curr == "Exit") {
         finished = 1;
      }
      // for (int j : runtime) {
      //    cout << "Run stack " << j << endl;
      // }
   }
   inFile.close();
}
