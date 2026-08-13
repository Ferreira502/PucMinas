module s_module_with_wires(
    input  wire x,
    input  wire y,
    input  wire z,
    output wire s
);
  wire w5, w3, w6, w4, w10, w11, w7b, w2;

  assign w5  = (~x) | (~y);       
  assign w3  = ~w5;               // = x & y
  assign w6  = y & z;
  assign w4  = w3 & (~w6);        // = x*y*z'
  assign w10 = x & y;
  assign w11 = ~z;
  assign w7b = w10 | w11;         // = x*y + z'
  assign w2  = ~w7b;              // = z*(x' + y')
  assign s   = w4 | w2;

endmodule
