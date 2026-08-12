// ---------------------------------------------
// Guia_0807.v
// Unidade Lógica (LU) - Comparador de Igualdade/Desigualdade (6 bits)
// Nome: Gabriel Ferreira Pereira
// Matrícula: 842527
// ---------------------------------------------
module Guia_0807 (
    output out,
    input [5:0] a, b,
    input sel
);
    wire [5:0] diff;
    wire neq, eq;

    // XOR bit a bit (detecta diferenças)
    xor (diff[0], a[0], b[0]);
    xor (diff[1], a[1], b[1]);
    xor (diff[2], a[2], b[2]);
    xor (diff[3], a[3], b[3]);
    xor (diff[4], a[4], b[4]);
    xor (diff[5], a[5], b[5]);

    // OR de todos os XOR → se algum bit é diferente => desigualdade
    or (neq, diff[0], diff[1], diff[2], diff[3], diff[4], diff[5]);

    // igualdade é o inverso
    not (eq, neq);

    // MUX: sel=0 => igualdade, sel=1 => desigualdade
    assign out = (sel == 1'b0) ? eq : neq;

endmodule

// -------------------------
// Testbench
// -------------------------
module test_Guia_0807;
    reg [5:0] x, y;
    reg sel;
    wire s;

    Guia_0807 dut (s, x, y, sel);

    initial begin
        $display("Guia_0807 - Teste comparador de 6 bits");
        $display(" a       b      sel => out");

        // Igualdade
        x = 6'b100101; y = 6'b100101; sel = 0; #1;
        $display("%b == %b, sel=%b => out=%b (igualdade)", x, y, sel, s);

        // Desigualdade
        x = 6'b100101; y = 6'b100111; sel = 1; #1;
        $display("%b != %b, sel=%b => out=%b (desigualdade)", x, y, sel, s);

        // Testando igualdade com sel=1
        x = 6'b111111; y = 6'b111111; sel = 1; #1;
        $display("%b == %b, sel=%b => out=%b (desigualdade esperado=0)", x, y, sel, s);

        // Testando desigualdade com sel=0
        x = 6'b000000; y = 6'b111111; sel = 0; #1;
        $display("%b != %b, sel=%b => out=%b (igualdade esperado=0)", x, y, sel, s);

        $finish;
    end
endmodule