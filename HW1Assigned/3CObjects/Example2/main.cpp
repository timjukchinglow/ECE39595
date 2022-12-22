#include "HelloWorld.h"

int main(int argc, char* argv[ ]) {
   HelloWorld* hello1 = new HelloWorld("Sam");
   HelloWorld* hello2 = new HelloWorld("Mary");
   hello1->sayHello( );
   hello2->sayHello( );
   hello1 = hello2;
   hello1->sayHello( );
}
