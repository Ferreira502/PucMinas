module flipflop_A_logic(
    input  wire a, b, c, d,
    output wire Da,
    output wire Sa, Ra,
    output wire Ta
);

    // a) SoP(Da)
    assign Da = (~a & ~b & ~c &  d) |
                ( a & ~b &  c & ~d) |
                ( a &  b &  c);


    // b) SoP(Sa) e SoP(Ra)

    assign Sa = (~a & ~b & ~c & d);

    assign Ra = (a & ~c) |
                (a & ~b & c & d);



    // c) SoP(Ta)

    assign Ta = (a & ~c) |
                (~b & ~c & d) |
                (a & ~b & d);

endmodule
