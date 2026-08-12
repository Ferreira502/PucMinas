// ------------------------- 
// Guia_1302
// Nome: Gabriel Ferreira Pereira
// Matricula: 842527 
// ------------------------- 

`timescale 1ns/1ps

module jk_ff (
    input clk,        // clock
    input async_clear,
    output reg q
);
    always @(negedge clk or posedge async_clear) begin
        if (async_clear)
            q <= 1'b0;     
        else
            q <= ~q;       
    end
endmodule


module up_counter_5bit (
    input clk_ext,           
    input clear,             
    output [4:0] q_out       
);
    wire q0, q1, q2, q3, q4;

    jk_ff FF0 (.clk(clk_ext),      .async_clear(clear), .q(q0));

    jk_ff FF1 (.clk(~q0),         .async_clear(clear), .q(q1));
    jk_ff FF2 (.clk(~q1),         .async_clear(clear), .q(q2));
    jk_ff FF3 (.clk(~q2),         .async_clear(clear), .q(q3));
    jk_ff FF4 (.clk(~q3),         .async_clear(clear), .q(q4));

    assign q_out = {q4, q3, q2, q1, q0};
endmodule
