//
// Created by mei on 10/01/17.
//

#include <iostream>
#include "ThreadCreator.h"
/*#include "../logging/easylogging++.h"*/

pthread_t createThread(void *(*pFunc)(void *), void *args) {
    pthread_t ptId;
    int ret = pthread_create(&ptId, NULL, pFunc, args);
    if (ret != 0) {
  /*      LOG(DEBUG) << "error in create thread! exited from the createThread";*/
    }
    /*LOG(DEBUG) << "finish create thread! exited from the createThread";*/
    return ptId;
}
