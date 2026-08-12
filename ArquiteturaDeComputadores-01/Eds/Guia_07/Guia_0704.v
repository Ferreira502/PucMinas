// ------------------------- 
// Guia_0704 - LU (OR, NOR, XOR, XNOR) 
// Nome: Gabriel Ferreira Pereira 
// Matricula: 842527 
// ------------------------- 

// ------------------------- 
// f10_gate = unidade lógica (gera as 4 portas) 
// ------------------------- 
module f10 (
    output s_or,
    output s_nor,
    output s_xor,
    output s_xnor,
    input  a,
    input  b
);

    or   OR1  (s_or,   a, b);
    nor  NOR1 (s_nor,  a, b);
    xor  XOR1 (s_xor,  a, b);
    xnor XNOR1(s_xnor, a, b);

endmodule // f10

// ------------------------- 
// mux 2x1 feito com portas
// ------------------------- 
module mux2 (
    output s,
    input  a,
    input  b,
    input  select
);
    wire not_select;
    wire sa, sb;

    not NOT1 (not_select, select);
    and AND1 (sa, a, not_select);
    and AND2 (sb, b, select);
    or  OR1  (s, sa, sb);
endmodule // mux2

// ------------------------- 
// mux 4x1 usando dois mux2
// ------------------------- 
module mux4 (
    output s,
    input  a,
    input  b,
    input  c,
    input  d,
    input  [1:0] select
);
    wire s0, s1;

    mux2 M1 (s0, a, b, select[0]);
    mux2 M2 (s1, c, d, select[0]); 

    mux2 M3 (s, s0, s1, select[1]);
endmodule // mux4

// ------------------------- 
// Teste
// ------------------------- 
module test_f10;
    // definir dados
    reg  x;
    reg  y;
    reg  [1:0] sel; 

    wire w_or;
    wire w_nor;
    wire w_xor;
    wire w_xnor;
    wire z;

    f10 modulo (w_or, w_nor, w_xor, w_xnor, x, y);

    mux4 MUX1 (z, w_nor, w_or, w_xor, w_xnor, sel);

    initial
    begin : main
        $display("Guia_0704 - Gabriel Ferreira Pereira - 842527");
        $display("Test LU's module (OR, NOR, XOR, XNOR)");
        $display("x y sel | OR NOR XOR XNOR | z");

        $monitor("%b %b  %2b |  %b   %b   %b    %b  | %b",
                  x, y, sel, w_or, w_nor, w_xor, w_xnor, z);

        x=0; y=0; sel=2'b00;