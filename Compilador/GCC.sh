#!/bin/bash
# Script to compile and execute a c program in one step.

gcc main.c FILES/files.c LEXICO/token.c LEXICO/lexico.c ADT/linked_list.c tableSymbols.c -o main && ./main



