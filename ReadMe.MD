#Demo for multi-thread openGL
This demo was created to show the performance comparison for single threaded game engine to multi threaded game engine.
##Models of multi thread game engine
Multithreaded engine aims to take use of multi core capacity of modern CPUs, which will increase the performance of game engine and make game runs more fluently.
There are two models of multi thread game engine, which has been used in game engine

1. Full multithreaded game engine, which means the main thread is used to process sync and control other worker thread, while the worker thread is used to do rendering, Physics, AI, audio etc
2. Main thread is used to process most work,but most computation extensive job are bring the other work threads.

Those two different models has their owns pros and cons

1. Most work are located in seperate thread, which means the fluency of game engine is not likely to be affected by game update and physics work. This model is hard to implement, which has beed used in commercial game engine for console and desktop platforms.
2. Try to move computation extensive job to work thread, the performance would be improved to a considerable extent.

##Demos
This simple demo is based on solution 2. To simplify the model, the demos contains:

1. Default openGL es rendering Demo created by IOS template.
2. Independent math computation, which will compute `acos` iteratively.

Three different situations are be considered in this demo.

1. single thread: the main thread is responsible for rendering and math computation
2. add one worker thread, the computation was mainly done by worker thread, if the computation cannot be finished, main thread will do the computation of the next frame
3. the situation is similar as 2, but with two worker thread added.

##Results
We test the performance on iPhone 4s, Here is the results:

1. The first row are the number of loopCount.
2. Two data are analyzed, fps and cpu percentage(worker thread will runs in an infinite loop if there is no work, it could be optimized by `std::condition`).

**The results suggested 50% performance gains if there is one worker thread and 80-90% for two.**

In order to gain performance improvements:

1. Computation should be independent, the less sync with main thread, the performance is better.
2. Multiple CPU are used to improve performance, could not be used for energe saving
3. The development and debugging could be harder.

##Notes
1. all the computation and multi thead logic are in TestComputation.cpp
2. MULTITHEAD ＝ 0 single thread, MULTITHEAD＝1 one work thread MULTITHEAD＝2 two worker thread
3.  const int loopCount = 1e4; loopCount of computation