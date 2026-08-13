// -------------------------
// Guia_0804 - COMPARADOR DE DESIGUALDADE 5 BITS
// Nome: Gabriel Ferreira Pereira
// Matrícula: 842527
// -------------------------

// -------------------------
// comparador de desigualdade
// -------------------------
module notEqualComparator5 (
    output diferente,   // saída = 1 se x != y
    input [4:0] x,      // operando A
    input [4:0] y       // operando B
);
    wire [4:0] xor_bits; // XOR bit a bit

    // comparação bit a bit
    xor X0 (xor_bits[0], x[0], y[0]);
    xor X1 (xor_bits[1], x[1], y[1]);
    xor X2 (xor_bits[2], x[2], y[2]);
    xor X3 (xor_bits[3], x[3], y[3]);
    xor X4 (xor_bits[4], x[4], y[4]);

    // pelo menos um diferente? OR de todos os XORs
    or OR_final (diferente, xor_bits[0], xor_bits[1], xor_bits[2],
                               xor_bits[3], xor_bits[4]);
endmodule // notEqualComparator5

// -------------------------
// Testbench
// -------------------------
module test_notEqualComparator5;
    reg  [4:0] x;
    reg  [4:0] y;
    wire diferente;

    // instancia do comparador
    notEqualComparator5 COMP (diferente, x, y);

    initial begin
        $display("Guia_0804 - Gabriel Ferreira Pereira - 842527");
        $display("Testando comparador de desigualdade 5 bits\n");

        // testes
        x = 5'b00000; y = 5'b00000; #1;
        $display("%b != %b ? = %b", x, y, diferente);

        x = 5'b00001; y = 5'b00001; #1;
        $display("%b != %b ? = %b", x, y, diferente);

        x = 5'b00101; y = 5'b00111; #1;
        $display("%b != %b ? = %b", x, y, diferente);

        x = 5'b11111; y = 5'b01111; #1;
        $display("%b != %b ? = %b", x, y, diferente);

        x = 5'b10101; y = 5'b01010; #1;
        $display("%b != %b ? = %b", x, y, diferente);
    end
endmodule // test_notEqualComparator5