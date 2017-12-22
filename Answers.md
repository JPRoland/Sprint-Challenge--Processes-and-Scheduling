      1. B 0 - 64000 for both, due to how memory allocation for forks is handled. Modern Unix variants use Copy-on-Write so the processes initially share the same data and the physical memory will not be copied until one of the processes tries to change the shared data, at which point it gets its own memory space. The first process to change the data is the one that is copied to a new memory space, so there's no way of knowing beforehand which process is going to get which chunk of memory.

      2. R - running or runable, the process is either currently active or is able to run when the CPU is ready to run it.

      D - uninterruptible sleep, generally means the process is doing a system call and cannot be interrupted or stopped until that system call completes.

      S - interruptible sleep, the process is waiting for a certain time or an event to occur, when that happens the process wakes up and runs.

      T - Stopped, the process is stopped and has given up all of its resources but remains in the process table until its parent process is notified.

      Z - Zombie, the process has been stopped and its parent process has been notified, but the process hasn't been removed from the process table. A process can be stuck in a zombie state if its parent process dies before the zombie process has been removed from the process table.

      3. On my machine write had an average running time of 1085ns while printf had an average running time of 329ns, with both calls printing a single character to the screen.

      4. printf runs faster than write because it is buffered. System calls come with some overhead, so limiting those system calls to only happen when a buffer has been filled will have the net effect of running faster.
