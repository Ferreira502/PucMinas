// Guia_0903.v

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

module pulse_div4 ( output reg signal, input clock );
  
  reg [1:0] count; 

  initial begin
    signal = 1'b0;
    count  = 2'b00;
  end

  always @(posedge clock) begin
    count <= count + 1;

    if (count == 2'b11) begin
      signal <= ~signal; 
    end
  end

endmodule

module Guia_0903;

  wire clock;
  clock clk ( clock );

  wire p4;  

  pulse_div4 generator ( p4, clock );

  initial begin
    $dumpfile("Guia_0903.vcd");
    $dumpvars(1, clock, p4);
  end

  initial begin
    #480 $finish;
  end

endmodule