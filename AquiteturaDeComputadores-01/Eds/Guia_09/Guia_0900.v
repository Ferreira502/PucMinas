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