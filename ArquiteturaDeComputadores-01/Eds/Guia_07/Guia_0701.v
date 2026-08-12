// ------------------------- 
// Guia_0701 - LU (AND / NAND) 
// Nome: Gabriel Ferreira Pereira 
// Matricula: 842527 
// ------------------------- 

// ------------------------- 
// f7_gate = unidade lógica (AND e NAND) 
// ------------------------- 
module f7 ( 
    output s_and, 
    output s_nand, 
    input  a, 
    input  b 
); 
    and  AND1  (s_and,  a, b); 
    nand NAND1 (s_nand, a, b); 

endmodule // f7 

// ------------------------- 
//  multiplexer (2x1) 
// ------------------------- 
module mux ( 
    output s, 
    input  a, 
    input  b, 
    input  select 
); 

    wire not_select; 
    wire sa; 
    wire sb; 

    not NOT1 ( not_select, select ); 
    and AND1 ( sa, a, not_select ); 
    and AND2 ( sb, b,    select  ); 
    or  OR1  ( s , sa, sb ); 

endmodule // mux 

// ------------------------- 
// Teste 
// ------------------------- 
module test_f7; 
    // ------------------------- definir dados 
    reg  x; 
    reg  y; 
    reg  sel; 
    wire w_and; 
    wire w_nand; 
    wire z; 

    // instancia a unidade lógica 
    f7 modulo ( w_and, w_nand, x, y ); 

    // multiplexer para escolher saída única 
    mux MUX1 ( z, w_nand, w_and, sel ); 

    // ------------------------- parte principal 
    initial 
    begin : main 
        $display("Guia_0701 - Gabriel Ferreira Pereira - 842527"); 
        $display("Test LU's module (AND / NAND)"); 
        $display("   x   y   sel  | AND  NAND  Z"); 

        x = 1'b0; y = 1'b0; sel = 1'b0; 
        #1 $monitor("%4b %4b %4b  |  %4b   %4b   %4b", x, y, sel, w_and, w_nand, z); 
        
        #1 y = 1'b1; 
        #1 x = 1'b1; y = 1'b0; 
        #1 y = 1'b1; 
        #1 sel = 1'b1; x = 1'b0; y = 1'b0; 
        #1 y = 1'b1; 
        #1 x = 1'b1; y = 1'b0; 
        #1 y = 1'b1; 
    end 

endmodule // test_f7