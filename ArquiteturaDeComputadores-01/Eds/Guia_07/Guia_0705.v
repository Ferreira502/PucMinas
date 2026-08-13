// ------------------------- 
// Guia_0705 - LU (NOT, AND, NAND, OR, NOR, XOR, XNOR) 
// Nome: Gabriel Ferreira Pereira 
// Matricula: 842527 
// ------------------------- 

// ------------------------- 
// f11_gate = gera todas as operações
// ------------------------- 
module f11 (
    output s_not,
    output s_and,
    output s_nand,
    output s_or,
    output s_nor,
    output s_xor,
    output s_xnor,
    input  a,
    input  b,
    input  neg_b // chave extra para negação de b
);

    wire b_eff;
    not NOTB (b_eff, b);         // b efetivo invertido se necessário
    wire b_use;
    and AND1 (b_use, b, ~neg_b); // se neg_b=0, b_use=b; se neg_b=1, b_use=0
    or  ORB (b_use, b_eff, neg_b); // simplificação: b_use = neg_b ? ~b : b

    // operações
    not  NOT1  (s_not, a);
    and  AND2  (s_and, a, b_use);
    nand NAND2(s_nand, a, b_use);
    or   OR2   (s_or, a, b_use);
    nor  NOR2  (s_nor, a, b_use);
    xor  XOR2  (s_xor, a, b_use);
    xnor XNOR2 (s_xnor, a, b_use);

endmodule // f11

// ------------------------- 
// mux2 = 2x1 com portas
// ------------------------- 
module mux2 (
    output s,
    input  a,
    input  b,
    input  sel
);
    wire nsel, sa, sb;
    not NOT1 (nsel, sel);
    and AND1 (sa, a, nsel);
    and AND2 (sb, b, sel);
    or  OR1  (s, sa, sb);
endmodule // mux2

// ------------------------- 
// mux4 = 4x1 usando mux2
// ------------------------- 
module mux4 (
    output s,
    input  a,
    input  b,
    input  c,
    input  d,
    input  [1:0] sel
);
    wire s0, s1;
    mux2 M1 (s0, a, b, sel[0]);
    mux2 M2 (s1, c, d, sel[0]);
    mux2 M3 (s, s0, s1, sel[1]);
endmodule // mux4

// ------------------------- 
// mux8 = 8x1 usando mux4 e mux2
// ------------------------- 
module mux8 (
    output s,
    input  [7:0] data,
    input  [2:0] sel
);
    wire s_low, s_high;
    mux4 M_LOW  (s_low,  data[0], data[1], data[2], data[3], sel[1:0]);
    mux4 M_HIGH (s_high, data[4], data[5], data[6], data[7], sel[1:0]);
    mux2 M_TOP  (s, s_low, s_high, sel[2]);
endmodule // mux8

// ------------------------- 
// Testbench
// ------------------------- 
module test_f11;
    reg  x;
    reg  y;
    reg  neg_b;
    reg  [2:0] sel;
    wire s_not;
    wire s_and;
    wire s_nand;
    wire s_or;
    wire s_nor;
    wire s_xor;
    wire s_xnor;
    wire z;

    f11 LU (s_not, s_and, s_nand, s_or, s_nor, s_xor, s_xnor, x, y, neg_b);

    wire [7:0] data;
    assign data = {s_xnor, s_xor, s_nor, s_or, s_nand, s_and, s_not, 1'b0}; 
    // 7 operações + 1 filler (não usado)

    mux8 MUX_FINAL (z, data, sel);

    initial
    begin : main
        $display("Guia_0705 - Gabriel Ferreira Pereira - 842527");
        $display("x y neg_b sel | NOT AND NAND OR NOR XOR XNOR | z");
        $monitor("%b %b   %b    %3b |  %b   %b    %b   %b   %b   %b    %b  | %b",
                  x, y, neg_b, sel, s_not, s_and, s_nand, s_or, s_nor, s_xor, s_xnor, z);

        // exemplos de teste
        x=0; y=0; neg_b=0; sel=3'b000; #1;
        x=0; y=1; sel=3'b001; #1;
        x=1; y=0; sel=3'b010; #1;
        x=1; y=1; sel=3'b011; #1;

        sel=3'b100; #1;
        sel=3'b101; #1;
        sel=3'b110; #1;
        sel=3'b111; #1;
    end
endmodule