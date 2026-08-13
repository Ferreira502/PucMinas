// ------------------------- 
// Guia_0503.v - GATES 
// Nome: Gabriel Ferreira Pereira 
// Matricula: 842527 
// ------------------------- 

module f3a ( output s, 
             input  a, 
             input  b ); 
// definir dados locais
   wire not_a;
// descrever por portas NOR
   nor NOR1 (not_a, a, a);      
   nor NOR2 (s, not_a, b);  
endmodule // f3a 

// ------------------------- 
// outra forma de implementar 
// ------------------------- 
module f3b ( output s, 
             input  a, 
             input  b ); 
// descrever por expressao
   assign s = ~(~a | b); 
endmodule // f3b 


// ------------------------- 
// Teste dos módulos
// ------------------------- 
module test_f3; 
    // ------------------------- definir dados 
    reg  x; 
    reg  y; 
    wire a, b; 

    f3a moduloA ( a, x, y ); 
    f3b moduloB ( b, x, y ); 

    // ------------------------- parte principal 
    initial 
    begin : main 
        $display("Guia_0503 - Gabriel Ferreira Pereira - 842527"); 
        $display("Test module ~(~a | b)"); 
        $display("   x     y    a    b"); 

        // projetar testes do modulo 
        $monitor("%4b %4b %4b %4b", x, y, a, b); 

        x = 1'b0;  y = 1'b0; 
    #1  x = 1'b0;  y = 1'b1; 
    #1  x = 1'b1;  y = 1'b0; 
    #1  x = 1'b1;  y = 1'b1; 
    end 
endmodule // test_f3