// -------------------------
// Guia_0803 - COMPARADOR DE IGUALDADE 6 BITS
// Nome: Gabriel Ferreira Pereira
// Matrícula: 842527
// -------------------------

// -------------------------
// comparador de igualdade
// -------------------------
module equalComparator6 (
    output igual,       // saída = 1 se x == y
    input [5:0] x,      // operando A
    input [5:0] y       // operando B
);
    wire [5:0] eq_bits; // XNOR bit a bit

    // comparação bit a bit
    xnor X0 (eq_bits[0], x[0], y[0]);
    xnor X1 (eq_bits[1], x[1], y[1]);
    xnor X2 (eq_bits[2], x[2], y[2]);
    xnor X3 (eq_bits[3], x[3], y[3]);
    xnor X4 (eq_bits[4], x[4], y[4]);
    xnor X5 (eq_bits[5], x[5], y[5]);

    // todos iguais? AND de todos os XNOR
    and AND_final (igual, eq_bits[0], eq_bits[1], eq_bits[2],
                             eq_bits[3], eq_bits[4], eq_bits[5]);
endmodule // equalComparator6

// -------------------------
// Testbench
// -------------------------
module test_equalComparator6;
    reg  [5:0] x;
    reg  [5:0] y;
    wire igual;

    // instancia do comparador
    equalComparator6 COMP (igual, x, y);

    initial begin
        $display("Guia_0803 - Gabriel Ferreira Pereira - 842527");
        $display("Testando comparador de igualdade 6 bits\n");

        // testes
        x = 6'b000000; y = 6'b000000; #1;
        $display("%b == %b ? = %b", x, y, igual);

        x = 6'b000001; y = 6'b000001; #1;
        $display("%b == %b ? = %b", x, y, igual);

        x = 6'b001011; y = 6'b001011; #1;
        $display("%b == %b ? = %b", x, y, igual);

        x = 6'b101010; y = 6'b101011; #1;
        $display("%b == %b ? = %b", x, y, igual);

        x = 6'b111111; y = 6'b111111; #1;
        $display("%b == %b ? = %b", x, y, igual);

        x = 6'b110011; y = 6'b101011; #1;
        $display("%b == %b ? = %b", x, y, igual);
    end
endmodule // test_equalComparator6