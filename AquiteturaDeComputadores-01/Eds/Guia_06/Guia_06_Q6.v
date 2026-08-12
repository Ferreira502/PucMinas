// s_pois.v - PoS form
module s_pois(
    input  wire x,
    input  wire y,
    input  wire w,
    input  wire z,
    output wire s
);
  wire m1, m2, m3;

  assign m1 = x | z;              // (X + Z)
  assign m2 = y | z;              // (Y + Z)
  assign m3 = (~w) | (~x) | (~z); // (W' + X' + Z')

  assign s = m1 & m2 & m3;       
endmodule
