/* 
  Guia_0105.v 
  999999 - Xxx Yyy Zzz 
*/ 
module Guia_0105; 
// define data 
   integer   x = 13; // decimal 
   reg [7:0] b        ; // binary 
   reg [0:2][7:0] s = "PUC"; // char array[3] (3x8 bits - little Endian) 
 
// actions 
   initial 
    begin : main 
     $display ( "Guia_0105 - Tests" ); 
     $display ( "x = %d"  , x ); 
     $display ( "b = %8b", b ); 
     $display ( "s = %s"  , s ); 
     b = x; 
     $display ( "b = [%4b] [%4b] = %h %h", b[7:4], b[3:0], b[7:4], b[3:0] ); 
     s[0] = "-"; 
     s[1] = 8'b01001101; // 'M' 
     s[2] = 71;                  // 'G' 
     $display ( "s = %s" , s ); 
    end // main 
 
endmodule // Guia_0105