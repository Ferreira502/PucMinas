// -------------------------
// Guia_0508.v
// Nome: Gabriel Ferreira Pereira
// Matricula: 842527
// -------------------------

module Guia_0508 (output s, input a, input b);
    wire nota, notb;

    // inverter a usando NAND
    nand NAND1(nota, a, a);   
    // inverter b usando NAND
    nand NAND2(notb, b, b);   
    
    // OR via NAND: x | y = ~(~x & ~y)
    nand NAND3(s, nota, notb);
endmodule


// -------------------------
// Testbench
// -------------------------
module test_Guia_0508;
    reg a, b;
    wire s;

    Guia_0508 modulo(s, a, b);

    initial begin
        $display("Guia_0508 - Gabriel Ferreira Pereira - 842527"); 
        $display("Test module- f(a,b) = ~a | b usando apenas NAND");
        $display(" a  b  |  s ");
        $display("-------------");

        a=0; b=0; #1 $display(" %b  %b  |  %b", a,b,s);
        a=0; b=1; #1 $display(" %b  %b  |  %b", a,b,s);
        a=1; b=0; #1 $display(" %b  %b  |  %b", a,b,s);
        a=1; b=1; #1 $display(" %b  %b  |  %b", a,b,s);
    end
endmodule