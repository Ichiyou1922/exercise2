#ifndef FILE_H
#define FILE_H

#include "list.h"

Task *load_tasks(const char *filename);

void save_tasks(const char *filename, Task *head);

#endif

