//
// Created by mei on 25/01/17.
//

#ifndef TAXI_CENTER_JOB_H
#define TAXI_CENTER_JOB_H


class Job {
private:
    void *arg;
    void * (*func)(void *arg);
public:
    Job(void * (*function)(void *args), void* arg);
    void execute();
    virtual ~Job();
};

#endif //TAXI_CENTER_JOB_H
