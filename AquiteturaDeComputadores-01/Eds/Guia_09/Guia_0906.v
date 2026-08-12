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

module pulse ( output reg signal, input clk );

    always @(negedge clk) begin
        signal = 1'b1;
        #3 signal = 1'b0;
    end

endmodule // pulse


module Guia_0906;

    wire clk;
    clock CLK1(clk);

    wire p1;
    pulse PULSE1(p1, clk);

    initial begin
        $dumpfile("Guia_0906.vcd");
        $dumpvars(1, clk, p1);
    end

    initial begin
        #200 $finish;
    end

endmodule
