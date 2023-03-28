#!/bin/bash

cmd1= "cat"
cmd2= "wc -w"
file1= file1.txt
file2= file2.txt

./pipex $(file2) $(cmd1) $(cmd2) $(file2)