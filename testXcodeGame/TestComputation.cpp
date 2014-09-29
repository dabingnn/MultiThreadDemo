//
//  TestComputation.cpp
//  testXcodeGame
//
//  Created by Huabing.Xu on 9/28/14.
//  Copyright (c) 2014 Chukong. All rights reserved.
//

#include "TestComputation.h"
#include <math.h>
#include <thread>
#include <functional>
#include <list>

void calculateImp();
class Job
{
public:
    std::function<void()> job;
    void Do()
    {
        if(job != nullptr)
            job();
    }
};
float g_data;
std::mutex mutex;
std::list<Job> jobs;
void Dojob()
{
    while (true)
    {
        Job job;
        {
            std::lock_guard<std::mutex> lock(mutex);
            if(!jobs.empty())
            {
                job = jobs.front();
                jobs.pop_front();
            }
        }
        job.Do();
    }
}
#define MULTITHEAD 1
#if (MULTITHEAD > 0)
void calculateMatrix()
{
    static std::thread thread(Dojob);
#if (MULTITHEAD > 1)
    static std::thread thread2(Dojob);
#endif
    
    Job job;
    job.job = std::bind(calculateImp);
    bool isEmpty = false;
    {
        std::lock_guard<std::mutex> lock(mutex);
        isEmpty = jobs.empty();
        if(isEmpty)
            jobs.push_back(job);
    }
    
    if(!isEmpty) job.Do();
}
#else
void calculateMatrix()
{
    calculateImp();
}
#endif

void calculateImp()
{
    const int loopCount = 1e4;
    float value = 2.5;
    for (int loop = 0; loop < loopCount; ++loop)
    {
        value = acos(value);
    }
    
    g_data = value;
}