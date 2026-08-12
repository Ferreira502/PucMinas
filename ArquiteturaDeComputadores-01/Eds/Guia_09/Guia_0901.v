// Guia_0901.v

// ---------------------------
// -- test clock generator (1)
// ---------------------------
module clock ( output clk );
reg clk;
initial begin
clk = 1'b0;
end

always begin
#12 clk = ~clk;
end
endmodule

module pulse ( output reg signal, input clock );
always @(posedge clock) begin
signal = 1'b1;
#3 signal = 1'b0;
#3 signal = 1'b1;
#3 signal = 1'b0;
end
endmodule // pulse

module trigger ( output reg signal, input on, input clock );
initial signal = 1'b0;

always @(posedge clock) begin
if (on) begin
#60 signal = 1'b1;
#60 signal = 1'b0;
end
end
endmodule // trigger

module Guia_0901;
wire clock;
clock clk_inst ( clock );

reg p;              
wire p1, t1;         

pulse    pulse1  ( p1, clock );
trigger  trigger1( t1, p, clock );

initial begin
p = 1'b0;
end

initial begin
$dumpfile ( "Guia_0901.vcd" );
$dumpvars ( 1, Guia_0901 ); 
end

initial begin
#060 p = 1'b1;
#120 p = 1'b0;
#180 p = 1'b1;
#240 p = 1'b0;
#300 p = 1'b1;
#360 p = 1'b0;
#376 $finish;
end

endmodule // Guia_0901
