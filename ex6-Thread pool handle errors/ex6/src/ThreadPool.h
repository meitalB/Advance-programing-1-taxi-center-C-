//
// Created by mei on 25/01/17.
//

//#ifndef TAXI_CENTER_THREADPOOL_H
//#define TAXI_CENTER_THREADPOOL_H
//#endif //TAXI_CENTER_THREADPOOL_H
#ifndef THREADPOOL_H
#define THREADPOOL_H


#include <sys/types.h>
#include <queue>
#include "Job.h"

class ThreadPool {
private:
    std::queue<Job *> jobs_queue;
    int threads_num;
    pthread_t* threads;
    bool stop;
    pthread_mutex_t lock;
public:
    ThreadPool(int threads_num);
    void doJobs();
    void addJob(Job *job);
    void terminate();
    bool isEmpty();
    virtual ~ThreadPool();
};


#endif //TAXI_CENTER_THREADPOOL_H
