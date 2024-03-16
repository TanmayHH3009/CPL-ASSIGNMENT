#include "symbolTable.h"

#define begin initialize_scope()
#define end finalize_scope()
#define assign(name, value) insert(name, value)
#define Print(name) printf("%s = %d\n", name, lookup(name, current_scope))
#define init initialize_scope0()

int main() {
    init;
        begin; 
            assign("a", 1);
            assign("b",2);
           
                begin; 
                    assign("a", 3);
                    assign("c", 4);
                    Print("b");
                        
                        begin;
                            assign("c", 5);
                            Print("b");
                            Print("a");
                            Print("c");
                        end;

                    Print("a");
                    Print("c");    

                end;

            Print("a");
                 
    end; 
    return 0;
}
