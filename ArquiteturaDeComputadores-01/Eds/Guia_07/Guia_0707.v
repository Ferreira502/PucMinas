// ------------------------- 
// Guia_0707 - Comparador de magnitude 4 bits
// Nome: Gabriel Ferreira Pereira 
// Matricula: 842527 
// ------------------------- 

// ------------------------- 
// comp4_mag = compara magnitude de 4 bits
// ------------------------- 
module comp4_mag (
    output maior,
    output menor,
    input  [3:0] a,
    input  [3:0] b
);
    wire nA3, nA2, nA1, nA0;
    wire nB3, nB2, nB1, nB0;

    not NOTA3(nA3, a[3]); not NOTA2(nA2, a[2]); not NOTA1(nA1, a[1]); not NOTA0(nA0, a[0]);
    not NOTB3(nB3, b[3]); not NOTB2(nB2, b[2]); not NOTB1(nB1, b[1]); not NOTB0(nB0, b[0]);

    wire m3, m2, m1, m0;

    and AND3(m3, a[3], nB3);
    wire eq3; and AND_EQ3(eq3, nA3, nB3);
    and AND2(m2, a[2], nB2, eq3);
    wire eq2; and AND_EQ2(eq2, eq3, nA2, nB2);
    and AND1(m1, a[1], nB1, eq2);
    wire eq1; and AND_EQ1(eq1, eq2, nA1, nB1);
    and AND0(m0, a[0], nB0, eq1);

    or OR_MAIOR(maior, m3, m2, m1, m0);

    wire n_maior; not NOT_M(n_maior, maior);
    and AND_MENOR(menor, n_maior, 1'b1); 
endmodule

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
    not NOT1(nsel, sel);
    and AND1(sa, a, nsel);
    and AND2(sb, b, sel);
    or  OR1(s, sa, sb);
endmodule

// ------------------------- 
// Testbench
// ------------------------- 
module test_comp4_mag;
    reg [3:0] x;
    reg [3:0] y;
    reg sel; 
    wire maior;
    wire menor;
    wire z;

    comp4_mag COMP (maior, menor, x, y);

    mux2 MUX1 (z, maior, menor, sel);

    initial
    begin : main
        $display("Guia_0707 - Gabriel Ferreira Pereira - 842527");
        $display("x    y    sel | maior menor | z");
        $monitor("%4b %4b  %b   | %b     %b    | %b", x, y, sel, maior, menor, z);

        // Testes
        sel = 0; // testar maior
        x = 4'b0000; y = 4'b0000; #1;
        x = 4'b1010; y = 4'b0101; #1;
        x = 4'b0110; y = 4'b1001; #1;
        x = 4'b1111; y = 4'b1110; #1;

        sel = 1; // testar menor
        x = 4'b0000; y = 4'b0000; #1;
        x = 4'b1010; y = 4'b0101; #1;
        x = 4'b0110; y = 4'b1001; #1;
        x = 4'b1111; y = 4'b1110; #1;
    end
endmodule