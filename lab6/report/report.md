# _**Design Report:**_

## **Approach:**

- Any given process will be able to use Asynchronous execution (`FlexSC`) or Synchronous execution (usual one).

- If a process wishes to use `FlexSC` functionality it needs to register itself as a process who requires `FlexSC`.

- If the process is registered as `FlexSC_requireProc` then on execution whenever the process calls a `SYSCALL` it won't wait for `SYSCALL` to execute on the same core, but it'll go to a state `SYSCALLWAIT` and scheduler will start execution of another process on that CPU.

- And there will be a separate CPU reserved just to execute the `SYSCALLS`.

---

## **Implementation:**

- Threading library:
    We use [this](https://github.com/amay19970/uthreads) as the threading library for creating user-level threads. Some changes may be needed in this.

- Minor-Tweak: In `struct proc` we'll add  `bool FlexSC_requireProc` and value of `FlexSC_requireProc` can be set by a systemCall named `flexsc_register()`.

- Minor-Tweak: We'll add one more state `SYSCALLWAIT` in `enum procstate state` in `proc.h` which will help us segregate processes that are waiting for a syscall's return value from other processes.

- Feature-add: We'll implement `syscall_page` in the following way.
  
  - Create a new struct `syscall page` in `proc.c` to store the syscall entries which acts as shared memory therefore the syscall thread created will also have this entry.
  - Data Structure:

    ```c
    struct {
        struct spinlock lock;
        struct syscall_entry entries[NSYSCALL_ENTRY];
    } syscall_page;

    struct syscall_entry {
        int syscall_number;
        int status;
        int nargs;
        int args[7];
        int ret;
    };
    ```
    - In this status will have three states like {SUBMIT, DONE, BUSY}.

- Minor Tweak: In scheduler, we keep a flag, such that if no process is `RUNNABLE` then we set the flag to 1, and therefore calling `flexsc_wait()`.

---

## **Algorithm:**

- In the initial phase of process if it wants to execute in `FlexSC` manner then it'll call `flexsc_register()`.
- If `FlexSC_requireProc` is true then we'll go into executing the following.
  - Scheduler will start executing in all the CPUs, and it'll check the `cpuid`. If it is corresponding to the syscall reserved CPU then it'll only execute `SYSCALLS` and if it's other CPUs then it'll execute `USER-PROCESS`.
  - When a Process calls a `SYSCALL` it'll change its state to `SYSCALLWAIT`. And lets another process takeover (Scheduler will take care of it).
  - Other than that after a `SYSCALL` completes its execution it'll change the process-state to `RUNNABLE` again.
- Else Normal execution as it was implemented initially.

---

## **Test Cases:**

- We will call normal and `FlexSC` syscalls and verify their outputs and compare their execution time.
