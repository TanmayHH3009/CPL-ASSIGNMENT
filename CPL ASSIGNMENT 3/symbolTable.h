#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 101

typedef struct Symbol {
    char *name;
    int value;
    struct Symbol *next;
} Symbol;

typedef struct Scope {
    int level;
    Symbol *table[HASH_SIZE];
    struct Scope *parent;
} Scope;

Scope *current_scope;

unsigned hash(char *s);

int lookup(char *name, Scope *scope);

Symbol *insert(char *name, int value);

void initialize_scope();

void initialize_scope0();

void finalize_scope();