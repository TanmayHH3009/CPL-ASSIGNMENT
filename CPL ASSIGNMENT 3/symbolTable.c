#include"symbolTable.h"


int unsigned hash(char *s) {
    unsigned hashval = 0;
    for (; *s != '\0'; s++) {
        hashval = *s + 13 * hashval;
    }
    return hashval % HASH_SIZE;
}

int lookup(char *name, Scope *scope) {
    unsigned hashval = hash(name);
    Symbol *sym = scope->table[hashval];
    while (sym != NULL) {
        if (strcmp(sym->name, name) == 0) {
            return sym->value;
        }
        sym = sym->next;
    }

    if (scope->parent != NULL) {
        return lookup(name, scope->parent);
    }

    return -1; 
}

Symbol *insert(char *name, int value) {
    unsigned hashval = hash(name);
    Symbol *sym = (Symbol *)malloc(sizeof(Symbol));
    if (sym == NULL) {
        return NULL;
    }
    sym->name = strdup(name);
    if (sym->name == NULL) {
        free(sym);
        return NULL;
    }
    sym->value = value;
    sym->next = current_scope->table[hashval];
    current_scope->table[hashval] = sym;
    return sym;
}
void initialize_scope0(){
    current_scope = (Scope *)malloc(sizeof(Scope));
    
    current_scope->level = 0;
    current_scope->parent = NULL;
}

void initialize_scope() {
    Scope *new_scope = (Scope *)malloc(sizeof(Scope));
    if (new_scope == NULL) {
        return;
    }
    new_scope->level = current_scope->level + 1;
    new_scope->parent = current_scope;
    current_scope = new_scope;
}

void finalize_scope() {
    Scope *old_scope = current_scope;
    current_scope = current_scope->parent;
    free(old_scope);
}
