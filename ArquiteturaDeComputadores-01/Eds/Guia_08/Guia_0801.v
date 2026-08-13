// -------------------------
// Guia_0801 - FULL ADDER 5 BITS
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
    // soma = XOR
    xor XOR1 (soma, a, b);
    // carry = AND
    and AND1 (carry, a, b);
endmodule // halfAdder

// -------------------------
// full adder (usando 2 half adders + OR)
// -------------------------
module fullAdder (
    output carryOut,
    output soma,
    input a,
    input b,
    input carryIn
);
    wire c1, c2, s1;

    // primeira meia-soma
    halfAdder HA1 (c1, s1, a, b);

    // segunda meia-soma (s1 + carryIn)
    halfAdder HA2 (c2, soma, s1, carryIn);

    // carry final
    or OR1 (carryOut, c1, c2);
endmodule // fullAdder

// -------------------------
// somador de 5 bits
// -------------------------
module adder5 (
    output [4:0] soma,    // resultado (5 bits)
    output carryOut,      // vai-um final
    input [4:0] x,        // operando A
    input [4:0] y         // operando B
);
    wire [4:0] carry; // sinais de "vai-um"

    // LSB com carryIn = 0
    fullAdder FA0 (carry[0], soma[0], x[0], y[0], 1'b0);

    // bits seguintes
    fullAdder FA1 (carry[1], soma[1], x[1], y[1], carry[0]);
    fullAdder FA2 (carry[2], soma[2], x[2], y[2], carry[1]);
    fullAdder FA3 (carry[3], soma[3], x[3], y[3], carry[2]);
    fullAdder FA4 (carryOut, soma[4], x[4], y[4], carry[3]);
endmodule // adder5

// -------------------------
// Testbench
// -------------------------
module test_adder5;
    reg  [4:0] x;
    reg  [4:0] y;
    wire [4:0] soma;
    wire carryOut;

    // instancia do somador
    adder5 ADD (soma, carryOut, x, y);

    initial begin
        $display("Guia_0801 - Gabriel Ferreira Pereira - 842527");
        $display("Testando Somador Completo de 5 bits\n");

        // casos de teste
        x = 5'b00001; y = 5'b00001; #1; 
        $display("%b + %b = %b (carry=%b)", x, y, soma, carryOut);

        x = 5'b00101; y = 5'b00011; #1;
        $display("%b + %b = %b (carry=%b)", x, y, soma, carryOut);

        x = 5'b11111; y = 5'b00001; #1;
        $display("%b + %b = %b (carry=%b)", x, y, soma, carryOut);

        x = 5'b10101; y = 5'b01011; #1;
        $display("%b + %b = %b (carry=%b)", x, y, soma, carryOut);

        x = 5'b11111; y = 5'b11111; #1;
        $display("%b + %b = %b (carry=%b)", x, y, soma, carryOut);
    end
endmodule // test_adder5