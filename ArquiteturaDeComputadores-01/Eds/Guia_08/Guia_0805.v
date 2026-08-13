// -------------------------
// Guia_0805 - COMPLEMENTO DE 2 (5 BITS)
// Nome: Gabriel Ferreira Pereira
// Matrícula: 842527
// -------------------------

// -------------------------
// half adder
// -------------------------
module halfAdder (
    output carry,
    output soma,
    input a,
    input b
);
    xor XOR1 (soma, a, b);
    and AND1 (carry, a, b);
endmodule // halfAdder

// -------------------------
// full adder
// -------------------------
module fullAdder (
    output carryOut,
    output soma,
    input a,
    input b,
    input carryIn
);
    wire s1, c1, c2;

    halfAdder HA1 (c1, s1, a, b);
    halfAdder HA2 (c2, soma, s1, carryIn);
    or OR1 (carryOut, c1, c2);
endmodule // fullAdder

// -------------------------
// complemento de 1 (bit a bit)
// -------------------------
module onesComplement5 (
    output [4:0] out,
    input [4:0] in
);
    not N0 (out[0], in[0]);
    not N1 (out[1], in[1]);
    not N2 (out[2], in[2]);
    not N3 (out[3], in[3]);
    not N4 (out[4], in[4]);
endmodule // onesComplement5

// -------------------------
// complemento de 2 (usa complemento de 1 + somador +1)
// -------------------------
module twosComplement5 (
    output [4:0] out,
    output carryOut,
    input [4:0] in
);
    wire [4:0] comp1;   // complemento de 1
    wire [4:0] soma;    // resultado da soma
    wire [4:0] carry;   // vai-uns

    // complemento de 1
    onesComplement5 OC (comp1, in);

    // soma (comp1 + 1)
    fullAdder FA0 (carry[0], soma[0], comp1[0], 1'b1, 1'b0); // adiciona +1
    fullAdder FA1 (carry[1], soma[1], comp1[1], 1'b0, carry[0]);
    fullAdder FA2 (carry[2], soma[2], comp1[2], 1'b0, carry[1]);
    fullAdder FA3 (carry[3], soma[3], comp1[3], 1'b0, carry[2]);
    fullAdder FA4 (carryOut, soma[4], comp1[4], 1'b0, carry[3]);

    assign out = soma;
endmodule // twosComplement5

// -------------------------
// Testbench
// -------------------------
module test_twosComplement5;
    reg  [4:0] x;
    wire [4:0] out;
    wire carryOut;

    // instancia do complemento de 2
    twosComplement5 TCOMP (out, carryOut, x);

    initial begin
        $display("Guia_0805 - Gabriel Ferreira Pereira - 842527");
        $display("Testando complemento de 2 (5 bits)\n");

        x = 5'b00000; #1;
        $display("in = %b -> 2's complement = %b (carry=%b)", x, out, carryOut);

        x = 5'b00001; #1;
        $display("in = %b -> 2's complement = %b (carry=%b)", x, out, carryOut);

        x = 5'b00101; #1;
        $display("in = %b -> 2's complement = %b (carry=%b)", x, out, carryOut);

        x = 5'b01111; #1;
        $display("in = %b -> 2's complement = %b (carry=%b)", x, out, carryOut);

        x = 5'b11111; #1;
        $display("in = %b -> 2's complement = %b (carry=%b)", x, out, carryOut);
    end
endmodule // test_twosComplement5