// Guia_0905.v

// --------------------------- 
// -- test clock generator (1) 
// --------------------------- 
 
module clock ( output clk ); 
reg      clk; 
 
 initial 
  begin 
   clk = 1'b0; 
  end 
 
 always 
  begin 
   #12 clk = ~clk; 
  end 
 
endmodule // clock ( ) 
 
 
module Guia_0900; 
 
 wire  clk; 
 clock CLK1 ( clk ); 
 
 initial begin 
  $dumpfile ( "Guia_0900.vcd" ); 
  $dumpvars; 
 
  #120 $finish; 
 end 
 
endmodule // Guia_0901 ( ) 

module pulse_mark4 ( output reg signal, input clock );

  initial begin
    signal = 1'b0;
  end

  always @(posedge clock) begin
    signal = 1'b1;   
    #4 signal = 1'b0; 
  end

endmodule

module Guia_0905;

  wire clock;
  clock clk ( clock );

  wire p4;

  pulse_mark4 generator ( p4, clock );

  initial begin
    $dumpfile("Guia_0905.vcd");
    $dumpvars(1, clock, p4);
  end

  initial begin
    #480 $finish;
  end

endmodule
