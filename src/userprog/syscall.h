#ifndef USERPROG_SYSCALL_H
#define USERPROG_SYSCALL_H

void syscall_init (void);
void syscall_exit (int);

#endif /* userprog/syscall.h */

struct lock syscall_lock;
