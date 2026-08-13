// ------------------------- 
// Guia_0706 - Comparador 4 bits (XOR / XNOR) 
// Nome: Gabriel Ferreira Pereira 
// Matricula: 842527 
// ------------------------- 

// ------------------------- 
// comparador 4 bits
// ------------------------- 
module comp4 (
    output eq,      // igualdade
    output neq,     // desigualdade
    input  [3:0] a,
    input  [3:0] b
);
    wire w0, w1, w2, w3;

    xnor X0 (w0, a[0], b[0]);
    xnor X1 (w1, a[1], b[1]);
    xnor X2 (w2, a[2], b[2]);
    xnor X3 (w3, a[3], b[3]);

    and AND_EQ (eq, w0, w1, w2, w3);

    not NOT_NEQ (neq, eq);

endmodule // comp4

// ------------------------- 
// mux 2x1 usando portas
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
// Testbench
// ------------------------- 
module test_comp4;
    reg [3:0] x;
    reg [3:0] y;
    reg sel; // 0-igual, 1-diferente
    wire eq;
    wire neq;
    wire z;

    comp4 COM (eq, neq, x, y);

    mux2 MUX1 (z, eq, neq, sel);

    initial
    begin : main
        $display("Guia_0706 - Gabriel Ferreira Pereira - 842527");
        $display("x    y    sel | eq neq | z");
        $monitor("%4b %4b  %b   | %b  %b  | %b", x, y, sel, eq, neq, z);

        // Testes
        sel = 0; // testar igualdade
        x = 4'b0000; y = 4'b0000; #1;
        x = 4'b1010; y = 4'b1010; #1;
        x = 4'b1111; y = 4'b1111; #1;
        x = 4'b1010; y = 4'b0101; #1;

        sel = 1; // testar diferença
        x = 4'b0000; y = 4'b0000; #1;
        x = 4'b1010; y = 4'b1010; #1;
        x = 4'b1111; y = 4'b1110; #1;
        x = 4'b1010; y = 4'b0101; #1;
    end
endmodule