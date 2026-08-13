module flipflop_C_logic(
    input  wire a,
    input  wire b,
    input  wire c,
    input  wire d,
    output wire Dc,
    output wire Sc,
    output wire Rc,
    output wire Tc
);

    // a) Dc 
    assign Dc = ( c & (a | b | ~d) ) |
                ( ~a & ~b & ~c & d );

    // b) Sc
    assign Sc = ( ~a & ~b & ~c & d );

    // c) Rc 
    assign Rc = ( ~a & ~b &  c & d );

    // d) Tc 
    assign Tc = ( ~a & ~b & d );

endmodule
