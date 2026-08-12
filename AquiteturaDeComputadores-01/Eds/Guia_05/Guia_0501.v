// ------------------------- 
// Guia_0501.v - GATES 
// Nome: Gabriel Ferreira Pereira 
// Matricula: 842527 
// ------------------------- 

module f1a ( output s, 
             input  a, 
             input  b ); 
// descrever por portas NOR
   nor NOR1 (s, a, b); 
endmodule // f1a 

// ------------------------- 
// outra forma de implementar 
// ------------------------- 
module f1b ( output s, 
             input  a, 
             input  b ); 
// descrever por expressao com operador nor
   assign s = ~(a | b); 
endmodule // f1b 


// ------------------------- 
// Teste dos módulos
// ------------------------- 
module test_f1; 
    // ------------------------- definir dados 
    reg  x; 
    reg  y; 
    wire a, b; 

    f1a moduloA ( a, x, y ); 
    f1b moduloB ( b, x, y ); 

    // ------------------------- parte principal 
    initial 
    begin : main 
        $display("Guia_0501 - Gabriel Ferreira Pereira - 842527"); 
        $display("Test module (~a & ~b)"); 
        $display("   x     y    a    b"); 

        // projetar testes do modulo 
        $monitor("%4b %4b %4b %4b", x, y, a, b); 

        x = 1'b0;  y = 1'b0; 
    #1  x = 1'b0;  y = 1'b1; 
    #1  x = 1'b1;  y = 1'b0; 
    #1  x = 1'b1;  y = 1'b1; 
    end 
endmodule // test_f1