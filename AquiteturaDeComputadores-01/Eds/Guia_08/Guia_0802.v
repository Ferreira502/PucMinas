// -------------------------
// Guia_0802 - FULL SUBTRACTOR 5 BITS
// Nome: Gabriel Ferreira Pereira
// Matrícula: 842527
// -------------------------

// -------------------------
// half subtractor
// -------------------------
module halfSubtractor (
    output borrow,
    output diff,
    input a,
    input b
);
    // diferença = a ⊕ b
    xor XOR1 (diff, a, b);

    // borrow = ~a & b
    wire notA;
    not NOT1 (notA, a);
    and AND1 (borrow, notA, b);
endmodule // halfSubtractor

// -------------------------
// full subtractor (usando 2 halfSub + OR)
// -------------------------
module fullSubtractor (
    output borrowOut,
    output diff,
    input a,
    input b,
    input borrowIn
);
    wire d1, b1, b2;

    // primeira meia-diferença
    halfSubtractor HS1 (b1, d1, a, b);

    // segunda meia-diferença (d1 - borrowIn)
    halfSubtractor HS2 (b2, diff, d1, borrowIn);

    // borrow final
    or OR1 (borrowOut, b1, b2);
endmodule // fullSubtractor

// -------------------------
// subtrator de 5 bits
// -------------------------
module subtractor5 (
    output [4:0] diff,     // resultado (5 bits)
    output borrowOut,      // vem-um final
    input [4:0] x,         // operando A
    input [4:0] y          // operando B
);
    wire [4:0] borrow; // sinais de "vem-um"

    // LSB com borrowIn = 0
    fullSubtractor FS0 (borrow[0], diff[0], x[0], y[0], 1'b0);

    // bits seguintes
    fullSubtractor FS1 (borrow[1], diff[1], x[1], y[1], borrow[0]);
    fullSubtractor FS2 (borrow[2], diff[2], x[2], y[2], borrow[1]);
    fullSubtractor FS3 (borrow[3], diff[3], x[3], y[3], borrow[2]);
    fullSubtractor FS4 (borrowOut, diff[4], x[4], y[4], borrow[3]);
endmodule // subtractor5

// -------------------------
// Testbench
// -------------------------
module test_subtractor5;
    reg  [4:0] x;
    reg  [4:0] y;
    wire [4:0] diff;
    wire borrowOut;

    // instancia do subtrator
    subtractor5 SUB (diff, borrowOut, x, y);

    initial begin
        $display("Guia_0802 - Gabriel Ferreira Pereira - 842527");
        $display("Testando Subtrator Completo de 5 bits\n");

        // casos de teste
        x = 5'b00001; y = 5'b00001; #1;
        $display("%b - %b = %b (borrow=%b)", x, y, diff, borrowOut);

        x = 5'b00101; y = 5'b00011; #1;
        $display("%b - %b = %b (borrow=%b)", x, y, diff, borrowOut);

        x = 5'b00011; y = 5'b00101; #1;
        $display("%b - %b = %b (borrow=%b)", x, y, diff, borrowOut);

        x = 5'b11111; y = 5'b00001; #1;
        $display("%b - %b = %b (borrow=%b)", x, y, diff, borrowOut);

        x = 5'b10101; y = 5'b01011; #1;
        $display("%b - %b = %b (borrow=%b)", x, y, diff, borrowOut);
    end
endmodule // test_subtractor5