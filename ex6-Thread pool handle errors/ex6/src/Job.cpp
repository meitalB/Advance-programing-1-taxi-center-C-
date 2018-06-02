//
// Created by mei on 25/01/17.
//

#include "Job.h"

Job::Job(void *(*function)(void *args), void *arg): func(function), arg(arg) {

}

void Job::execute() {
    func(arg);
}

Job::~Job() {
}