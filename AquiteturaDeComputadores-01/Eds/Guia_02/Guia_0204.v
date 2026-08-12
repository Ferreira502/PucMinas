/* 
  Guia_0204.v 
     842527 - Gabriel Ferreira Pereira
*/ 

module Guia_0204; 
// define data 
   real        x = 0.625;                 // decimal 
   reg [7:0] b = 8'b1010_0000  ; // binary 
   integer q [3:0]; 
// actions 
   initial 
    begin : main 
     $display ( "Guia_0204 - Tests" ); 
     $display ( "x = %f" , x ); 
     $display ( "b = 0.%8b", b ); 
     $display ( "b = 0.%x%x (16)", b[7:4],b[3:0] ); 
     q[3] = b[7:6]; 
     q[2] = b[5:4]; 
     q[1] = b[3:2]; 
     q[0] = b[1:0]; 
     $display ( "b = 0.%2b %2b %2b %2b (2)", b[7:6],b[5:4],b[3:2],b[1:0] ); 
     $display ( "q = 0.%2d %2d %2d %2d (4)", q[3]  ,q[2]  ,q[1]  ,q[0]   ); 
    end // main 
 
endmodule // Guia_0204