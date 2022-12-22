#include <iostream>
#include <chrono>
#include <memory>
#include <mutex>
#include <thread>
#include "QuickSort.h"
#include "WorkQueue.h"
#include "DotProduct.h"
#include "Command.h"

#define NUMSORTS 4
#define STARTSIZE 8000

using namespace std::chrono;

void worker(WorkQueue workQ) {
   std::shared_ptr<Command> c(workQ.get( ));
   while (c != nullptr) {
      c->execute( );
      static mutex outputLock;
      std::lock_guard<std::mutex> lck(outputLock); 
      c->identify( );
      c = workQ.get( );
   }
}

int main(int argc, char **args)
{
   auto start = high_resolution_clock::now();
   WorkQueue queue = WorkQueue();
   int sortSize = STARTSIZE;
   for (int i=0; i<NUMSORTS; i++) {
      queue.put(std::make_shared<QuickSort>(sortSize));
      queue.put(std::make_shared<DotProduct>(sortSize));
      sortSize *=2;
   }

   thread t1(worker, queue);
   thread t2(worker, queue);
   thread t3(worker, queue);
   thread t4(worker, queue);
   t1.join();
   t2.join();
   t3.join();
   t4.join();
   auto stop = high_resolution_clock::now();
   auto duration = duration_cast<microseconds>(stop - start).count( );
   std::cout << "execution time with 4 threads is " << duration << " microseconds\n";
}