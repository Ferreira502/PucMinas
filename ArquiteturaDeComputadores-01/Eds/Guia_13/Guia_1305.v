// ------------------------- 
// Guia_1305
// Nome: Gabriel Ferreira Pereira
// Matricula: 842527 
// ------------------------- 

`timescale 1ns/1ps

module t_ff (
    input clk,
    input T,
    input async_clear,  
    output reg Q
);
    always @(posedge clk or posedge async_clear) begin
        if (async_clear)
            Q <= 1'b0;
        else if (T)
            Q <= ~Q;
    end
endmodule

module mod6_sync_counter (
    input clk,
    input async_clear,     
    output [2:0] Q_out     
);
    wire q0, q1, q2;
    wire T0, T1, T2;
    wire not_q2;
    wire q1_or_q2;

    assign q0 = Q_out[0];
    assign q1 = Q_out[1];
    assign q2 = Q_out[2];

    assign T0 = 1'b1;                   
    assign T1 = q0 & ~q2;                
    assign q1_or_q2 = q1 | q2;
    assign T2 = q0 & q1_or_q2;           

    t_ff FF0 (.clk(clk), .T(T0), .async_clear(async_clear), .Q(Q_out[0]));
    t_ff FF1 (.clk(clk), .T(T1), .async_clear(async_clear), .Q(Q_out[1]));
    t_ff FF2 (.clk(clk), .T(T2), .async_clear(async_clear), .Q(Q_out[2]));

endmodule