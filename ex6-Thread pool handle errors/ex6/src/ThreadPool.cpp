//
// Created by mei on 25/01/17.
//

#include <pthread.h>
#include <unistd.h>
#include "ThreadPool.h"
static void *startJobs(void *arg) {
    ThreadPool *pool = (ThreadPool *)arg;
    pool->doJobs();
    return NULL;
}

void ThreadPool::doJobs() {
    while (!stop) {
        pthread_mutex_lock(&lock);
        if (!jobs_queue.empty()) {
            Job* job = jobs_queue.front();
            jobs_queue.pop();
            pthread_mutex_unlock(&lock);
            job->execute();

        } else {
            pthread_mutex_unlock(&lock);
            sleep(1);
        }
    }
    pthread_exit(NULL);
}

void ThreadPool::addJob(Job *job) {
    jobs_queue.push(job);
}

ThreadPool::ThreadPool(int threads_num) : threads_num(threads_num), stop(false) {
    threads = new pthread_t[threads_num];

    pthread_mutex_init(&lock, NULL);
    for (int i = 0; i < threads_num; i++) {
        pthread_create(threads + i, NULL, startJobs, this);
    }
}

void ThreadPool::terminate() {
    stop = true;
}

ThreadPool::~ThreadPool() {
    delete[] threads;
    pthread_mutex_destroy(&lock);
}

bool ThreadPool::isEmpty() {

}