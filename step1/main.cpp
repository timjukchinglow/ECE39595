#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <memory>
#include <string>
#include "Line.h"
#include "Negate.h"
#include "Dup.h"
#include "InstructionBuffer.h"
#include "Start.h"
#include "Exit.h"
#include "Pushi.h"
#include "Printtos.h"
#include "Add.h"
#include "Prints.h"
#include "SymbolTable.h"
#include "Jump.h"
#include "JumpZero.h"
#include "JumpNZero.h"
#include "Gosub.h"
#include "Gosublabel.h"
#include "SymbolTable.h"
#include "Label.h"
#include "Popscal.h"
#include "Pushscal.h"
#include "Poparr.h"
#include "Pusharr.h"
#include "Returns.h"
#include "Swap.h"
#include "Pop.h"
#include "Mul.h"
#include "Div.h"
// #include "Stmt.h"
//#include "Instruction.h"
using namespace std;

template <typename T>
void print_vector(std::vector<std::unique_ptr<T>> &vect, std::string sourcefile) {

   ofstream outFile(sourcefile + ".pout");

   for(auto &stmt: vect){
         auto curr = stmt->getOpCode();
         int val = stmt->val;
         if (curr == "Start ") {
            std::cout << *stmt << val << "\n";
            outFile << *stmt << val << "\n";
         }
         else if (curr == "GoSub ") {
            std::string label = stmt->label;
            std::cout << *stmt << label << "(" << val << ")" << "\n";
            outFile << *stmt << label << "(" << val << ")" << "\n";
         }
         else if (curr == "Jump, ") {
            std::string label = stmt->label;
            std::cout << *stmt << label << "\n";
            outFile << *stmt << label << "\n";
         }
         else if (curr == "JumpZero, ") {
            std::string label = stmt->label;
            std::cout << *stmt << label << ", (" << val << ")" << "\n";
            outFile << *stmt << label << ", (" << val << ")" << "\n";
         }
         else if (curr == "JumpNZero, ") {
            std::string label = stmt->label;
            std::cout << *stmt << label << ", (" << val << ")" << "\n";
            outFile << *stmt << label << ", (" << val << ")" << "\n";
         }
         else if (curr == "PopScalar ") {
            std::string label = stmt->label;
            int val = stmt->val;
            std::cout << *stmt << label << ", (" << val << ")" << "\n";
            outFile << *stmt << label << ", (" << val << ")" << "\n";
         }
         else if (curr == "PushScalar ") {
            std::string label = stmt->label;
            int val = stmt->val;
            std::cout << *stmt << label << ", (" << val << ")" << "\n";
            outFile << *stmt << label << ", (" << val << ")" << "\n";
         }
         else if (curr == "PopArray ") {
            std::string label = stmt->label;
            int val = stmt->val;
            std::cout << *stmt << label << ", (" << val << ")" << "\n";
            outFile << *stmt << label << ", (" << val << ")" << "\n";
         }
         else if (curr == "PushArray ") {
            std::string label = stmt->label;
            int val = stmt->val;
            std::cout << *stmt << label << ", (" << val << ")" << "\n";
            outFile << *stmt << label << ", (" << val << ")" << "\n";
         }
         else {
            std::cout << *stmt << "\n";
            outFile << *stmt << "\n";
         }
   }
   //std::cout << std::endl << "---------------" << std::endl;
   outFile.close();
}

template <typename T>
void update_start(std::vector<std::unique_ptr<T>> &vect, int i) {
   for(auto &stmt: vect){
         auto curr = stmt->getOpCode();
         if (curr == "Start ") {
            stmt->val = i;
            int val = stmt->val;
         }
   }
   std::cout << std::endl << "---------------" << std::endl;
}

template <typename T>
void update_sub(std::vector<std::unique_ptr<T>> &vect, int i) {
   for(auto &stmt: vect){
         auto curr = stmt->getOpCode();
         if (curr == "GoSub ") {
            stmt->val = i;
         }
   }
}

template <typename T>
void update_jump(std::vector<std::unique_ptr<T>> &vect, SymbolTable* sym) {
   for(auto &stmt: vect){
         auto curr = stmt->getOpCode();
         if (curr == "Jump, ") {
            for (auto const& x : sym->getSym()) {
               if (stmt->label == x.first) {
                  int temp = int(x.second.first);
                  stmt->label = std::to_string(temp);
               }
               //cout << x.first << " <" << x.second.first << ", " << x.second.second << "> " << stmt->label << "\n";
            }
            int val = stmt->val;
         }
         else if (curr == "JumpZero, ") {
            for (auto const& x : sym->getSym()) {
               if (stmt->label == x.first) {
                  int temp = int(x.second.first);
                  stmt->val = temp;
               }
               //cout << x.first << " <" << x.second.first << ", " << x.second.second << "> " << stmt->label << "\n";
            }
            int val = stmt->val;
         }
         else if (curr == "JumpNZero, ") {
            for (auto const& x : sym->getSym()) {
               if (stmt->label == x.first) {
                  int temp = int(x.second.first);
                  stmt->val = temp;
               }
               //cout << x.first << " <" << x.second.first << ", " << x.second.second << "> " << stmt->label << "\n";
            }
            int val = stmt->val;
         }
   }
}

// void determineStruct(std::vector<std::unique_ptr<Stmt>>& buff, Stmt stmt) {
   
// }

int main(int argc, char* argv[]) {
   
   if(argc == 1){
      cout << "Please use $./comp sourcefile\n";
      exit(0);
   }
   string sourcefile = argv[1];
   //cout << sourcefile <<"\n";
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
   SymbolTable* symTable = SymbolTable::getInstance();
   Instruct_Buff *instruct_buff = instruct_buff->getInstance();
   std::vector<std::unique_ptr<Stmt>> buff;
   int index = 0;
   int endFlag = 0;
   int mem = 0;
   int permMem = 0;
   int subroute = 0;
   int location = 0;
   while(getline(inFile, str)){

      Line newLine(str);
      allLines.push_back(newLine);

      std::string command = newLine.getCommand();
      std::string symbol = newLine.getSymbol();
      //cout << command << "\n";

      // This if statement determines if the given statement should be 
      // added to the instruction buffer or not
      if (command != "declscal" && command != "end" && command != "label" && command != "gosublabel" && command != "declarr" && command != "pop") {
         Stmt stmt(op_codes[command]);
         if (endFlag == 1){
            cout << "error: code encountered after an end statement" << "\n";
            ofstream outFile(sourcefile + ".pout");

            outFile << "error: code encountered after an end statement" << "\n";
            outFile.close();
            inFile.close();
            exit(0);
         }
         // determineStruct(buff, stmt);
         // buff.push_back(stmt);
         //cout << stmt.getOpCode() +"\n";
         if (stmt.getOpCode() == "OP_START_PROGRAM") {
            buff.push_back(std::move(std::unique_ptr<Start>(new Start(0))));
         }
         else if (stmt.getOpCode() == "OP_EXIT_PROGRAM") {
            buff.push_back(std::move(std::unique_ptr<Exit>(new Exit())));
         }
         else if (stmt.getOpCode() == "OP_PUSHI") {
            buff.push_back(std::move(std::unique_ptr<Pushi>(new Pushi(newLine.getSymbol()))));
         }
         else if (stmt.getOpCode() == "OP_PRINTTOS") {
            buff.push_back(std::move(std::unique_ptr<Printtos>(new Printtos())));
         }
         else if (stmt.getOpCode() == "OP_ADD") {
            buff.push_back(std::move(std::unique_ptr<Add>(new Add())));
         }
         else if (stmt.getOpCode() == "OP_MUL") {
            buff.push_back(std::move(std::unique_ptr<Mul>(new Mul())));
         }
         else if (stmt.getOpCode() == "OP_DIV") {
            buff.push_back(std::move(std::unique_ptr<Div>(new Div())));
         }
         else if (stmt.getOpCode() == "OP_DUP") {
            buff.push_back(std::move(std::unique_ptr<Dup>(new Dup())));
         }
         else if (stmt.getOpCode() == "OP_NEGATE") {
            buff.push_back(std::move(std::unique_ptr<Negate>(new Negate())));
         }
         else if (stmt.getOpCode() == "OP_PRINTS") {
            buff.push_back(std::move(std::unique_ptr<Prints>(new Prints(newLine.getSymbol()))));
         }
         else if (stmt.getOpCode() == "OP_JUMP") {
            buff.push_back(std::move(std::unique_ptr<Jump>(new Jump(newLine.getSymbol()))));
         }
         else if (stmt.getOpCode() == "OP_JUMPZERO") {
            buff.push_back(std::move(std::unique_ptr<JumpZero>(new JumpZero(newLine.getSymbol()))));
         }
         else if (stmt.getOpCode() == "OP_JUMPNZERO") {
            buff.push_back(std::move(std::unique_ptr<JumpNZero>(new JumpNZero(newLine.getSymbol()))));
         }
         else if (stmt.getOpCode() == "OP_ENTER_SUBROUTINE") {
            buff.push_back(std::move(std::unique_ptr<Gosublabel>(new Gosublabel(newLine.getSymbol()))));
         }
         else if (stmt.getOpCode() == "OP_GOSUB") {
            buff.push_back(std::move(std::unique_ptr<Gosub>(new Gosub(newLine.getSymbol()))));
         }
         else if (stmt.getOpCode() == "OP_SWAP") {
            buff.push_back(std::move(std::unique_ptr<Swap>(new Swap())));
         }
         
         else if (stmt.getOpCode() == "OP_POPSCALAR") {
            if (subroute == 1) {
               for (auto const& x : symTable->getSym2()) {
                  if (newLine.getSymbol() == x.first) {
                     std::string label = newLine.getSymbol();
                     int val = int(x.second.first);
                     buff.push_back(std::move(std::unique_ptr<Popscal>(new Popscal(label, val))));
                  }
               }
            }
            else {
               for (auto const& x : symTable->getSym()) {
                  if (newLine.getSymbol() == x.first) {
                     std::string label = newLine.getSymbol();
                     int val = int(x.second.first);
                     buff.push_back(std::move(std::unique_ptr<Popscal>(new Popscal(label, val))));
                  }
               }
            }
         }
         else if (stmt.getOpCode() == "OP_PUSHSCALAR") {
            if (subroute == 1) {
               for (auto const& x : symTable->getSym2()) {
                  if (newLine.getSymbol() == x.first) {
                     std::string label = newLine.getSymbol();
                     int val = int(x.second.first);
                     buff.push_back(std::move(std::unique_ptr<Pushscal>(new Pushscal(label, val))));
                  }
               }
            }
            else {
               for (auto const& x : symTable->getSym()) {
                  if (newLine.getSymbol() == x.first) {
                     std::string label = newLine.getSymbol();
                     int val = int(x.second.first);
                     buff.push_back(std::move(std::unique_ptr<Pushscal>(new Pushscal(label, val))));
                  }
               }
            }
         }
         else if (stmt.getOpCode() == "OP_POPARRAY") {
            if (subroute == 1) {
               for (auto const& x : symTable->getSym2()) {
                  if (newLine.getSymbol() == x.first) {
                     std::string label = newLine.getSymbol();
                     int val = int(x.second.first);
                     buff.push_back(std::move(std::unique_ptr<Poparr>(new Poparr(label, val))));
                  }
               }
            }
            else {
               for (auto const& x : symTable->getSym()) {
                  if (newLine.getSymbol() == x.first) {
                     std::string label = newLine.getSymbol();
                     int val = int(x.second.first);
                     buff.push_back(std::move(std::unique_ptr<Poparr>(new Poparr(label, val))));
                  }
               }
            }
         }
         else if (stmt.getOpCode() == "OP_PUSHARRAY") {
            if (subroute == 1) {
               for (auto const& x : symTable->getSym2()) {
                  if (newLine.getSymbol() == x.first) {
                     std::string label = newLine.getSymbol();
                     int val = int(x.second.first);
                     buff.push_back(std::move(std::unique_ptr<Pusharr>(new Pusharr(label, val))));
                  }
               }
            }
            else {
               for (auto const& x : symTable->getSym()) {
                  if (newLine.getSymbol() == x.first) {
                     std::string label = newLine.getSymbol();
                     int val = int(x.second.first);
                     buff.push_back(std::move(std::unique_ptr<Pusharr>(new Pusharr(label, val))));
                  }
               }
            }
         }
         else if (stmt.getOpCode() == "OP_RETURN") {
            buff.push_back(std::move(std::unique_ptr<Returns>(new Returns())));
            subroute = 0;
         }
      }
      else if (endFlag == 1) {
         cout << "error: code encountered after an end statement" << "\n";
         ofstream outFile(sourcefile + ".pout");
         outFile << "error: code encountered after an end statement" << "\n";
         outFile.close();
         inFile.close();
         exit(0);
      }
      else if (command == "declscal" && subroute == 0) {
         if (symTable->addLabel(symbol, mem, 1) == false) {
            ofstream outFile(sourcefile + ".pout");
            outFile << "error: attempting to add variable with name " << symbol << " twice" << "\n";
            std::cout << "error: attempting to add variable with name " << symbol << " twice" << "\n";
            outFile.close();
            inFile.close();
            exit(0);
         }
         mem += 1;
         permMem += 1;
         auto test = symTable->getData(symbol);
         //cout << symbol << " <" << test.first << ", " << test.second << ">\n";
      }
      else if (command == "declarr" && subroute == 0){
         int arrVal = stoi(newLine.getValue());
         if (symTable->addLabel(symbol, mem, arrVal) == false) {
            ofstream outFile(sourcefile + ".pout");
            outFile << "error: attempting to add variable with name " << symbol << " twice" << "\n";
            std::cout << "error: attempting to add variable with name " << symbol << " twice" << "\n";
            outFile.close();
            inFile.close();
            exit(0);
         }
         //symTable->addLabel(symbol, mem, arrVal);
         mem += arrVal;
         permMem += arrVal;
         auto test = symTable->getData(symbol);
         //cout << symbol << " <" << test.first << ", " << test.second << ">\n";
      }
      else if (command == "gosublabel") {
         subroute = 1;
         buff.push_back(std::move(std::unique_ptr<Gosublabel>(new Gosublabel(newLine.getSymbol()))));
         if (symTable->addLabel(symbol, index, 0) == false) {
            ofstream outFile(sourcefile + ".pout");
            outFile << "error: attempting to add variable with name " << symbol << " twice" << "\n";
            std::cout << "error: attempting to add variable with name " << symbol << " twice" << "\n";
            outFile.close();
            inFile.close();
            exit(0);
         }
         //symTable->addLabel(symbol, index, 0);
         auto test = symTable->getData(symbol);
         //cout << symbol << " <" << test.first << ", " << test.second << ">\n";
         location = index;
      }
      else if (command == "declscal" && subroute == 1) {
         if (symTable->addLabel2(symbol, mem, 1) == false) {
            ofstream outFile(sourcefile + ".pout");
            outFile << "error: attempting to add variable with name " << symbol << " twice" << "\n";
            std::cout << "error: attempting to add variable with name " << symbol << " twice" << "\n";
            outFile.close();
            inFile.close();
            exit(0);
         }
         //cout << "Adding symbol " << symbol << " with mem = " << mem << "\n";
         //symTable->addLabel2(symbol, mem, 1);
         mem += 1;
         auto test = symTable->getData2(symbol);
         //cout << symbol << " <" << test.first << ", " << test.second << ">\n";
      }
      else if (command == "declarr" && subroute == 1){
         int arrVal = stoi(newLine.getValue());
         if (symTable->addLabel2(symbol, mem, arrVal) == false) {
            ofstream outFile(sourcefile + ".pout");
            outFile << "error: attempting to add variable with name " << symbol << " twice" << "\n";
            std::cout << "error: attempting to add variable with name " << symbol << " twice" << "\n";
            outFile.close();
            inFile.close();
            exit(0);
         }
         //symTable->addLabel2(symbol, mem, arrVal);
         mem += arrVal;
         auto test = symTable->getData2(symbol);
         //cout << symbol << " <" << test.first << ", " << test.second << ">\n";
      }
      else if (command == "pop" && subroute == 1) {
         buff.push_back(std::move(std::unique_ptr<Pop>(new Pop())));
         if (symTable->addLabel(symbol, mem, 1) == false) {
            ofstream outFile(sourcefile + ".pout");
            outFile << "error: attempting to add variable with name " << symbol << " twice" << "\n";
            std::cout << "error: attempting to add variable with name " << symbol << " twice" << "\n";
            outFile.close();
            inFile.close();
            exit(0);
         }
         //symTable->addLabel2(symbol, mem, 1);
         auto test = symTable->getData2(symbol);
         //cout << symbol << " <" << test.first << ", " << test.second << ">\n";
      }
      else if (command == "pop" && subroute == 0) {
         buff.push_back(std::move(std::unique_ptr<Pop>(new Pop())));
         if (symTable->addLabel(symbol, mem, 1) == false) {
            ofstream outFile(sourcefile + ".pout");
            outFile << "error: attempting to add variable with name " << symbol << " twice" << "\n";
            std::cout << "error: attempting to add variable with name " << symbol << " twice" << "\n";
            outFile.close();
            inFile.close();
            exit(0);
         }
         //symTable->addLabel(symbol, mem, 1);
         auto test = symTable->getData(symbol);
         //cout << symbol << " <" << test.first << ", " << test.second << ">\n";
      }
      else if (command == "label") {
         if (subroute == 0) {
            if (symTable->addLabel(symbol, index, 0) == false) {
            ofstream outFile(sourcefile + ".pout");
            outFile << "error: attempting to add label with name " << symbol << " twice" << "\n";
            std::cout << "error: attempting to add label with name " << symbol << " twice" << "\n";
            outFile.close();
            inFile.close();
            exit(0);
            }
            //symTable->addLabel(symbol, index, 0);
            auto test = symTable->getData(symbol);
            //cout << index << " " << symbol << " <" << test.first << ", " << test.second << ">\n";
         }
      }
      else if (command == "end") {
         endFlag = 1;
      }
      if (command != "declarr" && command != "declscal" && command != "label") {
         index += 1;
      }
      
      
      
   }
   if (endFlag == 0) {
      cout << "error: no end statement in program" << "\n";
      ofstream outFile(sourcefile + ".pout");
      outFile << "error: no end statement in program" << "\n";
      outFile.close();
      inFile.close();
      exit(0);
   }
   update_start(buff, permMem);
   update_sub(buff, location);
   update_jump(buff, symTable);
   print_vector(buff, sourcefile);

   inFile.close();
}
