// POS52-C: Compliant Solution (Use a Nonblocking Call)

#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <stdint.h>
#include <pthread.h>

pthread_mutex_t mutex;

void thread_foo(void *ptr) {
  uint32_t num;
  int result;
  int sock;
 
  /* sock is a connected TCP socket */
 
  if ((result = recv(sock, (void *)&num, sizeof(uint32_t), O_NONBLOCK)) < 0) {
    /* Handle Error */
  }
 
  if ((result = pthread_mutex_lock(&mutex)) != 0) {
    /* Handle Error */
  }
 
  /* ... */
 
  if ((result = pthread_mutex_unlock(&mutex)) != 0) {
    /* Handle Error */
  }
}
