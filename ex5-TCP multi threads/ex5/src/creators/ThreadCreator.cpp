//
// Created by mei on 10/01/17.
//

#include <iostream>
#include "ThreadCreator.h"

pthread_t createThread(void *(*pFunc)(void *), void *args) {
    pthread_t ptId;
    int ret = pthread_create(&ptId, NULL, pFunc, args);
    if (ret != 0) {
        std::cout << " error in create thread! exited from the thread pool" << std::endl;
    }
    std::cout << " finish create thread! exited from the thread pool" << std::endl;
    return ptId;
}
