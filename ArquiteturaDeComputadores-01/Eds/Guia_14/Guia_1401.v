// ------------------------- 
// Guia_1401.v
// Nome: Gabriel Ferreira Pereira
// Matricula: 842527 
// ------------------------- 

// Registrador de deslocamento a esquerda (6 bits)
// com carga de 1 bit via preset no primeiro estagio

module shift_left_6bit (
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
        q_reg[0] <= 1'b1;         
    else
        q_reg <= q_reg << 1;      
end

assign q = q_reg;

endmodule