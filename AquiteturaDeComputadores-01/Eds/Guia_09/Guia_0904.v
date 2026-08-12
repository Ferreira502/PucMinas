// Guia_0904.v

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

module pulse_double_freq ( output reg signal, input clock );

  initial begin
    signal = 1'b0;
  end

  // alterna na borda de subida
  always @(posedge clock) begin
    signal <= ~signal;
  end

  // alterna tambem na borda de descida
  always @(negedge clock) begin
    signal <= ~signal;
  end

endmodule

module Guia_0904;

  wire clock;
  clock clk ( clock );

  wire p2; 

  pulse_double_freq generator ( p2, clock );

  initial begin
    $dumpfile("Guia_0904.vcd");
    $dumpvars(1, clock, p2);
  end

  initial begin
    #480 $finish;
  end

endmodule
