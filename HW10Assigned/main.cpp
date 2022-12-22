#include <iostream>
#include <chrono>
#include <memory>
#include <mutex>
#include <thread>
#include "QuickSort.h"
#include "DotProduct.h"
#include "WorkQueue.h"

#define NUMSORTS 4
#define STARTSIZE 8000

using namespace std::chrono;


void worker(WorkQueue workQ) {
   std::shared_ptr<Command> c(workQ.get( ));
   while (c != nullptr) {
      c->execute( );
      static std::mutex outputLock;
      std::lock_guard<std::mutex> lck(outputLock); 
      c->identify( );
      c = workQ.get( );
   }
}


int main(int argc, char** args) {
   WorkQueue queue = WorkQueue( );
   int size = STARTSIZE;
   std::shared_ptr<Command> ptr;
   auto start = high_resolution_clock::now();
   for (int i = 0; i < NUMSORTS; i++) {
      ptr = std::make_shared<DotProduct>(size);
      queue.put(ptr);
      ptr = std::make_shared<QuickSort>(size);
      size *= 2;
   }

   std::vector<std::thread> tv;

   for (int i = 0; i < NUMSORTS; i++) {
      tv.push_back(std::thread(worker, queue));
   }

   for (auto &t : tv) {
      t.join();
   }

   auto stop = high_resolution_clock::now( );
   auto duration = duration_cast<microseconds>(stop - start).count( );
   std::cout << "execution time with 4 threads is " << duration << " microseconds\n";
}
