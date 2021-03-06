#include "mutex.h"
#include "hemalloc.h"

int malloc_mutex_init(malloc_mutex_t *mutex)
{
#if 1
    pthread_mutexattr_t attr;

    if (pthread_mutexattr_init(&attr) != 0)
        return (TRUE);
    pthread_mutexattr_settype(&attr, MALLOC_MUTEX_TYPE);
    if (pthread_mutex_init(&(mutex->lock), &attr) != 0) {
        pthread_mutexattr_destroy(&attr);
        return (TRUE);
    }
    pthread_mutexattr_destroy(&attr);
#endif
    return (OK);
}

void malloc_mutex_lock(malloc_mutex_t *mutex)
{
    pthread_mutex_lock(&(mutex->lock));
}

void malloc_mutex_unlock(malloc_mutex_t *mutex)
{
    pthread_mutex_unlock(&(mutex->lock));
}
