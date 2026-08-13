// ------------------------- 
// Guia_0502.v - GATES 
// Nome: Gabriel Ferreira Pereira 
// Matricula: 842527 
// ------------------------- 

module f2a ( output s, 
             input  a, 
             input  b ); 
// descrever por portas NAND
   nand NAND1 (s, a, b); 
endmodule // f2a 

// ------------------------- 
// outra forma de implementar 
// ------------------------- 
module f2b ( output s, 
             input  a, 
             input  b ); 
// descrever por expressao
   assign s = ~(a & b); 
endmodule // f2b 


// ------------------------- 
// Teste dos módulos
// ------------------------- 
module test_f2; 
    // ------------------------- definir dados 
    reg  x; 
    reg  y; 
    wire a, b; 

    f2a moduloA ( a, x, y ); 
    f2b moduloB ( b, x, y ); 

    // ------------------------- parte principal 
    initial 
    begin : main 
        $display("Guia_0502 - Gabriel Ferreira Pereira - 842527"); 
        $display("Test module (~a | ~b)"); 
        $display("   x     y    a    b"); 

        // projetar testes do modulo 
        $monitor("%4b %4b %4b %4b", x, y, a, b); 

        x = 1'b0;  y = 1'b0; 
    #1  x = 1'b0;  y = 1'b1; 
    #1  x = 1'b1;  y = 1'b0; 
    #1  x = 1'b1;  y = 1'b1; 
    end 
endmodule // test_f2