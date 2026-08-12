// ------------------------- 
// Guia_1301
// Nome: Gabriel Ferreira Pereira
// Matricula: 842527 
// ------------------------- 

module jk_ff (
    input j, k, clk, clear,
    output reg q
);
    always @(negedge clk or posedge clear)
    begin
        if (clear)
            q <= 1'b1; // inicia em 1 para decrescer
        else if (j & ~k)
            q <= 1'b1;
        else if (~j & k)
            q <= 1'b0;
        else if (j & k)
            q <= ~q;
    end
endmodule


module down_counter_5bit (
    input clk,
    input clear,
    output [4:0] q
);
    wire q0, q1, q2, q3, q4;

    // Flip-flops
    jk_ff FF0 (1'b1, 1'b1, clk,   clear, q0);
    jk_ff FF1 (1'b1, 1'b1, q0,    clear, q1);
    jk_ff FF2 (1'b1, 1'b1, q1,    clear, q2);
    jk_ff FF3 (1'b1, 1'b1, q2,    clear, q3);
    jk_ff FF4 (1'b1, 1'b1, q3,    clear, q4);

    assign q = {q4, q3, q2, q1, q0};

endmodule
