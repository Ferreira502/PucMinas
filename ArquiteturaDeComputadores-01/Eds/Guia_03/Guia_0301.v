/* 
  Guia_0301.v 
  842527 - Gabriel Ferreira Pereira  
*/ 
module Guia_0301; 
// define data 
   reg [7:0] a = 8'b000_1010 ; // binary 
   reg [6:0] b = 8'b000_101   ; // binary 
   reg [5:0] c = 8'b001_01     ; // binary 
   reg [7:0] d = 0                    ; // binary 
   reg [6:0] e = 0                    ; // binary 
   reg [5:0] f  = 0                    ; // binary 
// actions 
   initial 
    begin : main 
     $display ( "Guia_0301 - Tests" ); 
     d = ~a+1; 
     $display ( "a = %8b -> C1(a) = %8b -> C2(a) = %8b", a, ~a, d ); 
     e = ~b+1; 
     $display ( "b = %7b -> C1(b) = %7b -> C2(b) = %7b", b, ~b, e ); 
     f = ~c+1; 
     $display ( "c = %6b -> C1(c) = %6b -> C2(c) = %6b", c, ~c, f ); 
    end // main 
 
endmodule // Guia_0301 