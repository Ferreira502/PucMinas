// ---------------------------------------------
// Guia_0806.v
// Unidade Aritmética (AU) - soma/subtração + igualdade/desigualdade
// Nome: Gabriel Ferreira Pereira
// Matrícula: 842527
// ---------------------------------------------
module full_adder (
    output sum, carry_out,
    input a, b, carry_in
);
    wire axorb, aandb, candaxorb;

    xor (axorb, a, b);
    xor (sum, axorb, carry_in);

    and (aandb, a, b);
    and (candaxorb, axorb, carry_in);
    or  (carry_out, aandb, candaxorb);
endmodule

// Complemento de 1 (XOR condicional)
module conditional_inverter (
    output y,
    input x, sel
);
    // se sel=1 => inverte x
    // se sel=0 => mantém x
    xor (y, x, sel);
endmodule

// Unidade Aritmética com comparador de igualdade/desigualdade
module arithmetic_unit (
    output [5:0] result,   // resultado soma/subtração
    output eq,             // igualdade
    output neq,            // desigualdade
    input [5:0] a, b,      // operandos
    input carryIn          // 0=soma, 1=subtração
);
    wire [5:0] b_inv;      // B invertido condicional
    wire [5:0] sum;
    wire [5:0] xor_bits;
    wire carry[6:0];

    assign carry[0] = carryIn; // carry inicial define soma ou subtração

    // Inverter condicionalmente cada bit de B
    genvar i;
    generate
        for (i=0; i<6; i=i+1) begin : inverter
            conditional_inverter CI (b_inv[i], b[i], carryIn);
        end
    endgenerate

    // Somador completo de 6 bits
    generate
        for (i=0; i<6; i=i+1) begin : adder
            full_adder FA (sum[i], carry[i+1], a[i], b_inv[i], carry[i]);
        end
    endgenerate

    assign result = sum;

    // Comparador (igualdade e desigualdade)
    generate
        for (i=0; i<6; i=i+1) begin : comparator
            xor (xor_bits[i], a[i], b[i]);
        end
    endgenerate

    wire diff_any;
    or (diff_any, xor_bits[0], xor_bits[1], xor_bits[2], xor_bits[3], xor_bits[4], xor_bits[5]);

    not (eq, diff_any);  // igualdade = nenhum bit diferente
    assign neq = diff_any;

endmodule

// Top-level com chave de seleção
module Guia_0806 (
    output [5:0] out,
    input [5:0] a, b,
    input carryIn, sel
);
    wire [5:0] res;
    wire eq, neq;

    arithmetic_unit AU (res, eq, neq, a, b, carryIn);

    // Seleção da saída final
    // sel=0 => saída aritmética
    // sel=1 => igualdade/desigualdade codificada em 6 bits
    wire [5:0] cmp_out;
    assign cmp_out = {4'b0000, neq, eq}; // exemplo: bit1=neq, bit0=eq

    assign out = (sel == 1'b0) ? res : cmp_out;
endmodule

// -------------------------
// Testbench
// -------------------------
module test_Guia_0806;
    reg [5:0] x, y;
    reg carryIn, sel;
    wire [5:0] s;

    Guia_0806 dut (s, x, y, carryIn, sel);

    initial begin
        $display("Guia_0806 - Teste AU com comparador");
        $display(" a     b   carryIn sel  =>  out");

        // Soma
        x = 6'b000101; y = 6'b000011; carryIn = 0; sel = 0; #1;
        $display("%b + %b = %b", x, y, s);

        // Subtração
        x = 6'b000101; y = 6'b000011; carryIn = 1; sel = 0; #1;
        $display("%b - %b = %b", x, y, s);

        // Comparador Igualdade
        x = 6'b000101; y = 6'b000101; carryIn = 0; sel = 1; #1;
        $display("a=%b, b=%b => cmp_out=%b (eq=1, neq=0)", x, y, s);

        // Comparador Desigualdade
        x = 6'b000101; y = 6'b000111; carryIn = 0; sel = 1; #1;
        $display("a=%b, b=%b => cmp_out=%b (eq=0, neq=1)", x, y, s);

        $finish;
    end
endmodule