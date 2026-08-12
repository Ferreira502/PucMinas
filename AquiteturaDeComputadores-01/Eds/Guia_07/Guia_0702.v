// ------------------------- 
// Guia_0702 - LU (OR / NOR) 
// Nome: Gabriel Ferreira Pereira 
// Matricula: 842527 
// ------------------------- 

// ------------------------- 
// f8_gate = unidade lógica (OR e NOR) 
// ------------------------- 
module f8 ( 
    output s_or, 
    output s_nor, 
    input  a, 
    input  b 
); 

    // descrever por portas 
    or  OR1  (s_or,  a, b); 
    nor NOR1 (s_nor, a, b); 

endmodule // f8 

// ------------------------- 
//  multiplexer (2x1) 
// ------------------------- 
module mux ( 
    output s, 
    input  a, 
    input  b, 
    input  select 
); 

    // definir dados locais 
    wire not_select; 
    wire sa; 
    wire sb; 

    // descrever por portas 
    not NOT1 ( not_select, select ); 
    and AND1 ( sa, a, not_select ); 
    and AND2 ( sb, b,    select  ); 
    or  OR1  ( s , sa, sb ); 

endmodule // mux 

// ------------------------- 
// Teste 
// ------------------------- 
module test_f8; 
    // ------------------------- definir dados 
    reg  x; 
    reg  y; 
    reg  sel; 
    wire w_or; 
    wire w_nor; 
    wire z; 

    // instancia a unidade lógica 
    f8 modulo ( w_or, w_nor, x, y ); 

    // multiplexer para escolher saída única 
    mux MUX1 ( z, w_nor, w_or, sel ); 

    // ------------------------- parte principal 
    initial 
    begin : main 
        $display("Guia_0702 - Gabriel Ferreira Pereira - 842527"); 
        $display("Test LU's module (OR / NOR)"); 
        $display("   x   y   sel  |  OR   NOR   Z"); 

        // aplicar estímulos
        x = 1'b0; y = 1'b0; sel = 1'b0; 
        #1 $monitor("%4b %4b %4b  |  %4b    %4b    %4b", x, y, sel, w_or, w_nor, z); 
        
        #1 y = 1'b1; 
        #1 x = 1'b1; y = 1'b0; 
        #1 y = 1'b1; 
        #1 sel = 1'b1; x = 1'b0; y = 1'b0; 
        #1 y = 1'b1; 
        #1 x = 1'b1; y = 1'b0; 
        #1 y = 1'b1; 
    end 

endmodule // test_f8