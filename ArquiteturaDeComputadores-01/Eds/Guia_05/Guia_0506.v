// ------------------------- 
// Guia_0506.v - GATES 
// Nome: Gabriel Ferreira Pereira 
// Matricula: 842527 
// ------------------------- 

module Guia_0506 (output s, input a, input b);
    wire nota, notb;
    wire aandb, notaandnotb;
    wire or1;

    // NOT usando NAND
    nand NAND1 (nota, a, a);   
    nand NAND2 (notb, b, b);   

    // AND(a,b) = ~(a nand b)
    wire nand_ab;
    nand NAND3 (nand_ab, a, b);
    nand NAND4 (aandb, nand_ab, nand_ab); 

    // AND(~a, ~b)
    wire nand_notab;
    nand NAND5 (nand_notab, nota, notb);
    nand NAND6 (notaandnotb, nand_notab, nand_notab); 

    // OR = NAND(~x, ~y)
    wire na, nb;
    nand NAND7 (na, aandb, aandb);           
    nand NAND8 (nb, notaandnotb, notaandnotb); 
    nand NAND9 (s, na, nb);                  
endmodule


// -------------------------
// Testbench
// -------------------------
module test_Guia_0506;
    reg a, b;
    wire s;

    // Instância
    Guia_0506 XNOR1 (s, a, b);

    initial begin
        $display("Guia_0506 - Gabriel Ferreira Pereira - 842527"); 
        $display("Test module (a ^ b) = a xor b"); 
        $display(" a  b  |  s ");
        $display("-------------");

        // Testes
        a=0; b=0; #1 $display(" %b  %b  |  %b", a,b,s);
        a=0; b=1; #1 $display(" %b  %b  |  %b", a,b,s);
        a=1; b=0; #1 $display(" %b  %b  |  %b", a,b,s);
        a=1; b=1; #1 $display(" %b  %b  |  %b", a,b,s);
    end
endmodule