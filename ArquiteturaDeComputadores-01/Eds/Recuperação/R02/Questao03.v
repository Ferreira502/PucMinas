module flipflop_B_logic(
    input  wire a,
    input  wire b,
    input  wire c,
    input  wire d,
    output wire Db,
    output wire Sb,
    output wire Rb,
    output wire Tb
);


    // a) SoP(Db)

    assign Db = ( ~a & ~b & ~c &  d ) |
                (  b &  c & ~d ) |
                (  a & ~b &  c &  d );


    // b) SoP(Sb) 

    assign Sb = ( ~a & ~b & ~c & d ) |
                (  a & ~b &  c & d );


    // c) SoP(Rb)

    assign Rb = ( b & d ) |
                ( b & ~c );


    // d) SoP(Tb) 

    assign Tb = ( b & d ) |
                ( b & ~c ) |
                ( a &  c & d ) |
                ( d & ~a & ~c );

endmodule
