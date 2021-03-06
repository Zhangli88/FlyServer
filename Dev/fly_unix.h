/********************************
system's method's package and other thing about system.

Author: Andrew lin
********************************/
#ifndef _FLY_UNIX_H
#define _FLY_UNIX_H

#include <errno.h>
#include "fly_core_file.h"

/* 
   noblocking recv mode, can't proved that read length bytes content.
   if recv return >= 0, we just return the number. 
   else if the error is EAGAIN, we return FLY_AGAIN; if EINTR, we recv again right away;
   other error we return FLY_ERROR. 

   EAGAIN means this time call is failed, maybe next time it will success
*/
int fly_recv(fly_connection_t *conn, fly_buf_t *buf, int length);

//the logic is same as fly_recv
int fly_send(fly_connection_t *conn, fly_buf_t *buf, int length);

//the length means that we want to read length bytes from fd and copy it to buf.
int fly_read(int fd, fly_buf_t *buf, int length);

int fly_write(int fd, fly_buf_t *buf, int length);

//return a file's total size, in bytes.
unsigned long fly_get_file_size(const char *path);

#endif