/*
 Questao_03.v
 842527 - Gabriel Ferreira Pereira
*/

module f (output s, input a, input b);
    wire w1, w2, w3, w4, w5, w6;
    
    // XNOR(a,b)
    xnor X1 (w1, a, b);
    
    // NOT(a), NOT(b)
    not N1 (w2, a);
    not N2 (w3, b);
    
    // NOR(NOT(a), NOT(b))
    nor N3 (w4, w2, w3);
    
    // NAND(XNOR(a,b), NOR(NOT(a),NOT(b)))
    nand N4 (s, w1, w4);
endmodule
