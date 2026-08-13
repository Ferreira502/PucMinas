// ------------------------- 
// Guia_1404.v
// Nome: Gabriel Ferreira Pereira
// Matricula: 842527 
// ------------------------- 

// Registrador de deslocamento circular
// para a ESQUERDA, com 6 bits e carga unitária no primeiro estagio

module twisted_ring_left_6bit (
    input clk,          
    input clear,        
    input ld,           
    output [5:0] q      
);

reg [5:0] q_reg;

always @(posedge clk or posedge clear or posedge ld)
begin
    if (clear)
        q_reg <= 6'b000000;           
    else if (ld)
        q_reg <= 6'b100000;           
    else
        q_reg <= {q_reg[4:0], ~q_reg[5]};
end

assign q = q_reg;

endmodule
