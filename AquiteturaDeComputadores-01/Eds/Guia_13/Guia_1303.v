// ------------------------- 
// Guia_1303
// Nome: Gabriel Ferreira Pereira
// Matricula: 842527 
// ------------------------- 

module jk_ff (
    input J, K, clk, clr,
    output reg Q
);
    always @(negedge clk or posedge clr) begin
        if (clr)
            Q <= 0;
        else if (J & ~K)
            Q <= 1;
        else if (~J & K)
            Q <= 0;
        else if (J & K)
            Q <= ~Q;
    end
endmodule

module contador_decadico_6bit (
    input clk,
    output [5:0] Q
);
    wire clr;
    wire q0, q1, q2, q3, q4, q5;

    assign clr = (q3 & ~q2 & q1 & ~q0);

    jk_ff FF0 (1'b1, 1'b1, clk, clr, q0);
    jk_ff FF1 (1'b1, 1'b1, q0, clr, q1);
    jk_ff FF2 (1'b1, 1'b1, q1, clr, q2);
    jk_ff FF3 (1'b1, 1'b1, q2, clr, q3);
    jk_ff FF4 (1'b1, 1'b1, q3, clr, q4);
    jk_ff FF5 (1'b1, 1'b1, q4, clr, q5);

    assign Q = {q5, q4, q3, q2, q1, q0};
endmodule
