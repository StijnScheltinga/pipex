# Pipex – Rebuilding Unix Pipelines in C

Pipex is a systems programming project in the 42 curriculum that focuses on recreating the behavior of Unix shell pipelines. The goal is to understand how processes, pipes, file descriptors, and I/O redirection work under the hood—by rebuilding it from scratch in C.

# What It Does

Pipex mimics the shell behavior for commands like `< infile cmd1 | cmd2 > outfile`

It involves:
- Using fork(), execve(), and pipe() to create a chain of processes.
- Redirecting standard input and output using dup2().
- Managing file access, including reading input from a file and writing the final output to another.
- Resolving command paths using the system’s $PATH.
- Handling multiple commands and error cases.

Pipex is a great introduction to how the shell and operating system interact—and builds a strong foundation for more complex projects like Minishell and Webserv.
